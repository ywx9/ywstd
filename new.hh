// ywstd/new.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <cstdarg>
#else

#include "@/../exception.hh"
#include "@/operator-new.hh"

namespace std {

class bad_alloc : public exception {
  bad_alloc() noexcept;
  bad_alloc(const bad_alloc&) noexcept;
  bad_alloc& operator=(const bad_alloc&) noexcept;
  virtual const char* what() const noexcept;
};

class bad_array_new_length : public bad_alloc {
  bad_array_new_length() noexcept;
  bad_array_new_length(const bad_array_new_length&) noexcept;
  bad_array_new_length& operator=(const bad_array_new_length&) noexcept;
  virtual const char* what() const noexcept;
};

struct destroying_delete_t { explicit destroying_delete_t() = default; };
inline constexpr destroying_delete_t destroying_delete{};

using new_handler = void (*)();
new_handler get_new_handler() noexcept;
new_handler set_new_handler(new_handler) noexcept;

template<typename Ty> [[nodiscard]] constexpr Ty* launder(Ty* p) noexcept { return p; }

inline constexpr size_t hardware_destructive_interference_size = 64;
inline constexpr size_t hardware_constructive_interference_size = 64;

}

#endif
