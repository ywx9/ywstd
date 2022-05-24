// ywstd/initializer_list.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <initializer_list>
#else

namespace std {

using size_t = decltype(sizeof(int));

template<typename Ty> class initializer_list {
  const Ty *_first, *_last;
public:
  using value_type = Ty;
  using reference = const Ty&;
  using const_reference = const Ty&;
  using size_type = size_t;
  using iterator = const Ty*;
  using const_iterator = const Ty*;
  constexpr initializer_list() noexcept : _first{}, _last{} {}
  constexpr const Ty* begin() const noexcept { return _first; }
  constexpr const Ty* end() const noexcept { return _last; }
  constexpr size_t size() const noexcept { return end() - begin(); }
};

template<typename Ty> constexpr const Ty* begin(initializer_list<Ty> il) noexcept { return il.begin(); }
template<typename Ty> constexpr const Ty* end(initializer_list<Ty> il) noexcept { return il.end(); }

}

#endif
