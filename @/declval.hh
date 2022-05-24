// ywstd/@/declval.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "add-remove.hh"

namespace std {

template<typename Ty> [[noreturn]] add_rvalue_reference_t<Ty> declval() noexcept;

}
