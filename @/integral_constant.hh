// ywstd/@/integral_constant.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

namespace std {

template<typename Ty, Ty Vx> struct integral_constant {
  using type = integral_constant;
  using value_type = Ty;
  static constexpr value_type value = Vx;
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};

template<bool Bx> using bool_constant = integral_constant<bool, Bx>;
using false_type = bool_constant<false>;
using true_type = bool_constant<true>;

}
