// ywstd/@/ranges-in_out_result.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../concepts.hh"

namespace std::ranges {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-attributes"

template<typename In, typename Ot> struct in_out_result {
  [[no_unique_address]] In in;
  [[no_unique_address]] Ot out;
  template<_::convertible_from<const In&> I2, _::convertible_from<const Ot&> O2>
  constexpr operator in_out_result<I2, O2>() const& { return {in, out}; }

template<_::convertible_from<In> I2, _::convertible_from<Ot> O2>
constexpr operator in_out_result<I2, O2>() && { return {_::move(in), _::move(out)}; }
};

#pragma clang diagnostic pop

}
