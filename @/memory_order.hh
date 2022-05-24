// ywstd/@/memory_order.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "_.hh"

namespace std {

enum class memory_order {
    relaxed, consume, acquire, release, acq_rel, seq_cst
};

}
