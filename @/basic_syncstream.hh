// ywstd/@/basic_syncstream.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "allocator.hh"
#include "basic_ios.hh"
#include "char_traits.hh"

namespace std {

template<typename Ct, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>>
class basic_syncbuf : public basic_streambuf<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;
  using allocator_type = Al;
  using streambuf_type = basic_streambuf<Ct, Tr>;

  ~basic_syncbuf();
  basic_syncbuf() : basic_syncbuf(nullptr) {}
  explicit basic_syncbuf(streambuf_type* obuf) : basic_syncbuf(obuf, Al()) {}
  basic_syncbuf(streambuf_type*, const Al&);
  basic_syncbuf(basic_syncbuf&&);

  basic_syncbuf& operator=(basic_syncbuf&&);
  void swap(basic_syncbuf&);

  bool emit();
  streambuf_type* get_wrapped() const noexcept;
  allocator_type get_allocator() const noexcept;
  void set_emit_on_sync(bool) noexcept;

protected:
  int sync() override;
};

using syncbuf = basic_syncbuf<char>;
using wsyncbuf = basic_syncbuf<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>, typename Al = allocator<Ct>>
class basic_osyncstream : public basic_ostream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;
  using allocator_type = Al;
  using streambuf_type = basic_streambuf<Ct, Tr>;
  using syncbuf_type = basic_syncbuf<Ct, Tr, Al>;

  ~basic_osyncstream();
  basic_osyncstream(streambuf_type*, const Al&);
  explicit basic_osyncstream(streambuf_type* obuf) : basic_osyncstream(obuf, Al()) {}
  basic_osyncstream(basic_ostream<Ct, Tr>& os, const Al& allocator) : basic_osyncstream(os.rdbuf(), allocator) {}
  explicit basic_osyncstream(basic_ostream<Ct, Tr>& os) : basic_osyncstream(os, Al()) {}
  basic_osyncstream(basic_osyncstream&&) noexcept;

  basic_osyncstream& operator=(basic_osyncstream&&) noexcept;

  void emit();
  streambuf_type* get_wrapped() const noexcept;
  syncbuf_type* rdbuf() const noexcept { return const_cast<syncbuf_type*>(addressof(sb)); }
};

using osyncstream = basic_osyncstream<char>;
using wosyncstream = basic_osyncstream<wchar_t>;

}
