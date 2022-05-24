// ywstd/@/back_insert_iterator.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/_.hh"
#include "../@/iterator-concepts.hh"

namespace std {

using ptrdiff_t = decltype((int*)0 - (int*)0);

template<typename Rg> class back_insert_iterator {
  static_assert(requires { declval<Rg*&>()->push_back(declval<const typename Rg::value_type&>()); });
protected:
  Rg* container = nullptr;
public:
  using container_type = Rg;
  using iterator_category = output_iterator_tag;
  using difference_type = ptrdiff_t;
  using value_type = void;
  using pointer = void;
  using reference = void;
  constexpr back_insert_iterator() noexcept = default;
  constexpr explicit back_insert_iterator(Rg& r) : container(_::addressof(r)) {}
  constexpr back_insert_iterator& operator=(const typename Rg::value_type& v) { return container->push_back(v), *this; }
  constexpr back_insert_iterator& operator=(typename Rg::value_type&& v) { return container->push_back(_::move(v)), *this; }
  [[nodiscard]] constexpr back_insert_iterator& operator*() { return *this; }
  constexpr back_insert_iterator& operator++() { return *this; }
  constexpr back_insert_iterator operator++(int) { return *this; }
};

template<typename Rg> constexpr back_insert_iterator<Rg> back_inserter(Rg& c) { return back_insert_iterator<Rg>{c}; }

}
