// ywstd/@/allocator.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/../limits.hh"
#include "../@/_.hh"
#include "../@/integral_constant.hh"
#include "../@/operator-new.hh"
#include "../@/pointer_traits.hh"

namespace std {

using size_t = decltype(sizeof(int));
struct allocator_arg_t { explicit allocator_arg_t() = default; };
inline constexpr allocator_arg_t allocator_arg{};
template<typename Pointer> struct allocation_result { Pointer ptr; size_t count; };

template<typename Ty> class allocator {
public:
  using value_type = Ty;
  using size_type = size_t;
  using difference_type = size_t;
  using propagate_on_container_move_assignment = true_type;
  constexpr ~allocator(){};
  constexpr allocator() noexcept {};
  constexpr allocator(const allocator&) noexcept {};
  template<typename Uy> constexpr allocator(const allocator<Uy>&) noexcept {};
  [[nodiscard]] constexpr Ty* allocate(size_t n) { return ::operator new (n, align_val_t{}); }
  [[nodiscard]] constexpr allocation_result<Ty*> allocate_at_least(size_t n) { return {allocate(n), n}; }
  constexpr void deallocate(Ty* p, size_t n) { ::operator delete (p, align_val_t{}); }
};

template<typename T1, typename T2> constexpr bool operator==(const allocator<T1>&, const allocator<T2>&) noexcept { return true; }

namespace _::_allocator_traits {
  template<typename Ty> concept has_pcca = requires { typename Ty::propagate_on_container_copy_assignment; };
  template<typename Ty> concept has_pcma = requires { typename Ty::propagate_on_container_move_assignment; };
  template<typename Ty> concept has_propagate_on_container_swap = requires { typename Ty::propagate_on_container_swap; };
  template<typename Al> struct pointer { using type = typename Al::value_type*; };
  template<has_pointer Al> struct pointer<Al> { using type = typename Al::pointer; };
  template<typename Al> using pointer_t = typename pointer<Al>::type;
  template<typename Al> struct const_pointer { using type = typename pointer_traits<pointer_t<Al>>::template rebind<const typename Al::value_type>; };
  template<has_const_pointer Al> struct const_pointer<Al> { using type = typename Al::const_pointer; };
  template<typename Al> struct void_pointer { using type = typename pointer_traits<pointer_t<Al>>::template rebind<void>; };
  template<has_void_pointer Al> struct const_pointer<Al> { using type = typename Al::void_pointer; };
  template<typename Al> struct const_void_pointer { using type = typename pointer_traits<pointer_t<Al>>::template rebind<const void>; };
  template<has_const_void_pointer Al> struct const_pointer<Al> { using type = typename Al::const_void_pointer; };
  template<typename Al> struct difference_type { using type = typename pointer_traits<pointer_t<Al>>::difference_type; };
  template<has_difference_type Al> struct difference_type<Al> { using type = typename Al::difference_type; };
  template<typename Al> struct size_type { using type = typename pointer_traits<pointer_t<Al>>::size_type; };
  template<has_size_type Al> struct size_type<Al> { using type = typename Al::size_type; };
  template<typename Al> struct propagate_on_container_copy_assignment : integral_constant<bool, false> {};
  template<has_pcca Al> struct propagate_on_container_copy_assignment<Al> { using type = typename Al::propagate_on_container_copy_assignment; };
  template<typename Al> struct propagate_on_container_move_assignment : integral_constant<bool, false> {};
  template<has_pcma Al> struct propagate_on_container_move_assignment<Al> { using type = typename Al::propagate_on_container_move_assignment; };
  template<typename Al> struct propagate_on_container_swap : integral_constant<bool, false> {};
  template<has_propagate_on_container_swap Al> struct propagate_on_container_swap<Al> { using type = typename Al::propagate_on_container_swap; };
  template<typename Al> struct is_always_equal : integral_constant<bool, _::is_empty_v<Al>> {};
  template<has_is_always_equal Al> struct is_always_equal<Al> { using type = typename Al::is_always_equal; };
  template<typename Al, typename Ty> struct rebind_alloc {};
  template<typename Ty, has_rebind_other<Ty> Al> struct rebind_alloc<Al, Ty> { using type = typename Al::template rebind<Ty>::other; };
  template<template<typename, typename...> typename Tm, typename Uy, typename... Ts, typename Ty> requires(!has_rebind_other<Tm<Uy, Ts...>, Ty>)
  struct rebind_alloc<Tm<Uy, Ts...>, Ty> { using type = Tm<Uy, Ts...>; };
  template<typename Ty, typename... As> constexpr Ty* construct_at(Ty* p, As&&... as) {
    return ::new (const_cast<void*>(static_cast<const volatile void*>(p))) Ty{static_cast<As&&>(as)...}; }
  template<typename Ty> constexpr void destroy_at(Ty* p) {
    if constexpr (is_array_v<Ty>) for (auto &e : *p) _allocator_traits::destroy_at(_::addressof(e));
    else p->~Ty(); }
}

template<typename Al> struct allocator_traits {
  using allocator_type = Al;
  using value_type = typename Al::value_type;
  using pointer = typename _::_allocator_traits::pointer<Al>::type;
  using const_pointer = typename _::_allocator_traits::const_pointer<Al>::type;
  using void_pointer = typename _::_allocator_traits::void_pointer<Al>::type;
  using const_void_pointer = typename _::_allocator_traits::const_void_pointer<Al>::type;
  using difference_type = typename _::_allocator_traits::difference_type<Al>::type;
  using size_type = typename _::_allocator_traits::size_type<Al>::type;
  using propagate_on_container_copy_assignment = typename _::_allocator_traits::propagate_on_container_copy_assignment<Al>::type;
  using propagate_on_container_move_assignment = typename _::_allocator_traits::propagate_on_container_move_assignment<Al>::type;
  using is_always_equal = typename _::_allocator_traits::is_always_equal<Al>::type;
  template<typename Ty> using rebind_alloc = typename _::_allocator_traits::rebind_alloc<Al, Ty>::type;
  template<typename Ty> using rebind_traits = allocator_traits<rebind_alloc<Ty>>;
  [[nodiscard]] static constexpr pointer allocate(Al& a, size_type n) { return a.allocate(n); }
  [[nodiscard]] static constexpr pointer allocate(Al& a, size_type n, const_void_pointer hint) {
    if constexpr (requires { a.allocate(n, hint); }) return a.allocate(n, hint);
    else return a.allocate(n);
  }
  static constexpr void deallocate(Al& a, pointer p, size_type n) { return a.deallocate(p, n); }
  template<typename Ty, typename... As> static constexpr void construct(Al& a, Ty* p, As&&... as) {
    if constexpr (requires {a.construct(p, static_cast<As&&>(as)...); }) a.construct(p, static_cast<As&&>(as)...);
    else _::_allocator_traits::construct_at(p, static_cast<As&&>(as)...);
  }
  template<typename Ty> static constexpr void destroy(Al& a, Ty* p) {
    if constexpr (requires { a.destroy(p); }) a.destroy(p);
    else _::_allocator_traits::destroy_at(p);
  }
  template<typename Ty> static constexpr size_type max_size(const Al& a) noexcept {
    if constexpr (requires { a.max_size(); }) return a.max_size();
    else return numeric_limits<size_type>::max() / sizeof(value_type);
  }
  static constexpr Al select_on_container_copy_construction(const Al& a) {
    if constexpr (requires { a.select_on_container_copy_construction(); }) return a.select_on_container_copy_construction();
    else return a;
  }
};

}
