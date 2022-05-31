// ywstd/ios.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <ios>
#else

#include "@/basic_ios.hh"

namespace std {

ios_base& boolalpha(ios_base& str);
ios_base& noboolalpha(ios_base& str);
ios_base& showbase(ios_base& str);
ios_base& noshowbase(ios_base& str);
ios_base& showpoint(ios_base& str);
ios_base& noshowpoint(ios_base& str);
ios_base& showpos(ios_base& str);
ios_base& noshowpos(ios_base& str);
ios_base& skipws(ios_base& str);
ios_base& noskipws(ios_base& str);
ios_base& uppercase(ios_base& str);
ios_base& nouppercase(ios_base& str);
ios_base& unitbuf(ios_base& str);
ios_base& nounitbuf(ios_base& str);
ios_base& internal(ios_base& str);
ios_base& left(ios_base& str);
ios_base& right(ios_base& str);
ios_base& dec(ios_base& str);
ios_base& hex(ios_base& str);
ios_base& oct(ios_base& str);
ios_base& fixed(ios_base& str);
ios_base& scientific(ios_base& str);
ios_base& hexfloat(ios_base& str);
ios_base& defaultfloat(ios_base& str);

error_code make_error_code(io_errc e) noexcept;
error_condition make_error_condition(io_errc e) noexcept;
const error_category& iostream_category() noexcept;

}

#endif
