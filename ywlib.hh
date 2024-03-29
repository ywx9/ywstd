#pragma once

namespace yw {

using cat1 = char;
using cat2 = wchar_t;
using uct1 = char8_t;
using uct2 = char16_t;
using uct4 = char32_t;

using int1 = signed char;
using int2 = signed short;
using int4 = signed int;
using int8 = signed long long;
using intt = decltype((int*)0 - (int*)0);

using nat1 = unsigned char;
using nat2 = unsigned short;
using nat4 = unsigned int;
using nat8 = unsigned long long;
using natt = decltype(sizeof(int));

using fat4 = float;
using fat8 = double;

inline namespace literals {
constexpr auto operator""_c1(nat8 a) noexcept { return static_cast<cat1>(a); }
constexpr auto operator""_c2(nat8 a) noexcept { return static_cast<cat2>(a); }
constexpr auto operator""_u1(nat8 a) noexcept { return static_cast<uct1>(a); }
constexpr auto operator""_u2(nat8 a) noexcept { return static_cast<uct2>(a); }
constexpr auto operator""_u4(nat8 a) noexcept { return static_cast<uct4>(a); }
constexpr auto operator""_i1(nat8 a) noexcept { return static_cast<int1>(a); }
constexpr auto operator""_i2(nat8 a) noexcept { return static_cast<int2>(a); }
constexpr auto operator""_i4(nat8 a) noexcept { return static_cast<int4>(a); }
constexpr auto operator""_i8(nat8 a) noexcept { return static_cast<int8>(a); }
constexpr auto operator""_ii(nat8 a) noexcept { return static_cast<intt>(a); }
constexpr auto operator""_n1(nat8 a) noexcept { return static_cast<nat1>(a); }
constexpr auto operator""_n2(nat8 a) noexcept { return static_cast<nat2>(a); }
constexpr auto operator""_n4(nat8 a) noexcept { return static_cast<nat4>(a); }
constexpr auto operator""_n8(nat8 a) noexcept { return static_cast<nat8>(a); }
constexpr auto operator""_nn(nat8 a) noexcept { return static_cast<natt>(a); }
constexpr auto operator""_f4(nat8 a) noexcept { return static_cast<fat4>(a); }
constexpr auto operator""_f8(nat8 a) noexcept { return static_cast<fat8>(a); }
constexpr auto operator""_f4(long double a) noexcept { return static_cast<fat4>(a); }
constexpr auto operator""_f8(long double a) noexcept { return static_cast<fat8>(a); }
}

template<typename Ty> struct Type {
  using type = Ty;
};
template<typename Ty> using type = typename Type<Ty>::type;
template<typename... Ts> concept valid = (requires { typename type<Ts>; } && ...);
template<typename Ty, typename Uy> concept explicitly_convertible_to = requires(Ty (&f)()) { static_cast<Uy>(f()); };
template<typename Ty, typename Uy> concept explicitly_convertible_from = explicitly_convertible_to<Uy, Ty>;
template<auto Vx, explicitly_convertible_from<decltype(Vx)> Ty = decltype(Vx)> inline constexpr Ty cev = static_cast<Ty>(Vx);
template<auto Vx, explicitly_convertible_from<decltype(Vx)> Ty = decltype(Vx)> struct Constant : Type<Ty> {
  static constexpr Ty value = static_cast<Ty>(Vx);
};

namespace _ { // clang-format off
using _true = Constant<true>; using _false = Constant<false>;
template<typename T1, typename T2=T1, typename T3=T2, typename T4=T3, typename T5=T4, typename T6=T5>
struct _types { using t1 = T1; using t2 = T2; using t3 = T3; using t4 = T4; using t5 = T5; using t6 = T6; };
template<natt Nx> struct _make_type {};
template<> struct _make_type<1> { using c = cat1; using u = uct1; using i = int1; using n = nat1; };
template<> struct _make_type<2> { using c = cat2; using u = uct2; using i = int2; using n = nat2; };
template<> struct _make_type<4> { using u = uct4; using i = int4; using n = nat4; using f = fat4; };
template<> struct _make_type<8> { using i = int8; using n = nat8; using f = fat8; };
template<auto Ix, typename... Ts> struct _type_switch : _type_switch<cev<Ix, natt>, T0, Ts...> {};
template<bool Bx, typename... Ts> struct _type_switch<Bx, Ts...> {};
template<natt Ix, typename T0, typename... Ts> struct _type_switch<Ix, T0, Ts...> : _type_switch<Ix - 1, Ts...> {};
template<typename T0, typename... Ts> struct _type_switch<0_nn, T0, Ts...> : Type<T0> {};
template<typename T1, typename T2> struct _type_switch<false, T1, T2> : Type<T2> {};
template<typename T1, typename T2> struct _type_switch<true, T1, T2> : Type<T1> {};
template<natt Ix, typename T0, typename... Ts> inline constexpr auto _parameter_switch(T0&& x0, Ts&&... xs) noexcept {
  if  constexpr (Ix == 0) return static_cast<T0&&>(x0); else return _::_parameter_switch<Ix>(static_cast<Ts&&>(xs)...); }
template<typename Ty> struct _remove_cv : _types<Ty, Ty, Ty, _false, _false> {};
template<typename Ty> struct _remove_cv<const Ty> : _types<Ty, Ty,const Ty, _true, _false> {};
template<typename Ty> struct _remove_cv<volatile Ty> : _types<Ty, volatile Ty, Ty, _false, _true> {};
template<typename Ty> struct _remove_cv<const volatile Ty> : _types<Ty, volatile Ty, const Ty, _true, _true> {};
template<typename Ty> struct _remove_ref : _types<Ty, _false, _false> {};
template<typename Ty> struct _remove_ref<Ty&> : _types<Ty, _true, _false> {};
template<typename Ty> struct _remove_ref<Ty&&> : _types<Ty, _false, _true> {};
template<typename Ty> struct _remove_pointer : _types<Ty, Ty, _false> {};
template<typename Ty> struct _remove_pointer<Ty*> : _types<Ty, typename _remove_pointer<Ty>::t2, _true> {};
template<typename Ty> struct _remove_pointer<Ty* const> : _types<Ty, typename _remove_pointer<Ty>::t2, _true> {};
template<typename Ty> struct _remove_pointer<Ty* volatile> : _types<Ty, typename _remove_pointer<Ty>::t2, _true> {};
template<typename Ty> struct _remove_pointer<Ty* const volatile> : _types<Ty, typename _remove_pointer<Ty>::t2, _true> {};
template<typename Ty> struct _remove_extent : _types<Ty, Ty, _false, Constant<0_nn>> {};
template<typename Ty> struct _remove_extent<Ty[]> : _types<Ty, typename _remove_extent<Ty>::t2, _true, Constant<0_nn>> {};
template<typename Ty, natt Nx> struct _remove_extent<Ty[Nx]> : _types<Ty, typename _remove_extent<Ty>::t2, _false, Constant<Nx>> {};
template<typename Ty> struct _add_cv : _types<const volatile Ty, const Ty, volatile Ty> {};
template<typename Ty> struct _add_cv<Ty&> : _types<const volatile Ty&, const Ty&, volatile Ty&> {};
template<typename Ty> struct _add_cv<Ty&&> : _types<const volatile Ty&&, const Ty&&, volatile Ty&&> {};
template<typename Ty> struct _add_reference : _types<Ty, Ty, Ty> {};
template<typename Ty> struct _add_reference<Ty&> : _types<Ty&, Ty&&, Ty&> {};
template<typename Ty> requires valid<type<Ty&>> struct _add_reference<Ty> : _types<Ty&, Ty&&, Ty&&> {};
template<typename Ty> struct _add_pointer : _types<Ty> {};
template<typename Ty> requires valid<type<Ty*>> struct _add_pointer<Ty> : _types<Ty*> {};
template<typename Ty> requires valid<type<Ty*>> struct _add_pointer<Ty&> : _types<Ty*&> {};
template<typename Ty> requires valid<type<Ty*>> struct _add_pointer<Ty&&> : _types<Ty*&&> {};
template<typename Ty, natt Nx> struct _add_extent : _types<Ty> {};
template<typename Ty, natt Nx> struct _add_extent<Ty&, Nx> : _types<typename _add_extent<Ty, Nx>::t1&> {};
template<typename Ty, natt Nx> struct _add_extent<Ty&&, Nx> : _types<typename _add_extent<Ty, Nx>::t1&&> {};
template<typename Ty, natt Nx> requires valid<type<Ty[Nx]>> struct _add_extent<Ty, Nx> : _types<Ty[Nx]> {};
template<typename Ty> requires valid<type<Ty[]>> struct _add_extent<Ty, 0> : _types<Ty[]> {};
template<typename Ty> struct _class_type : _types<void, void, _false> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::*> : _types<Uy, Ty, _true> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::* const> : _types<Uy, Ty, _true> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::* volatile> : _types<Uy, Ty, _true> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::* const volatile> : _types<Uy, Ty, _true> {};
template<typename Ty, typename Uy> struct _is_same : _false {};
template<typename Ty> struct _is_same<Ty, Ty> : _true {};
template<typename Ty, typename Uy> concept _same_as = _is_same<Ty, Uy>::value;
} // clang-format on

template<typename Ty> using make_cat = typename _::_make_type<sizeof(Ty)>::c;
template<typename Ty> using make_uct = typename _::_make_type<sizeof(Ty)>::u;
template<typename Ty> using make_int = typename _::_make_type<sizeof(Ty)>::i;
template<typename Ty> using make_nat = typename _::_make_type<sizeof(Ty)>::n;
template<typename Ty> using make_fat = typename _::_make_type<sizeof(Ty)>::f;

template<explicitly_convertible_to<natt> auto Ix, typename... Ts>
using type_switch = typename _::_type_switch<Ix, Ts...>::type;

template<explicitly_convertible_to<natt> auto Ix, auto... Vs>
inline constexpr auto value_switch = type_switch<Ix, Constant<Vs>...>::value;

template<explicitly_convertible_to<natt> auto Ix>
inline constexpr auto parameter_switch = []<typename... Ts>(Ts&&... xs) noexcept {
  if constexpr (sizeof...(Ts) == 0) return none;
  else return _::_parameter_switch<csv<Ix, natt>>(static_cast<Ts&&>(xs)...);
};

template<typename Ty> using remove_cv = typename _::_remove_cv<Ty>::t1;
template<typename Ty> using remove_const = typename _::_remove_cv<Ty>::t2;
template<typename Ty> using remove_volatile = typename _::_remove_cv<Ty>::t3;
template<typename Ty> concept is_const = _::_remove_cv<Ty>::t4::value;
template<typename Ty> concept is_volatile = _::_remove_cv<Ty>::t5::value;
template<typename Ty> concept is_const_volatile = is_const<Ty> && is_volatile<Ty>;
template<typename Ty> using add_cv = typename _::_add_cv<Ty>::t1;
template<typename Ty> using add_const = typename _::_add_cv<Ty>::t2;
template<typename Ty> using add_volatile = typename _::_add_cv<Ty>::t3;

template<typename Ty> using remove_ref = typename _::_remove_ref<Ty>::t1;
template<typename Ty> using remove_cvref = remove_cv<remove_ref<Ty>>;
template<typename Ty> concept is_lvref = _::_remove_ref<Ty>::t2::value;
template<typename Ty> concept is_rvref = _::_remove_ref<Ty>::t3::value;
template<typename Ty> concept is_reference = is_lvref<Ty> || is_rvref<Ty>;
template<typename Ty> using add_lvref = typename _::_add_reference<Ty>::t1;
template<typename Ty> using add_rvref = typename _::_add_reference<Ty>::t2;
template<typename Ty> using add_fwref = typename _::_add_reference<Ty>::t3;

template<typename Ty> using remove_pointer = typename _::_remove_pointer<Ty>::t1;
template<typename Ty> using remove_all_pointers = typename _::_remove_pointer<Ty>::t2;
template<typename Ty> concept is_pointer = _::_remove_pointer<Ty>::t3::value;
template<typename Ty> using add_pointer = typename _::_add_pointer<Ty>::t1;

template<typename Ty> using remove_extent = typename _::_remove_extent<Ty>::t1;
template<typename Ty> using remove_all_extents = typename _::_remove_extent<Ty>::t2;
template<typename Ty> concept is_bounded_array = _::_remove_extent<Ty>::t4::value != 0;
template<typename Ty> concept is_unbounded_array = _::_remove_extent<Ty>::t3::value;
template<typename Ty> concept is_array = is_bounded_array<Ty> || is_unbounded_array<Ty>;
template<typename Ty, natt Nx> using add_extent = typename _::_add_extent<Ty, Nx>::t1;

template<typename Ty> concept is_function = !is_const<const Ty> && !is_reference<Ty>;
template<typename Ty> concept is_class = __is_class(Ty);
template<typename Ty> concept is_union = __is_union(Ty);
template<typename Ty> concept is_enum = __is_enum(Ty);

template<typename Ty> concept is_member_pointer = is_pointer<Ty> && _::_class_type<Ty>::t3::value;
template<is_member_pointer Ty> using class_type = typename _::_class_type<Ty>::t1;
template<is_member_pointer Ty> using member_type = typename _::_class_type<Ty>::t2;
template<typename Ty> concept is_member_function_pointer = is_member_pointer<Ty> && is_function<member_type<Ty>>;
template<typename Ty> concept is_member_object_pointer = is_member_pointer<Ty> && !is_member_function_pointer<Ty>;

template<typename Ty, typename Uy> concept same_as = _::_same_as<Ty, Uy> && _::_same_as<Uy, Ty>;
template<typename Ty, typename Uy> concept convertible_to = __is_convertible_to(Ty, Uy) && requires(Ty (&f)()) { static_cast<Uy>(f()); };
template<typename Ty, typename Uy> concept base_of = __is_base_of(Ty, Uy);
template<typename Ty, typename Uy> concept derived_from = base_of<Uy, Ty> && convertible_to<add_cv<Ty*>, add_cv<Uy*>>;

namespace _ { // clang-format off
template<typename Ty, typename Uy> struct _copy_cv : _types<Uy, Uy, Uy> {};
template<typename Ty, typename Uy> requires is_const_volatile<remove_ref<Ty>>
struct _copy_cv<Ty, Uy> : _types<add_cv<Uy>, add_const<Uy>, add_volatile<Uy>> {};
template<typename Ty, typename Uy> requires is_const<remove_ref<Ty>> struct _copy_cv<Ty, Uy>
} // clang-format on
}
