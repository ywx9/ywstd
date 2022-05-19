// ywstd/string.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <string>
#else

#include "@/basic_string.hh"
#include "@/polymorphic_allocator.hh"
#include "compare.hh"
#include "initializer_list.hh"

namespace std {



template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& lhs, const basic_string<Ct, Tr, Al>& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& lhs, const basic_string<Ct, Tr, Al>& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& lhs, basic_string<Ct, Tr, Al>&& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& lhs, basic_string<Ct, Tr, Al>&& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const Ct* lhs, const basic_string<Ct, Tr, Al>& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const Ct* lhs, basic_string<Ct, Tr, Al>&& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(Ct lhs, const basic_string<Ct, Tr, Al>& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(Ct lhs, basic_string<Ct, Tr, Al>&& rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& lhs, const Ct* rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& lhs, const Ct* rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(const basic_string<Ct, Tr, Al>& lhs, Ct rhs);

template<typename Ct, typename Tr, typename Al> constexpr basic_string<Ct, Tr, Al>
operator+(basic_string<Ct, Tr, Al>&& lhs, Ct rhs);

template<typename Ct, typename Tr, typename Al> constexpr bool
operator==(const basic_string<Ct, Tr, Al>& lhs, const basic_string<Ct, Tr, Al>& rhs) noexcept;

template<typename Ct, typename Tr, typename Al> constexpr bool
operator==(const basic_string<Ct, Tr, Al>& lhs, const Ct* rhs);

template<typename Ct, typename Tr, typename Al> constexpr _::comp_cat<Tr>
operator<=>(const basic_string<Ct, Tr, Al>& lhs, const basic_string<Ct, Tr, Al>& rhs) noexcept;

template<typename Ct, typename Tr, typename Al> constexpr _::comp_cat<Tr>
operator<=>(const basic_string<Ct, Tr, Al>& lhs, const Ct* rhs);

template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>&
operator>>(basic_istream<Ct, Tr>& is, basic_string<Ct, Tr, Al>& str);

template<typename Ct, typename Tr, typename Al> basic_ostream<Ct, Tr>&
operator<<(basic_ostream<Ct, Tr>& os, const basic_string<Ct, Tr, Al>& str);

using string = basic_string<char>;
using u8string = basic_string<char8_t>;
using u16string = basic_string<char16_t>;
using u32string = basic_string<char32_t>;
using wstring = basic_string<wchar_t>;

template<typename Ct, typename Tr, typename Al> constexpr void
swap(basic_string<Ct, Tr, Al>& lhs, basic_string<Ct, Tr, Al>& rhs) noexcept(noexcept(lhs.swap(rhs)));

template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>&
getline(basic_istream<Ct, Tr>& is, basic_string<Ct, Tr, Al>& str, Ct delim);

template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>&
getline(basic_istream<Ct, Tr>&& is, basic_string<Ct, Tr, Al>& str, Ct delim);

template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>&
getline(basic_istream<Ct, Tr>& is, basic_string<Ct, Tr, Al>& str);

template<typename Ct, typename Tr, typename Al> basic_istream<Ct, Tr>&
getline(basic_istream<Ct, Tr>&& is, basic_string<Ct, Tr, Al>& str);

template<typename Ct, typename Tr, typename Al, class U>
constexpr typename basic_string<Ct, Tr, Al>::size_type
erase(basic_string<Ct, Tr, Al>& c, const U& value);

template<typename Ct, typename Tr, typename Al, class Pred>
constexpr typename basic_string<Ct, Tr, Al>::size_type
erase_if(basic_string<Ct, Tr, Al>& c, Pred pred);

int stoi(const string& str, size_t* idx = nullptr, int base = 10);
long stol(const string& str, size_t* idx = nullptr, int base = 10);
unsigned long stoul(const string& str, size_t* idx = nullptr, int base = 10);
long long stoll(const string& str, size_t* idx = nullptr, int base = 10);
unsigned long long stoull(const string& str, size_t* idx = nullptr, int base = 10);
float stof(const string& str, size_t* idx = nullptr);
double stod(const string& str, size_t* idx = nullptr);
long double stold(const string& str, size_t* idx = nullptr);

string to_string(int val);
string to_string(unsigned val);
string to_string(long val);
string to_string(unsigned long val);
string to_string(long long val);
string to_string(unsigned long long val);
string to_string(float val);
string to_string(double val);
string to_string(long double val);

int stoi(const wstring& str, size_t* idx = nullptr, int base = 10);
long stol(const wstring& str, size_t* idx = nullptr, int base = 10);
unsigned long stoul(const wstring& str, size_t* idx = nullptr, int base = 10);
long long stoll(const wstring& str, size_t* idx = nullptr, int base = 10);
unsigned long long stoull(const wstring& str, size_t* idx = nullptr, int base = 10);
float stof(const wstring& str, size_t* idx = nullptr);
double stod(const wstring& str, size_t* idx = nullptr);
long double stold(const wstring& str, size_t* idx = nullptr);

wstring to_wstring(int val);
wstring to_wstring(unsigned val);
wstring to_wstring(long val);
wstring to_wstring(unsigned long val);
wstring to_wstring(long long val);
wstring to_wstring(unsigned long long val);
wstring to_wstring(float val);
wstring to_wstring(double val);
wstring to_wstring(long double val);

namespace pmr {
  template<typename Ct, typename Tr = char_traits<Ct>>
  using basic_string = std::basic_string<Ct, Tr, polymorphic_allocator<Ct>>;
  using string = basic_string<char>;
  using u8string = basic_string<char8_t>;
  using u16string = basic_string<char16_t>;
  using u32string = basic_string<char32_t>;
  using wstring = basic_string<wchar_t>;
}

template<typename Ty> struct hash;
template<> struct hash<string> { size_t operator()(const string&); };
template<> struct hash<u8string> { size_t operator()(const u8string&); };
template<> struct hash<u16string> { size_t operator()(const u16string&); };
template<> struct hash<u32string> { size_t operator()(const u32string&); };
template<> struct hash<wstring> { size_t operator()(const wstring&); };
template<> struct hash<pmr::string> { size_t operator()(const pmr::string&); };
template<> struct hash<pmr::u8string> { size_t operator()(const pmr::u8string&); };
template<> struct hash<pmr::u16string> { size_t operator()(const pmr::u16string&); };
template<> struct hash<pmr::u32string> { size_t operator()(const pmr::u32string&); };
template<> struct hash<pmr::wstring> { size_t operator()(const pmr::wstring&); };

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuser-defined-literals"
inline namespace literals {
  inline namespace string_literals {
    constexpr string operator""s(const char* str, size_t len);
    constexpr u8string operator""s(const char8_t* str, size_t len);
    constexpr u16string operator""s(const char16_t* str, size_t len);
    constexpr u32string operator""s(const char32_t* str, size_t len);
    constexpr wstring operator""s(const wchar_t* str, size_t len);
  }
}
#pragma clang diagnostic pop

}

#endif
