// ywstd/bitset.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <bitset>
#else

// #include "@/../iosfwd.hh"
#include "@/../string.hh"

namespace std {

template<typename Ct, typename Tr> class basic_istream;
template<typename Ct, typename Tr> class basic_ostream;

template<size_t N> class bitset {
public:
  class reference {
    friend class bitset;
    reference() noexcept;
  public:
    ~reference();
    reference(const reference&) = default;
    reference& operator=(bool x) noexcept;
    reference& operator=(const reference&) noexcept;
    bool operator~() const noexcept;
    operator bool() const noexcept;
    reference& flip() noexcept;
  };

  constexpr bitset() noexcept;
  constexpr bitset(unsigned long long val) noexcept;

  template<typename Ct, typename Tr, typename Al> explicit
  bitset(const basic_string<Ct, Tr, Al>& str, typename basic_string<Ct, Tr, Al>::size_type pos = 0,
    typename basic_string<Ct, Tr, Al>::size_type n = basic_string<Ct, Tr, Al>::npos, Ct zero = Ct('0'), Ct one = Ct('1'));

  template<typename Ct> explicit bitset(
    const Ct* str, typename basic_string<Ct>::size_type n = basic_string<Ct>::npos, Ct zero = Ct('0'), Ct one = Ct('1'));

  bitset& operator&=(const bitset& rhs) noexcept;
  bitset& operator|=(const bitset& rhs) noexcept;
  bitset& operator^=(const bitset& rhs) noexcept;
  bitset& operator<<=(size_t pos) noexcept;
  bitset& operator>>=(size_t pos) noexcept;
  bitset& set() noexcept;
  bitset& set(size_t pos, bool val = true);
  bitset& reset() noexcept;
  bitset& reset(size_t pos);
  bitset  operator~() const noexcept;
  bitset& flip() noexcept;
  bitset& flip(size_t pos);
  constexpr bool operator[](size_t pos) const;
  reference operator[](size_t pos);
  unsigned long to_ulong() const;
  unsigned long long to_ullong() const;

  template<typename Ct = char, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>>
  basic_string<Ct, Tr, Al> to_string(Ct zero = Ct('0'), Ct one = Ct('1')) const;

  size_t count() const noexcept;
  constexpr size_t size() const noexcept;
  bool operator==(const bitset& rhs) const noexcept;
  bool test(size_t pos) const;
  bool all() const noexcept;
  bool any() const noexcept;
  bool none() const noexcept;
  bitset operator<<(size_t pos) const noexcept;
  bitset operator>>(size_t pos) const noexcept;
};

template<typename Ty> struct hash;
template<size_t Nx> struct hash<bitset<Nx>> { size_t operator()(const bitset<Nx>&); };

template<size_t N> bitset<N> operator&(const bitset<N>&, const bitset<N>&) noexcept;
template<size_t N> bitset<N> operator|(const bitset<N>&, const bitset<N>&) noexcept;
template<size_t N> bitset<N> operator^(const bitset<N>&, const bitset<N>&) noexcept;
template<typename Ct, typename Tr, size_t N> basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& is, bitset<N>& x);
template<typename Ct, typename Tr, size_t N> basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& os, const bitset<N>& x);

}

#endif
