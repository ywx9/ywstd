// ywstd/@/type_identity.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

namespace std {

template<typename Ty> struct type_identity { using type = Ty; };

}
