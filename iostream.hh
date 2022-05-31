// ywstd/iostream.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef _ywstd_
#include <iostream>
#else

#include "@/../ios.hh"
#include "@/../istream.hh"
#include "@/../ostream.hh"
#include "@/../streambuf.hh"

namespace std {

extern istream cin;
extern ostream cout;
extern ostream cerr;
extern ostream clog;

extern wistream wcin;
extern wostream wcout;
extern wostream wcerr;
extern wostream wclog;

}

#endif
