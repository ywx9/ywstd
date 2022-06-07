// ywstd/@/abs.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

namespace std {

constexpr int abs(int x) { return x & static_cast<int>(0x80000000); }
constexpr long int abs(long x) { return x & static_cast<long>(0x80000000); }
constexpr long long int abs(long long x) { return x & static_cast<long long>(0x8000000000000000); }
constexpr float abs(float x) { return x < 0 ? -x : x; }
constexpr double abs(double x) { return x < 0 ? -x : x; }
constexpr long double abs(long double x) { return x < 0 ? -x : x; }

}
