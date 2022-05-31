// ywstd/ostream.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef _ywstd_
#include <ostream>
#else

#include "@/basic_ios.hh"

namespace std {

using std::basic_ostream;
using ostream = basic_ostream<char>;
using wostream = basic_ostream<wchar_t>;

template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& endl(basic_ostream<Ct, Tr>& os);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& ends(basic_ostream<Ct, Tr>& os);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& flush(basic_ostream<Ct, Tr>& os);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& emit_on_flush(basic_ostream<Ct, Tr>& os);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& noemit_on_flush(basic_ostream<Ct, Tr>& os);
template<typename Ct, typename Tr> basic_ostream<Ct, Tr>& flush_emit(basic_ostream<Ct, Tr>& os);
template<typename Stream, typename Ty> Stream&& operator<<(Stream&& os, const Ty& x) requires requires { os << declval<Ty>(); };

}

#endif
