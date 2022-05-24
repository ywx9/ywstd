// ywstd/@/to_address.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "pointer_traits.hh"

namespace std {

template<typename Ty> constexpr Ty* to_address(Ty* x) noexcept { return x; }
template<typename Ty> constexpr auto to_address(const Ty& x) noexcept {
  if constexpr (requires { pointer_traits<Ty>::to_address(x); }) return pointer_traits<Ty>::to_address(x);
  else return to_address(x.operator->());
}

}
