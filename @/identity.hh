// ywstd/@/identity.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

namespace std {

struct identity {
  using is_transparent = int;
  template<typename Ty> constexpr Ty&& operator()(Ty&& x) const noexcept { return static_cast<Ty&&>(x); }
};

}
