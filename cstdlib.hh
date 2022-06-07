// ywstd/cstdlib.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <cstdlib>
#else

#include "@/abs.hh"

namespace std {

using size_t = decltype(sizeof(int));
struct div_t { int rem, quot; };
struct ldiv_t { long rem, quot; };
struct lldiv_t { long long rem, quot; };

namespace _ {
  extern "C" using c_atexit_handler = void();
  extern "C" using c_compare_pred = int(const void*, const void*);
  extern "C++" using atexit_handler = void();
  extern "C++" using compare_pred = int(const void*, const void*);
}

[[noreturn]] void abort() noexcept;
[[noreturn]] void exit(int);
[[noreturn]] void quick_exit(int) noexcept;
[[noreturn]] void _Exit(int) noexcept;
int atexit(_::c_atexit_handler*) noexcept;
int atexit(_::atexit_handler*) noexcept;
int at_quick_exit(_::c_atexit_handler*) noexcept;
int at_quick_exit(_::atexit_handler*) noexcept;
int system(const char*);
char* getenv(const char*);
void* malloc(size_t);
void* aligned_alloc(size_t, size_t);
void* calloc(size_t, size_t);
void* realloc(void*, size_t);
void free(void*);
int atoi(const char*);
long atol(const char*);
long long atoll(const char*);
double atof(const char*);
long strtol(const char*, char**, int);
long long strtoll(const char*, char**, int);
unsigned long strtoul(const char*, char**, int);
unsigned long long strtoull(const char*, char**, int);
float strtof(const char*, char**);
double strtod(const char*, char**);
long double strtold(const char*, char**);
int mblen(const char*, size_t);
int mbtowc(wchar_t*, const char*, size_t);
int wctomb(char*, wchar_t);
size_t mbstowcs(wchar_t*, const char*, size_t);
size_t wcstombs(char*, const wchar_t*, size_t);
int rand();
void srand(unsigned int);
void qsort(void*, size_t, size_t, _::c_compare_pred*);
void qsort(void*, size_t, size_t, _::compare_pred*);
void* bsearch(const void*, const void*, size_t, size_t, _::c_compare_pred*);
void* bsearch(const void*, const void*, size_t, size_t, _::compare_pred*);
long labs(long);
long long llabs(long long);
div_t div(int, int);
ldiv_t div(long, long);
lldiv_t div(long long, long long);
ldiv_t ldiv(long, long);
lldiv_t lldiv(long long, long long);

}

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MB_CUR_MAX   5
#define RAND_MAX 32767

#ifndef NULL
#define NULL nullptr
#endif

#endif
