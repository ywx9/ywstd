// ywstd/compare.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <compare>
#else

#include "@/_.hh"
#include "@/common_type.hh"
#include "@/type_identity.hh"

namespace std {

using nullptr_t = decltype(nullptr);

struct partial_ordering {
  static const partial_ordering less, equivalent, greater, unordered;
  friend constexpr bool operator==(const partial_ordering x, nullptr_t) noexcept { return x._value == 0; }
  friend constexpr bool operator==(partial_ordering, partial_ordering) noexcept = default;
  friend constexpr bool operator<(const partial_ordering x, nullptr_t) noexcept { return x._value == -1; }
  friend constexpr bool operator>(const partial_ordering x, nullptr_t) noexcept { return x._value == 1; }
  friend constexpr bool operator<=(const partial_ordering x, nullptr_t) noexcept { return -x._value >= 0; }
  friend constexpr bool operator>=(const partial_ordering x, nullptr_t) noexcept { return x._value >= 0; }
  friend constexpr bool operator<(nullptr_t, const partial_ordering y) noexcept { return y > 0; }
  friend constexpr bool operator>(nullptr_t, const partial_ordering y) noexcept { return y < 0; }
  friend constexpr bool operator<=(nullptr_t, const partial_ordering y) noexcept { return y >= 0; }
  friend constexpr bool operator>=(nullptr_t, const partial_ordering y) noexcept { return y <= 0; }
  friend constexpr partial_ordering operator<=>(const partial_ordering x, nullptr_t) noexcept { return x; }
  friend constexpr partial_ordering operator<=>(nullptr_t, const partial_ordering y) noexcept { return {-y._value}; }
  int _value;
};

inline constexpr partial_ordering partial_ordering::less{-1};
inline constexpr partial_ordering partial_ordering::equivalent{0};
inline constexpr partial_ordering partial_ordering::greater{1};
inline constexpr partial_ordering partial_ordering::unordered{static_cast<int>(0x80000000)};

struct weak_ordering {
  static const weak_ordering less, equivalent, greater;
  constexpr operator partial_ordering() const noexcept { return {_value}; }
  friend constexpr bool operator==(const weak_ordering x, nullptr_t) noexcept { return x._value == 0; }
  friend constexpr bool operator==(weak_ordering, weak_ordering) noexcept = default;
  friend constexpr bool operator<(const weak_ordering x, nullptr_t) noexcept { return x._value < 0; }
  friend constexpr bool operator>(const weak_ordering x, nullptr_t) noexcept { return x._value > 0; }
  friend constexpr bool operator<=(const weak_ordering x, nullptr_t) noexcept { return x._value <= 0; }
  friend constexpr bool operator>=(const weak_ordering x, nullptr_t) noexcept { return x._value >= 0; }
  friend constexpr bool operator<(nullptr_t, const weak_ordering y) noexcept { return y > 0; }
  friend constexpr bool operator>(nullptr_t, const weak_ordering y) noexcept { return y < 0; }
  friend constexpr bool operator<=(nullptr_t, const weak_ordering y) noexcept { return y >= 0; }
  friend constexpr bool operator>=(nullptr_t, const weak_ordering y) noexcept { return y <= 0; }
  friend constexpr weak_ordering operator<=>(const weak_ordering y, nullptr_t) noexcept { return y; }
  friend constexpr weak_ordering operator<=>(nullptr_t, const weak_ordering y) noexcept { return {-y._value}; }
  int _value;
};

inline constexpr weak_ordering weak_ordering::less{-1};
inline constexpr weak_ordering weak_ordering::equivalent{0};
inline constexpr weak_ordering weak_ordering::greater{1};

struct strong_ordering {
  static const strong_ordering less, equal, equivalent, greater;
  constexpr operator partial_ordering() const noexcept { return {static_cast<int>(_value)}; }
  constexpr operator weak_ordering() const noexcept { return {static_cast<int>(_value)}; }
  friend constexpr bool operator==(const strong_ordering x, nullptr_t) noexcept { return x._value == 0; }
  friend constexpr bool operator==(strong_ordering, strong_ordering) noexcept = default;
  friend constexpr bool operator<(const strong_ordering x, nullptr_t) noexcept { return x._value < 0; }
  friend constexpr bool operator>(const strong_ordering x, nullptr_t) noexcept { return x._value > 0; }
  friend constexpr bool operator<=(const strong_ordering x, nullptr_t) noexcept { return x._value <= 0; }
  friend constexpr bool operator>=(const strong_ordering x, nullptr_t) noexcept { return x._value >= 0; }
  friend constexpr bool operator<(nullptr_t, const strong_ordering y) noexcept { return y > 0; }
  friend constexpr bool operator>(nullptr_t, const strong_ordering y) noexcept { return y < 0; }
  friend constexpr bool operator<=(nullptr_t, const strong_ordering y) noexcept { return y >= 0; }
  friend constexpr bool operator>=(nullptr_t, const strong_ordering y) noexcept { return y <= 0; }
  friend constexpr strong_ordering operator<=>(const strong_ordering x, nullptr_t) noexcept { return x; }
  friend constexpr strong_ordering operator<=>(nullptr_t, const strong_ordering y) noexcept { return {-y._value}; }
  int _value;
};

inline constexpr strong_ordering strong_ordering::less{-1};
inline constexpr strong_ordering strong_ordering::equal{0};
inline constexpr strong_ordering strong_ordering::equivalent{0};
inline constexpr strong_ordering strong_ordering::greater{1};

namespace _ {
  template<typename... Ts> concept is_three_way_result = (included_in<Ts, partial_ordering, weak_ordering, strong_ordering> && ...);
  template<typename... Ts> using common_comparison_category_t = type_switch_t<inspects<!is_three_way_result<Ts...>,
    included_in<partial_ordering, Ts...>, included_in<weak_ordering, Ts...>>, void, partial_ordering, weak_ordering, strong_ordering>;
  template<typename T1, typename T2> using compare_three_way_result_t =
    decltype(declval<const remove_reference_t<T1>&>() <=> declval<const remove_reference_t<T2>&>());
  template<typename Ty, typename Ct> concept compares_as = same_as<common_comparison_category_t<Ty, Ct>, Ct>;
  template<typename Ty, typename Ct = partial_ordering> concept three_way_comparable =
    half_weakly_equality_comparable_with<Ty, Ty> && half_partially_ordered_with<Ty, Ty> &&
    requires(const remove_reference_t<Ty>& x, const remove_reference_t<Ty>& y) { { x <=> y } -> compares_as<Ct>; };
  template<typename T1, typename T2, typename Ct = partial_ordering> concept three_way_comparable_with =
    weakly_equality_comparable_with<T1, T2> && partially_ordered_with<T1, T2> && three_way_comparable<T1, Ct> && three_way_comparable<T2, Ct> &&
    common_reference_with<const remove_reference_t<T1>&, const remove_reference_t<T2>&> &&
    three_way_comparable<common_reference_t<const remove_reference_t<T1>&, const remove_reference_t<T2>&>, Ct> &&
    requires(const remove_reference_t<T1>& x, const remove_reference_t<T2>& y) { { x <=> y } -> compares_as<Ct>; { y <=> x } -> compares_as<Ct>; };
  template<typename T1, typename T2> constexpr auto synth_three_way(const T1& x, const T2& y)
    requires requires { { x < y } -> boolean_testable; { y < x } -> boolean_testable; } {
    if constexpr (three_way_comparable_with<T1, T2>) return x <=> y;
    else if (x < y) return weak_ordering::less;
    else if (y < x) return weak_ordering::greater;
    else return weak_ordering::equivalent; }
  template<typename T1, typename T2 = T1> using synth_three_way_result_t = decltype(_::synth_three_way(declval<T1>(), declval<T2>()));
}

constexpr bool is_eq(const partial_ordering x) noexcept { return x == 0; }
constexpr bool is_neq(const partial_ordering x) noexcept { return x != 0; }
constexpr bool is_lt(const partial_ordering x) noexcept { return x < 0; }
constexpr bool is_lteq(const partial_ordering x) noexcept { return x <= 0; }
constexpr bool is_gt(const partial_ordering x) noexcept { return x > 0; }
constexpr bool is_gteq(const partial_ordering x) noexcept { return x >= 0; }

template<typename... Ts> struct common_comparison_category : type_identity<_::common_comparison_category_t<Ts...>> {};
template<typename... Ts> using common_comparison_category_t = typename common_comparison_category<Ts...>::type;

template<typename T1, typename T2 = T1> struct compare_three_way_result {};
template<typename T1, typename T2 = T1> using compare_three_way_result_t = typename compare_three_way_result<T1, T2>::type;
template<typename T1, typename T2> requires requires(const _::remove_reference_t<T1>& x, const _::remove_reference_t<T2>& y) { x <=> y; }
struct compare_three_way_result<T1, T2> : type_identity<_::compare_three_way_result_t<T1, T2>> {};

template<typename Ty, typename Ct = partial_ordering> concept three_way_comparable = _::three_way_comparable<Ty, Ct>;
template<typename T1, typename T2, typename Ct = partial_ordering> concept three_way_comparable_with = _::three_way_comparable_with<T1, T2, Ct>;

struct compare_three_way {
  using is_transparent = int;
  template<typename T1, three_way_comparable_with<T1> T2> constexpr auto operator()(T1&& x, T2&& y) const
    noexcept(noexcept(static_cast<T1&&>(x) <=> static_cast<T2&&>(y))) { return static_cast<T1&&>(x) <=> static_cast<T2&&>(y); }
};

namespace _::_order {
  void partial_order();
  void weak_order();
  void strong_order();
  struct strong {
    template<typename T1, typename T2> static constexpr bool c1 = requires(T1& x, T2& y) { static_cast<strong_ordering>(strong_order(x, y)); };
    template<typename T1, typename T2> static constexpr bool c2 = floating_point<decay_t<T2>>;
    template<typename T1, typename T2> static constexpr bool c3 = requires(T1& x, T2& y) { static_cast<strong_ordering>(compare_three_way{}(x, y)); };
    template<typename T1, typename T2> static constexpr auto cs = []() -> call_style {
      if constexpr (!same_as<decay_t<T1>, decay_t<T2>>) return {};
      else if constexpr (c1<T1, T2>) return {1, true, noexcept(static_cast<strong_ordering>(strong_order(declval<T1&>(), declval<T2&>())))};
      else if constexpr (c2<T1, T2>) return {2, true, true};
      else if constexpr (c3<T1, T2>) return {3, true, noexcept(static_cast<strong_ordering>(compare_three_way{}(declval<T1&>(), declval<T2&>())))};
      else return {}; }();
    template<typename T1, typename T2> requires(cs<T1, T2>.able)
    constexpr strong_ordering operator()(T1&& x, T2&& y) const noexcept(cs<T1, T2>.nothrow) {
      if constexpr (cs<T1, T2>.style == 1) return static_cast<strong_ordering>(strong_order(x, y));
      else if constexpr (cs<T1, T2>.style == 2) {
        using it = conditional_t<sizeof(T1) == 4, int, long long>;
        using nt = conditional_t<sizeof(T1) == 4, unsigned int, unsigned long long>;
        constexpr nt sign_shift = bit_size<nt> - 1, sign_mask = nt{1} << sign_shift;
        const nt x_0 = _::bit_cast<nt>(x), y_0 = _::bit_cast<nt>(y);
        if (x_0 == y_0) return strong_ordering::equal;
        const nt x_1 = x_0 & sign_mask, y_1 = y_0 & sign_mask;
        return static_cast<it>(x_0 ^ (x_1 - (x_1 >> sign_shift))) <=> static_cast<it>(y_0 ^ (y_1 - (y_1 >> sign_shift)));
      } else if constexpr (cs<T1, T2>.style == 3) return static_cast<strong_ordering>(compare_three_way{}(x, y));
    }
  };
  struct weak {
    template<typename T1, typename T2> static constexpr bool c1 = requires(T1& x, T2& y) { static_cast<weak_ordering>(weak_order(x, y)); };
    template<typename T1, typename T2> static constexpr bool c2 = floating_point<decay_t<T1>>;
    template<typename T1, typename T2> static constexpr bool c3 = requires(T1& x, T2& y) { static_cast<weak_ordering>(compare_three_way{}(x, y)); };
    template<typename T1, typename T2> static constexpr bool c4 = strong::c1<T1, T2>;
    template<typename T1, typename T2> static constexpr auto cs = []() -> call_style {
      if constexpr (!same_as<decay_t<T1>, decay_t<T2>>) return {};
      else if constexpr (c1<T1, T2>) return {1, true, noexcept(static_cast<weak_ordering>(weak_order(declval<T1&>(), declval<T2&>())))};
      else if constexpr (c2<T1, T2>) return {2, true, true};
      else if constexpr (c3<T1, T2>) return {3, true, noexcept(static_cast<weak_ordering>(compare_three_way{}(declval<T1&>(), declval<T2&>())))};
      else if constexpr (c4<T1, T2>) return {4, true, noexcept(static_cast<strong_ordering>(strong_order(declval<T1&>(), declval<T2&>())))};
      else return {}; }();
    template<typename T1, typename T2> requires(cs<T1, T2>.able)
    constexpr weak_ordering operator()(T1&& x, T2&& y) const noexcept(cs<T1, T2>.nothrow) {
      if constexpr (cs<T1, T2>.style == 1) return static_cast<weak_ordering>(weak_order(x, y));
      else if constexpr (cs<T1, T2>.style == 2) {
        using it = conditional_t<sizeof(T1) == 4, int, long long>;
        using nt = conditional_t<sizeof(T1) == 4, unsigned int, unsigned long long>;
        constexpr nt digits = sizeof(T1) == 4 ? flt_mant_dig : (sizeof(T1) == 8 ? dbl_mant_dig : ldbl_mant_dig);
        constexpr nt sign_shift = bit_size<nt> - 1, sign_mask = nt{1} << sign_shift;
        constexpr nt inf_plus_one = _::bit_mask<nt>(digits - 1, sizeof(nt) - 1) + 1;
        auto x_0 = _::bit_cast<nt>(x), y_0 = _::bit_cast<nt>(y);
        if (x_0 == y_0) return weak_ordering::equivalent;
        const nt x_1 = x_0 & sign_mask, y_1 = y_0 & sign_mask;
        if ((x_0 & ~sign_mask) > inf_plus_one) x_0 = x_1 | inf_plus_one;
        if ((y_0 & ~sign_mask) > inf_plus_one) y_0 = y_1 | inf_plus_one;
        const nt x_2 = x_1 >> sign_shift, y_2 = y_1 >> sign_shift;
        return static_cast<weak_ordering>(static_cast<it>((x_0 ^ (x_1 - x_2)) + x_2) <=> static_cast<it>((y_0 ^ (y_1 - y_2)) + y_2));
      }
      else if constexpr (cs<T1, T2>.style == 3) return static_cast<weak_ordering>(compare_three_way{}(x, y));
      else if constexpr (cs<T1, T2>.style == 4) return static_cast<weak_ordering>(static_cast<strong_ordering>(strong_order(x, y)));
    }
  };
  struct partial {
    template<typename T1, typename T2> static constexpr bool c1 = requires(T1& x, T2& y) { static_cast<partial_ordering>(partial_order(x, y)); };
    template<typename T1, typename T2> static constexpr bool c2 = requires(T1& x, T2& y) { static_cast<partial_ordering>(compare_three_way{}(x, y)); };
    template<typename T1, typename T2> static constexpr bool c3 = weak::c1<T1, T2>;
    template<typename T1, typename T2> static constexpr bool c4 = strong::c1<T1, T2>;
    template<typename T1, typename T2> static constexpr auto cs = []() -> call_style {
      if constexpr (!same_as<decay_t<T1>, decay_t<T2>>) return {};
      else if constexpr (c1<T1, T2>) return {1, true, noexcept(static_cast<partial_ordering>(partial_order(declval<T1&>(), declval<T2&>())))};
      else if constexpr (c2<T1, T2>) return {2, true, noexcept(static_cast<partial_ordering>(compare_three_way{}(declval<T1&>(), declval<T2&>())))};
      else if constexpr (c3<T1, T2>) return {3, true, noexcept(static_cast<weak_ordering>(weak_order(declval<T1&>(), declval<T2&>())))};
      else if constexpr (c4<T1, T2>) return {4, true, noexcept(static_cast<strong_ordering>(strong_order(declval<T1&>(), declval<T2&>())))};
      else return {}; }();
    template<typename T1, typename T2> requires(cs<T1, T2>.able)
    constexpr partial_ordering operator()(T1&& x, T2&& y) const noexcept(cs<T1, T2>.nothrow) {
      if constexpr (cs<T1, T2>.style == 1) return static_cast<partial_ordering>(partial_order(x, y));
      else if constexpr (cs<T1, T2>.style == 2) return static_cast<partial_ordering>(compare_three_way{}(x, y));
      else if constexpr (cs<T1, T2>.style == 3) return static_cast<partial_ordering>(static_cast<weak_ordering>(weak_order(x, y)));
      else if constexpr (cs<T1, T2>.style == 4) return static_cast<partial_ordering>(static_cast<strong_ordering>(strong_order(x, y)));
    }
  };
}

inline namespace _cpo {
  inline constexpr _::_order::strong strong_order;
  inline constexpr _::_order::weak weak_order;
  inline constexpr _::_order::partial partial_order;
}

namespace _::_compare_fallback {
  template<typename T1, typename T2> concept can = requires(T1& x, T2& y) { { x == y && x < y } -> boolean_testable; };
  template<typename T1, typename T2> concept nt = requires(T1& x, T2& y) { { x == y && x < y } noexcept -> nt_boolean_testable; };
  struct strong {
    template<typename T1, typename T2> static constexpr auto cs = []() -> call_style {
      if constexpr (!same_as<decay_t<T1>, decay_t<T2>>) return {};
      else if constexpr (requires(T1& x, T2& y) { std::strong_order(x, y); }) return {1, true, noexcept(std::strong_order(declval<T1&>(), declval<T2&>()))};
      else if constexpr (can<T1, T2>) return {2, true, nt<T1, T2>};
      else return {}; }();
    template<typename T1, typename T2> requires(cs<T1&, T2&>.able)
    constexpr strong_ordering operator()(T1&& x, T2&& y) const noexcept(cs<T1&, T2&>.nothrow) {
      if constexpr (cs<T1&, T2&>.style == 1) return std::strong_order(x, y);
      else if constexpr (cs<T1&, T2&>.style == 2) return x == y ? strong_ordering::equal : (x < y ? strong_ordering::less : strong_ordering::greater);
    }
  };
  struct weak {
    template<typename T1, typename T2> static constexpr auto cs = []() -> call_style {
      if constexpr (!same_as<decay_t<T1>, decay_t<T2>>) return {};
      else if constexpr (requires(T1& x, T2& y) { std::weak_order(x, y); }) return {1, true, noexcept(std::weak_order(declval<T1&>(), declval<T2&>()))};
      else if constexpr (can<T1, T2>) return {2, true, nt<T1, T2>};
      else return {}; }();
    template<typename T1, typename T2> requires(cs<T1&, T2&>.able)
    constexpr weak_ordering operator()(T1&& x, T2&& y) const noexcept(cs<T1&, T2&>.nothrow) {
      if constexpr (cs<T1&, T2&>.style == 1) return std::weak_order(x, y);
      else if constexpr (cs<T1&, T2&>.style == 2) return x == y ? weak_ordering::equivalent : (x < y ? weak_ordering::less : weak_ordering::greater);
    }
  };
  struct partial {
    template<typename T1, typename T2> static constexpr auto cs = []() -> call_style {
      if constexpr (!same_as<decay_t<T1>, decay_t<T2>>) return {};
      else if constexpr (requires(T1& x, T2& y) { std::partial_order(x, y); }) return {1, true, noexcept(std::partial_order(declval<T1&>(), declval<T2&>()))};
      else if constexpr (can<T1, T2>) return {2, true, nt<T1, T2>};
      else return {}; }();
    template<typename T1, typename T2> requires(cs<T1&, T2&>.able)
    constexpr partial_ordering operator()(T1&& x, T2&& y) const noexcept(cs<T1&, T2&>.nothrow) {
      if constexpr (cs<T1&, T2&>.style == 1) return std::partial_order(x, y);
      else if constexpr (cs<T1&, T2&>.style == 2)
        return x == y ? partial_ordering::equivalent : (x < y ? partial_ordering::less : (y < x ? partial_ordering::greater : partial_ordering::unordered));
    }
  };
}

inline namespace _cpo {
  inline constexpr _::_compare_fallback::strong compare_strong_order_fallback;
  inline constexpr _::_compare_fallback::weak compare_weak_order_fallback;
  inline constexpr _::_compare_fallback::partial compare_partial_order_fallback;
}

}

#endif
