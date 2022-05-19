// ywstd/@/unique_ptr.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDeleterX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../compare.hh"
#include "../iosfwd.hh"
#include "../type_traits.hh"

namespace std {

template<typename Ty> struct default_delete {
  constexpr default_delete() noexcept = default;
  template<typename Uy> default_delete(const default_delete<Uy>&) noexcept;
  void operator()(Ty*) const;
};

template<typename Ty> struct default_delete<Ty[]> {
  constexpr default_delete() noexcept = default;
  template<typename Uy> default_delete(const default_delete<Uy[]>&) noexcept;
  template<typename Uy> void operator()(Uy* p) const;
};

namespace _ {
  template<typename Ty> concept nullable_pointer =
    _::is_destructible_v<Ty> && _::is_constructible_v<Ty> && _::is_constructible_v<Ty, const Ty&> && _::is_constructible_v<Ty, nullptr_t> &&
    _::is_assignable_v<Ty&, const Ty&> && _::is_assignable_v<Ty&, nullptr_t> && equality_comparable_with<Ty, nullptr_t>;
  template<typename Ty, typename Deleter> struct unique_ptr_pointer { using type = Ty*; };
  template<typename Ty, typename Deleter> requires requires { typename remove_reference<Deleter>::type::pointer; }
  struct unique_ptr_pointer<Ty, Deleter> { using type = typename remove_reference<Deleter>::type::pointer; };
}

template<typename Ty, typename Deleter = default_delete<Ty>> class unique_ptr {
public:
  using pointer = typename _::unique_ptr_pointer<Ty, Deleter>::type;
  using element_type = Ty;
  using deleter_type = Deleter;
  static_assert(_::nullable_pointer<Ty>);

  constexpr ~unique_ptr() { if (get() != nullptr) get_deleter()(get()); }
  unique_ptr(const unique_ptr&) = delete;
  constexpr unique_ptr() noexcept requires _::is_default_constructible_v<Deleter> &&  (!_::is_pointer_v<Deleter>) : _ptr{}, _del{} {}
  constexpr unique_ptr(nullptr_t) noexcept requires _::is_default_constructible_v<Deleter> &&  (!_::is_pointer_v<Deleter>) : unique_ptr{} {}
  constexpr explicit unique_ptr(pointer p) noexcept requires _::is_default_constructible_v<Deleter> : _ptr{p}, _del{} {}

  constexpr unique_ptr(pointer p, const Deleter& d) noexcept
    requires (!_::is_reference_v<Deleter> && _::is_nothrow_constructible_v<Deleter, const Deleter&>) : _ptr{p}, _del{d} {}

  constexpr unique_ptr(pointer p, typename remove_reference<Deleter>::type&& d) noexcept
    requires (!_::is_reference_v<Deleter> && _::is_nothrow_constructible_v<Deleter, Deleter>) : _ptr{p}, _del{static_cast<Deleter&&>(d)} {}

  constexpr unique_ptr(pointer p, Deleter d) noexcept
    requires _::is_lvalue_reference_v<Deleter> && _::is_constructible_v<Deleter, Deleter> : _ptr{p}, _del{d} {}

  constexpr unique_ptr(unique_ptr&& u) noexcept
    requires _::is_constructible_v<Deleter, Deleter> && (_::is_lvalue_reference_v<Ty> || _::is_nothrow_constructible_v<Deleter, Deleter>)
    : _ptr{u._ptr}, _del{static_cast<Deleter&&>(u._ptr)} { u._ptr = nullptr; }

  template<typename T2, typename D2> unique_ptr(unique_ptr<T2, D2>&& u) noexcept
    requires _::is_convertible_v<typename unique_ptr<T2, D2>::pointer, pointer> && (!_::is_array_v<T2>) &&
             (_::is_reference_v<Deleter> && _::is_same_v<Deleter, D2>) || (!_::is_reference_v<Deleter> && _::is_convertible_v<D2, Deleter>)
    : _ptr{u.get()}, _del{static_cast<D2&&>(u.get_deleter())} {}

  unique_ptr& operator=(const unique_ptr&) = delete;

  constexpr unique_ptr& operator=(unique_ptr&& u) noexcept requires _::is_nothrow_assignable_v<Deleter&, Deleter> {
    reset(u.release()); get_deleter() = static_cast<Deleter&&>(u.get_deleter()); return *this;
  }

  template<typename T2, typename D2> constexpr unique_ptr& operator=(unique_ptr<T2, D2>&& u) noexcept
    requires (!_::is_array_v<T2> && _::is_convertible_v<typename unique_ptr<T2, D2>::pointer, pointer> && _::is_assignable_v<Deleter&, D2&&>) {
    reset(u.release()); get_deleter() = static_cast<D2&&>(u.get_deleter()); return *this;
  }

  constexpr unique_ptr& operator=(nullptr_t) noexcept { reset(); return *this; }

  constexpr pointer release() noexcept { get_deleter()(get()); }
  constexpr void reset(pointer p = pointer{}) noexcept;
  void swap(unique_ptr& u) noexcept;

  typename add_lvalue_reference<Ty>::type operator*() const noexcept(noexcept(*_::declval<pointer>()));
  pointer operator->() const noexcept;
  pointer get() const noexcept;
  deleter_type& get_deleter() noexcept;
  const deleter_type& get_deleter() const noexcept;
  explicit operator bool() const noexcept;
private:
  pointer _ptr;
  deleter_type _del;
};

template<typename Ty, typename Deleter> class unique_ptr<Ty[], Deleter> {
public:
  using pointer = typename _::unique_ptr_pointer<Ty, Deleter>::type;
  using element_type = Ty;
  using deleter_type = Deleter;
  static_assert(_::nullable_pointer<Ty>);
private:
  template<typename T2> static constexpr bool can_ctor = _::is_same_v<T2, pointer> || _::is_null_pointer_v<T2> ||
    (_::is_same_v<pointer, element_type*> && _::is_pointer_v<T2> && _::is_convertible_v<_::remove_reference_t<T2>(*)[], element_type(*)[]>);
public:
  ~unique_ptr() { if (get() != nullptr) get_deleter()(get()); }
  unique_ptr(const unique_ptr&) = delete;
  constexpr unique_ptr() noexcept requires _::is_default_constructible_v<Deleter> &&  (!_::is_pointer_v<Deleter>) : _ptr{}, _del{} {}
  constexpr unique_ptr(nullptr_t) noexcept requires _::is_default_constructible_v<Deleter> &&  (!_::is_pointer_v<Deleter>) : unique_ptr{} {}
  template<typename T2> explicit unique_ptr(T2 p) noexcept requires _::is_default_constructible_v<Deleter> : _ptr{p}, _del{} {}

  template<typename T2> unique_ptr(T2 p, const Deleter& d) noexcept
    requires (!_::is_reference_v<Deleter>) && _::is_nothrow_constructible_v<Deleter, const Deleter&> && can_ctor<T2> : _ptr(p), _del{d} {}

  template<typename T2> unique_ptr(T2 p, typename remove_reference<Deleter>::type&& d) noexcept
    requires (!_::is_reference_v<Deleter>) && _::is_nothrow_constructible_v<Deleter, Deleter> && can_ctor<T2> : _ptr{p}, _del{static_cast<Deleter&&>(d)} {}

  template<typename T2> unique_ptr(T2 p, Deleter d) noexcept
    requires _::is_lvalue_reference_v<Deleter> && _::is_constructible_v<Deleter, Deleter> && can_ctor<T2> : _ptr{p}, _del{d} {}

  unique_ptr(unique_ptr&& u) noexcept
    requires _::is_constructible_v<Deleter, Deleter> && (_::is_lvalue_reference_v<Ty> || _::is_nothrow_constructible_v<Deleter, Deleter>)
    : _ptr{u._ptr}, _del{static_cast<Deleter&&>(u._ptr)} { u._ptr = nullptr; }

  template<typename T2, typename D2> unique_ptr(unique_ptr<T2, D2>&& u) noexcept
    requires _::is_array_v<T2> && _::is_same_v<pointer, element_type*> &&
             _::is_same_v<typename unique_ptr<T2, D2>::pointer, typename unique_ptr<T2, D2>::element_type*> &&
             ((_::is_reference_v<Deleter> && _::is_same_v<D2, Deleter>) || (!_::is_reference_v<Deleter> && _::is_convertible_v<D2, Deleter>))
    : _ptr{u.get()}, _del{static_cast<D2&&>(u.get_deleter())} {}

  unique_ptr& operator=(const unique_ptr&) = delete;
  constexpr unique_ptr& operator=(nullptr_t) noexcept { reset(); return *this; }

  constexpr unique_ptr& operator=(unique_ptr&& u) noexcept requires _::is_nothrow_assignable_v<Deleter&, Deleter> {
    reset(u.release()); get_deleter() = static_cast<Deleter&&>(u.get_deleter()); return *this;
  }

  template<typename T2, typename D2> unique_ptr& operator=(unique_ptr<T2, D2>&& u) noexcept
    requires _::is_array_v<T2> && _::is_same_v<pointer, element_type*> &&
             _::is_same_v<typename unique_ptr<T2, D2>::pointer, typename unique_ptr<T2, D2>::element_type*> &&
             _::is_convertible_v<typename unique_ptr<T2, D2>::element_type(*)[], element_type(*)[]> && _::is_assignable_v<Deleter&, D2&&> {
    reset(u.release()); get_deleter() = static_cast<Deleter&&>(u.get_deleter()); return *this;
  }

  pointer release() noexcept;
  template<typename T2> void reset(T2 p) noexcept;
  void reset(nullptr_t = nullptr) noexcept;
  void swap(unique_ptr& u) noexcept;

  Ty& operator[](size_t i) const;
  pointer get() const noexcept;
  deleter_type& get_deleter() noexcept;
  const deleter_type& get_deleter() const noexcept;
  explicit operator bool() const noexcept;
private:
  pointer _ptr;
  deleter_type _del;
};

}
