// ywstd/@/pointer_traits.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "_.hh"

namespace std {

using ptrdiff_t = decltype((int*)0 - (int*)0);

namespace _::_pointer_traits {
  template<typename Ty> struct element_type {};
  template<has_element_type Ty> struct element_type<Ty> { using type = typename Ty::element_type; };
  template<template<typename, typename...> typename Tm, typename T1, typename... Ts> requires (!has_element_type<Tm<T1, Ts...>>)
  struct element_type<Tm<T1, Ts...>> { using type = T1; };
  template<typename Ty> struct difference_type { using type = ptrdiff_t; };
  template<has_difference_type Ty> struct difference_type<Ty> { using type = typename Ty::difference_type; };
  template<typename Ty, typename Uy> struct rebind {};
  template<typename Uy, has_rebind<Uy> Ty> struct rebind<Ty, Uy> { using type = typename Ty::template rebind<Uy>; };
  template<template<typename, typename...> typename Tm, typename T1, typename... Ts, typename Uy> requires (!has_rebind<Tm<T1, Ts...>, Uy>)
  struct rebind<Tm<T1, Ts...>, Uy> { using type = Tm<Uy, Ts...>; };
}

template<typename Ty> struct pointer_traits {
  using pointer = Ty;
  using element_type = typename _::_pointer_traits::element_type<Ty>::type;
  using difference_type = typename _::_pointer_traits::difference_type<Ty>::type;
  template<typename Uy> using rebind = typename _::_pointer_traits::rebind<Ty, Uy>::type;
  static pointer pointer_to(element_type& x) noexcept(noexcept(Ty::pointer_to(x)))
    requires requires { Ty::pointer_to(x); } { return Ty::pointer_to(x); }
};

template<typename Ty> struct pointer_traits<Ty*> {
  using pointer = Ty*;
  using element_type = Ty;
  using difference_type = ptrdiff_t;
  template<typename Uy> using rebind = Uy*;
  static constexpr pointer pointer_to(element_type& x) noexcept { return _::addressof(x); }
};

namespace _ {
  template<typename Ty> constexpr Ty* to_address(Ty* x) noexcept { return x; }
  template<typename Ty> constexpr auto to_address(const Ty& x) noexcept {
    if constexpr (requires { typename pointer_traits<Ty>::element_type; pointer_traits<Ty>::to_address(x); }) return pointer_traits<Ty>::to_address(x);
    else return _::to_address(x.operator->());
  }
}

}
