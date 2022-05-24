// ywstd/@/ranges-less.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../concepts.hh"

namespace std::ranges {

struct less {
  using is_transparent = int;
  template<typename T1, totally_ordered_with<T1> T2> constexpr bool operator()(T1&& x, T2&& y) { return static_cast<T1&&>(x) < static_cast<T2&&>(y); }
};

}
