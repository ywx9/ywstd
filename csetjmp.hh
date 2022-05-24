// ywstd/csetjmp.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <csetjmp>
#else

namespace std {

struct jmp_buf {};
[[noreturn]] void longfmp(jmp_buf Env, int Val);

}

#define setjmp(Env) 0

#endif
