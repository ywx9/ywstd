// ywstd/cfenv.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <cfenv>
#else

namespace std {

struct fenv_t {
  unsigned long _1, _2;
};

using fexcept_t = unsigned long;

int fegetround(void);
int fesetround(int);

int fegetenv(fenv_t*);
int fesetenv(const fenv_t*);

int fegetexceptflag(fexcept_t*, int);
int fesetexceptflag(const fexcept_t*, int);

int fetestexcept(int);
int feclearexcept(int);
int feraiseexcept(int);
int feholdexcept(fenv_t*);
int feupdateenv(const fenv_t*);

}

#endif
