// ywstd/source_location.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <source_location>
#else

namespace std {

using uint_least32_t = unsigned int;

struct source_location {
  static consteval source_location current(
    uint_least32_t Line = __builtin_LINE(), uint_least32_t Column = __builtin_COLUMN(),
    const char* File = __builtin_FILE(), const char* Function = __builtin_FUNCTION()
  ) noexcept {
    source_location a{};
    a._line = Line, a._column = Column, a._file = File, a._function = Function;
    return a;
  }
  constexpr source_location() noexcept = default;
  constexpr uint_least32_t line() const noexcept { return _line; }
  constexpr uint_least32_t column() const noexcept { return _column; }
  constexpr const char* file_name() const noexcept { return _file; }
  constexpr const char* function_name() const noexcept { return _function; }
private:
  uint_least32_t _line, _column;
  const char *_file, *_function;
};

}

#endif
