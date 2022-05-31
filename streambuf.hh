// ywstd/streambuf.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef _ywstd_
#include <streambuf>
#else

#include "@/basic_ios.hh"

namespace std {

using std::basic_streambuf;
using streambuf = basic_streambuf<char>;
using wstreambuf = basic_streambuf<wchar_t>;

}

#endif
