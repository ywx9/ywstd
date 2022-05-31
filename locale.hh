// ywstd/locale.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <locale>
#else

#include "@/locale.hh"
#include "@/streambuf_iterator.hh"
#include "@/tm.hh"

namespace std {

// std::ctype_base
class ctype_base {
public:
  using mask = short;
  static const mask upper = 0x01;
  static const mask lower = 0x02;
  static const mask digit = 0x04;
  static const mask cntrl = 0x20;
  static const mask alpha = upper | lower | 0x100;
  static const mask space = 0x08 | 0x40;
  static const mask print = 0x01 | 0x02 | 0x04 | 0x10 | 0x40 | 0x80 | 0x100;
  static const mask punct = 0x10;
  static const mask xdigit = 0x80;
  static const mask blank = space;
  static const mask alnum = alpha | digit;
  static const mask graph = alnum | punct;
};

// std::codecvt_base
class codecvt_base { // clang-format off
public:
  enum result { ok, partial, error, noconv };
}; // clang-format on

// std::messages_base
class messages_base {
public:
  using catalog = int;
};

// std::time_base
class time_base { // clang-format off
public:
  enum dateorder { no_order, dmy, mdy, ymd, ydm };
}; // clang-format on

// std::money_base
class money_base { // clang-format off
public:
  enum part { none, space, symbol, sign, value };
  struct pattern { char field[4]; };
}; // clang-format on

// std::ctype
template<typename CT> class ctype : public ctype_base, public locale::facet {
public:
  using char_type = CT;
  static locale::id id;
  explicit ctype(size_t = 0);
  bool is(mask, CT) const;
  const CT* is(const CT* lo, const CT* hi, mask*) const;
  const CT* scan_is(mask, const CT* First, const CT* Last) const;
  const CT* scan_not(mask, const CT* First, const CT* Last) const;
  CT toupper(CT) const;
  const CT* toupper(CT* First, const CT* End) const;
  CT tolower(CT) const;
  const CT* tolower(CT* First, const CT* End) const;
  CT widen(char) const;
  const char* widen(const char* First, const char* End, CT*) const;
  char narrow(CT, char) const;
  CT* narrow(const CT* First, const CT* End, char, char*) const;

protected:
  ~ctype();
  virtual bool do_is(mask, CT) const;
  virtual const CT* do_is(const CT* lo, const CT* hi, mask*) const;
  virtual const CT* do_scan_is(mask, const CT* First, const CT* Last) const;
  virtual const CT* do_scan_not(mask, const CT* First, const CT* Last) const;
  virtual CT do_toupper(CT) const;
  virtual const CT* do_toupper(CT* First, const CT* End) const;
  virtual CT do_tolower(CT) const;
  virtual const CT* do_tolower(CT* First, const CT* End) const;
  virtual CT do_widen(char) const;
  virtual const char* do_widen(const char* First, const char* End, CT*) const;
  virtual char do_narrow(CT, char) const;
  virtual CT* do_narrow(const CT* First, const CT* End, char, char*) const;
};

// std::ctype<char>
template<> class ctype<char> : public ctype_base, public locale::facet {
public:
  using char_type = char;
  static locale::id id;
  static const std::size_t table_size;
  static const mask* classic_table() noexcept;
  explicit ctype(const mask* = nullptr, bool = false, size_t = 0);
  const mask* table() const noexcept;
  bool is(mask, char) const;
  const char* is(const char* lo, const char* hi, mask*) const;
  const char* scan_is(mask, const char* First, const char* Last) const;
  const char* do_scan_not(mask, const char* First, const char* Last) const;
  char toupper(char) const;
  const char* toupper(char* First, const char* End) const;
  char tolower(char) const;
  const char* tolower(char* First, const char* End) const;
  char widen(char) const;
  const char* widen(const char* First, const char* End, char*) const;
  char narrow(wchar_t, char) const;
  char* narrow(const char* First, const char* End, char, char*) const;

protected:
  ~ctype();
  virtual char do_toupper(char) const;
  virtual const char* do_toupper(char* First, const char* End) const;
  virtual char do_tolower(char) const;
  virtual const char* do_tolower(char* First, const char* End) const;
  virtual char do_widen(char) const;
  virtual const char* do_widen(const char* First, const char* End, char*) const;
  virtual char do_narrow(char, char) const;
  virtual char* do_narrow(const char* First, const char* End, char, char*) const;
};

// std::ctype<wchar_t>
template<> class ctype<wchar_t> : public ctype_base, public locale::facet {
public:
  using char_type = wchar_t;
  static locale::id id;
  static const std::size_t table_size;
  static const mask* classic_table() noexcept;
  explicit ctype(const mask* = nullptr, bool = false, size_t = 0);
  const mask* table() const noexcept;
  bool is(mask, wchar_t) const;
  const wchar_t* is(const wchar_t* lo, const wchar_t* hi, mask*) const;
  const wchar_t* scan_is(mask, const wchar_t* First, const wchar_t* Last) const;
  const wchar_t* do_scan_not(mask, const wchar_t* First, const wchar_t* Last) const;
  wchar_t toupper(wchar_t) const;
  const wchar_t* toupper(wchar_t* First, const wchar_t* End) const;
  wchar_t tolower(wchar_t) const;
  const wchar_t* tolower(wchar_t* First, const wchar_t* End) const;
  wchar_t widen(char) const;
  const char* widen(const char* First, const char* End, wchar_t*) const;
  char narrow(wchar_t, char) const;
  wchar_t* narrow(const wchar_t* First, const wchar_t* End, char, char*) const;

protected:
  ~ctype();
  virtual wchar_t do_toupper(wchar_t) const;
  virtual const wchar_t* do_toupper(wchar_t* First, const wchar_t* End) const;
  virtual wchar_t do_tolower(wchar_t) const;
  virtual const wchar_t* do_tolower(wchar_t* First, const wchar_t* End) const;
  virtual wchar_t do_widen(char) const;
  virtual const char* do_widen(const char* First, const char* End, wchar_t*) const;
  virtual char do_narrow(char, char) const;
  virtual wchar_t* do_narrow(const wchar_t* First, const wchar_t* End, char, char*) const;
};

// std::codecvt
template<typename Intern, typename Extern, typename State> class codecvt : public codecvt_base, public locale::facet {
public:
  using intern_type = Intern;
  using extern_type = Extern;
  using state_type = State;
  static const locale::id id;
  explicit codecvt(size_t = 0);
  result out(State&, const Intern*, const Intern*, const Intern*&, Extern*, Extern*, Extern*&) const;
  result in(State&, const Extern*, const Extern*, const Extern*&, Intern*, Intern*, Intern*&) const;
  result unshift(State&, Extern*, Extern*, Extern*&) const;
  int encoding() const noexcept;
  bool always_noconv() const noexcept;
  int length(State&, const Extern*, const Extern*, size_t);
  int max_length() const noexcept;

protected:
  ~codecvt();
  virtual result do_out(State&, const Intern*, const Intern*, const Intern*&, Extern*, Extern*, Extern*&) const;
  virtual result do_in(State&, const Extern*, const Extern*, const Extern*&, Intern*, Intern*, Intern*&) const;
  virtual result do_unshift(State&, Extern*, Extern*, Extern*&) const;
  virtual int do_encoding() const noexcept;
  virtual bool do_always_noconv() const noexcept;
  virtual int do_length(State&, const Extern*, const Extern*, size_t);
  virtual int do_max_length() const noexcept;
};

template<> class codecvt<char, char, mbstate_t>;
template<> class codecvt<wchar_t, char, mbstate_t>;
template<> class codecvt<char16_t, char8_t, mbstate_t>;
template<> class codecvt<char32_t, char8_t, mbstate_t>;

// std::collate
template<typename CT> class collate : public locale::facet {
public:
  using char_type = CT;
  using string_type = basic_string<CT>;
  explicit collate(size_t = 0);
  int compare(const CT*, const CT*, const CT*, const CT*) const;
  string_type transform(const CT*, const CT*) const;
  long hash(const CT*, const CT*) const;

protected:
  ~collate();
  virtual int do_compare(const CT*, const CT*, const CT*, const CT*) const;
  virtual string_type do_transform(const CT*, const CT*) const;
  virtual long do_hash(const CT*, const CT*) const;
};

// std::messages
template<typename CT> class messages : public messages_base, public locale::facet {
public:
  using char_type = CT;
  using string_type = basic_string<CT>;
  static const locale::id id;
  explicit messages(size_t = 0);
  catalog open(const basic_string<char>&, const locale&) const;
  string_type get(catalog, int, int, const string_type&) const;
  void close(catalog) const;

protected:
  ~messages();
  virtual catalog do_open(const basic_string<char>&, const locale&) const;
  virtual string_type do_get(catalog, int, int, const string_type&) const;
  virtual void do_close(catalog) const;
};

// std::time_get
template<typename CT, typename It = istreambuf_iterator<CT>> class time_get : public time_base, public locale::facet {
public:
  using char_type = CT;
  using iter_type = It;
  explicit time_get(size_t = 0);
  dateorder date_order() const;
  iter_type get_time(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  iter_type get_date(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  iter_type get_weekday(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  iter_type get_monthname(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  iter_type get_year(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*, const char_type*, const char_type*) const;

protected:
  ~time_get();
  virtual dateorder do_date_order() const;
  virtual iter_type do_get_time(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_date(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_weekday(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_monthname(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_year(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, tm*, const char_type*, const char_type*) const;
};

// std::time_put
template<typename CT, typename Out = ostreambuf_iterator<CT>> class time_put : public time_base, public locale::facet {
public:
  using char_type = CT;
  using iter_type = Out;
  explicit time_put(size_t = 0);
  iter_type put(iter_type, ios_base&, char_type, const tm*, const CT*, const CT*) const;
  iter_type put(iter_type, ios_base&, char_type, const tm*, char, char = 0) const;

protected:
  ~time_put();
  virtual iter_type do_put(iter_type, ios_base&, char_type, const tm*, char, char) const;
};

// std::num_get
template<typename CT, typename It = istreambuf_iterator<CT>> class num_get : public locale::facet {
  using char_type = CT;
  using iter_type = It;
  static locale::id id;
  explicit num_get(size_t = 0);
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, bool&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, long&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, long long&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned short&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned int&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned long&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned long long&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, float&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, double&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, long double&) const;
  iter_type get(iter_type, iter_type, ios_base&, ios_base::iostate&, void*&) const;

protected:
  ~num_get();
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, bool&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, long&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, long long&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned short&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned int&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned long&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, unsigned long long&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, float&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, double&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, long double&) const;
  virtual iter_type do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, void*&) const;
};

// std::num_put
template<typename CT, typename Out = ostreambuf_iterator<CT>> class num_put : public locale::facet {
public:
  using char_type = CT;
  using iter_type = Out;
  static locale::id id;
  explicit num_put(size_t = 0);
  iter_type put(iter_type, ios_base&, char_type, bool) const;
  iter_type put(iter_type, ios_base&, char_type, long) const;
  iter_type put(iter_type, ios_base&, char_type, long long) const;
  iter_type put(iter_type, ios_base&, char_type, unsigned long) const;
  iter_type put(iter_type, ios_base&, char_type, unsigned long long) const;
  iter_type put(iter_type, ios_base&, char_type, double) const;
  iter_type put(iter_type, ios_base&, char_type, long double) const;
  iter_type put(iter_type, ios_base&, char_type, const void*) const;

protected:
  ~num_put();
  virtual iter_type do_put(iter_type, ios_base&, char_type, bool) const;
  virtual iter_type do_put(iter_type, ios_base&, char_type, long) const;
  virtual iter_type do_put(iter_type, ios_base&, char_type, long long) const;
  virtual iter_type do_put(iter_type, ios_base&, char_type, unsigned long) const;
  virtual iter_type do_put(iter_type, ios_base&, char_type, unsigned long long) const;
  virtual iter_type do_put(iter_type, ios_base&, char_type, double) const;
  virtual iter_type do_put(iter_type, ios_base&, char_type, long double) const;
  virtual iter_type do_put(iter_type, ios_base&, char_type, const void*) const;
};

// std::numpunct
template<typename CT> class numpunct : public locale::facet {
public:
  using char_type = CT;
  using string_type = basic_string<CT>;
  static locale::id id;
  explicit numpunct(size_t = 0);
  char_type decimal_point() const;
  char_type thousands_sep() const;
  string grouping() const;
  string_type truename() const;
  string_type falsename() const;

protected:
  ~numpunct();
  virtual char_type do_decimal_point() const;
  virtual char_type do_thousands_sep() const;
  virtual string do_grouping() const;
  virtual string_type do_truename() const;
  virtual string_type do_falsename() const;
};

// std::muney_get
template<typename CT, typename It = istreambuf_iterator<CT>> class money_get : public locale::facet {
public:
  using char_type = CT;
  using iter_type = It;
  using string_type = basic_string<CT>;
  static locale::id id;
  explicit money_get(size_t = 0);
  iter_type get(iter_type, iter_type, bool, ios_base&, ios_base::iostate&, long double&) const;
  iter_type get(iter_type, iter_type, bool, ios_base&, ios_base::iostate&, string_type&) const;

protected:
  ~money_get();
  virtual iter_type do_get(iter_type, iter_type, bool, ios_base&, ios_base::iostate&, long double&) const;
  virtual iter_type do_get(iter_type, iter_type, bool, ios_base&, ios_base::iostate&, string_type&) const;
};

// std::money_put
template<typename CT, typename Out = ostreambuf_iterator<CT>> class money_put : public locale::facet {
public:
  using char_type = CT;
  using iter_type = Out;
  using string_type = basic_string<CT>;
  static locale::id id;
  explicit money_put(size_t = 0);
  iter_type put(iter_type, bool, ios_base&, char_type, long double) const;
  iter_type put(iter_type, bool, ios_base&, char_type, const string_type&) const;

protected:
  ~money_put();
  virtual iter_type do_put(iter_type, bool, ios_base&, char_type, long double) const;
  virtual iter_type do_put(iter_type, bool, ios_base&, char_type, const string_type&) const;
};

// std::moneypuct
template<typename CT, bool Intl = false> class moneypunct : public locale::facet, public money_base {
public:
  using char_type = CT;
  using string_type = basic_string<CT>;
  static locale::id id;
  static const bool intl = Intl;
  explicit moneypunct(size_t = 0);
  CT decimal_point() const;
  CT thousands_sep() const;
  string grouping() const;
  string_type curr_symbol() const;
  string_type positive_sign() const;
  string_type negative_sign() const;
  int frac_digits() const;
  pattern pos_format() const;
  pattern neg_format() const;

protected:
  ~moneypunct();
  virtual CT do_decimal_point() const;
  virtual CT do_thousands_sep() const;
  virtual string do_grouping() const;
  virtual string_type do_curr_symbol() const;
  virtual string_type do_positive_sign() const;
  virtual string_type do_negative_sign() const;
  virtual int do_frac_digits() const;
  virtual pattern do_pos_format() const;
  virtual pattern do_neg_format() const;
};

// std::ctype_byname
template<typename CT> class ctype_byname : public ctype<CT> {
public:
  typedef typename ctype<CT>::mask mask;
  explicit ctype_byname(const char*, size_t = 0);
  explicit ctype_byname(const string&, size_t = 0);

protected:
  ~ctype_byname();
};

// std::codecvt_byname
template<typename Intern, typename Extern, typename State> class codecvt_byname : public codecvt<Intern, Extern, State> {
public:
  explicit codecvt_byname(const char*, size_t = 0);
  explicit codecvt_byname(const string&, size_t = 0);

protected:
  ~codecvt_byname();
};

// std::message_byname
template<typename CT> class messages_byname : public messages<CT> {
public:
  using catalog = messages_base::catalog;
  using string_type = basic_string<CT>;
  explicit messages_byname(const char*, size_t = 0);
  explicit messages_byname(const string&, size_t = 0);

protected:
  ~messages_byname();
};

// std::collate_byname
template<typename CT> class collate_byname : public collate<CT> {
public:
  using string_type = basic_string<CT>;
  explicit collate_byname(const char*, size_t = 0);
  explicit collate_byname(const string&, size_t = 0);

protected:
  ~collate_byname();
};

// std::time_get_byname
template<typename CT, typename It = istreambuf_iterator<CT>> class time_get_byname : public time_get<CT, It> {
public:
  using dateorder = time_base::dateorder;
  using iter_type = It;
  explicit time_get_byname(const char*, size_t = 0);
  explicit time_get_byname(const string&, size_t = 0);

protected:
  ~time_get_byname();
};

// std::time_put_byname
template<typename CT, typename Out = ostreambuf_iterator<CT>> class time_put_byname : public time_put<CT, Out> {
public:
  using char_type = CT;
  using iter_type = Out;
  explicit time_put_byname(const char*, size_t = 0);
  explicit time_put_byname(const string&, size_t = 0);

protected:
  ~time_put_byname();
};

// std::numpunct_byname
template<typename CT> class numpunct_byname : public numpunct<CT> {
public:
  using char_type = CT;
  using string_type = basic_string<CT>;
  explicit numpunct_byname(const char*, size_t = 0);
  explicit numpunct_byname(const string&, size_t = 0);

protected:
  ~numpunct_byname();
};

// std::moneypunct_byname
template<typename CT, bool Intl = false> class moneypunct_byname : public moneypunct<CT, Intl> {
public:
  using pattern = money_base::pattern;
  using string_type = basic_string<CT>;
  explicit moneypunct_byname(const char*, size_t = 0);
  explicit moneypunct_byname(const string&, size_t = 0);

protected:
  ~moneypunct_byname();
};

// std::use_facet
template<typename Facet> const Facet& use_facet(const locale&);

// std::has_facet
template<typename Facet> bool has_facet(const locale&) noexcept;

// std::isspace
template<typename CT> bool isspace(CT, const locale&);

// std::isprint
template<typename CT> bool isprint(CT, const locale&);

// std::iscntrl
template<typename CT> bool iscntrl(CT, const locale&);

// std::isupper
template<typename CT> bool isupper(CT, const locale&);

// std::islower
template<typename CT> bool islower(CT, const locale&);

// std::isalpha
template<typename CT> bool isalpha(CT, const locale&);

// std::isdigit
template<typename CT> bool isdigit(CT, const locale&);

// std::ispunct
template<typename CT> bool ispunct(CT, const locale&);

// std::isxdigit
template<typename CT> bool isxdigit(CT, const locale&);

// std::isalnum
template<typename CT> bool isalnum(CT, const locale&);

// std::isgraph
template<typename CT> bool isgraph(CT, const locale&);

// std::toupper
template<typename CT> CT toupper(CT, const locale&);

// std::tolower
template<typename CT> CT tolower(CT, const locale&);

}
#endif
