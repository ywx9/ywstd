// ywstd/@/tuple_element.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

namespace std {

using size_t = decltype(sizeof(int));

template<size_t Ix, typename Tp> struct tuple_element {};
template<size_t Ix, typename Tp> using tuple_element_t = typename tuple_element<Ix, Tp>::type;

template<typename Tp> struct tuple_size {};
template<typename Tp> inline constexpr size_t tuple_size_v = tuple_size<Tp>::value;

}
