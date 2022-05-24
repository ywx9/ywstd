// ywstd/tuple.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <tuple>
#else

#include "@/../compare.hh"
#include "@/../type_traits.hh"
#include "@/allocator.hh"
#include "@/pair.hh"
#include "@/tuple_element.hh"
#include "@/uses_allocator.hh"

namespace std::_ {
template<typename... Ts> struct tuple_value {
  constexpr void swap(const tuple_value&) const noexcept {}
};
template<typename T1> struct tuple_value<T1> {
  using type = T1;
  T1 value;
  struct tag {};
  constexpr tuple_value& get_this() & noexcept { return *this; }
  constexpr tuple_value&& get_this() && noexcept { return static_cast<tuple_value&&>(*this); }
  constexpr const tuple_value& get_this() const& noexcept { return *this; }
  constexpr const tuple_value&& get_this() const&& noexcept { return static_cast<const tuple_value&&>(*this); }
  constexpr tuple_value() : value{} {}
  template<typename U1> constexpr tuple_value(U1&& x1) requires (!specialized_of<remove_cvref_t<U1>, tuple_value>) : value{_::forward<U1>(x1)} {}
  template<typename Tp> constexpr tuple_value(Tp&& t) requires specialized_of<remove_cvref_t<Tp>, tuple_value> : value{_::forward<Tp>(t).value} {}

  template<typename Al> constexpr tuple_value(tag, const Al& al) requires (!uses_allocator<T1, Al>::value) : value{} {}
  template<typename Al> constexpr tuple_value(tag, const Al& al)
    requires uses_allocator<T1, Al>::value && is_constructible_v<T1, allocator_arg_t, const Al&> : value{allocator_arg_t{}, al} {}
  template<typename Al> constexpr tuple_value(tag, const Al& al)
    requires uses_allocator<T1, Al>::value && (!is_constructible_v<T1, allocator_arg_t, const Al&>) && is_constructible_v<T1, const Al&> : value{al} {}

  template<typename Al, typename U1> constexpr tuple_value(tag, const Al& al, U1&& x1)
    requires (!specialized_of<remove_cvref_t<U1>, tuple_value> && !uses_allocator<T1, Al>::value) : value{_::forward<U1>(x1)} {}
  template<typename Al, typename U1> constexpr tuple_value(tag, const Al& al, U1&& x1)
    requires (!specialized_of<remove_cvref_t<U1>, tuple_value>) && uses_allocator<T1, Al>::value && is_constructible_v<T1, allocator_arg_t, const Al&, U1>
    : value{allocator_arg_t{}, al, _::forward<U1>(x1)} {}
  template<typename Al, typename U1> constexpr tuple_value(tag, const Al& al, U1&& x1)
    requires (!specialized_of<remove_cvref_t<U1>, tuple_value>) && uses_allocator<T1, Al>::value &&
             (!is_constructible_v<T1, allocator_arg_t, const Al&, U1>) && is_constructible_v<T1, U1, const Al&> : value{_::forward<U1>(x1), al} {}

  template<typename Al, typename Tp> constexpr tuple_value(tag, const Al& al, Tp&& x1)
    requires specialized_of<remove_cvref_t<Tp>, tuple_value> && (!uses_allocator<T1, Al>::value) : value{_::forward<Tp>(x1).value} {}
  template<typename Al, typename Tp> constexpr tuple_value(tag, const Al& al, Tp&& x1)
    requires specialized_of<remove_cvref_t<Tp>, tuple_value> && uses_allocator<T1, Al>::value && is_constructible_v<T1, allocator_arg_t, const Al&, Tp>
    : value{allocator_arg_t{}, al, _::forward<Tp>(x1).value} {}
  template<typename Al, typename Tp> constexpr tuple_value(tag, const Al& al, Tp&& x1)
    requires specialized_of<remove_cvref_t<Tp>, tuple_value> && uses_allocator<T1, Al>::value &&
             (!is_constructible_v<T1, allocator_arg_t, const Al&, Tp>) && is_constructible_v<T1, Tp, const Al&> : value{_::forward<Tp>(x1).value, al} {}

  template<typename U1> constexpr void operator=(U1&& x1) requires (!specialized_of<remove_cvref_t<U1>, tuple_value>) { value = _::forward<U1>(x1); }
  template<typename Tp> constexpr void operator=(Tp&& t) requires specialized_of<remove_cvref_t<Tp>, tuple_value> { value = _::forward<Tp>(t).value; }
  template<typename U1> constexpr void operator=(U1&& x1) const requires (!specialized_of<remove_cvref_t<U1>, tuple_value>) { value = _::forward<U1>(x1); }
  template<typename Tp> constexpr void operator=(Tp&& t) const requires specialized_of<remove_cvref_t<Tp>, tuple_value> { value = _::forward<Tp>(t).value; }

  constexpr void swap(tuple_value& t) noexcept(is_nothrow_swappable_v<T1>) { swap(value, t.value); }
  constexpr void swap(const tuple_value& t) const noexcept(is_nothrow_swappable_v<const T1>) { swap(value, t.value); }
};
template<typename T1, typename... Ts> struct tuple_value<T1, Ts...> : tuple_value<Ts...> {
  using type = T1;
  T1 value;
  struct tag {};
  constexpr tuple_value& get_this() & noexcept { return *this; }
  constexpr tuple_value&& get_this() && noexcept { return static_cast<tuple_value&&>(*this); }
  constexpr const tuple_value& get_this() const& noexcept { return *this; }
  constexpr const tuple_value&& get_this() const&& noexcept { return static_cast<const tuple_value&&>(*this); }
  constexpr tuple_value<Ts...>& get_base() & noexcept { return tuple_value<Ts...>::get_this(); }
  constexpr tuple_value<Ts...>&& get_base() && noexcept { return tuple_value<Ts...>::get_this(); }
  constexpr const tuple_value<Ts...>& get_base() const& noexcept { return tuple_value<Ts...>::get_this(); }
  constexpr const tuple_value<Ts...>&& get_base() const&& noexcept { return tuple_value<Ts...>::get_this(); }
  constexpr tuple_value() : tuple_value<Ts...>{}, value{} {}
  template<typename U1, typename... Us> constexpr tuple_value(U1&& x1, Us&&... xs) : tuple_value<Ts...>{_::forward<Us>(xs)...}, value{_::forward<U1>(x1)} {}
  template<typename Tp> constexpr tuple_value(Tp&& t) : tuple_value<Ts...>{_::forward<Tp>(t).get_base()}, value{_::forward<Tp>(t).value} {}

  template<typename Al> constexpr tuple_value(tag, const Al& al) requires (!uses_allocator<T1, Al>::value) : tuple_value<Ts...>{tag{}}, value{} {}
  template<typename Al> constexpr tuple_value(tag, const Al& al)
    requires uses_allocator<T1, Al>::value && is_constructible_v<T1, allocator_arg_t, const Al&>
    : tuple_value<Ts...>{tag{}, al}, value{allocator_arg_t{}, al} {}
  template<typename Al> constexpr tuple_value(tag, const Al& al)
    requires uses_allocator<T1, Al>::value && (!is_constructible_v<T1, allocator_arg_t, const Al&>) && is_constructible_v<T1, const Al&>
    : tuple_value<Ts...>{tag{}, al}, value{al} {}

  template<typename Al, typename U1, typename... Us> constexpr tuple_value(tag, const Al& al, U1&& x1, Us&&... xs)
    requires (!uses_allocator<T1, Al>::value) : tuple_value<Ts...>{tag{}, al, static_cast<Us&&>(xs)...}, value{_::forward<U1>(x1)} {}
  template<typename Al, typename U1, typename... Us> constexpr tuple_value(tag, const Al& al, U1&& x1, Us&&... xs)
    requires uses_allocator<T1, Al>::value && is_constructible_v<T1, allocator_arg_t, const Al&, U1>
    : tuple_value<Ts...>{tag{}, al, static_cast<Us&&>(xs)...}, value{allocator_arg_t{}, al, _::forward<U1>(x1)} {}
  template<typename Al, typename U1, typename... Us> constexpr tuple_value(tag, const Al& al, U1&& x1, Us&&... xs)
    requires uses_allocator<T1, Al>::value && (!is_constructible_v<T1, allocator_arg_t, const Al&, U1>) && is_constructible_v<T1, U1, const Al&>
    : tuple_value<Ts...>{tag{}, al, static_cast<Us&&>(xs)...}, value{_::forward<U1>(x1), al} {}

  template<typename Al, typename Tp> constexpr tuple_value(tag, const Al& al, Tp&& x)
    requires (!uses_allocator<T1, Al>::value) : tuple_value<Ts...>{tag{}, al, _::forward<Tp>(x).get_base()}, value{_::forward<Tp>(x).value} {}
  template<typename Al, typename Tp> constexpr tuple_value(tag, const Al& al, Tp&& x)
    requires uses_allocator<T1, Al>::value && is_constructible_v<T1, allocator_arg_t, const Al&, copy_cvref_t<typename Tp::type, Tp>>
    : tuple_value<Ts...>{tag{}, al, _::forward<Tp>(x).get_base()}, value{allocator_arg_t{}, al, _::forward<Tp>(x).value} {}
  template<typename Al, typename Tp> constexpr tuple_value(tag, const Al& al, Tp&& x)
    requires uses_allocator<T1, Al>::value && (!is_constructible_v<T1, allocator_arg_t, const Al&, copy_cvref_t<typename Tp::type, Tp>>) &&
             is_constructible_v<T1, copy_cvref_t<typename Tp::type, Tp>, const Al&>
    : tuple_value<Ts...>{tag{}, al, _::forward<Tp>(x).get_base()}, value{_::forward<Tp>(x).value, al} {}

  template<typename Pr> constexpr void operator=(Pr&& p)
    requires specialized_of<remove_cvref_t<Pr>, pair> { value = _::forward<Pr>(p).first; get_base() = _::forward<Pr>(p).second; }

  template<typename Tp> constexpr void operator=(Tp&& p)
    requires specialized_of<remove_cvref_t<Tp>, tuple_value> { value = _::forward<Tp>(p).value; get_base() = _::forward<Tp>(p).get_base(); }

  template<typename Pr> constexpr void operator=(Pr&& p) const
    requires specialized_of<remove_cvref_t<Pr>, pair> { value = _::forward<Pr>(p).first; get_base() = _::forward<Pr>(p).second; }

  template<typename Tp> constexpr void operator=(Tp&& p) const
    requires specialized_of<remove_cvref_t<Tp>, tuple_value> { value = _::forward<Tp>(p).value; get_base() = _::forward<Tp>(p).get_base(); }

  constexpr void swap(tuple_value& t) noexcept((is_nothrow_swappable_v<Ts> && ...)) { swap(value, t.value); swap(t.get_base()); }
  constexpr void swap(const tuple_value& t) const noexcept((is_nothrow_swappable_v<const Ts> && ...)) { swap(value, t.value); swap(t.get_base()); }
};
struct tuple_get;
}

namespace std {

template<typename... Ts> class tuple {
  template<typename... Us> friend class tuple;
  friend struct _::tuple_get;
  _::tuple_value<Ts...> values;
  static constexpr bool expl_ctor1 = !(_::is_implicitly_default_constructible_v<Ts> && ...);
  static constexpr bool expl_ctor2 = !(_::is_convertible_v<const Ts&, Ts> && ...);
  template<typename... Us> static constexpr bool expl_ctor3 = requires { requires !(_::is_convertible_v<Us, Ts> && ...); };
  template<typename... Us> static constexpr bool can_ctor = requires { requires (_::is_constructible_v<Ts, Us> && ...); };
  template<typename... Us> static constexpr bool can_assign1 = requires { requires (_::is_assignable_v<Ts&, Us> && ...); };
  template<typename... Us> static constexpr bool can_assign2 = requires { requires (_::is_assignable_v<const Ts&, Us> && ...); };
public:
  constexpr explicit(expl_ctor1) tuple() requires (_::is_default_constructible_v<Ts> && ...) : values{} {}

  constexpr explicit(expl_ctor2) tuple(const Ts&... xs)
    requires (sizeof...(Ts) != 0) && (_::is_copy_constructible_v<Ts> && ...) : values{xs...} {}

  template<typename... Us> constexpr explicit(expl_ctor3<Us...>) tuple(Us&&... xs)
    requires requires {
      requires sizeof...(Ts) != 0 && sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, Us> && ...);
      requires !(sizeof...(Ts) == 1 && (_::specialized_of<_::remove_cvref_t<Us>, tuple> && ...));
      requires !(sizeof...(Ts) == 2 || sizeof...(Ts) == 3) &&
               (_::is_same_v<_::remove_cvref_t<_::type_switch_t<0, Us...>>, allocator_arg_t> && !_::is_same_v<_::type_switch_t<0, Ts...>, allocator_arg_t>);
    } : values{static_cast<Us>(xs)...} {}

  template<typename... Us> constexpr explicit(expl_ctor3<Us&...>) tuple(tuple<Us...>& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, Us&> && ...);
      requires sizeof...(Ts) != 1 || !(_::is_convertible_v<tuple<Us...>&, _::type_switch_t<0, Ts...>> ||
                                     _::is_convertible_v<_::type_switch_t<0, Ts...>, tuple<Us...>&> ||
                                     _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>);
    } : values{x.values} {}

  template<typename... Us> constexpr explicit(expl_ctor3<const Us&...>) tuple(const tuple<Us...>& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, const Us&> && ...);
      requires (sizeof...(Ts) != 1 || !(_::is_convertible_v<const tuple<Us...>&, _::type_switch_t<0, Ts...>> ||
                                      _::is_convertible_v<_::type_switch_t<0, Ts...>, const tuple<Us...>&> ||
                                      _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>));
    } : values{x.values} {}

  template<typename... Us> constexpr explicit(expl_ctor3<Us...>) tuple(tuple<Us...>&& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, Us> && ...);
      requires (sizeof...(Ts) != 1 || !(_::is_convertible_v<tuple<Us...>, _::type_switch_t<0, Ts...>> ||
                                      _::is_convertible_v<_::type_switch_t<0, Ts...>, tuple<Us...>> ||
                                      _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>));
    } : values{x.values} {}

  template<typename... Us> constexpr explicit(expl_ctor3<const Us...>) tuple(const tuple<Us...>&& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, const Us> && ...);
      requires (sizeof...(Ts) != 1 || !(_::is_convertible_v<const tuple<Us...>, _::type_switch_t<0, Ts...>> ||
                                      _::is_convertible_v<_::type_switch_t<0, Ts...>, const tuple<Us...>> ||
                                      _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>));
    } : values{x.values} {}

  template<typename U1, typename U2> constexpr explicit(expl_ctor3<U1&, U2&>) tuple(pair<U1, U2>& x)
    requires (sizeof...(Ts) == 2) && can_ctor<U1&, U2&> : values{x.first, x.second} {}

  template<typename U1, typename U2> constexpr explicit(expl_ctor3<const U1&, const U2&>) tuple(const pair<U1, U2>& x)
    requires (sizeof...(Ts) == 2) && can_ctor<const U1&, const U2&> : values{x.first, x.second} {}

  template<typename U1, typename U2> constexpr explicit(expl_ctor3<U1, U2>) tuple(pair<U1, U2>&& x)
    requires (sizeof...(Ts) == 2) && can_ctor<U1, U2> : values{_::move(x.first), _::move(x.second)} {}

  template<typename U1, typename U2> constexpr explicit(expl_ctor3<const U1, const U2>) tuple(const pair<U1, U2>&& x)
    requires (sizeof...(Ts) == 2) && can_ctor<const U1, const U2> : values{_::move(x.first), _::move(x.second)} {}

  constexpr tuple(const tuple&) = default;
  constexpr tuple(tuple&&) = default;

  template<typename Al> constexpr explicit(expl_ctor1) tuple(allocator_arg_t, const Al& al)
    requires (_::is_default_constructible_v<Ts> && ...) : values{typename _::tuple_value<Ts...>::tag{}, al} {}

  template<typename Al> constexpr explicit(expl_ctor2) tuple(allocator_arg_t, const Al& al, const Ts&... xs)
    requires (sizeof...(Ts) != 0) && (_::is_copy_constructible_v<Ts> && ...) : values{typename _::tuple_value<Ts...>::tag{}, al, xs...} {}

  template<typename Al, typename... Us> constexpr explicit(expl_ctor3<Us...>) tuple(allocator_arg_t, const Al& al, Us&&... xs)
    requires requires {
      requires sizeof...(Ts) != 0 && (_::is_constructible_v<Ts, Us> && ...);
      requires !(sizeof...(Ts) == 1 && (_::specialized_of<_::remove_cvref_t<Us>, tuple> && ...));
      requires !((sizeof...(Ts) == 2 || sizeof...(Ts) == 3) && _::is_same_v<_::remove_cvref_t<_::type_switch_t<0, Us...>>, allocator_arg_t> &&
                                                              !_::is_same_v<_::type_switch_t<0, Ts...>, allocator_arg_t>);
    } : values{typename _::tuple_value<Ts...>::tag{}, al, static_cast<Us>(xs)...} {}

  template<typename Al, typename... Us> constexpr explicit(expl_ctor3<Us&...>) tuple(allocator_arg_t, const Al& al, tuple<Us...>& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, Us&> && ...);
      requires sizeof...(Ts) != 1 || !(_::is_convertible_v<tuple<Us...>&, _::type_switch_t<0, Ts...>> ||
                                     _::is_convertible_v<_::type_switch_t<0, Ts...>, tuple<Us...>&> ||
                                     _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>);
    } : values{typename _::tuple_value<Ts...>::tag{}, al, x.values} {}

  template<typename Al, typename... Us> constexpr explicit(expl_ctor3<const Us&...>) tuple(allocator_arg_t, const Al& al, const tuple<Us...>& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, const Us&> && ...);
      requires (sizeof...(Ts) != 1 || !(_::is_convertible_v<const tuple<Us...>&, _::type_switch_t<0, Ts...>> ||
                                      _::is_convertible_v<_::type_switch_t<0, Ts...>, const tuple<Us...>&> ||
                                      _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>));
    } : values{typename _::tuple_value<Ts...>::tag{}, al, x.values} {}

  template<typename Al, typename... Us> constexpr explicit(expl_ctor3<Us...>) tuple(allocator_arg_t, const Al& al, tuple<Us...>&& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, Us> && ...);
      requires (sizeof...(Ts) != 1 || !(_::is_convertible_v<tuple<Us...>, _::type_switch_t<0, Ts...>> ||
                                      _::is_convertible_v<_::type_switch_t<0, Ts...>, tuple<Us...>> ||
                                      _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>));
    } : values{typename _::tuple_value<Ts...>::tag{}, al, x.values} {}

  template<typename Al, typename... Us> constexpr explicit(expl_ctor3<const Us...>) tuple(allocator_arg_t, const Al& al, const tuple<Us...>&& x)
    requires requires {
      requires sizeof...(Ts) == sizeof...(Us) && (_::is_constructible_v<Ts, const Us> && ...);
      requires (sizeof...(Ts) != 1 || !(_::is_convertible_v<const tuple<Us...>, _::type_switch_t<0, Ts...>> ||
                                      _::is_convertible_v<_::type_switch_t<0, Ts...>, const tuple<Us...>> ||
                                      _::is_same_v<_::type_switch_t<0, Ts...>, _::type_switch_t<0, Us...>>));
    } : values{typename _::tuple_value<Ts...>::tag{}, al, x.values} {}

  template<typename Al, typename U1, typename U2> constexpr explicit(expl_ctor3<U1&, U2&>) tuple(allocator_arg_t, const Al& al, pair<U1, U2>& x)
    requires (sizeof...(Ts) == 2) && can_ctor<U1&, U2&> : values{typename _::tuple_value<Ts...>::tag{}, al, x.first, x.second} {}

  template<typename Al, typename U1, typename U2> constexpr explicit(expl_ctor3<const U1&, const U2&>) tuple(allocator_arg_t, const Al& al, const pair<U1, U2>& x)
    requires (sizeof...(Ts) == 2) && can_ctor<const U1&, const U2&> : values{typename _::tuple_value<Ts...>::tag{}, al, x.first, x.second} {}

  template<typename Al, typename U1, typename U2> constexpr explicit(expl_ctor3<U1, U2>) tuple(allocator_arg_t, const Al& al, pair<U1, U2>&& x)
    requires (sizeof...(Ts) == 2) && can_ctor<U1, U2> : values{typename _::tuple_value<Ts...>::tag{}, al, _::move(x.first), _::move(x.second)} {}

  template<typename Al, typename U1, typename U2> constexpr explicit(expl_ctor3<const U1, const U2>) tuple(allocator_arg_t, const Al& al, const pair<U1, U2>&& x)
    requires (sizeof...(Ts) == 2) && can_ctor<const U1, const U2> : values{typename _::tuple_value<Ts...>::tag{}, al, _::move(x.first), _::move(x.second)} {}

  template<typename Al> constexpr explicit(expl_ctor3<const Ts...>) tuple(allocator_arg_t, const Al& al, const tuple& t)
    requires can_ctor<const Ts&...> : values{typename _::tuple_value<Ts...>::tag{}, al, t.values} {}

  template<typename Al> constexpr explicit(expl_ctor3<Ts...>) tuple(allocator_arg_t, const Al& al, tuple&& t)
    requires can_ctor<Ts...> : values{typename _::tuple_value<Ts...>::tag{}, al, t.values} {}

  constexpr tuple& operator=(const tuple& t) requires can_assign1<const Ts&...> { values = t.values; return *this; }
  constexpr const tuple& operator=(const tuple& t) const requires can_assign2<const Ts&...> { values = t.values; return *this; }

  constexpr tuple& operator=(tuple&& t) noexcept((_::is_nothrow_move_assignable_v<Ts> && ...))
    requires can_assign1<Ts...> { values = _::move(t).values; return *this; }
  constexpr const tuple& operator=(tuple&& t) const requires can_assign2<Ts...> { values = _::move(t).values; return *this; }

  template<typename... Us> constexpr tuple& operator=(const tuple<Us...>& t) requires can_assign1<const Us&...> { values = t.values; return *this; }
  template<typename... Us> constexpr const tuple& operator=(const tuple<Us...>& t) const requires can_assign2<const Us&...> { values = t.values; return *this; }

  template<typename... Us> constexpr tuple& operator=(tuple<Us...>&& t) requires can_assign1<Us...> { values = _::move(t).values; return *this; }
  template<typename... Us> constexpr const tuple& operator=(tuple<Us...>&& t) const requires can_assign2<Us...> { values = _::move(t).values; return *this; }

  template<typename U1, typename U2> constexpr tuple& operator=(const pair<U1, U2>& p) requires can_assign1<U1, U2> { values = p; return *this; }
  template<typename U1, typename U2> constexpr const tuple& operator=(const pair<U1, U2>& p) const requires can_assign2<U1, U2> { values = p; return *this; }

  template<typename U1, typename U2> constexpr tuple& operator=(pair<U1, U2>&& p) requires can_assign1<U1, U2> { values = _::move(p); return *this; }
  template<typename U1, typename U2> constexpr const tuple& operator=(pair<U1, U2>&& p) const requires can_assign1<U1, U2> { values = _::move(p); return *this; }

  constexpr void swap(tuple& t) noexcept((_::is_nothrow_swappable_v<Ts> && ...)) requires (_::is_swappable_v<Ts> && ...) { values.swap(t.values); }
  constexpr void swap(const tuple& t) const noexcept((_::is_nothrow_swappable_v<const Ts> && ...)) requires (_::is_swappable_v<const Ts> && ...) { values.swap(t.values); }
};

template<typename... Us> tuple(Us...) -> tuple<Us...>;
template<typename T1, typename T2> tuple(pair<T1, T2>) -> tuple<T1, T2>;
template<typename Al, typename... Us> tuple(allocator_arg_t, Al, Us...) -> tuple<Us...>;
template<typename Al, typename T1, typename T2> tuple(allocator_arg_t, Al, pair<T1, T2>) -> tuple<T1, T2>;
template<typename Al, typename... Us> tuple(allocator_arg_t, Al, tuple<Us...>) -> tuple<Us...>;

template<size_t Ix, typename... Ts> struct tuple_element<Ix, tuple<Ts...>> : type_identity<_::type_switch_t<Ix, Ts...>> {};
template<typename... Ts> struct tuple_size<tuple<Ts...>> : integral_constant<size_t, sizeof...(Ts)> {};

template<typename... Ts, typename Al> struct uses_allocator<tuple<Ts...>, Al> : integral_constant<bool, true> {};

template<typename... Ts, typename... Us, template<typename> typename TQ, template<typename> typename UQ>
requires requires { typename tuple<common_reference_t<TQ<Ts>, UQ<Us>>...>; }
struct basic_common_reference<tuple<Ts...>, tuple<Us...>, TQ, UQ>
  : type_identity<tuple<common_reference_t<TQ<Ts>, UQ<Us>>...>> {};

template<typename... Ts, typename... Us>
requires requires { typename tuple<typename common_type<Ts, Us>::type...>; }
struct common_type<tuple<Ts...>, tuple<Us...>>
  : type_identity<tuple<typename common_type<Ts, Us>::type...>> {};

template<typename... Ts, typename... Us> constexpr bool operator==(const tuple<Ts...>& x, const tuple<Us...>& y);

template<typename... Ts, typename... Us> constexpr common_comparison_category<_::synth_three_way_result_t<Ts, Us>...>
operator<=>(const tuple<Ts...>& x, const tuple<Us...>& y);

template<typename... Ts> constexpr void swap(tuple<Ts...>& x, tuple<Ts...>& y) noexcept(x.swap(y));

}

namespace std::_ {

struct tuple_get {
  template<size_t Ix, typename Tp> constexpr decltype(auto) operator()(constant<Ix>, Tp&& t) noexcept {
    if constexpr (specialized_of<remove_cvref_t<Tp>, tuple>) return (*this)(constant<Ix>{}, _::forward<Tp>(t).values);
    else if constexpr (Ix == 0) return _::forward<Tp>(t).value;
    else return (*this)(constant<Ix - 1>{}, _::forward<Tp>(t).values.get_base());
  }
};

template<size_t Ix, typename... Ts> typename tuple_element<Ix, tuple<Ts...>>::type& get(tuple<Ts...>& t) noexcept { return tuple_get{}(constant<Ix>{}, t); }
template<size_t Ix, typename... Ts> const typename tuple_element<Ix, tuple<Ts...>>::type& get(const tuple<Ts...>& t) noexcept { return tuple_get{}(constant<Ix>{}, t); }
template<size_t Ix, typename... Ts> typename tuple_element<Ix, tuple<Ts...>>::type&& get(tuple<Ts...>&& t) noexcept { return tuple_get{}(constant<Ix>{}, _::move(t)); }
template<size_t Ix, typename... Ts> const typename tuple_element<Ix, tuple<Ts...>>::type&& get(const tuple<Ts...>&& t) noexcept { return tuple_get{}(constant<Ix>{}, _::move(t)); }

template<typename... Ts> tuple<unwrap_ref_decay_t<Ts>...> make_tuple(Ts&&... Args) { return tuple<unwrap_ref_decay_t<Ts>...>(_::forward<Ts>(Args)...); }

template<typename... Ts> tuple<Ts&...> tie(Ts&... Args) noexcept { return {Args...}; }

template<typename... Ts> tuple<Ts&&...> forward_as_tuple(Ts&&... Args) noexcept { return {_::forward<Ts>(Args)...}; }

template<size_t Ix, size_t... Is, typename Tp, typename... Ts>
constexpr auto _tuple_cat(constant<Ix>, sequence<size_t, Is...>, Tp&& Tuple, Ts&&... Args) {
  if constexpr (Ix == 0) return tuple<>{};
  if constexpr (Ix == 1) return _::make_tuple(_::forward<Ts>(Args)..., _::get<Is>(_::forward<Tp>(Tuple))...);
  else return _::_tuple_cat(constant<Ix - 1>{}, make_sequence<tuple_size<type_switch_t<0, Ts...>>::value>{},
                            _::forward<Ts>(Args)..., _::get<Is>(_::forward<Tp>(Tuple))...);
}

constexpr auto tuple_cat() { return tuple<>{}; }
template<typename Tp1, typename... Tps> constexpr auto tuple_cat(Tp1 Tuple1, Tps&&... Tuples)
  requires (specialized_of<remove_cvref_t<Tps>, tuple> && ...) {
  return _::_tuple_cat(constant<1 + sizeof...(Tps)>{}, make_sequence<tuple_size<Tp1>::value>{}, _::forward<Tp1>(Tuple1), _::forward<Tps>(Tuples)...);
}

template<typename Fn, typename Tp, size_t... Is> constexpr decltype(auto) _apply(Fn& f, Tp&& t, sequence<size_t, Is...>) {
  return std::invoke(_::forward<Fn>(f), _::get<Is>(_::forward<Tp>(t))...);
}

template<typename Fn, typename Tp>
constexpr decltype(auto) apply(Fn&& f, Tp&& t) {
  return _::_apply(_::forward<Fn>(f), _::forward<Tp>(t), make_sequence<tuple_size<remove_cvref_t<Tp>>::value>{});
}

template<typename Ty, typename Tp, size_t... Is> constexpr Ty _make_from_tuple(Tp&& t, sequence<size_t, Is...>) {
  return Ty{_::get<Is>(_::forward<Tp>(t))...};
}

template<typename Ty, typename Tp> constexpr Ty make_from_tuple(Tp&& t) {
  return _::_make_from_tuple<Ty>(_::forward<Tp>(t), make_sequence<tuple_size<remove_cv_t<Tp>>::value>{});
}

}


namespace std {

namespace _ {
  struct ignore_t {
    template<typename Ty> constexpr void operator=(Ty&&) const noexcept {}
  };
}
inline constexpr _::ignore_t ignore;

template<typename... Ts> constexpr tuple<unwrap_ref_decay_t<Ts>...> make_tuple(Ts&&... Args) { return _::make_tuple(_::forward<Ts>(Args)...); }
template<typename... Ts> constexpr tuple<Ts&&...> forward_as_tuple(Ts&&... Args) noexcept { return _::forward_as_tuple(_::forward<Ts>(Args)...); }
template<typename... Ts> constexpr tuple<Ts&...> tie(Ts&... Args) noexcept { return _::tie(_::forward<Ts>(Args)...); }
template<typename... Tps> constexpr auto tuple_cat(Tps&&... Tuples) { return _::tuple_cat(_::forward<Tps>(Tuples)...); }
template<typename Fn, typename Tp> constexpr decltype(auto) apply(Fn&& f, Tp&& t) { return _::apply(_::forward<Fn>(f), _::forward<Tp>(t)); }
template<typename Ty, typename Tp> constexpr Ty make_from_tuple(Tp&& t) { return _::make_from_tuple<Ty>(_::forward<Tp>(t)); }

template<size_t Ix, typename... Ts> constexpr tuple_element_t<Ix, tuple<Ts...>>& get(tuple<Ts...>& t) noexcept { return _::get<Ix>(t); }
template<size_t Ix, typename... Ts> constexpr tuple_element_t<Ix, tuple<Ts...>>&& get(tuple<Ts...>&& t) noexcept { return _::get<Ix>(_::move(t)); }
template<size_t Ix, typename... Ts> constexpr const tuple_element_t<Ix, tuple<Ts...>>& get(const tuple<Ts...>& t) noexcept { return _::get<Ix>(t); }
template<size_t Ix, typename... Ts> constexpr const tuple_element_t<Ix, tuple<Ts...>>&& get(const tuple<Ts...>&& t) noexcept { return _::get<Ix>(_::move(t)); }

template<typename Ty, typename... Ts> requires (_::counts<_::is_same_v<Ty, Ts>...> == 1)
constexpr Ty& get(tuple<Ts...>& t) noexcept { return _::get<_::inspects<_::is_same_v<Ty, Ts>...>>(t); }
template<typename Ty, typename... Ts> requires (_::counts<_::is_same_v<Ty, Ts>...> == 1)
constexpr Ty&& get(tuple<Ts...>&& t) noexcept { return _::get<_::inspects<_::is_same_v<Ty, Ts>...>>(_::move(t)); }
template<typename Ty, typename... Ts> requires (_::counts<_::is_same_v<Ty, Ts>...> == 1)
constexpr const Ty& get(const tuple<Ts...>& t) noexcept { return _::get<_::inspects<_::is_same_v<Ty, Ts>...>>(t); }
template<typename Ty, typename... Ts> requires (_::counts<_::is_same_v<Ty, Ts>...> == 1)
constexpr const Ty&& get(const tuple<Ts...>&& t) noexcept { return _::get<_::inspects<_::is_same_v<Ty, Ts>...>>(_::move(t)); }

}

#endif
