// ywstd/cstdarg.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <cstdarg>
#else

namespace std {

using va_list = char*;

}

#define va_arg(ap, t) (*(t*)0)
#define va_copy(dst, src) ((void)0)
#define va_start(ap, param) ((void)0)
#define va_end(ap) ((void)0)

#endif
