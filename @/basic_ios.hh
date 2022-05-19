// ywstd/@/basic_ios.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/../system_error.hh"
#include "../@/char_traits.hh"
#include "../@/locale.hh"

namespace std {

using streamsize = decltype(sizeof(int));
template<typename Ct, typename Tr> class basic_ostream;

enum class io_errc { stream = 1 };
template<> struct is_error_code_enum<io_errc> : public integral_constant<bool, true> {};

//======================================================================================================================

class ios_base {
protected:
  ios_base();
public:
  class failure : public system_error {
  public:
    explicit failure(const string& msg, const error_code& ec = io_errc::stream);
    explicit failure(const char* msg, const error_code& ec = io_errc::stream);
  };
  class Init {
  public:
    ~Init();
    Init();
    Init(const Init&) = default;
    Init& operator=(const Init&) = default;
  };
  enum event {
    erase_event,
    imbue_event,
    copyfmt_event
  };
  using event_callback = void (*)(event, ios_base&, int);

  using openmode = int;
  static constexpr openmode app = 0x01;
  static constexpr openmode binary = 0x02;
  static constexpr openmode in = 0x04;
  static constexpr openmode out = 0x8;
  static constexpr openmode trunc = 0x10;
  static constexpr openmode ate = 0x20;

  using fmtflags = int;
  static constexpr fmtflags dec = 0x0001;
  static constexpr fmtflags oct = 0x0002;
  static constexpr fmtflags hex = 0x0004;
  static constexpr fmtflags basefield = dec | oct | hex;
  static constexpr fmtflags left = 0x0008;
  static constexpr fmtflags right = 0x0010;
  static constexpr fmtflags internal = 0x0020;
  static constexpr fmtflags adjustfield = left | right | internal;
  static constexpr fmtflags scientific = 0x0040;
  static constexpr fmtflags fixed = 0x0080;
  static constexpr fmtflags floatfield = scientific | fixed;
  static constexpr fmtflags boolalpha = 0x0100;
  static constexpr fmtflags showbase = 0x0200;
  static constexpr fmtflags showpos = 0x0400;
  static constexpr fmtflags skipws = 0x0800;
  static constexpr fmtflags unitbuf = 0x1000;
  static constexpr fmtflags uppercase = 0x2000;

  using iostate = int;
  static constexpr iostate goodbit = 0x1;
  static constexpr iostate badbit = 0x2;
  static constexpr iostate failbit = 0x4;
  static constexpr iostate eofbit = 0x8;

  using seekdir = int;
  static constexpr seekdir beg = 0x1;
  static constexpr seekdir end = 0x2;
  static constexpr seekdir cur = 0x4;

  virtual ~ios_base();
  ios_base(const ios_base&) = delete;
  ios_base& operator=(const ios_base&) = delete;

  fmtflags flags() const;
  fmtflags flags(fmtflags fmtfl);
  fmtflags setf(fmtflags fmtfl);
  fmtflags setf(fmtflags fmtfl, fmtflags mask);
  void unsetf(fmtflags mask);

  streamsize precision() const;
  streamsize precision(streamsize prec);
  streamsize width() const;
  streamsize width(streamsize wide);

  locale imbue(const locale& loc);
  locale getloc() const;

  static int xalloc();
  long& iword(int idx);
  void*& pword(int idx);

  void register_callback(event_callback fn, int idx);
  static bool sync_with_stdio(bool sync = true);
};

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>> class basic_streambuf {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  virtual ~basic_streambuf();

  locale pubimbue(const locale& loc);
  locale getloc() const;

  basic_streambuf* pubsetbuf(char_type* s, streamsize n);
  pos_type pubseekoff(off_type off, ios_base::seekdir way, ios_base::openmode which = ios_base::in | ios_base::out);
  pos_type pubseekpos(pos_type sp, ios_base::openmode which = ios_base::in | ios_base::out);
  int pubsync();

  streamsize in_avail();
  int_type snextc();
  int_type sbumpc();
  int_type sgetc();
  streamsize sgetn(char_type* s, streamsize n);

  int_type sputbackc(char_type c);
  int_type sungetc();

  int_type sputc(char_type c);
  streamsize sputn(const char_type* s, streamsize n);

protected:
  basic_streambuf();
  basic_streambuf(const basic_streambuf& rhs);
  basic_streambuf& operator=(const basic_streambuf& rhs);

  void swap(basic_streambuf& rhs);

  char_type* eback() const;
  char_type* gptr() const;
  char_type* egptr() const;
  void gbump(int n);
  void setg(char_type* gbeg, char_type* gnext, char_type* gend);

  char_type* pbase() const;
  char_type* pptr() const;
  char_type* epptr() const;
  void pbump(int n);
  void setp(char_type* pbeg, char_type* pend);

  virtual void imbue(const locale& loc);
  virtual basic_streambuf* setbuf(char_type* s, streamsize n);
  virtual pos_type seekoff(off_type off, ios_base::seekdir way, ios_base::openmode which = ios_base::in | ios_base::out);
  virtual pos_type seekpos(pos_type sp, ios_base::openmode which = ios_base::in | ios_base::out);
  virtual int sync();
  virtual streamsize showmanyc();
  virtual streamsize xsgetn(char_type* s, streamsize n);
  virtual int_type underflow();
  virtual int_type uflow();

  virtual int_type pbackfail(int_type c = Tr::eof());
  virtual streamsize xsputn(const char_type* s, streamsize n);
  virtual int_type overflow(int_type c = Tr::eof());
};

using streambuf = basic_streambuf<char>;
using wstreambuf = basic_streambuf<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>> class basic_ios : public ios_base {
protected:
  basic_ios();
  void init(basic_streambuf<Ct, Tr>*);
  void move(basic_ios&);
  void move(basic_ios&&);
  void swap(basic_ios&) noexcept;
  void set_rdbuf(basic_streambuf<Ct, Tr>*);
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;
  virtual ~basic_ios();
  explicit basic_ios(basic_streambuf<Ct, Tr>*);
  basic_ios(const basic_ios&) = delete;
  basic_ios& operator=(const basic_ios&) = delete;
  bool good() const;
  bool eof() const;
  bool fail() const;
  bool bad() const;
  bool operator!() const;
  explicit operator bool() const;
  iostate rdstate() const;
  void setstate(iostate);
  void clear(iostate = goodbit);
  basic_ios& copyfmt(const basic_ios&);
  char_type fill() const;
  char_type fill(char_type);
  iostate exceptions() const;
  void exceptions(iostate);
  locale imbue(const locale&);
  basic_streambuf<Ct, Tr>* rdbuf() const;
  basic_streambuf<Ct, Tr>* rdbuf(basic_streambuf<Ct, Tr>*);
  basic_ostream<Ct, Tr>* tie() const;
  basic_ostream<Ct, Tr>* tie(basic_ostream<Ct, Tr>*);
  char narrow(char_type, char) const;
  char_type widen(char) const;
};

using ios = basic_ios<char>;
using wios = basic_ios<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>> class basic_istream : virtual public basic_ios<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  class sentry {
  public:
    ~sentry();
    sentry(const sentry&) = delete;
    explicit sentry(basic_istream<Ct, Tr>& is, bool noskipws = false);
    sentry& operator=(const sentry&) = delete;
    explicit operator bool() const;
  };

  virtual ~basic_istream();
  explicit basic_istream(basic_streambuf<Ct, Tr>* sb);

  basic_istream<Ct, Tr>& operator>>(basic_istream<Ct, Tr>& (*pf)(basic_istream<Ct, Tr>&));
  basic_istream<Ct, Tr>& operator>>(basic_ios<Ct, Tr>& (*pf)(basic_ios<Ct, Tr>&));
  basic_istream<Ct, Tr>& operator>>(ios_base& (*pf)(ios_base&));
  basic_istream<Ct, Tr>& operator>>(bool& n);
  basic_istream<Ct, Tr>& operator>>(short& n);
  basic_istream<Ct, Tr>& operator>>(unsigned short& n);
  basic_istream<Ct, Tr>& operator>>(int& n);
  basic_istream<Ct, Tr>& operator>>(unsigned int& n);
  basic_istream<Ct, Tr>& operator>>(long& n);
  basic_istream<Ct, Tr>& operator>>(unsigned long& n);
  basic_istream<Ct, Tr>& operator>>(long long& n);
  basic_istream<Ct, Tr>& operator>>(unsigned long long& n);
  basic_istream<Ct, Tr>& operator>>(float& f);
  basic_istream<Ct, Tr>& operator>>(double& f);
  basic_istream<Ct, Tr>& operator>>(long double& f);
  basic_istream<Ct, Tr>& operator>>(void*& p);
  basic_istream<Ct, Tr>& operator>>(basic_streambuf<char_type, Tr>* sb);

  streamsize gcount() const;
  int_type get();
  basic_istream<Ct, Tr>& get(char_type& c);
  basic_istream<Ct, Tr>& get(char_type* s, streamsize n);
  basic_istream<Ct, Tr>& get(char_type* s, streamsize n, char_type delim);
  basic_istream<Ct, Tr>& get(basic_streambuf<char_type, Tr>& sb);
  basic_istream<Ct, Tr>& get(basic_streambuf<char_type, Tr>& sb, char_type delim);

  basic_istream<Ct, Tr>& getline(char_type* s, streamsize n);
  basic_istream<Ct, Tr>& getline(char_type* s, streamsize n, char_type delim);

  basic_istream<Ct, Tr>& ignore(streamsize n = 1, int_type delim = Tr::eof());
  int_type peek();
  basic_istream<Ct, Tr>& read(char_type* s, streamsize n);
  streamsize readsome(char_type* s, streamsize n);

  basic_istream<Ct, Tr>& putback(char_type c);
  basic_istream<Ct, Tr>& unget();
  int sync();

  pos_type tellg();
  basic_istream<Ct, Tr>& seekg(pos_type);
  basic_istream<Ct, Tr>& seekg(off_type, ios_base::seekdir);

protected:
  basic_istream(const basic_istream&) = delete;
  basic_istream(basic_istream&& rhs);
  basic_istream& operator=(const basic_istream&) = delete;
  basic_istream& operator=(basic_istream&& rhs);
  void swap(basic_istream& rhs);
};

using istream = basic_istream<char>;
using wistream = basic_istream<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>> class basic_ostream : virtual public basic_ios<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  class sentry {
    ~sentry();
    explicit sentry(basic_ostream<Ct, Tr>&);
    sentry(const sentry&) = delete;
    sentry& operator=(const sentry&) = delete;
    explicit operator bool() const;
  };

  virtual ~basic_ostream();
  explicit basic_ostream(basic_streambuf<char_type, Tr>*);
  basic_ostream<Ct, Tr>& operator<<(basic_ostream<Ct, Tr>& (*)(basic_ostream<Ct, Tr>&));
  basic_ostream<Ct, Tr>& operator<<(basic_ios<Ct, Tr>& (*)(basic_ios<Ct, Tr>&));
  basic_ostream<Ct, Tr>& operator<<(ios_base& (*)(ios_base&));
  basic_ostream<Ct, Tr>& operator<<(bool);
  basic_ostream<Ct, Tr>& operator<<(short);
  basic_ostream<Ct, Tr>& operator<<(unsigned short);
  basic_ostream<Ct, Tr>& operator<<(int);
  basic_ostream<Ct, Tr>& operator<<(unsigned int);
  basic_ostream<Ct, Tr>& operator<<(long);
  basic_ostream<Ct, Tr>& operator<<(unsigned long);
  basic_ostream<Ct, Tr>& operator<<(long long);
  basic_ostream<Ct, Tr>& operator<<(unsigned long long);
  basic_ostream<Ct, Tr>& operator<<(float);
  basic_ostream<Ct, Tr>& operator<<(double);
  basic_ostream<Ct, Tr>& operator<<(long double);
  basic_ostream<Ct, Tr>& operator<<(const void*);
  basic_ostream<Ct, Tr>& operator<<(const volatile void*);
  basic_ostream<Ct, Tr>& operator<<(nullptr_t);
  basic_ostream<Ct, Tr>& operator<<(basic_streambuf<char_type, Tr>*);
  basic_ostream<Ct, Tr>& put(char_type);
  basic_ostream<Ct, Tr>& write(const char_type*, streamsize);
  basic_ostream<Ct, Tr>& flush();
  pos_type tellp();
  basic_ostream<Ct, Tr>& seekp(pos_type);
  basic_ostream<Ct, Tr>& seekp(off_type, ios_base::seekdir);
protected:
  basic_ostream(const basic_ostream&) = delete;
  basic_ostream(basic_ostream&&);
  basic_ostream& operator=(const basic_ostream&) = delete;
  basic_ostream& operator=(basic_ostream&&);
  void swap(basic_ostream&);
};

using ostream = basic_ostream<char>;
using wostream = basic_ostream<wchar_t>;

//======================================================================================================================

template<typename Ct, typename Tr = char_traits<Ct>> class basic_iostream : public basic_istream<Ct, Tr>, public basic_ostream<Ct, Tr> {
public:
  using char_type = Ct;
  using int_type = typename Tr::int_type;
  using pos_type = typename Tr::pos_type;
  using off_type = typename Tr::off_type;
  using traits_type = Tr;

  virtual ~basic_iostream();
  explicit basic_iostream(basic_streambuf<Ct, Tr>* sb);

protected:
  basic_iostream(const basic_iostream&) = delete;
  basic_iostream(basic_iostream&& rhs);
  basic_iostream& operator=(const basic_iostream&) = delete;
  basic_iostream& operator=(basic_iostream&& rhs);
  void swap(basic_iostream& rhs);
};

using iostream = basic_iostream<char>;
using wiostream = basic_iostream<wchar_t>;

}
