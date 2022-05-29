// ywstd/@/swap.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "_.hh"

namespace std {

template<typename Ty> constexpr void swap(Ty& x, Ty& y)
  noexcept(_::is_nothrow_move_constructible_v<Ty> && _::is_nothrow_move_assignable_v<Ty>)
  requires _::is_move_constructible_v<Ty> && _::is_move_assignable_v<Ty> {
  Ty t = static_cast<Ty&&>(x); x = static_cast<Ty&&>(y); y = static_cast<Ty&&>(t);
}

template<typename Ty, size_t Nx> constexpr void swap(Ty (&x)[Nx], Ty (&y)[Nx])
  noexcept(_::is_nothrow_swappable_v<Ty>) requires _::is_swappable_v<Ty> {
  for (size_t i = 0; i < Nx; ++i) swap(x[i], y[i]);
}

}
