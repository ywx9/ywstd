// ywstd/stdexcept.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "@/../exception.hh"
#include "@/basic_string.hh"

namespace std {

class logic_error : public exception {
public:
  explicit logic_error(const string&);
  explicit logic_error(const char*);
};

class domain_error : public logic_error {
public:
  explicit domain_error(const string&);
  explicit domain_error(const char*);
};

class invalid_argument : public logic_error {
public:
  explicit invalid_argument(const string&);
  explicit invalid_argument(const char*);
};

class length_error : public logic_error {
public:
  explicit length_error(const string&);
  explicit length_error(const char*);
};

class out_of_range : public logic_error {
public:
  explicit out_of_range(const string&);
  explicit out_of_range(const char*);
};

class runtime_error : public exception {
public:
  explicit runtime_error(const string&);
  explicit runtime_error(const char*);
};

class range_error : public runtime_error {
public:
  explicit range_error(const string&);
  explicit range_error(const char*);
};

class overflow_error : public runtime_error {
public:
  explicit overflow_error(const string&);
  explicit overflow_error(const char*);
};

class underflow_error : public runtime_error {
public:
  explicit underflow_error(const string&);
  explicit underflow_error(const char*);
};

}
