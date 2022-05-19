// ywstd/system_error.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "compare.hh"
#include "stdexcept.hh"

namespace std {

template<typename Ty> struct is_error_code_enum : integral_constant<bool, false> {};
template<typename Ty> inline constexpr bool is_error_code_enum_v = is_error_code_enum<Ty>::value;

template<typename Ty> struct is_error_condition_enum : integral_constant<bool, false> {};
template<typename Ty> inline constexpr bool is_error_condition_enum_v = is_error_condition_enum<Ty>::value;

class error_category;

class error_condition {
public:
  error_condition() noexcept;
  error_condition(int, const error_category&) noexcept;
  template<typename ErrCond> requires is_error_condition_enum_v<ErrCond> error_condition(ErrCond) noexcept;
  template<typename ErrCond> requires is_error_condition_enum_v<ErrCond> error_condition& operator=(ErrCond) noexcept;
  void assign(int, const error_category&) noexcept;
  void clear() noexcept;
  int value() const noexcept;
  const error_category& category() const noexcept;
  string message() const;
  explicit operator bool() const noexcept;
};

class error_code {
public:
  error_code() noexcept;
  error_code(int, const error_category&) noexcept;
  template<typename ErrCode> requires is_error_code_enum_v<ErrCode> error_code(ErrCode) noexcept;
  template<typename ErrCode> requires is_error_code_enum_v<ErrCode> error_code& operator=(ErrCode) noexcept;
  void assign(int, const error_category&) noexcept;
  void clear() noexcept;
  int value() const noexcept;
  const error_category& category() const noexcept;
  error_condition default_error_condition() const noexcept;
  string message() const;
  explicit operator bool() const noexcept;
};

class error_category {
public:
  virtual ~error_category();
  constexpr error_category() noexcept;
  error_category(const error_category&) = delete;
  error_category& operator=(const error_category&) = delete;
  virtual const char* name() const noexcept = 0;
  virtual error_condition default_error_condition(int) const noexcept;
  virtual bool equivalent(int, const error_condition&) const noexcept;
  virtual bool equivalent(const error_code&, int) const noexcept;
  virtual string message(int) const = 0;
  bool operator==(const error_category&) const noexcept;
  strong_ordering operator<=>(const error_category&) const noexcept;
};

class system_error : public runtime_error {
public:
  system_error(error_code, const string&);
  system_error(error_code, const char*);
  system_error(error_code);
  system_error(int, const error_category&, const string&);
  system_error(int, const error_category&, const char*);
  system_error(int, const error_category&);
  const error_code& code() const noexcept;
  const char* what() const noexcept override;
};

enum class errc {
  address_family_not_supported,
  address_in_use,
  address_not_available,
  already_connected,
  argument_list_too_long,
  argument_out_of_domain,
  bad_address,
  bad_file_descriptor,
  bad_message,
  broken_pipe,
  connection_aborted,
  connection_already_in_progress,
  connection_refused,
  connection_reset,
  cross_device_link,
  destination_address_required,
  device_or_resource_busy,
  directory_not_empty,
  executable_format_error,
  file_exists,
  file_too_large,
  filename_too_long,
  function_not_supported,
  host_unreachable,
  identifier_removed,
  illegal_byte_sequence,
  inappropriate_io_control_operation,
  interrupted,
  invalid_argument,
  invalid_seek,
  io_error,
  is_a_directory,
  message_size,
  network_down,
  network_reset,
  network_unreachable,
  no_buffer_space,
  no_child_process,
  no_link,
  no_lock_available,
  no_message_available,
  no_message,
  no_protocol_option,
  no_space_on_device,
  no_stream_resources,
  no_such_device_or_address,
  no_such_device,
  no_such_file_or_directory,
  no_such_process,
  not_a_directory,
  not_a_socket,
  not_a_stream,
  not_connected,
  not_enough_memory,
  not_supported,
  operation_canceled,
  operation_in_progress,
  operation_not_permitted,
  operation_not_supported,
  operation_would_block,
  owner_dead,
  permission_denied,
  protocol_error,
  protocol_not_supported,
  read_only_file_system,
  resource_deadlock_would_occur,
  resource_unavailable_try_again,
  result_out_of_range,
  state_not_recoverable,
  stream_timeout,
  text_file_busy,
  timed_out,
  too_many_files_open_in_system,
  too_many_files_open,
  too_many_links,
  too_many_symbolic_link_levels,
  value_too_large,
  wrong_protocol_type,
};

template<> struct is_error_condition_enum<errc> : integral_constant<bool, true> {};

error_code make_error_code(errc) noexcept;
error_condition make_error_condition(errc) noexcept;
template<typename CT, typename Tr> basic_ostream<CT, Tr>& operator<<(basic_ostream<CT, Tr>& os, const error_code& ec);
bool operator==(const error_code&, const error_code&) noexcept;
bool operator==(const error_code&, const error_condition&) noexcept;
bool operator==(const error_condition&, const error_condition&) noexcept;
strong_ordering operator<=>(const error_code&, const error_code&) noexcept;
strong_ordering operator<=>(const error_condition&, const error_condition&) noexcept;

template<typename Ty> struct hash;
template<> struct hash<error_code> { size_t operator()(error_code) const; };
template<> struct hash<error_condition> { size_t operator()(error_condition) const; };

}
