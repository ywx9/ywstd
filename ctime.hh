// ywstd/ctime.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <ctime>
#else

#include "@/tm.hh"

namespace std {

using clock_t = long;
using size_t = decltype(sizeof(int));
using std::tm;
using time_t = decltype((int*)0 - (int*)0);

struct timespec { time_t tv_sec; long tv_nsec; };

clock_t clock();
time_t time(time_t*);
double difftime(time_t, time_t);
int timespec_get(timespec*, int);
char* ctime(const time_t*);
char* asctime(const tm*);
size_t strftime(char*, size_t, const char*, const tm*);
size_t wcstime(wchar_t*, size_t, wchar_t*, const tm*);
tm* gmtime(const time_t*);
tm* localtime(const time_t*);
time_t mktime(tm*);

}

#ifndef NULL
#define NULL nullptr
#endif

#define CLOCKS_PER_SEC ((clock_t)1000)

#endif
