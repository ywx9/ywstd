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
template<typename Ty> struct _class_type : _types<void, void, _false> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::*> : _types<Uy, Ty, _true> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::* const> : _types<Uy, Ty, _true> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::* volatile> : _types<Uy, Ty, _true> {};
template<typename Ty, typename Uy> struct _class_type<Ty Uy::* const volatile> : _types<Uy, Ty, _true> {};
} // clang-format on

template<typename Ty> using make_cat = typename _::_make_type<sizeof(Ty)>::c;
template<typename Ty> using make_uct = typename _::_make_type<sizeof(Ty)>::u;
template<typename Ty> using make_int = typename _::_make_type<sizeof(Ty)>::i;
template<typename Ty> using make_nat = typename _::_make_type<sizeof(Ty)>::n;
template<typename Ty> using make_fat = typename _::_make_type<sizeof(Ty)>::f;

template<typename Ty> using remove_cv = typename _::_remove_cv<Ty>::t1;
template<typename Ty> using remove_const = typename _::_remove_cv<Ty>::t2;
template<typename Ty> using remove_volatile = typename _::_remove_cv<Ty>::t3;
template<typename Ty> concept is_const = _::_remove_cv<Ty>::t4::value;
template<typename Ty> concept is_volatile = _::_remove_cv<Ty>::t5::value;

template<typename Ty> using remove_ref = typename _::_remove_ref<Ty>::t1;
template<typename Ty> using remove_cvref = remove_cv<remove_ref<Ty>>;
template<typename Ty> concept is_lvref = _::_remove_ref<Ty>::t2::value;
template<typename Ty> concept is_rvref = _::_remove_ref<Ty>::t3::value;
template<typename Ty> concept is_reference = is_lvref<Ty> || is_rvref<Ty>;

template<typename Ty> using remove_pointer = typename _::_remove_pointer<Ty>::t1;
template<typename Ty> using remove_all_pointers = typename _::_remove_pointer<Ty>::t2;
template<typename Ty> concept is_pointer = _::_remove_pointer<Ty>::t3::value;

template<typename Ty> using remove_extent = typename _::_remove_extent<Ty>::t1;
template<typename Ty> using remove_all_extents = typename _::_remove_extent<Ty>::t2;
template<typename Ty> concept is_bounded_array = _::_remove_extent<Ty>::t4::value != 0;
template<typename Ty> concept is_unbounded_array = _::_remove_extent<Ty>::t3::value;
template<typename Ty> concept is_array = is_bounded_array<Ty> || is_unbounded_array<Ty>;

template<typename Ty> concept is_function = !is_const<const Ty> && !is_reference<Ty>;
template<typename Ty> concept is_class = __is_class(Ty);
template<typename Ty> concept is_union = __is_union(Ty);
template<typename Ty> concept is_enum = __is_enum(Ty);

template<typename Ty> concept is_memptr = is_pointer<Ty> && _::_class_type<Ty>::t3::value;
template<is_memptr Ty> using class_type = typename _::_class_type<Ty>::t1;
template<is_memptr Ty> using member_type = typename _::_class_type<Ty>::t2;
template<typename Ty> concept is_memptr_function = is_memptr<Ty> && is_function<member_type<Ty>>;
template<typename Ty> concept is_memptr_object = is_memptr<Ty> && !is_memptr_function<Ty>;

namespace _ { // clang-format off
} // clang-format on
}
