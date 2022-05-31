// ywstd/istream.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <istream>
#else

#include "@/basic_ios.hh"

namespace std {

using std::basic_istream;
using istream = basic_istream<char>;
using wistream = basic_istream<wchar_t>;

using std::basic_iostream;
using iostream = basic_iostream<char>;
using wiostream = basic_iostream<wchar_t>;

template<typename Ct, typename Tr> basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>&, Ct&);
template<typename Tr> basic_istream<char, Tr>& operator>>(basic_istream<char, Tr>&, unsigned char&);
template<typename Tr> basic_istream<char, Tr>& operator>>(basic_istream<char, Tr>&, signed char&);

template<typename Ct, typename Tr, size_t N> basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>&, Ct (&)[N]);
template<typename Tr, size_t N> basic_istream<char, Tr>& operator>>(basic_istream<char, Tr>&, unsigned char (&)[N]);
template<typename Tr, size_t N> basic_istream<char, Tr>& operator>>(basic_istream<char, Tr>&, signed char (&)[N]);

template<typename Ct, typename Tr> basic_istream<Ct, Tr>& ws(basic_istream<Ct, Tr>& is);
template<typename Stream, typename Ty> Stream&& operator>>(Stream&& s, Ty&& x) requires requires { s >> declval<Ty>(x); };

}

#endif
