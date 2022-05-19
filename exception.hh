// ywstd/exception.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <exception>
#else

namespace std {

using nullptr_t = decltype(nullptr);

class exception {
public:
  virtual ~exception();
  exception() noexcept;
  exception(const exception&) noexcept;
  exception& operator=(const exception&) noexcept;
  virtual const char* what() const noexcept;
};

class bad_exception : public exception {
  public: const char* what() const noexcept override;
};

class exception_ptr {
public:
  ~exception_ptr() noexcept;
  exception_ptr() noexcept;
  exception_ptr(nullptr_t) noexcept;
  exception_ptr(const exception_ptr&) noexcept;
  exception_ptr& operator=(const exception_ptr&);
  exception_ptr& operator=(nullptr_t) noexcept;
  explicit operator bool() const noexcept;
  friend void swap(exception_ptr&, exception_ptr&) noexcept;
  friend bool operator==(const exception_ptr&, const exception_ptr&) noexcept;
  friend bool operator==(nullptr_t, const exception_ptr&) noexcept;
  friend bool operator==(const exception_ptr&, nullptr_t) noexcept;
  friend bool operator!=(const exception_ptr&, const exception_ptr&) noexcept;
  friend bool operator!=(nullptr_t, const exception_ptr&) noexcept;
  friend bool operator!=(const exception_ptr&, nullptr_t) noexcept;
};

class nested_exception {
public:
  virtual ~nested_exception() = default;
  nested_exception() noexcept;
  nested_exception(const nested_exception&) noexcept = default;
  nested_exception& operator=(const nested_exception&) noexcept = default;
  [[noreturn]] void rethrow_nested() const;
  exception_ptr nested_ptr() const noexcept;
};

template<typename Ty> [[noreturn]] void throw_with_nested(Ty&& t);
template<typename Ex> void rethrow_if_nested(const Ex& e);

using terminate_handler = void (*)();
terminate_handler get_terminate() noexcept;
terminate_handler set_terminate(terminate_handler f) noexcept;
[[noreturn]] void terminate() noexcept;

int uncaught_exceptions() noexcept;

exception_ptr current_exception() noexcept;
[[noreturn]] void rethrow_exception(exception_ptr p);
template<typename Ex> exception_ptr make_exception_ptr(Ex e) noexcept;

template<typename Ty> [[noreturn]] void throw_with_nested(Ty&& t);
template<typename Ex> void rethrow_if_nested(const Ex& e);

}

#endif
