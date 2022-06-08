// ywstd/filesystem.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef _ywstd_
#include <filesystem>
#else

#include "@/../compare.hh"
#include "@/../system_error.hh"
#include "@/basic_string.hh"
#include "@/chrono-file_clock.hh"
#include "@/filesystem-path.hh"

namespace std::filesystem {

using uintmax_t = unsigned long long;

using std::filesystem::path;
void swap(path& lhs, path& rhs) noexcept;
size_t hash_value(const path& p) noexcept;

using file_time_type = chrono::time_point<chrono::file_clock>;

enum class file_type {
  none,
  not_found,
  directory,
  symlink,
  block,
  character,
  fifo,
  socket,
  unknown
};

enum class perms {
  none = 0,
  owner_read = 0400,
  owner_write = 0200,
  owner_exec = 0100,
  owner_all = owner_read | owner_write | owner_exec,
  group_read = 040,
  group_write = 020,
  group_exec = 010,
  group_all = group_read | group_write | group_exec,
  others_read = 04,
  others_write = 02,
  others_exec = 01,
  others_all = others_read | others_write | others_exec,
  get_uid = 04000,
  get_gid = 02000,
  sticky_bit = 01000,
  mask = 07777,
  unknown = 0xFFFF
};

enum class perm_options {
  replace,
  add,
  remove,
  nofollow
};

enum class copy_options {
  skip_existing,
  overwrite_existing,
  update_existing,
  recursive,
  copy_symlinks,
  skip_symlinks,
  directories_only,
  create_symlinks,
  create_hard_links
};

enum class directory_options {
  none,
  follow_directory_symlink,
  skip_permission_denied
};

class file_status {
public:
  ~file_status();
  file_status() noexcept : file_status(file_type::none) {}
  explicit file_status(file_type ft, perms prms = perms::unknown) noexcept;
  file_status(const file_status&) noexcept = default;
  file_status(file_status&&) noexcept = default;
  file_status& operator=(const file_status&) noexcept = default;
  file_status& operator=(file_status&&) noexcept = default;
  void type(file_type ft) noexcept;
  void permissions(perms prms) noexcept;
  file_type type() const noexcept;
  perms permissions() const noexcept;
  friend bool operator==(const file_status& lhs, const file_status& rhs) noexcept;
};

struct space_info {
  uintmax_t capacity;
  uintmax_t free;
  uintmax_t available;
  friend bool operator==(const space_info&, const space_info&) = default;
};

class filesystem_error : public system_error {
public:
  filesystem_error(const string& what_arg, error_code ec);
  filesystem_error(const string& what_arg, const path& p1, error_code ec);
  filesystem_error(const string& what_arg, const path& p1, const path& p2, error_code ec);
  const path& path1() const noexcept;
  const path& path2() const noexcept;
  const char* what() const noexcept override;
};

class directory_entry {
public:
  ~directory_entry();
  directory_entry() noexcept = default;
  directory_entry(const directory_entry&) = default;
  directory_entry(directory_entry&&) noexcept = default;
  explicit directory_entry(const filesystem::path& p);
  directory_entry(const filesystem::path& p, error_code& ec);
  directory_entry& operator=(const directory_entry&) = default;
  directory_entry& operator=(directory_entry&&) noexcept = default;
  void assign(const filesystem::path& p);
  void assign(const filesystem::path& p, error_code& ec);
  void replace_filename(const filesystem::path& p);
  void replace_filename(const filesystem::path& p, error_code& ec);
  void refresh();
  void refresh(error_code& ec) noexcept;
  const filesystem::path& path() const noexcept;
  operator const filesystem::path&() const noexcept;
  bool exists() const;
  bool exists(error_code& ec) const noexcept;
  bool is_block_file() const;
  bool is_block_file(error_code& ec) const noexcept;
  bool is_character_file() const;
  bool is_character_file(error_code& ec) const noexcept;
  bool is_directory() const;
  bool is_directory(error_code& ec) const noexcept;
  bool is_fifo() const;
  bool is_fifo(error_code& ec) const noexcept;
  bool is_other() const;
  bool is_other(error_code& ec) const noexcept;
  bool is_regular_file() const;
  bool is_regular_file(error_code& ec) const noexcept;
  bool is_socket() const;
  bool is_socket(error_code& ec) const noexcept;
  bool is_symlink() const;
  bool is_symlink(error_code& ec) const noexcept;
  uintmax_t file_size() const;
  uintmax_t file_size(error_code& ec) const noexcept;
  uintmax_t hard_link_count() const;
  uintmax_t hard_link_count(error_code& ec) const noexcept;
  file_time_type last_write_time() const;
  file_time_type last_write_time(error_code& ec) const noexcept;
  file_status status() const;
  file_status status(error_code& ec) const noexcept;
  file_status symlink_status() const;
  file_status symlink_status(error_code& ec) const noexcept;
  bool operator==(const directory_entry& rhs) const noexcept;
  strong_ordering operator<=>(const directory_entry& rhs) const noexcept;
  template<typename charT, typename traits> friend basic_ostream<charT, traits>&
  operator<<(basic_ostream<charT, traits>& os, const directory_entry& d);
};

class directory_iterator {
public:
  using iterator_category = input_iterator_tag;
  using value_type = directory_entry;
  using difference_type = ptrdiff_t;
  using pointer = const directory_entry*;
  using reference = const directory_entry&;

  ~directory_iterator();
  directory_iterator() noexcept;
  explicit directory_iterator(const path& p);
  directory_iterator(const path& p, directory_options options);
  directory_iterator(const path& p, error_code& ec);
  directory_iterator(const path& p, directory_options options, error_code& ec);
  directory_iterator(const directory_iterator& rhs);
  directory_iterator(directory_iterator&& rhs) noexcept;
  directory_iterator& operator=(const directory_iterator& rhs);
  directory_iterator& operator=(directory_iterator&& rhs) noexcept;
  const directory_entry& operator*() const;
  const directory_entry* operator->() const;
  directory_iterator& operator++();
  directory_iterator& increment(error_code& ec);
  friend bool operator==(const directory_iterator&, const directory_iterator&);
};

directory_iterator begin(directory_iterator iter) noexcept;
directory_iterator end(directory_iterator) noexcept;

class recursive_directory_iterator {
public:
  using iterator_category = input_iterator_tag;
  using value_type = directory_entry;
  using difference_type = ptrdiff_t;
  using pointer = const directory_entry*;
  using reference = const directory_entry&;
  ~recursive_directory_iterator();
  recursive_directory_iterator() noexcept;
  explicit recursive_directory_iterator(const path& p);
  recursive_directory_iterator(const path& p, directory_options options);
  recursive_directory_iterator(const path& p, directory_options options, error_code& ec);
  recursive_directory_iterator(const path& p, error_code& ec);
  recursive_directory_iterator(const recursive_directory_iterator& rhs);
  recursive_directory_iterator(recursive_directory_iterator&& rhs) noexcept;
  directory_options options() const;
  int depth() const;
  bool recursion_pending() const;
  const directory_entry& operator*() const;
  const directory_entry* operator->() const;
  recursive_directory_iterator& operator=(const recursive_directory_iterator& rhs);
  recursive_directory_iterator& operator=(recursive_directory_iterator&& rhs) noexcept;
  recursive_directory_iterator& operator++();
  recursive_directory_iterator& increment(error_code& ec);
  void pop();
  void pop(error_code& ec);
  void disable_recursion_pending();
  friend bool operator==(const recursive_directory_iterator&, const recursive_directory_iterator&);
};

recursive_directory_iterator begin(recursive_directory_iterator iter) noexcept;
recursive_directory_iterator end(recursive_directory_iterator) noexcept;

path absolute(const path& p);
path absolute(const path& p, error_code& ec);
path canonical(const path& p);
path canonical(const path& p, error_code& ec);

void copy(const path& from, const path& to);
void copy(const path& from, const path& to, error_code& ec);
void copy(const path& from, const path& to, copy_options options);
void copy(const path& from, const path& to, copy_options options, error_code& ec);
bool copy_file(const path& from, const path& to);
bool copy_file(const path& from, const path& to, error_code& ec);
bool copy_file(const path& from, const path& to, copy_options option);
bool copy_file(const path& from, const path& to, copy_options option, error_code& ec);
void copy_symlink(const path& existing_symlink, const path& new_symlink);
void copy_symlink(const path& existing_symlink, const path& new_symlink, error_code& ec) noexcept;
bool create_directories(const path& p);
bool create_directories(const path& p, error_code& ec);
bool create_directory(const path& p);
bool create_directory(const path& p, error_code& ec) noexcept;
bool create_directory(const path& p, const path& attributes);
bool create_directory(const path& p, const path& attributes, error_code& ec) noexcept;
void create_directory_symlink(const path& to, const path& new_symlink);
void create_directory_symlink(const path& to, const path& new_symlink, error_code& ec) noexcept;
void create_hard_link(const path& to, const path& new_hard_link);
void create_hard_link(const path& to, const path& new_hard_link, error_code& ec) noexcept;
void create_symlink(const path& to, const path& new_symlink);
void create_symlink(const path& to, const path& new_symlink, error_code& ec) noexcept;

path current_path();
path current_path(error_code& ec);
void current_path(const path& p);
void current_path(const path& p, error_code& ec) noexcept;

bool equivalent(const path& p1, const path& p2);
bool equivalent(const path& p1, const path& p2, error_code& ec) noexcept;
bool exists(file_status s) noexcept;
bool exists(const path& p);
bool exists(const path& p, error_code& ec) noexcept;

uintmax_t file_size(const path& p);
uintmax_t file_size(const path& p, error_code& ec) noexcept;
uintmax_t hard_link_count(const path& p);
uintmax_t hard_link_count(const path& p, error_code& ec) noexcept;

bool is_block_file(file_status s) noexcept;
bool is_block_file(const path& p);
bool is_block_file(const path& p, error_code& ec) noexcept;
bool is_character_file(file_status s) noexcept;
bool is_character_file(const path& p);
bool is_character_file(const path& p, error_code& ec) noexcept;
bool is_directory(file_status s) noexcept;
bool is_directory(const path& p);
bool is_directory(const path& p, error_code& ec) noexcept;
bool is_empty(const path& p);
bool is_empty(const path& p, error_code& ec);
bool is_fifo(file_status s) noexcept;
bool is_fifo(const path& p);
bool is_fifo(const path& p, error_code& ec) noexcept;
bool is_other(file_status s) noexcept;
bool is_other(const path& p);
bool is_other(const path& p, error_code& ec) noexcept;
bool is_regular_file(const path& p);
bool is_regular_file(const path& p, error_code& ec) noexcept;
bool is_socket(file_status s) noexcept;
bool is_socket(const path& p);
bool is_socket(const path& p, error_code& ec) noexcept;
bool is_symlink(file_status s) noexcept;
bool is_symlink(const path& p);
bool is_symlink(const path& p, error_code& ec) noexcept;

file_time_type last_write_time(const path& p);
file_time_type last_write_time(const path& p, error_code& ec) noexcept;
void last_write_time(const path& p, file_time_type new_time);
void last_write_time(const path& p, file_time_type new_time, error_code& ec) noexcept;

void permissions(const path& p, perms prms, perm_options opts = perm_options::replace);
void permissions(const path& p, perms prms, error_code& ec) noexcept;
void permissions(const path& p, perms prms, perm_options opts, error_code& ec);

path proximate(const path& p, error_code& ec);
path proximate(const path& p, const path& base = current_path());
path proximate(const path& p, const path& base, error_code& ec);

path read_symlink(const path& p);
path read_symlink(const path& p, error_code& ec);
bool is_regular_file(file_status s) noexcept;

path relative(const path& p, error_code& ec);
path relative(const path& p, const path& base = current_path());
path relative(const path& p, const path& base, error_code& ec);

bool remove(const path& p);
bool remove(const path& p, error_code& ec) noexcept;

uintmax_t remove_all(const path& p);
uintmax_t remove_all(const path& p, error_code& ec);

void rename(const path& from, const path& to);
void rename(const path& from, const path& to, error_code& ec) noexcept;

void resize_file(const path& p, uintmax_t size);
void resize_file(const path& p, uintmax_t size, error_code& ec) noexcept;

space_info space(const path& p);
space_info space(const path& p, error_code& ec) noexcept;

file_status status(const path& p);
file_status status(const path& p, error_code& ec) noexcept;

bool status_known(file_status s) noexcept;

file_status symlink_status(const path& p);
file_status symlink_status(const path& p, error_code& ec) noexcept;

path temp_directory_path();
path temp_directory_path(error_code& ec);

path weakly_canonical(const path& p);
path weakly_canonical(const path& p, error_code& ec);

}

namespace std {

template<typename Ty> struct hash;
template<> struct hash<filesystem::path> { size_t operator()(const filesystem::path&); };

namespace ranges {
  template<> inline constexpr bool enable_borrowed_range<filesystem::directory_iterator> = true;
  template<> inline constexpr bool enable_borrowed_range<filesystem::recursive_directory_iterator> = true;
  template<> inline constexpr bool enable_view<filesystem::directory_iterator> = true;
  template<> inline constexpr bool enable_view<filesystem::recursive_directory_iterator> = true;
}

}

#endif
