// ywstd/@/uses_allocator.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "_.hh"
#include "integral_constant.hh"

namespace std {

template<typename Ty, typename Al> struct uses_allocator : integral_constant<bool, false> {};
template<typename Ty, typename Al> requires _::is_convertible_v<typename Ty::allocator_type, Al>
struct uses_allocator<Ty, Al> : integral_constant<bool, true> {};

}
