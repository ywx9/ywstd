// ywstd/@/hash.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

namespace std {

using nullptr_t = decltype(nullptr);
using size_t = decltype(sizeof(int));

template<typename Ty> struct hash;

template<> struct hash<bool> { size_t operator()(const bool&); };
template<> struct hash<char> { size_t operator()(const char&); };
template<> struct hash<wchar_t> { size_t operator()(const wchar_t&); };
template<> struct hash<char8_t> { size_t operator()(const char8_t&); };
template<> struct hash<char16_t> { size_t operator()(const char16_t&); };
template<> struct hash<char32_t> { size_t operator()(const char32_t&); };
template<> struct hash<signed char> { size_t operator()(const signed char&); };
template<> struct hash<short> { size_t operator()(const short&); };
template<> struct hash<int> { size_t operator()(const int&); };
template<> struct hash<long> { size_t operator()(const long&); };
template<> struct hash<long long> { size_t operator()(const long long&); };
template<> struct hash<unsigned char> { size_t operator()(const unsigned char&); };
template<> struct hash<unsigned short> { size_t operator()(const unsigned short&); };
template<> struct hash<unsigned int> { size_t operator()(const unsigned int&); };
template<> struct hash<unsigned long> { size_t operator()(const unsigned long&); };
template<> struct hash<unsigned long long> { size_t operator()(const unsigned long long&); };
template<> struct hash<float> { size_t operator()(const float&); };
template<> struct hash<double> { size_t operator()(const double&); };
template<> struct hash<long double> { size_t operator()(const long double&); };
template<> struct hash<nullptr_t> { size_t operator()(const nullptr_t&); };
template<typename Ty> struct hash<Ty*> { size_t operator()(const Ty*&); };

}
