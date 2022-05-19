// ywstd/@/in_place.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

namespace std {

using size_t = decltype(sizeof(int));

struct in_place_t { explicit in_place_t() = default; };
inline constexpr in_place_t in_place{};

template<size_t Ix> struct in_place_index_t { explicit in_place_index_t() = default; };
template<size_t Ix> inline constexpr in_place_index_t<Ix> in_place_index{};

template<typename Ty> struct in_place_type_t { explicit in_place_type_t() = default; };
template<typename Ty> inline constexpr in_place_type_t<Ty> in_place_type{};

namespace _ {
  template<typename Ty> inline constexpr bool is_special_in_place = false;
  template<> inline constexpr bool is_special_in_place<in_place_t> = true;

  template<typename Ty> inline constexpr bool is_special_in_place_index = false;
  template<size_t Ix> inline constexpr bool is_special_in_place_index<in_place_index_t<Ix>> = true;

  template<typename Ty> inline constexpr bool is_special_in_place_type = false;
  template<typename Ty> inline constexpr bool is_special_in_place_type<in_place_type_t<Ty>> = true;
}

}
