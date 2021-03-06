// ywstd/cstdint.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <cstdint>
#else

#include "@/_.hh"

namespace std {

using int8_t         = signed char;
using int16_t        = short;
using int32_t        = int;
using int64_t        = long long;

using int_fast8_t    = signed char;
using int_fast16_t   = short;
using int_fast32_t   = int;
using int_fast64_t   = long long;

using int_least8_t   = signed char;
using int_least16_t  = short;
using int_least32_t  = int;
using int_least64_t  = long long;

using intmax_t       = long long;
using intptr_t       = decltype((int*)9 - (int*)0);

using uint8_t        = unsigned char;
using uint16_t       = unsigned short;
using uint32_t       = unsigned int;
using uint64_t       = unsigned long long;

using uint_fast8_t   = unsigned char;
using uint_fast16_t  = unsigned short;
using uint_fast32_t  = unsigned int;
using uint_fast64_t  = unsigned long long;

using uint_least8_t  = unsigned char;
using uint_least16_t = unsigned short;
using uint_least32_t = unsigned int;
using uint_least64_t = unsigned long long;

using uintmax_t      = unsigned long long;
using uintptr_t      = decltype(sizeof(int));

}

#endif
