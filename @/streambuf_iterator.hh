// ywstd/@/byte.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/basic_ios.hh"
#include "../@/char_traits.hh"
#include "../@/iterator-concepts.hh"

namespace std {

template<typename Ct, typename Tr = char_traits<Ct>> class istreambuf_iterator {
public:
  using iterator_category = input_iterator_tag;
  using value_type = Ct;
  using difference_type = typename Tr::off_type;
  using pointer = Ct*;
  using reference = Ct;
  using char_type = Ct;
  using traits_type = Tr;
  using int_type = typename Tr::int_type;
  using streambuf_type = basic_streambuf<Ct, Tr>;
  using istream_type = basic_istream<Ct, Tr>;

  class proxy { Ct operator*(); };

  ~istreambuf_iterator() = default;
  constexpr istreambuf_iterator() noexcept {}
  constexpr istreambuf_iterator(default_sentinel_t) noexcept {}
  istreambuf_iterator(const istreambuf_iterator&) noexcept = default;
  istreambuf_iterator(istream_type & s) noexcept;
  istreambuf_iterator(streambuf_type * s) noexcept;
  istreambuf_iterator(const proxy& p) noexcept;
  istreambuf_iterator& operator=(const istreambuf_iterator&) noexcept = default;
  Ct operator*() const;
  istreambuf_iterator& operator++();
  proxy operator++(int);
  bool equal(const istreambuf_iterator& b) const;
  friend bool operator==(const istreambuf_iterator& i, default_sentinel_t s);
};

template<typename Ct, typename Tr = char_traits<Ct>> class ostreambuf_iterator {
public:
  using iterator_category = output_iterator_tag;
  using value_type = void;
  using difference_type = ptrdiff_t;
  using pointer = void;
  using reference = void;
  using char_type = Ct;
  using traits_type = Tr;
  using streambuf_type = basic_streambuf<Ct, Tr>;
  using ostream_type = basic_ostream<Ct, Tr>;

  constexpr ostreambuf_iterator() noexcept = default;
  ostreambuf_iterator(ostream_type & s) noexcept;
  ostreambuf_iterator(streambuf_type * s) noexcept;
  ostreambuf_iterator& operator=(Ct c);

  ostreambuf_iterator& operator*();
  ostreambuf_iterator& operator++();
  ostreambuf_iterator& operator++(int);
  bool failed() const noexcept;
};

}
