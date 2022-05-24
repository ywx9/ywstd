// ywstd/variant.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <variant>
#else

#include "@/../compare.hh"
#include "@/../exception.hh"
#include "@/variant.hh"

namespace std {

template<typename Visitor, typename... Variants> constexpr decltype(auto) visit(Visitor&& vis, Variants&&... vars);
template<typename Rt, typename Visitor, typename... Variants> constexpr Rt visit(Visitor&& vis, Variants&&... vars);

struct monostate{};

constexpr bool operator==(monostate, monostate) noexcept { return true; }
constexpr strong_ordering operator<=>(monostate, monostate) noexcept { return strong_ordering::equal; }

class bad_variant_access : public exception {
public:
  const char* what() const noexcept override;
};

template<typename Ty> struct hash;
template<typename... Ts> struct hash<variant<Ts...>> { size_t operator()(const variant<Ts...>&); };
template<> struct hash<monostate> { size_t operator()(const monostate&); };

}

#endif
