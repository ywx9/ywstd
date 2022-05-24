// ywstd/@/basic_fstream.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "basic_ios.hh"
#include "char_traits.hh"
#include "filesystem-path.hh"

namespace std {

template<typename Ct, typename Tr = char_traits<Ct>>
class basic_filebuf : public basic_streambuf<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  virtual ~basic_filebuf();
  basic_filebuf();
  basic_filebuf(const basic_filebuf&) = delete;
  basic_filebuf(basic_filebuf&& rhs);

  basic_filebuf& operator=(const basic_filebuf&) = delete;
  basic_filebuf& operator=(basic_filebuf&& rhs);
  void swap(basic_filebuf& rhs);

  bool is_open() const;
  basic_filebuf* open(const char* s, ios_base::openmode mode);
  basic_filebuf* open(const filesystem::path::value_type* s, ios_base::openmode mode);
  basic_filebuf* open(const string& s, ios_base::openmode mode);
  basic_filebuf* open(const filesystem::path& s, ios_base::openmode mode);
  basic_filebuf* close();

protected:
  streamsize showmanyc() override;
  int_type underflow() override;
  int_type uflow() override;
  int_type pbackfail(int_type c = Tr::eof()) override;
  int_type overflow(int_type c = Tr::eof()) override;

  basic_streambuf<Ct, Tr>* setbuf(char_type* s, streamsize n) override;
  pos_type seekoff(off_type off, ios_base::seekdir way, ios_base::openmode which = ios_base::in | ios_base::out) override;
  pos_type seekpos(pos_type sp, ios_base::openmode which = ios_base::in | ios_base::out) override;
  int sync() override;
  void imbue(const locale& loc) override;
};

using filebuf = basic_filebuf<char>;
using wfilebuf = basic_filebuf<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>>
class basic_ifstream : public basic_istream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  basic_ifstream();
  explicit basic_ifstream(const char* s, ios_base::openmode mode = ios_base::in);
  explicit basic_ifstream(const filesystem::path::value_type* s, ios_base::openmode mode = ios_base::in);
  explicit basic_ifstream(const string& s, ios_base::openmode mode = ios_base::in);
  explicit basic_ifstream(const filesystem::path& s, ios_base::openmode mode = ios_base::in);
  basic_ifstream(const basic_ifstream&) = delete;
  basic_ifstream(basic_ifstream&& rhs);

  basic_ifstream& operator=(const basic_ifstream&) = delete;
  basic_ifstream& operator=(basic_ifstream&& rhs);
  void swap(basic_ifstream& rhs);

  basic_filebuf<Ct, Tr>* rdbuf() const;

  bool is_open() const;
  void open(const char* s, ios_base::openmode mode = ios_base::in);
  void open(const filesystem::path::value_type* s, ios_base::openmode mode = ios_base::in);
  void open(const string& s, ios_base::openmode mode = ios_base::in);
  void open(const filesystem::path& s, ios_base::openmode mode = ios_base::in);
  void close();
};

using ifstream = basic_ifstream<char>;
using wifstream = basic_ifstream<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>>
class basic_ofstream : public basic_ostream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  basic_ofstream();
  explicit basic_ofstream(const char* s, ios_base::openmode mode = ios_base::out);
  explicit basic_ofstream(const filesystem::path::value_type* s, ios_base::openmode mode = ios_base::out);
  explicit basic_ofstream(const string& s, ios_base::openmode mode = ios_base::out);
  explicit basic_ofstream(const filesystem::path& s, ios_base::openmode mode = ios_base::out);
  basic_ofstream(const basic_ofstream&) = delete;
  basic_ofstream(basic_ofstream&& rhs);

  basic_ofstream& operator=(const basic_ofstream&) = delete;
  basic_ofstream& operator=(basic_ofstream&& rhs);
  void swap(basic_ofstream& rhs);

  basic_filebuf<Ct, Tr>* rdbuf() const;

  bool is_open() const;
  void open(const char* s, ios_base::openmode mode = ios_base::out);
  void open(const filesystem::path::value_type* s, ios_base::openmode mode = ios_base::out);
  void open(const string& s, ios_base::openmode mode = ios_base::out);
  void open(const filesystem::path& s, ios_base::openmode mode = ios_base::out);
  void close();
};

using ofstream = basic_ofstream<char>;
using wofstream = basic_ofstream<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>>
class basic_fstream : public basic_iostream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  basic_fstream();
  explicit basic_fstream(const char* s, ios_base::openmode mode = ios_base::in | ios_base::out);
  explicit basic_fstream(const filesystem::path::value_type* s, ios_base::openmode mode = ios_base::in | ios_base::out);
  explicit basic_fstream(const string& s, ios_base::openmode mode = ios_base::in | ios_base::out);
  explicit basic_fstream(const filesystem::path& s, ios_base::openmode mode = ios_base::in | ios_base::out);
  basic_fstream(const basic_fstream&) = delete;
  basic_fstream(basic_fstream&& rhs);

  basic_fstream& operator=(const basic_fstream&) = delete;
  basic_fstream& operator=(basic_fstream&& rhs);
  void swap(basic_fstream& rhs);

  basic_filebuf<Ct, Tr>* rdbuf() const;
  bool is_open() const;
  void open(const char* s, ios_base::openmode mode = ios_base::in | ios_base::out);
  void open(const filesystem::path::value_type* s, ios_base::openmode mode = ios_base::in | ios_base::out);
  void open(const string& s, ios_base::openmode mode = ios_base::in | ios_base::out);
  void open(const filesystem::path& s, ios_base::openmode mode = ios_base::in | ios_base::out);
  void close();
};

using fstream = basic_fstream<char>;
using wfstream = basic_fstream<wchar_t>;

}
