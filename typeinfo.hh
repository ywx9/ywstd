// ywstd/typeinfo.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <typeinfo>
#else

#include "@/../exception.hh"

namespace std {

using size_t = decltype(sizeof(int));

class type_info {
public:
  virtual ~type_info();
  type_info(const type_info&) = delete;
  type_info& operator=(const type_info&) = delete;
  constexpr bool operator==(const type_info& y) const noexcept;
  bool before(const type_info& rhs) const noexcept;
  size_t hash_code() const noexcept;
  const char* name() const noexcept;
};

class bad_cast : public exception {
public:
  const char* what() const noexcept override;
};

class bad_typeid : public exception {
public:
  const char* what() const noexcept override;
};

}

#endif
