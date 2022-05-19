// ywstd/cinttypes.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <cinttypes>
#else

#include "@/../cstdint.hh"

namespace std {

struct imaxdiv_t { intmax_t quot, rem; };

intmax_t imaxabs(intmax_t);
imaxdiv_t imaxdiv(intmax_t, intmax_t);
intmax_t strtoimax(const char*, char**, int);
uintmax_t strtoumax(const char*, char**, int);
intmax_t wcstoimax(const wchar_t*, wchar_t**, int);
uintmax_t wcstoumax(const wchar_t*, wchar_t**, int);

}


#endif
