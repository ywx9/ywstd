// ywstd/@/add_const.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "_.hh"
#include "type_identity.hh"

namespace std {

template<typename Ty> struct add_cv : type_identity<_::add_cv_t<Ty>> {};
template<typename Ty> struct add_const : type_identity<_::add_const_t<Ty>> {};
template<typename Ty> struct add_volatile : type_identity<_::add_volatile_t<Ty>> {};
template<typename Ty> struct add_lvalue_reference : type_identity<_::add_lvalue_reference_t<Ty>> {};
template<typename Ty> struct add_rvalue_reference : type_identity<_::add_rvalue_reference_t<Ty>> {};
template<typename Ty> struct add_pointer : type_identity<_::add_pointer_t<Ty>> {};

template<typename Ty> using add_cv_t = typename add_cv<Ty>::type;
template<typename Ty> using add_const_t = typename add_const<Ty>::type;
template<typename Ty> using add_volatile_t = typename add_volatile<Ty>::type;
template<typename Ty> using add_lvalue_reference_t = typename add_lvalue_reference<Ty>::type;
template<typename Ty> using add_rvalue_reference_t = typename add_rvalue_reference<Ty>::type;
template<typename Ty> using add_pointer_t = typename add_pointer<Ty>::type;

template<typename Ty> struct remove_cv : type_identity<_::remove_cv_t<Ty>> {};
template<typename Ty> struct remove_const : type_identity<_::remove_const_t<Ty>> {};
template<typename Ty> struct remove_volatile : type_identity<_::remove_volatile_t<Ty>> {};
template<typename Ty> struct remove_reference : type_identity<_::remove_reference_t<Ty>> {};
template<typename Ty> struct remove_cvref : type_identity<_::remove_cvref_t<Ty>> {};
template<typename Ty> struct remove_pointer : type_identity<_::remove_pointer_t<Ty>> {};
template<typename Ty> struct remove_extent : type_identity<_::remove_extent_t<Ty>> {};
template<typename Ty> struct remove_all_extents : type_identity<_::remove_all_extents_t<Ty>> {};

template<typename Ty> using remove_cv_t = typename remove_cv<Ty>::type;
template<typename Ty> using remove_const_t = typename remove_const<Ty>::type;
template<typename Ty> using remove_volatile_t = typename remove_volatile<Ty>::type;
template<typename Ty> using remove_reference_t = typename remove_reference<Ty>::type;
template<typename Ty> using remove_cvref_t = typename remove_cvref<Ty>::type;
template<typename Ty> using remove_pointer_t = typename remove_pointer<Ty>::type;
template<typename Ty> using remove_extent_t = typename remove_extent<Ty>::type;
template<typename Ty> using remove_all_extents_t = typename remove_all_extents<Ty>::type;

template<typename Ty> struct decay : type_identity<_::decay_t<Ty>> {};
template<typename Ty> using decay_t = typename decay<Ty>::type;

}
