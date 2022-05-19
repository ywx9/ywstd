// ywstd/@/basic_stringstream.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clnag-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/allocator.hh"
#include "../@/basic_ios.hh"
#include "../@/char_traits.hh"

namespace std {

template<typename Ct, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>>
class basic_stringbuf : public basic_streambuf<Ct, Tr> {
  static constexpr bool nt_swappable = allocator_traits<Al>::propagate_on_container_swap::value || allocator_traits<Al>::is_always_equal::value;

public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using Tr_type = Tr;
  using allocator_type = Al;

  basic_stringbuf() : basic_stringbuf(ios_base::in | ios_base::out) {}
  explicit basic_stringbuf(ios_base::openmode which);
  explicit basic_stringbuf(const basic_string<Ct, Tr, Al>& s, ios_base::openmode which = ios_base::in | ios_base::out);
  explicit basic_stringbuf(const Al& a) : basic_stringbuf(ios_base::in | ios_base::out, a) {}
  basic_stringbuf(ios_base::openmode which, const Al& a);
  explicit basic_stringbuf(basic_string<Ct, Tr, Al>&& s, ios_base::openmode which = ios_base::in | ios_base::out);
  template<typename A2> basic_stringbuf(const basic_string<Ct, Tr, A2>& s, const Al& a) : basic_stringbuf(s, ios_base::in | ios_base::out, a) {}
  template<typename A2> basic_stringbuf(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which, const Al& a);
  template<typename A2> explicit basic_stringbuf(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which = ios_base::in | ios_base::out);
  basic_stringbuf(const basic_stringbuf&) = delete;
  basic_stringbuf(basic_stringbuf&& rhs);
  basic_stringbuf(basic_stringbuf&& rhs, const Al& a);

  basic_stringbuf& operator=(const basic_stringbuf&) = delete;
  basic_stringbuf& operator=(basic_stringbuf&& rhs);
  void swap(basic_stringbuf& rhs) noexcept(nt_swappable);

  allocator_type get_allocator() const noexcept;

  basic_string<Ct, Tr, Al> str() const&;
  template<typename A2> basic_string<Ct, Tr, A2> str(const A2& sa) const;
  basic_string<Ct, Tr, Al> str() &&;
  basic_string_view<Ct, Tr> view() const noexcept;

  void str(const basic_string<Ct, Tr, Al>& s);
  template<typename A2> void str(const basic_string<Ct, Tr, A2>& s);
  void str(basic_string<Ct, Tr, Al>&& s);

protected:
  int_type underflow() override;
  int_type pbackfail(int_type c = Tr::eof()) override;
  int_type overflow(int_type c = Tr::eof()) override;
  basic_streambuf<Ct, Tr>* setbuf(Ct*, streamsize) override;
  pos_type seekoff(off_type off, ios_base::seekdir way, ios_base::openmode which = ios_base::in | ios_base::out) override;
  pos_type seekpos(pos_type sp, ios_base::openmode which = ios_base::in | ios_base::out) override;
};

using stringbuf = basic_stringbuf<char>;
using wstringbuf = basic_stringbuf<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>>
class basic_istringstream : public basic_istream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using Tr_type = Tr;
  using allocator_type = Al;

  basic_istringstream() : basic_istringstream(ios_base::in) {}
  explicit basic_istringstream(ios_base::openmode which);
  explicit basic_istringstream(const basic_string<Ct, Tr, Al>& s, ios_base::openmode which = ios_base::in);
  basic_istringstream(ios_base::openmode which, const Al& a);
  explicit basic_istringstream(basic_string<Ct, Tr, Al>&& s, ios_base::openmode which = ios_base::in);
  template<typename A2> basic_istringstream(const basic_string<Ct, Tr, A2>& s, const Al& a) : basic_istringstream(s, ios_base::in, a) {}
  template<typename A2> basic_istringstream(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which, const Al& a);
  template<typename A2> explicit basic_istringstream(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which = ios_base::in);
  basic_istringstream(const basic_istringstream&) = delete;
  basic_istringstream(basic_istringstream&& rhs);

  basic_istringstream& operator=(const basic_istringstream&) = delete;
  basic_istringstream& operator=(basic_istringstream&& rhs);
  void swap(basic_istringstream& rhs);

  basic_stringbuf<Ct, Tr, Al>* rdbuf() const;
  basic_string<Ct, Tr, Al> str() const&;
  template<typename A2> basic_string<Ct, Tr, A2> str(const A2& sa) const;
  basic_string<Ct, Tr, Al> str() &&;
  basic_string_view<Ct, Tr> view() const noexcept;

  void str(const basic_string<Ct, Tr, Al>& s);
  template<typename A2> void str(const basic_string<Ct, Tr, A2>& s);
  void str(basic_string<Ct, Tr, Al>&& s);
};

using istringstream = basic_istringstream<char>;
using wistringstream = basic_istringstream<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>>
class basic_ostringstream : public basic_ostream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using Tr_type = Tr;
  using allocator_type = Al;

  basic_ostringstream() : basic_ostringstream(ios_base::out) {}
  explicit basic_ostringstream(ios_base::openmode which);
  explicit basic_ostringstream(const basic_string<Ct, Tr, Al>& s, ios_base::openmode which = ios_base::out);
  basic_ostringstream(ios_base::openmode which, const Al& a);
  explicit basic_ostringstream(basic_string<Ct, Tr, Al>&& s, ios_base::openmode which = ios_base::out);
  template<typename A2> basic_ostringstream(const basic_string<Ct, Tr, A2>& s, const Al& a) : basic_ostringstream(s, ios_base::out, a) {}
  template<typename A2> basic_ostringstream(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which, const Al& a);
  template<typename A2> explicit basic_ostringstream(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which = ios_base::out);
  basic_ostringstream(const basic_ostringstream&) = delete;
  basic_ostringstream(basic_ostringstream&& rhs);

  basic_ostringstream& operator=(const basic_ostringstream&) = delete;
  basic_ostringstream& operator=(basic_ostringstream&& rhs);
  void swap(basic_ostringstream& rhs);

  basic_stringbuf<Ct, Tr, Al>* rdbuf() const;

  basic_string<Ct, Tr, Al> str() const&;
  template<typename A2> basic_string<Ct, Tr, A2> str(const A2& sa) const;
  basic_string<Ct, Tr, Al> str() &&;
  basic_string_view<Ct, Tr> view() const noexcept;

  void str(const basic_string<Ct, Tr, Al>& s);
  template<typename A2> void str(const basic_string<Ct, Tr, A2>& s);
  void str(basic_string<Ct, Tr, Al>&& s);
};

using ostringstream = basic_ostringstream<char>;
using wostringstream = basic_ostringstream<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>>
class basic_stringstream : public basic_iostream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using Tr_type = Tr;
  using allocator_type = Al;

  basic_stringstream() : basic_stringstream(ios_base::out | ios_base::in) {}
  explicit basic_stringstream(ios_base::openmode which);
  explicit basic_stringstream(const basic_string<Ct, Tr, Al>& s, ios_base::openmode which = ios_base::out | ios_base::in);
  basic_stringstream(ios_base::openmode which, const Al& a);
  explicit basic_stringstream(basic_string<Ct, Tr, Al>&& s, ios_base::openmode which = ios_base::out | ios_base::in);
  template<typename A2> basic_stringstream(const basic_string<Ct, Tr, A2>& s, const Al& a) : basic_stringstream(s, ios_base::out | ios_base::in, a) {}
  template<typename A2> basic_stringstream(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which, const Al& a);
  template<typename A2> explicit basic_stringstream(const basic_string<Ct, Tr, A2>& s, ios_base::openmode which = ios_base::out | ios_base::in);
  basic_stringstream(const basic_stringstream&) = delete;
  basic_stringstream(basic_stringstream&& rhs);

  basic_stringstream& operator=(const basic_stringstream&) = delete;
  basic_stringstream& operator=(basic_stringstream&& rhs);
  void swap(basic_stringstream& rhs);

  basic_stringbuf<Ct, Tr, Al>* rdbuf() const;

  basic_string<Ct, Tr, Al> str() const&;
  template<typename A2> basic_string<Ct, Tr, A2> str(const A2& sa) const;
  basic_string<Ct, Tr, Al> str() &&;
  basic_string_view<Ct, Tr> view() const noexcept;

  void str(const basic_string<Ct, Tr, Al>& s);
  template<typename A2> void str(const basic_string<Ct, Tr, A2>& s);
  void str(basic_string<Ct, Tr, Al>&& s);
};

using stringstream = basic_stringstream<char>;
using wstringstream = basic_stringstream<wchar_t>;

}
