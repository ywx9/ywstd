// ywstd/typeindex.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <typeinfo>
#else

#include "@/../compare.hh"

namespace std {

using size_t = decltype(sizeof(int));

class type_index {
public:
  type_index(const type_info& rhs) noexcept;
  bool operator==(const type_index& rhs) const noexcept;
  bool operator<(const type_index& rhs) const noexcept;
  bool operator>(const type_index& rhs) const noexcept;
  bool operator<=(const type_index& rhs) const noexcept;
  bool operator>=(const type_index& rhs) const noexcept;
  strong_ordering operator<=>(const type_index& rhs) const noexcept;
  size_t hash_code() const noexcept;
  const char* name() const noexcept;
};

template<class T> struct hash;
template<> struct hash<type_index> { size_t operator()(const type_index&); };

}

#endif
