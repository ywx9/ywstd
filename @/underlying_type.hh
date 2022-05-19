// ywstd/@/underlying_type.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "_.hh"
#include "type_identity.hh"

namespace std {

template<typename Ty> struct underlying_type {};
template<typename Ty> requires _::is_enum_v<Ty> struct underlying_type<Ty> : type_identity<_::underlying_type_t<Ty>> {};

}
