// ywstd/cfloat.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <cfloat>
#else

#include "@/_.hh"

#define FLT_ROUNDS 0
#define FLT_EVAL_METHOD -1
#define FLT_HAS_SUBNORM std::_::flt_has_subnorm
#define DBL_HAS_SUBNORM std::_::dbl_has_subnorm
#define LDBL_HAS_SUBNORM std::_::ldbl_has_subnorm
#define FLT_RADIX std::_::flt_radix
#define FLT_MANT_DIG std::_::flt_mant_dig
#define DBL_MANT_DIG std::_::dbl_mant_dig
#define LDBL_MANT_DIG std::_::ldbl_mant_dig
#define FLT_DECIMAL_DIG std::_::flt_decimal_dig
#define DBL_DECIMAL_DIG std::_::dbl_decimal_dig
#define LDBL_DECIMAL_DIG std::_::ldbl_decimal_dig
#define DECIMAL_DIG std::_::decimal_dig
#define FLT_DIG std::_::flt_dig
#define DBL_DIG std::_::dbl_dig
#define LDBL_DIG std::_::ldbl_dig
#define FLT_MIN_EXP std::_::flt_min_exp
#define DBL_MIN_EXP std::_::dbl_min_exp
#define LDBL_MIN_EXP std::_::ldbl_min_exp
#define FLT_MIN_10_EXP std::_::flt_min_10_exp
#define DBL_MIN_10_EXP std::_::dbl_min_10_exp
#define LDBL_MIN_10_EXP std::_::ldbl_min_10_exp
#define FLT_MAX_EXP std::_::flt_max_exp
#define DBL_MAX_EXP std::_::dbl_max_exp
#define LDBL_MAX_EXP std::_::ldbl_max_exp
#define FLT_MAX_10_EXP std::_::flt_max_10_exp
#define DBL_MAX_10_EXP std::_::dbl_max_10_exp
#define LDBL_MAX_10_EXP std::_::ldbl_max_10_exp
#define FLT_MAX std::_::flt_max
#define DBL_MAX std::_::dbl_max
#define LDBL_MAX std::_::ldbl_max
#define FLT_EPSILON std::_::flt_epsilon
#define DBL_EPSILON std::_::dbl_epsilon
#define LDBL_EPSILON std::_::ldbl_epsilon
#define FLT_MIN std::_::flt_min
#define DBL_MIN std::_::dbl_min
#define LDBL_MIN std::_::ldbl_min
#define FLT_TRUE_MIN std::_::flt_true_min
#define DBL_TRUE_MIN std::_::dbl_true_min
#define LDBL_TRUE_MIN std::_::ldbl_true_min

#endif
