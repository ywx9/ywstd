// ywstd/cstddef.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <cstddef>
#else

#include "@/_.hh"
#include "@/byte.hh"

namespace std {

using max_align_t = long double;
using nullptr_t = decltype(nullptr);
using ptrdiff_t = decltype((int*)0 - (int*)0);
using size_t = decltype(sizeof(int));

}

#ifndef NULL
#define NULL nullptr
#endif

#define offsetof(type, member) ((::size_t)&reinterpret_cast<char const volatile&>((((type*)0)->member)))

#endif
