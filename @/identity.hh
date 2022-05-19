// ywstd/@/identity.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

namespace std {

struct identity {
  using is_transparent = int;
  template<typename Ty> constexpr Ty&& operator()(Ty&& x) const noexcept { return static_cast<Ty&&>(x); }
};

}
