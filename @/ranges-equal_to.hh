// ywstd/@/ranges-equal_to.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../concepts.hh"

namespace std::ranges {

struct equal_to {
  using is_transparent = int;
  template<typename T1, equality_comparable_with<T1> T2> constexpr bool operator()(T1&& x, T2&& y) { return static_cast<T1&&>(x) == static_cast<T2&&>(y); }
};

}
