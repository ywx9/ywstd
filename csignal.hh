// ywstd/csignal.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <csignal>
#else

namespace std {

namespace _ {
  extern "C" using signal_handler = void(int);
}

using sig_atomic_t = int;

_::signal_handler* signal(int Sig, _::signal_handler* Func);
int raise(int Sig);

}

#define SIGTERM 0
#define SIGSEGV 1
#define SIGINT  2
#define SIGILL  3
#define SIGABRT 4
#define SIGFPE  5

#define SIG_DFL ((std::_::signal_handler*)0)
#define SIG_IGN ((std::_::signal_handler*)1)
#define SIG_ERR ((std::_::signal_handler*)2)

#endif
