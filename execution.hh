// ywstd/execution.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <execution>
#else

#include "@/_.hh"
#include "@/integral_constant.hh"

namespace std {

namespace execution {
  class parallel_policy { public: explicit parallel_policy() = default; };
  inline constexpr parallel_policy par;

  class sequenced_policy { public: explicit sequenced_policy() = default; };
  inline constexpr sequenced_policy seq;

  class parallel_unsequenced_policy { public: explicit parallel_unsequenced_policy() = default; };
  inline constexpr parallel_unsequenced_policy par_unseq;

  class unsequenced_policy { public: explicit unsequenced_policy() = default; };
  inline constexpr unsequenced_policy unseq;
}

namespace _ {
  template<> inline constexpr bool _execution_policy<execution::parallel_policy> = true;
  template<> inline constexpr bool _execution_policy<execution::sequenced_policy> = true;
  template<> inline constexpr bool _execution_policy<execution::parallel_unsequenced_policy> = true;
  template<> inline constexpr bool _execution_policy<execution::unsequenced_policy> = true;
}

template<typename Ty> struct is_execution_policy : integral_constant<bool, _::execution_policy<Ty>> {};
template<typename Ty> inline constexpr bool is_execution_policy_v = is_execution_policy<Ty>::value;

}

#endif
