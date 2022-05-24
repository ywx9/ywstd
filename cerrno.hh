// ywstd/cerrno.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <cerrno>
#else

#define errno (*(int*)nullptr)

#endif
