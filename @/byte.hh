// ywstd/@/byte.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/_.hh"

namespace std {

enum class byte : unsigned char {};

constexpr byte operator~(byte b) noexcept { return static_cast<byte>(static_cast<unsigned char>(~static_cast<unsigned char>(b))); }

constexpr byte operator&(byte x, byte y) noexcept
{ return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned char>(x) & static_cast<unsigned char>(y))); }

constexpr byte operator|(byte x, byte y) noexcept
{ return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned char>(x) | static_cast<unsigned char>(y))); }

constexpr byte operator^(byte x, byte y) noexcept
{ return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned char>(x) ^ static_cast<unsigned char>(y))); }

constexpr byte& operator&=(byte& x, byte y) noexcept { return x = x & y; }
constexpr byte& operator|=(byte& x, byte y) noexcept { return x = x | y; }
constexpr byte& operator^=(byte& x, byte y) noexcept { return x = x ^ y; }

template<_::integral Int> constexpr byte operator<<(byte b, Int i) noexcept
{ return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned char>(b) << i)); }

template<_::integral Int> constexpr byte operator>>(byte b, Int i) noexcept
{ return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned char>(b) >> i)); }

template<_::integral Int> constexpr byte& operator<<=(byte& b, Int i) noexcept { return b = b << i; }
template<_::integral Int> constexpr byte& operator>>=(byte& b, Int i) noexcept { return b = b >> i; }

template<_::integral Int> constexpr Int to_integer(byte b) noexcept { return static_cast<Int>(static_cast<unsigned char>(b)); }

}
