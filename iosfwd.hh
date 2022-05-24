// ywstd/iosfwd.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <iosfwd>
#else

#include "@/basic_ios.hh"
#include "@/basic_fstream.hh"
#include "@/basic_stringstream.hh"
#include "@/basic_syncstream.hh"
#include "@/char_traits.hh"
#include "@/fpos.hh"
#include "@/streambuf_iterator.hh"

namespace std {

using size_t = decltype(sizeof(int));
using streamoff = long long;
using uint_least16_t = unsigned short;
using uint_least32_t = unsigned int;
using wint_t = unsigned short;

template<typename Ty> class allocator;

template<typename Ct, typename Tr = char_traits<Ct>> class basic_spanbuf;
using spanbuf = basic_spanbuf<char>;
using wspanbuf = basic_spanbuf<wchar_t>;

template<typename Ct, typename Tr = char_traits<Ct>> class basic_ispanstream;
using ispanstream = basic_ispanstream<char>;
using wispanstream = basic_ispanstream<wchar_t>;

template<typename Ct, typename Tr = char_traits<Ct>> class basic_ospanstream;
using ospanstream = basic_ospanstream<char>;
using wospanstream = basic_ospanstream<wchar_t>;

template<typename Ct, typename Tr = char_traits<Ct>> class basic_spanstream;
using spanstream = basic_spanstream<char>;
using wspanstream = basic_spanstream<wchar_t>;

}

#endif
