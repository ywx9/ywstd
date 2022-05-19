// ywstd/@/less.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "_.hh"

namespace std {

template<typename Ty = void> struct less {
  constexpr bool operator()(const Ty& x, const Ty& y) const { return x < y; }
};

template<> struct less<void> {
  template<typename Ty, typename Uy> constexpr auto operator()(Ty&& x, Uy&& y) const
    -> decltype(static_cast<Ty&&>(x), static_cast<Uy&&>(y)) {
    return x < y;
  }
};

}
