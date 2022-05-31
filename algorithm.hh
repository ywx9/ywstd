// ywstd/algorithm.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <algorithm>
#else

#include "@/../initializer_list.hh"
#include "@/../iterator.hh"
#include "@/../random.hh"
#include "@/../ranges.hh"
#include "@/ranges-equal_to.hh"
#include "@/ranges-in_out_result.hh"
#include "@/swap.hh"

//==============================================================================
// algorithm functions

namespace std {

//==============================================================================
// non-modifying sequence operations

template<typename InpIt, typename Ty> constexpr InpIt find(InpIt i, InpIt s, const Ty& v) { for (; i != s; ++i) if (*i == v) return i; return s; }
template<_::execution_policy Ex, typename FwdIt, typename Ty> FwdIt find(Ex&&, FwdIt i, FwdIt s, const Ty& v);

template<typename InpIt, typename Fn> constexpr InpIt find_if(InpIt i, InpIt s, Fn f) { for (; i != s; ++i) if (f(*i)) return i; return s; }
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt find_if(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr InpIt find_if_not(InpIt i, InpIt s, Fn f) { for (; i != s; ++i) if (!f(*i)) return i; return s; }
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt find_if_not(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr bool all_of(InpIt i, InpIt s, Fn f) { return std::find_if_not(i, s, f) == s; }
template<_::execution_policy Ex, typename FwdIt, typename Fn> bool all_of(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr bool any_of(InpIt i, InpIt s, Fn f) { return std::find_if(i, s, f) != s; }
template<_::execution_policy Ex, typename FwdIt, typename Fn> bool any_of(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr bool none_of(InpIt i, InpIt s, Fn f) { return std::find_if(i, s, f) == s; }
template<_::execution_policy Ex, typename FwdIt, typename Fn> bool none_of(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr Fn for_each(InpIt i, InpIt s, Fn f) { for (; i != s; ++i) f(*i); return f; }
template<_::execution_policy Ex, typename FwdIt, typename Fn> void for_each(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Size, typename Fn> constexpr InpIt for_each_n(InpIt i, Size n, Fn f) { for (; n != 0; ++i, --n) f(*i); return i; }
template<_::execution_policy Ex, typename FwdIt, typename Size, typename Fn> FwdIt for_each_n(Ex&&, FwdIt i, Size n, Fn f);

template<typename InpIt, typename Ty> constexpr typename iterator_traits<InpIt>::difference_type count(InpIt i, InpIt s, const Ty& v) {
  for (typename iterator_traits<InpIt>::difference_type n = 0;; ++i) { if (i == s) return n; if (*i == v) ++n; } }
template<typename InpIt, typename Fn> constexpr typename iterator_traits<InpIt>::difference_type count_if(InpIt i, InpIt s, Fn f) {
  for (typename iterator_traits<InpIt>::difference_type n = 0;; ++i) { if (i == s) return n; if (f(*i)) ++n; } }
template<_::execution_policy Ex,typename FwdIt,typename Ty> typename iterator_traits<FwdIt>::difference_type count(Ex&&,FwdIt i,FwdIt s,const Ty& v);
template<_::execution_policy Ex, typename FwdIt, typename Fn> typename iterator_traits<FwdIt>::difference_type count_if(Ex&&, FwdIt i,FwdIt s,Fn f);

template<typename InpI1, typename InpI2> constexpr pair<InpI1, InpI2> mismatch(InpI1 i1, InpI1 s1, InpI2 i2) {
  for (;; ++i1, ++i2) if (i1 == s1 || *i1 == *i2) return {_::move(i1), _::move(i2)}; }
template<typename InpI1, typename InpI2, typename Fn> constexpr pair<InpI1, InpI2> mismatch(InpI1 i1, InpI1 s1, InpI2 i2, Fn f) {
  for (;; ++i1, ++i2) if (i1 == s1 || f(*i1, *i2)) return {_::move(i1), _::move(i2)}; }
template<typename InpI1, typename InpI2> constexpr pair<InpI1, InpI2> mismatch(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2) {
  for (;; ++i1, ++i2) if (i1 == s1 || i2 == s2 || *i1 == *i2) return {_::move(i1), _::move(i2)}; }
template<typename InpI1, typename InpI2, typename Fn> constexpr pair<InpI1, InpI2> mismatch(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, Fn f) {
  for (;; ++i1, ++i2) if (i1 == s1 || i2 == s2 || f(*i1, *i2)) return {_::move(i1), _::move(i2)}; }
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> pair<FwdI1, FwdI2> mismatch(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> pair<FwdI1, FwdI2> mismatch(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> pair<FwdI1, FwdI2> mismatch(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<_::execution_policy Ex,typename FwdI1,typename FwdI2,typename Fn>pair<FwdI1,FwdI2> mismatch(Ex&&,FwdI1 i1,FwdI1 s1,FwdI2 i2,FwdI2 s2,Fn f);

template<typename FwdI1, typename FwdI2> constexpr FwdI1 search(FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2) {
  for (auto j = i1;; j = i1++) for (auto k = i2;; ++j, ++k) { if (k == s2) return i1; if (j == s1) return s1; if (*j != *k) break; } }
template<typename FwdI1, typename FwdI2, typename Fn> constexpr FwdI1 search(FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f) {
  for (auto j = i1;; j = i1++) for (auto k = i2;; ++j, ++k) { if (k == s2) return i1; if (j == s1) return s1; if (!f(*j, *k)) break; } }
template<typename FwdIt, typename Fn> constexpr FwdIt search(FwdIt i, FwdIt s, const Fn& f) { return f(i, s).first; }
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI1 search(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> FwdI1 search(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f);

template<typename FwdI1, typename FwdI2> constexpr FwdI1 find_end(FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2) {
  if (i2 == s2) return s1; for (FwdI1 j = s1, k;; j = k, i1 = j, ++i1) { k = std::search(i1, s1, i2, s2); if (k == s1) return j; } }
template<typename FwdI1, typename FwdI2, typename Fn> constexpr FwdI1 find_end(FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f) {
  if (i2 == s2) return s1; for (FwdI1 j = s1, k;; j = k, i1 = j, ++i1) { k = std::search(i1, s1, i2, s2, f); if (k == s1) return j; } }
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI1 find_end(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> FwdI1 find_end(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f);

template<typename InpIt, typename FwdIt> constexpr InpIt find_first_of(InpIt i1, InpIt s1, FwdIt i2, FwdIt s2);
template<typename InpIt, typename FwdIt, typename Fn> constexpr InpIt find_first_of(InpIt i1, InpIt s1, FwdIt i2, FwdIt s2, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI1 find_first_of(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> FwdI1 find_first_of(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f);

template<typename FwdIt> constexpr FwdIt adjacent_find(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr FwdIt adjacent_find(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt> FwdIt adjacent_find(Ex&&, FwdIt i, FwdIt s);
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt adjacent_find(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename FwdIt, typename Size, typename Ty> constexpr FwdIt search_n(FwdIt i, FwdIt s, Size n, const Ty& v) {
  if (n <= 0) return i;
  for (auto j = i; i != s; j = i++) { if (*i != v) continue; for (Size m = 1;; ++m) { if (m == n) return j; if (++i == s) return s; if (*i != v) break; } }
  return s; }
template<typename FwdIt, typename Size, typename Ty, typename Fn> constexpr FwdIt search_n(FwdIt i, FwdIt s, Size n, const Ty& v, Fn f) {
  if (n <= 0) return i;
  for (auto j = i; i != s; j = i++) { if (!f(*i, v)) continue; for (Size m = 1;; ++m) { if (m == n) return j; if (++i == s) return s; if (!f(i, v)) break; } }
  return s; }
template<_::execution_policy Ex, typename FwdIt, typename Size, typename Ty> FwdIt search_n(Ex&&, FwdIt i, FwdIt s, Size n, const Ty& v);
template<_::execution_policy Ex, typename FwdIt, typename Size, typename Ty, typename Fn> FwdIt search_n(Ex&&, FwdIt i, FwdIt s, Size n, const Ty& v, Fn f);

//==============================================================================
// modifying sequence operations

template<typename InpIt, typename OutIt> constexpr OutIt copy(InpIt i, InpIt s, OutIt o) { for (;; *o++ = *i, ++i) if (i == s) return o; }
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI2 copy(Ex&&, FwdI1 i, FwdI1 s, FwdI2 o);

template<typename InpIt, typename Size, typename OutIt> constexpr OutIt copy_n(InpIt i, Size n, OutIt o) { for (;; *o++ = *i, ++i) if (0 >= n--) return o; }
template<_::execution_policy Ex, typename FwdI1, typename Size, typename FwdI2> FwdI2 copy_n(Ex&&, FwdI1 i, Size n, FwdI2 o);

template<typename InpIt, typename OutIt, typename Fn> constexpr OutIt copy_if(InpIt i, InpIt s, OutIt o, Fn f) { for (; i != s; ++i)if(f(*i))*o++ =*i;return o;}
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> FwdI2 copy_if(Ex&&, FwdI1 i, FwdI1 s, FwdI2 o, Fn f);

template<typename BidIt1, typename BidIt2> constexpr BidIt2 copy_backward(BidIt1 i, BidIt1 s, BidIt2 o) { for (;; *--o = *--s) if (i == s) return o; }

template<typename InpIt, typename OutIt> constexpr OutIt move(InpIt i, InpIt s, OutIt o) { for (;; *o++ = _::move(*i), ++i) if (i == s) return o; }
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI2 move(Ex&&, FwdI1 i, FwdI1 s, FwdI2 o);

template<typename BidIt1, typename BidIt2> constexpr BidIt2 move_backward(BidIt1 i, BidIt1 s, BidIt2 o) { for (;; *--o = _::move(*--s)) if (i == s) return o; }

template<typename FwdIt, typename Ty> constexpr void fill(FwdIt i, FwdIt s, const Ty& v) { for (; i != s;) *i++ = v; }
template<_::execution_policy Ex, typename FwdIt, typename Ty> void fill(Ex&&, FwdIt i, FwdIt s, const Ty& v);

template<typename OutIt, typename Size, typename Ty> constexpr OutIt fill_n(OutIt i, Size n, const Ty& v) { for (; 0 < n--; ++i) *i = v; }
template<_::execution_policy Ex, typename FwdIt, typename Size, typename Ty> FwdIt fill_n(Ex&&, FwdIt i, Size n, const Ty& v);

template<typename InpIt, typename OutIt, typename Fn> constexpr OutIt transform(InpIt i, InpIt s, OutIt o, Fn f) { for (;; *o++ = f(*i), ++i) if(i==s)return o;}
template<typename InpI1, typename InpI2, typename OutIt, typename Fn> constexpr OutIt transform(InpI1 i1, InpI1 s1, InpI2 i2, OutIt o, Fn f) {
  for (;; *o++ = f(*i1, *i2), ++i1, ++i2) if (i1 == s1) return o; }
template<_::execution_policy Ex, typename FwdIt, typename FwdOt, typename Fn> FwdIt transform(Ex&&, FwdIt i, FwdIt s, FwdOt o, Fn f);
template<_::execution_policy Ex,typename FwdI1,typename FwdI2,typename FwdOt,typename Fn>FwdOt transform(Ex&&,FwdI1 i1,FwdI1 s1,FwdI2 i2,FwdOt o,Fn f);

template<typename FwdIt, typename Fn> constexpr void generate(FwdIt i, FwdIt s, Fn f) { for (; i != s;) *i++ = f(); }
template<_::execution_policy Ex, typename FwdIt, typename Fn> void generate(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename OutIt, typename Size, typename Fn> constexpr OutIt generate_n(OutIt o, Size n, Fn f) { while (0 < n--) *o++ = f(); }
template<_::execution_policy Ex, typename FwdIt, typename Size, typename Fn> FwdIt generate_n(Ex&&, FwdIt i, Size n, Fn f);

template<typename FwdIt, typename Ty> constexpr FwdIt remove(FwdIt i, FwdIt s, const Ty& v) {
  i = std::find(i, s, v); if (i != s) for (auto j = i; ++j != s;) if (*j != v) *i++ = _::move(*j); return i; }
template<_::execution_policy Ex, typename FwdIt, typename Ty> FwdIt remove(Ex&&, FwdIt i, FwdIt s, const Ty& v);

template<typename FwdIt, typename Fn> constexpr FwdIt remove_if(FwdIt i, FwdIt s, Fn f) {
  i = std::find(i, s, f); if (i != s) for (auto j = i; ++j != s;) if (!f(*j)) *i++ = _::move(*j); return i; }
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt remove_if(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename OutIt,typename Ty> constexpr OutIt remove_copy(InpIt i,InpIt s,OutIt o,const Ty& v){for(;i!=s;++i)if(*i!=v)*o++ =*i;return o;}
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Ty> FwdI2 remove_copy(Ex&&, FwdI1 i, FwdI1 s, FwdI2 o, const Ty& v);

template<typename InpIt, typename OutIt, typename Fn> constexpr OutIt remove_copy_if(InpIt i, InpIt s, OutIt o,Fn f){for(;i!=s;++i)if(!f(*i))*o++ =*i;return o;}
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> FwdI2 remove_copy_if(Ex&&, FwdI1 i, FwdI1 s, FwdI2 o, Fn f);

template<typename FwdIt, typename Ty> constexpr void replace(FwdIt i, FwdIt s, const Ty& Old, const Ty& New) { for (; i != s; ++i) if (*i == Old) *i = New; }
template<_::execution_policy Ex, typename FwdIt, typename Ty> void replace(Ex&&, FwdIt i, FwdIt s, const Ty& Old, const Ty& New);

template<typename FwdIt, typename Fn, typename Ty> constexpr void replace_if(FwdIt i, FwdIt s, Fn f, const Ty& New) { for (; i != s; ++i) if (f(*i)) *i = New; }
template<_::execution_policy Ex, typename FwdIt, typename Fn, typename Ty> void replace_if(Ex&&, FwdIt i, FwdIt s, Fn f, const Ty& New);

template<typename InpIt, typename OutIt, typename Ty> constexpr OutIt replace_copy(InpIt i, InpIt s, OutIt o, const Ty& Old, const Ty& New) {
  for (;; *o++ = (*i == Old) ? New : *i, ++i) if (i == s) return o; }
template<_::execution_policy Ex, typename FwdI1,typename FwdOt,typename Ty>FwdOt replace_copy(Ex&&, FwdI1 i,FwdI1 s,FwdOt o,const Ty& Old,const Ty& New);

template<typename InpIt, typename OutIt, typename Fn, typename Ty> constexpr OutIt replace_copy_if(InpIt i, InpIt s, OutIt o, Fn f, const Ty& New) {
  for (;; *o++ = (f(*i)) ? New : *i, ++i) if (i == s) return o; }
template<_::execution_policy Ex, typename FwdI1, typename FwdOt, typename Fn, typename Ty> FwdOt replace_copy_if(Ex&&, FwdI1, FwdI1,FwdOt, Fn,const Ty&);

template<typename FwdI1, typename FwdI2> constexpr void iter_swap(FwdI1 i1, FwdI2 i2) { using std::swap; swap(*i1, *i2); }
template<typename FwdI1, typename FwdI2> constexpr FwdI2 swap_ranges(FwdI1 i1, FwdI1 s1, FwdI2 i2) { for(;;std::iter_swap(i1++,i2++))if(i1==s1)return i2;}
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI2 swap_ranges(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2);

template<typename BidIt> constexpr void reverse(BidIt i, BidIt s) {
  if constexpr (is_base_of_v<random_access_iterator_tag, _::iter_category_t<BidIt>>) { if (i == s) return; for (--s; i < s; ++i, --s) std::iter_swap(i, s); }
  else for (; i != s && i != --s;) std::iter_swap(i++, s); }
template<_::execution_policy Ex, typename BidIt> void reverse(Ex&&, BidIt i, BidIt s);

template<typename BidIt, typename OutIt> constexpr OutIt reverse_copy(BidIt i, BidIt s, OutIt o) { for(;; *o++ = *--s) if (i == s) return o; }
template<_::execution_policy Ex, typename BidIt, typename FwdIt> FwdIt reverse_copy(Ex&&, BidIt i, BidIt s, FwdIt o);

template<typename FwdIt> constexpr FwdIt rotate(FwdIt i, FwdIt middle, FwdIt s);
template<_::execution_policy Ex, typename FwdIt> FwdIt rotate(Ex&&, FwdIt i, FwdIt middle, FwdIt s);

template<typename FwdIt, typename OutIt> constexpr OutIt rotate_copy(FwdIt i, FwdIt middle, FwdIt s, OutIt o);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI2 rotate_copy(Ex&&, FwdI1 i, FwdI1 middle, FwdI1 s, FwdI2 o);

template<typename FwdIt> constexpr FwdIt shift_left(FwdIt i, FwdIt s, typename iterator_traits<FwdIt>::difference_type n);
template<_::execution_policy Ex, typename FwdIt> FwdIt shift_left(Ex&&, FwdIt i, FwdIt s, typename iterator_traits<FwdIt>::difference_type n);

template<typename FwdIt> constexpr FwdIt shift_right(FwdIt i, FwdIt s, typename iterator_traits<FwdIt>::difference_type n);
template<_::execution_policy Ex, typename FwdIt> FwdIt shift_right(Ex&&, FwdIt i, FwdIt s, typename iterator_traits<FwdIt>::difference_type n);

template<typename RndIt, typename Fn> void shuffle(RndIt i, RndIt s, Fn&& g);
template<typename InpIt, typename OutIt, typename Size, typename Fn> OutIt sample(InpIt i, InpIt s, OutIt out, Size n, Fn&& g);

template<typename FwdIt> constexpr FwdIt unique(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr FwdIt unique(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt> FwdIt unique(Ex&&, FwdIt i, FwdIt s);
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt unique(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename OutIt> constexpr OutIt unique_copy(InpIt i, InpIt s, OutIt o);
template<typename InpIt, typename OutIt, typename Fn> constexpr OutIt unique_copy(InpIt i, InpIt s, OutIt o, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> FwdI2 unique_copy(Ex&&, FwdI1 i, FwdI1 s, FwdI2 o);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> FwdI2 unique_copy(Ex&&, FwdI1 i, FwdI1 s, FwdI2 o, Fn f);

//==============================================================================
// partitioning operations

template<typename InpIt, typename Fn> constexpr bool is_partitioned(InpIt i, InpIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt, typename Fn> bool is_partitioned(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename FwdIt, typename Fn> constexpr FwdIt partition(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt partition(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename OutIt1, typename OutIt2, typename Fn> constexpr pair<OutIt1, OutIt2> partition_copy(InpIt i,InpIt s,OutIt1 o1,OutIt2 o2,Fn f);
template<_::execution_policy Ex, typename FwdIt, typename FwdOt1, typename FwdOt2, typename Fn>
pair<FwdOt1, FwdOt2> partition_copy(Ex&&, FwdIt, FwdIt, FwdOt1, FwdOt2, Fn);

template<typename BidIt, typename Fn> BidIt stable_partition(BidIt i, BidIt s, Fn f);
template<_::execution_policy Ex, typename BidIt, typename Fn> BidIt stable_partition(Ex&&, BidIt i, BidIt s, Fn f);

template<typename FwdIt, typename Fn> constexpr FwdIt partition_point(FwdIt i, FwdIt s, Fn f);

//==============================================================================
// sorting operations

template<typename FwdIt> constexpr bool is_sorted(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr bool is_sorted(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt> bool is_sorted(Ex&&, FwdIt i, FwdIt s);
template<_::execution_policy Ex, typename FwdIt, typename Fn> bool is_sorted(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename FwdIt> constexpr FwdIt is_sorted_until(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr FwdIt is_sorted_until(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt> FwdIt is_sorted_until(Ex&&, FwdIt i, FwdIt s);
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt is_sorted_until(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename RndIt> constexpr void sort(RndIt i, RndIt s);
template<typename RndIt, typename Fn> constexpr void sort(RndIt i, RndIt s, Fn f);
template<_::execution_policy Ex, typename RndIt> void sort(Ex&&, RndIt i, RndIt s);
template<_::execution_policy Ex, typename RndIt, typename Fn> void sort(Ex&&, RndIt i, RndIt s, Fn f);

template<typename RndIt> constexpr void partial_sort(RndIt i, RndIt middle, RndIt s);
template<typename RndIt, typename Fn> constexpr void partial_sort(RndIt i, RndIt middle, RndIt s, Fn f);
template<_::execution_policy Ex, typename RndIt> void partial_sort(Ex&&, RndIt i, RndIt middle, RndIt s);
template<_::execution_policy Ex, typename RndIt, typename Fn> void partial_sort(Ex&&, RndIt i, RndIt middle, RndIt s, Fn f);

template<typename InpIt, typename RndIt> constexpr RndIt partial_sort_copy(InpIt i, InpIt s, RndIt o_i, RndIt o_s);
template<typename InpIt, typename RndIt, typename Fn> constexpr RndIt partial_sort_copy(InpIt i, InpIt s, RndIt o_i, RndIt o_s, Fn f);
template<_::execution_policy Ex, typename FwdIt, typename RndIt> RndIt partial_sort_copy(Ex&&, FwdIt i, FwdIt s, RndIt o_i, RndIt o_s);
template<_::execution_policy Ex, typename FwdIt, typename RndIt, typename Fn> RndIt partial_sort_copy(Ex&&, FwdIt i, FwdIt s, RndIt o_i, RndIt o_s, Fn f);

template<typename RndIt> void stable_sort(RndIt i, RndIt s);
template<typename RndIt, typename Fn> void stable_sort(RndIt i, RndIt s, Fn f);
template<_::execution_policy Ex, typename RndIt> void stable_sort(Ex&&, RndIt i, RndIt s);
template<_::execution_policy Ex, typename RndIt, typename Fn> void stable_sort(Ex&&, RndIt i, RndIt s, Fn f);

template<typename RndIt> constexpr void nth_element(RndIt i, RndIt nth, RndIt s);
template<typename RndIt, typename Fn> constexpr void nth_element(RndIt i, RndIt nth, RndIt s, Fn f);
template<_::execution_policy Ex, typename RndIt> void nth_element(Ex&&, RndIt i, RndIt nth, RndIt s);
template<_::execution_policy Ex, typename RndIt, typename Fn> void nth_element(Ex&&, RndIt i, RndIt nth, RndIt s, Fn f);

//==============================================================================
// binary search operations

template<typename FwdIt, typename Ty> constexpr FwdIt lower_bound(FwdIt i, FwdIt s, const Ty& v);
template<typename FwdIt, typename Ty, typename Fn> constexpr FwdIt lower_bound(FwdIt i, FwdIt s, const Ty& v, Fn f);

template<typename FwdIt, typename Ty> constexpr FwdIt upper_bound(FwdIt i, FwdIt s, const Ty& v);
template<typename FwdIt, typename Ty, typename Fn> constexpr FwdIt upper_bound(FwdIt i, FwdIt s, const Ty& v, Fn f);

template<typename FwdIt, typename Ty> constexpr bool binary_search(FwdIt i, FwdIt s, const Ty& v);
template<typename FwdIt, typename Ty, typename Fn> constexpr bool binary_search(FwdIt i, FwdIt s, const Ty& v, Fn f);

template<typename FwdIt, typename Ty> constexpr pair<FwdIt, FwdIt> equal_range(FwdIt i, FwdIt s, const Ty& v);
template<typename FwdIt, typename Ty, typename Fn> constexpr pair<FwdIt, FwdIt> equal_range(FwdIt i, FwdIt s, const Ty& v, Fn f);

//==============================================================================
// merge operations

template<typename InpI1, typename InpI2, typename OutIt> constexpr OutIt merge(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o);
template<typename InpI1, typename InpI2, typename OutIt, typename Fn> constexpr OutIt merge(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdIt> FwdIt merge(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, FwdIt o);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdIt, typename Fn> FwdIt merge(Ex&&, FwdI1, FwdI1, FwdI2, FwdI2, FwdIt,Fn);

template<typename BidIt> void inplace_merge(BidIt i, BidIt middle, BidIt s);
template<typename BidIt, typename Fn> void inplace_merge(BidIt i, BidIt middle, BidIt s, Fn f);
template<_::execution_policy Ex, typename BidIt> void inplace_merge(Ex&&, BidIt i, BidIt middle, BidIt s);
template<_::execution_policy Ex, typename BidIt, typename Fn> void inplace_merge(Ex&&, BidIt i, BidIt middle, BidIt s, Fn f);

//==============================================================================
// set operations

template<typename InpI1, typename InpI2> constexpr bool includes(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2);
template<typename InpI1, typename InpI2, typename Fn> constexpr bool includes(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> bool includes(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> bool includes(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f);

template<typename InpI1, typename InpI2, typename OutIt> constexpr OutIt set_difference(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o);
template<typename InpI1, typename InpI2, typename OutIt, typename Fn> constexpr OutIt set_difference(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2,OutIt o,Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdOt> FwdOt set_difference(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2,FwdOt o);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdOt, typename Fn>FwdOt set_difference(Ex&&, FwdI1, FwdI1, FwdI2,FwdI2,FwdOt,Fn);

template<typename InpI1, typename InpI2, typename OutIt> constexpr OutIt set_intersection(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o);
template<typename InpI1, typename InpI2, typename OutIt, typename Fn> constexpr OutIt set_intersection(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdOt> FwdOt set_intersection(Ex&&, FwdI1 i1, FwdI1 s1,FwdI2 i2,FwdI2 s2,FwdOt o);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdOt, typename Fn> FwdOt set_intersection(Ex&&,FwdI1,FwdI1,FwdI2,FwdI2,FwdOt,Fn);

template<typename InpI1, typename InpI2, typename OutIt> constexpr OutIt set_symmetric_difference(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o);
template<typename InpI1, typename InpI2, typename OutIt, typename Fn>constexpr OutIt set_symmetric_difference(InpI1 i1,InpI1 s1,InpI2 i2,InpI2 s2,OutIt o,Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdOt> FwdOt set_symmetric_difference(Ex&&, FwdI1, FwdI1, FwdI2, FwdI2, FwdOt);
template<_::execution_policy Ex,typename FwdI1,typename FwdI2,typename FwdOt,typename Fn>FwdOt set_symmetric_difference(Ex&&,FwdI1,FwdI1,FwdI2,FwdI2,FwdOt,Fn);

template<typename InpI1, typename InpI2, typename OutIt> constexpr OutIt set_union(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o);
template<typename InpI1, typename InpI2, typename OutIt, typename Fn> constexpr OutIt set_union(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, OutIt o, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdIt> FwdIt set_union(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, FwdIt o);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename FwdIt, typename Fn> FwdIt set_union(Ex&&, FwdI1, FwdI1, FwdI2, FwdI2, FwdIt, Fn);

//==============================================================================
// heap operations

template<typename RndIt> constexpr bool is_heap(RndIt i, RndIt s);
template<typename RndIt, typename Fn> constexpr bool is_heap(RndIt i, RndIt s, Fn f);
template<_::execution_policy Ex, typename RndIt> bool is_heap(Ex&&, RndIt i, RndIt s);
template<_::execution_policy Ex, typename RndIt, typename Fn> bool is_heap(Ex&&, RndIt i, RndIt s, Fn f);

template<typename RndIt> constexpr RndIt is_heap_until(RndIt i, RndIt s);
template<typename RndIt, typename Fn> constexpr RndIt is_heap_until(RndIt i, RndIt s, Fn f);
template<_::execution_policy Ex, typename RndIt> RndIt is_heap_until(Ex&&, RndIt i, RndIt s);
template<_::execution_policy Ex, typename RndIt, typename Fn> RndIt is_heap_until(Ex&&, RndIt i, RndIt s, Fn f);

template<typename RndIt> constexpr void make_heap(RndIt i, RndIt s);
template<typename RndIt, typename Fn> constexpr void make_heap(RndIt i, RndIt s, Fn f);

template<typename RndIt> constexpr void pop_heap(RndIt i, RndIt s);
template<typename RndIt, typename Fn> constexpr void pop_heap(RndIt i, RndIt s, Fn f);

template<typename RndIt> constexpr void push_heap(RndIt i, RndIt s);
template<typename RndIt, typename Fn> constexpr void push_heap(RndIt i, RndIt s, Fn f);

template<typename RndIt> constexpr void sort_heap(RndIt i, RndIt s);
template<typename RndIt, typename Fn> constexpr void sort_heap(RndIt i, RndIt s, Fn f);

//==============================================================================
// max / min operations

template<typename Ty> constexpr const Ty& max(const Ty& a, const Ty& b);
template<typename Ty, typename Fn> constexpr const Ty& max(const Ty& a, const Ty& b, Fn f);
template<typename Ty> constexpr Ty max(initializer_list<Ty> t);
template<typename Ty, typename Fn> constexpr Ty max(initializer_list<Ty> t, Fn f);

template<typename Ty> constexpr const Ty& min(const Ty& a, const Ty& b);
template<typename Ty, typename Fn> constexpr const Ty& min(const Ty& a, const Ty& b, Fn f);
template<typename Ty> constexpr Ty min(initializer_list<Ty> t);
template<typename Ty, typename Fn> constexpr Ty min(initializer_list<Ty> t, Fn f);

template<typename Ty> constexpr pair<const Ty&, const Ty&> minmax(const Ty& a, const Ty& b);
template<typename Ty, typename Fn> constexpr pair<const Ty&, const Ty&> minmax(const Ty& a, const Ty& b, Fn f);
template<typename Ty> constexpr pair<Ty, Ty> minmax(initializer_list<Ty> t);
template<typename Ty, typename Fn> constexpr pair<Ty, Ty> minmax(initializer_list<Ty> t, Fn f);

template<typename FwdIt> constexpr FwdIt max_element(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr FwdIt max_element(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt> FwdIt max_element(Ex&&, FwdIt i, FwdIt s);
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt max_element(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename FwdIt> constexpr FwdIt min_element(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr FwdIt min_element(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt> FwdIt min_element(Ex&&, FwdIt i, FwdIt s);
template<_::execution_policy Ex, typename FwdIt, typename Fn> FwdIt min_element(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename FwdIt> constexpr pair<FwdIt, FwdIt> minmax_element(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr pair<FwdIt, FwdIt> minmax_element(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Ex, typename FwdIt> pair<FwdIt, FwdIt> minmax_element(Ex&&, FwdIt i, FwdIt s);
template<_::execution_policy Ex, typename FwdIt, typename Fn> pair<FwdIt, FwdIt> minmax_element(Ex&&, FwdIt i, FwdIt s, Fn f);

template<typename Ty> constexpr const Ty& clamp(const Ty& v, const Ty& lo, const Ty& hi);
template<typename Ty, typename Fn> constexpr const Ty& clamp(const Ty& v, const Ty& lo, const Ty& hi, Fn f);

//==============================================================================
// farison operations

template<typename InpI1, typename InpI2> constexpr bool equal(InpI1 i1, InpI1 s1, InpI2 i2);
template<typename InpI1, typename InpI2, typename Fn> constexpr bool equal(InpI1 i1, InpI1 s1, InpI2 i2, Fn f);
template<typename InpI1, typename InpI2> constexpr bool equal(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2);
template<typename InpI1, typename InpI2, typename Fn> constexpr bool equal(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> bool equal(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> bool equal(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> bool equal(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> bool equal(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f);

template<typename InpI1, typename InpI2> constexpr bool lexicographical_compare(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2);
template<typename InpI1, typename InpI2, typename Fn> constexpr bool lexicographical_compare(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, Fn f);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2> bool lexicographical_compare(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<_::execution_policy Ex, typename FwdI1, typename FwdI2, typename Fn> bool lexicographical_compare(Ex&&, FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f);

template<typename InpI1, typename InpI2, typename Fn> constexpr auto lexicographical_compare_three_way(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2, Fn f)
  -> decltype(f(*i1, *i2)) { static_assert(_::is_three_way_result<decltype(f(*i1, *i2))>);
  for (;;) { if (i1 == s1) return i2 == s2 ? strong_ordering::equal : strong_ordering::less;
             if (i2 == s2) return strong_ordering::greater;
             if (auto c = f(*i1, *i2); c != 0) return c; } }
template<typename InpI1, typename InpI2> constexpr auto lexicographical_compare_three_way(InpI1 i1, InpI1 s1, InpI2 i2, InpI2 s2) {
  return std::lexicographical_compare_three_way(_::move(i1), _::move(s1), _::move(i2), _::move(s2), compare_three_way{}); }

//==============================================================================
// permutation operations

template<typename FwdI1, typename FwdI2> constexpr bool is_permutation(FwdI1 i1, FwdI1 s1, FwdI2 i2);
template<typename FwdI1, typename FwdI2, typename Fn> constexpr bool is_permutation(FwdI1 i1, FwdI1 s1, FwdI2 i2, Fn f);
template<typename FwdI1, typename FwdI2> constexpr bool is_permutation(FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2);
template<typename FwdI1, typename FwdI2, typename Fn> constexpr bool is_permutation(FwdI1 i1, FwdI1 s1, FwdI2 i2, FwdI2 s2, Fn f);

template<typename BidIt> constexpr bool next_permutation(BidIt i, BidIt s);
template<typename BidIt, typename Fn> constexpr bool next_permutation(BidIt i, BidIt s, Fn comp);

template<typename BidIt> constexpr bool prev_permutation(BidIt i, BidIt s);
template<typename BidIt, typename Fn> constexpr bool prev_permutation(BidIt i, BidIt s, Fn comp);

}

//==============================================================================
// algorithm results

namespace std::ranges {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-attributes"

template<typename It, typename Fn> struct in_fun_result {
  [[no_unique_address]] It in; [[no_unique_address]] Fn fun;
  template<_::convertible_from<const It&> ItA, _::convertible_from<const Fn&> FnA> constexpr operator in_fun_result<ItA, FnA>() const& { return {in, fun}; }
  template<_::convertible_from<It> ItA, _::convertible_from<Fn> FnA> constexpr operator in_fun_result<ItA, FnA>() && { return {_::move(in), _::move(fun)}; }
};

template<typename I1, typename I2> struct in_in_result {
  [[no_unique_address]] I1 in1; [[no_unique_address]] I2 in2;
  template<_::convertible_from<const I1&> I1A, _::convertible_from<const I2&> I2A> constexpr operator in_in_result<I1A, I2A>() const& { return {in1, in2}; }
  template<_::convertible_from<I1> I1A, _::convertible_from<I2> I2A> constexpr operator in_in_result<I1A, I2A>() && { return {_::move(in1), _::move(in2)}; }
};

using std::ranges::in_out_result;

template<typename I1, typename I2, typename Ot> struct in_in_out_result {
  [[no_unique_address]] I1 in1; [[no_unique_address]] I2 in2; [[no_unique_address]] Ot out;
  template<_::convertible_from<const I1&> I1A, _::convertible_from<const I2&> I2A, _::convertible_from<const Ot&> OtA>
  constexpr operator in_in_out_result<I1A, I2A, OtA>() const& { return {in1, in2, out}; }
  template<_::convertible_from<I1> I1A, _::convertible_from<I2> I2A, _::convertible_from<Ot> OtA>
  constexpr operator in_in_out_result<I1A, I2A, OtA>() && { return {_::move(in1), _::move(in2), _::move(out)}; }
};

template<typename It, typename O1, typename O2> struct in_out_out_result {
  [[no_unique_address]] It in; [[no_unique_address]] O1 out1; [[no_unique_address]] O2 out2;
  template<_::convertible_from<const It&> ItA, _::convertible_from<const O1&> O1A, _::convertible_from<const O2&> O2A>
  constexpr operator in_out_out_result<ItA, O1A, O2A>() const& { return {in, out1, out2}; }
  template<_::convertible_from<It> ItA, _::convertible_from<O1> O1A, _::convertible_from<O2> O2A>
  constexpr operator in_out_out_result<ItA, O1A, O2A>() && { return {_::move(in), _::move(out1), _::move(out2)}; }
};

template<typename Ty> struct min_max_result {
  [[no_unique_address]] Ty min, max;
  template<_::convertible_from<const Ty&> TyA> constexpr operator min_max_result<TyA>() const& { return {min, max}; }
  template<_::convertible_from<Ty> TyA> constexpr operator min_max_result<TyA>() && { return {_::move(min), _::move(max)}; }
};

template<typename It> struct in_found_result {
  [[no_unique_address]] It in; bool found;
  template<_::convertible_from<const It&> ItA> constexpr operator in_found_result<ItA>() const& { return {in, found}; }
  template<_::convertible_from<It> ItA> constexpr operator in_found_result<ItA>() && { return {_::move(in), found}; }
};

template<typename Ot, typename Ty> struct out_value_result {
  [[no_unique_address]] Ot out; [[no_unique_address]] Ty value;
  template<_::convertible_from<const Ot&> OtA, _::convertible_from<const Ty&> TyA>
  constexpr operator out_value_result<OtA, TyA>() const& { return {out, value}; }
  template<_::convertible_from<Ot> OtA, _::convertible_from<Ty> TyA>
  constexpr operator out_value_result<OtA, TyA>() && { return {_::move(out), _::move(value)}; }
};

#pragma clang diagnostic pop

template<typename It, typename Fn> using for_each_result = in_fun_result<It, Fn>;
template<typename It, typename Fn> using for_each_n_result = in_fun_result<It, Fn>;
template<typename I1, typename I2> using mismatch_result = in_in_result<I1, I2>;
template<typename It, typename Ot> using copy_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using copy_n_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using copy_if_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using copy_backward_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using move_result = in_out_result<It, Ot>;
template<typename I1, typename I2> using move_backward_result = in_out_result<I1, I2>;
template<typename It, typename Ot> using unary_transform_result = in_out_result<It, Ot>;
template<typename I1, typename I2, typename Ot> using binary_transform_result = in_in_out_result<I1, I2, Ot>;
template<typename It, typename Ot> using remove_copy_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using remove_copy_if_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using replace_copy_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using replace_copy_if_result = in_out_result<It, Ot>;
template<typename I1, typename I2> using swap_ranges_result = in_in_result<I1, I2>;
template<typename It, typename Ot> using reverse_copy_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using rotate_copy_result = in_out_result<It, Ot>;
template<typename It, typename Ot> using unique_copy_result = in_out_result<It, Ot>;
template<typename It, typename O1, typename O2> using partition_copy_result = in_out_out_result<It, O1, O2>;
template<typename It, typename Ot> using partial_sort_copy_result = in_out_result<It, Ot>;
template<typename I1, typename I2, typename Ot> using merge_result = in_in_out_result<I1, I2, Ot>;
template<typename I1, typename I2, typename Ot> using set_union_result = in_in_out_result<I1, I2, Ot>;
template<typename I1, typename I2, typename Ot> using set_intersection_result = in_in_out_result<I1, I2, Ot>;
template<typename It, typename Ot> using set_difference_result = in_out_result<It, Ot>;
template<typename I1, typename I2, typename Ot> using set_symmetric_difference_result = in_in_out_result<I1, I2, Ot>;
template<typename Ty>using minmax_result = min_max_result<Ty>;
template<typename It> using minmax_element_result = min_max_result<It>;
template<typename It> using next_permutation_result = in_found_result<It>;
template<typename It> using prev_permutation_result = in_found_result<It>;

}

//==============================================================================
// non-modifying sequence operations

namespace std::_ {

template<typename Fn, typename I1, typename I2, typename P1 = identity, typename P2 = identity>
concept iter_comparable = indirect_binary_predicate<Fn, projected<I1, P1>, projected<I2, P2>>;

template<typename Fn, typename R1, typename R2, typename P1 = identity, typename P2 = identity>
concept range_comparable = iter_comparable<Fn, ranges::iterator_t<R1>, ranges::iterator_t<R2>, P1, P2>;

struct _find {
  template<input_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, It, const Ty*, Pj>
  constexpr It operator()(It i, Se s, const Ty& v, Pj p = {}) const { for (; i != s; ++i) if (std::invoke(p, *i) == v) break; return i; }
  template<ranges::input_range Rg, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, ranges::iterator_t<Rg>, const Ty*, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, const Ty& v, Pj p = {}) const {
    return (*this)(ranges::begin(r), ranges::end(r), v, _::move(p)); }
};

struct _find_if {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr It operator()(It i, Se s, Fn f, Pj p = {}) const { for (; i != s; ++i) if (std::invoke(f, std::invoke(p, *i))) break; return i; }
  template<ranges::input_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(p)); }
};

struct _find_if_not {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr It operator()(It i, Se s, Fn f, Pj p = {}) const { for (; i != s; ++i) if (!std::invoke(f, std::invoke(p, *i))) break; return i; }
  template<ranges::input_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(p)); }
};

struct _all_of {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr bool operator()(It i, Se s, Fn f, Pj p = {}) const { return _find_if_not{}(i, s, _::move(f), _::move(p)) == s; }
  template<ranges::input_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr bool operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(f), _::move(p)); }
};

struct _any_of {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr bool operator()(It i, Se s, Fn f, Pj p = {}) const { return _find_if{}(i, s, _::move(f), _::move(p)) != s; }
  template<ranges::input_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr bool operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(f), _::move(p)); }
};

struct _none_of {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr bool operator()(It i, Se s, Fn f, Pj p = {}) const { return _find_if{}(i, s, _::move(f), _::move(p)) == s; }
  template<ranges::input_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr bool operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(f), _::move(p)); }
};

struct _for_each {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirectly_unary_invocable<projected<It, Pj>> Fn>
  constexpr ranges::for_each_result<It, Fn> operator()(It i, Se s, Fn f, Pj p = {}) const {
    for (; i != s; ++i) std::invoke(f, invoke(p, *i)); return {_::move(i), _::move(s)}; }
  template<ranges::input_range Rg, typename Pj = identity, indirectly_unary_invocable<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr ranges::for_each_result<ranges::borrowed_iterator_t<Rg>, Fn> operator()(Rg&& r, Fn f, Pj p = {}) const {
    return (*this)(ranges::begin(r), ranges::end(r), _::move(f), _::move(p)); }
};

struct _for_each_n {
  template<input_iterator It, typename Pj = identity, indirectly_unary_invocable<projected<It, Pj>> Fn>
  constexpr ranges::for_each_n_result<It, Fn> operator()(It i, iter_difference_t<It> n, Fn f, Pj p = {}) const {
    for (; n != 0; ++i, --n) std::invoke(f, std::invoke(p, *i)); return {_::move(i), _::move(f)}; }
};

struct _count {
  template<input_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, It, const Ty*, Pj>
  constexpr iter_difference_t<It> operator()(It i, Se s, const Ty& v, Pj p = {}) const;
  template<ranges::input_range Rg, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, ranges::iterator_t<Rg>, const Ty*, Pj>
  constexpr ranges::range_difference_t<Rg> operator()(Rg&& r, const Ty& v, Pj p = {}) const;
};

struct _count_if {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr iter_difference_t<It> operator()(It i, Se s, Fn f, Pj p = {}) const;
  template<ranges::input_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr ranges::range_difference_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const;
};

struct _mismatch {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
            iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
  constexpr ranges::mismatch_result<I1, I2> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, typename P1 = identity, typename P2 = identity,
            range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
  constexpr ranges::mismatch_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>>
  operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const {
    return (*this)(ranges::begin(r1), ranges::end(r1), ranges::begin(r2), ranges::end(r2), _::move(f), _::move(p1), _::move(p2)); }
};

struct _find_end {
  template<forward_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
            iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
  constexpr ranges::subrange<I1> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::forward_range R1, ranges::forward_range R2, typename P1 = identity, typename P2 = identity,
            range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
  constexpr ranges::borrowed_subrange_t<R1> operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) {
    return (*this)(ranges::begin(r1), ranges::end(r1), ranges::begin(r2), ranges::end(r2), _::move(f), _::move(p1), _::move(p2)); }
};

struct _find_first_of {
  template<input_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2,
            typename P1 = identity, typename P2 = identity, iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
  constexpr I1 operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::forward_range R2,
            typename P1 = identity, typename P2 = identity, range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
  constexpr ranges::borrowed_iterator_t<R1> operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) {
    return (*this)(ranges::begin(r1), ranges::end(r1), ranges::begin(r2), ranges::end(r2), _::move(f), _::move(p1), _::move(p2)); }
};

struct _adjacent_find {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, iter_comparable<It, It, Pj, Pj> Fn = ranges::equal_to>
  constexpr It operator()(It i, Se s, Fn f = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, range_comparable<Rg, Pj, Rg, Pj> Fn = ranges::equal_to>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f = {}, Pj p = {}) const;
};

struct _search {
  template<forward_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
            iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
  constexpr ranges::subrange<I1> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::forward_range R1, ranges::forward_range R2, typename P1 = identity, typename P2 = identity,
            range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
  constexpr ranges::borrowed_subrange_t<R1> operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _search_n {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity, iter_comparable<It, const Ty*, Pj> Fn = ranges::equal_to>
  constexpr ranges::subrange<It> operator()(It i, Se s, iter_difference_t<It> n, const Ty& v, Fn f = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity, iter_comparable<ranges::iterator_t<Rg>, const Ty*, Pj> Fn = ranges::equal_to>
  constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, ranges::range_difference_t<Rg> n, const Ty& v, Fn f = {}, Pj p = {}) const;
};

struct _starts_with {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
            iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
  constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, typename P1 = identity, typename P2 = identity,
            range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
  constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _ends_with {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
            iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
  requires (forward_iterator<I1> || sized_sentinel_for<S1, I1>) && (forward_iterator<I2> || sized_sentinel_for<S2, I2>)
  constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, typename P1 = identity, typename P2 = identity,
            range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
  requires (ranges::forward_range<R1> || ranges::sized_range<R1>) && (ranges::forward_range<R2> || ranges::sized_range<R2>)
  constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _equal {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
            iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
  constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2,typename P1 = identity, typename P2 = identity,
            range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
  constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _lexicographical_compare {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
           indirect_strict_weak_order<projected<I1, P1>, projected<I2, P2>> Fn = ranges::less>
  constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {});
  template<ranges::input_range R1, ranges::input_range R2, typename P1 = identity, typename P2 = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<R1>, P1>, projected<ranges::iterator_t<R2>, P2>> Fn = ranges::less>
  constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const {
    return (*this)(ranges::begin(r1), ranges::end(r1), ranges::begin(r2), ranges::end(r2), _::move(f), _::move(p1), _::move(p2));
  }
};

}

namespace std::ranges {

inline constexpr _::_find find;
inline constexpr _::_find_if find_if;
inline constexpr _::_find_if_not find_if_not;
inline constexpr _::_all_of all_of;
inline constexpr _::_any_of any_of;
inline constexpr _::_none_of none_of;
inline constexpr _::_for_each for_each;
inline constexpr _::_for_each_n for_each_n;
inline constexpr _::_count count;
inline constexpr _::_count_if count_if;
inline constexpr _::_mismatch mismatch;
inline constexpr _::_find_end find_end;
inline constexpr _::_find_first_of find_first_of;
inline constexpr _::_adjacent_find adjacent_find;
inline constexpr _::_search search;
inline constexpr _::_search_n search_n;
inline constexpr _::_starts_with starts_with;
inline constexpr _::_ends_with ends_with;
inline constexpr _::_equal equal;
inline constexpr _::_lexicographical_compare lexicographical_compare;

}

//==============================================================================
// modifying sequence operations

namespace std::_ {

struct _copy {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot> requires indirectly_copyable<It, Ot>
  constexpr ranges::copy_result<It, Ot> operator()(It i, Se s, Ot o) const;
  template<ranges::input_range Rg, weakly_incrementable Ot> requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
  constexpr ranges::copy_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o) const;
};

struct _copy_n {
  template<input_iterator It, weakly_incrementable Ot> requires indirectly_copyable<It, Ot>
  constexpr ranges::copy_n_result<It, Ot> operator()(It i, iter_difference_t<It> n, Ot o) const;
};

struct _copy_if {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  requires indirectly_copyable<It, Ot> constexpr ranges::copy_if_result<It, Ot> operator()(It i, Se s, Ot o, Fn f, Pj p = {}) const;
  template<ranges::input_range Rg, weakly_incrementable Ot, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> constexpr ranges::copy_if_result<ranges::borrowed_iterator_t<Rg>, Ot>
  operator()(Rg&& r, Ot o, Fn f, Pj p = {}) const;
};

struct _copy_backward {
  template<bidirectional_iterator I1, sentinel_for<I1> S1, bidirectional_iterator I2> requires indirectly_copyable<I1, I2>
  constexpr ranges::copy_backward_result<I1, I2> operator()(I1 i, S1 s, I2 o) const;
  template<ranges::bidirectional_range Rg, bidirectional_iterator It> requires indirectly_copyable<ranges::iterator_t<Rg>, It>
  constexpr ranges::copy_backward_result<ranges::borrowed_iterator_t<Rg>, It> operator()(Rg&& r, It o) const;
};

struct _move {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot> requires indirectly_movable<It, Ot>
  constexpr ranges::move_result<It, Ot> operator()(It i, Se s, Ot o) const;
  template<ranges::input_range Rg, weakly_incrementable Ot> requires indirectly_movable<ranges::iterator_t<Rg>, Ot>
  constexpr ranges::move_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o) const;
};

struct _move_backward {
  template<bidirectional_iterator I1, sentinel_for<I1> S1, bidirectional_iterator I2> requires indirectly_movable<I1, I2>
  constexpr ranges::move_backward_result<I1, I2> operator()(I1 i, S1 s, I2 o) const;
  template<ranges::bidirectional_range Rg, bidirectional_iterator It> requires indirectly_movable<ranges::iterator_t<Rg>, It>
  constexpr ranges::move_backward_result<ranges::borrowed_iterator_t<Rg>, It> operator()(Rg&& r, It o) const;
};

struct _fill {
  template<typename Ty, output_iterator<const Ty&> Ot, sentinel_for<Ot> Se>
  constexpr Ot operator()(Ot i, Se s, const Ty& v) const { for (;; *i++ = v) if (i == s) return i; }
  template<typename Ty, ranges::output_range<const Ty&> Rg> constexpr ranges::borrowed_iterator_t<Rg>
  operator()(Rg&& r, const Ty& v) const { return (*this)(ranges::begin(r), ranges::end(r), v); }
};

struct _fill_n {
  template<typename Ty, output_iterator<const Ty&> Ot> constexpr Ot operator()(Ot i, iter_difference_t<Ot> n, const Ty& v) const;
};

struct _transform {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, copy_constructible Fn, typename Pj = identity>
  requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<It, Pj>>>
  constexpr ranges::unary_transform_result<It, Ot> operator()(It i, Se s1, Ot o, Fn f, Pj p = {}) const;
  template<ranges::input_range Rg, weakly_incrementable Ot, copy_constructible Fn, typename Pj = identity>
  requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<ranges::iterator_t<Rg>, Pj>>>
  constexpr ranges::unary_transform_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o, Fn f, Pj p = {}) const;
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, weakly_incrementable Ot, copy_constructible Fn,
            typename P1 = identity, typename P2 = identity> requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<I1, P1>, projected<I2, P2>>>
  constexpr ranges::binary_transform_result<I1, I2, Ot> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Fn f, P1 p1 = {}, P2 p2 = {});
  template<ranges::input_range R1, ranges::input_range R2, weakly_incrementable Ot, copy_constructible Fn, typename P1 = identity, typename P2 = identity>
  requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<ranges::iterator_t<R1>, P1>, projected<ranges::iterator_t<R2>, P2>>>
  constexpr ranges::binary_transform_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  operator()(R1&& r1, R2&& r2, Ot o, Fn f, P1 p1 = {}, P2 p2 = {}) const;
};

struct _generate {
  template<input_or_output_iterator Ot, sentinel_for<Ot> Se, copy_constructible Fn> requires invocable<Fn&> && indirectly_writable<Ot, invoke_result_t<Fn&>>
  constexpr Ot operator()(Ot i, Se s, Fn f) const;
  template<typename Rg, copy_constructible Fn> requires invocable<Fn&> && ranges::output_range<Rg, invoke_result_t<Fn&>>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f) const;
  template<input_or_output_iterator Ot, copy_constructible Fn> requires invocable<Fn&> && indirectly_writable<Ot, invoke_result_t<Fn&>>
  constexpr Ot operator()(Ot i, iter_difference_t<Ot> n, Fn f) const;
};

struct _generate_n {
  template<input_or_output_iterator Ot, copy_constructible Fn> requires invocable<Fn&> && indirectly_writable<Ot, invoke_result_t<Fn&>>
  constexpr Ot operator()(Ot i, iter_difference_t<Ot> n, Fn f) const { for (; 0 < n--; *i = std::invoke(f), ++i) continue; return i; }
};

struct _remove {
  template<permutable It, sentinel_for<It> Se, typename Ty, typename Pj = identity>
  requires indirect_binary_predicate<ranges::equal_to, projected<It, Pj>, const Ty*>
  constexpr ranges::subrange<It> operator()(It i, Se s, const Ty& v, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity>
  requires permutable<ranges::iterator_t<Rg>> && indirect_binary_predicate<ranges::equal_to, projected<ranges::iterator_t<Rg>, Pj>, const Ty*>
  constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, const Ty& v, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), v, _::move(p));}
};

struct _remove_if {
  template<permutable It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr ranges::subrange<It> operator()(It i, Se s, Fn f, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires permutable<ranges::iterator_t<Rg>> constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) {
    return (*this)(ranges::begin(r), ranges::end(r), _::move(f), _::move(p)); }
};

struct _remove_copy {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, typename Ty, typename Pj = identity>
  requires indirectly_copyable<It, Ot> && indirect_binary_predicate<ranges::equal_to, projected<It, Pj>, const Ty*>
  constexpr ranges::remove_copy_result<It, Ot> operator()(It i, Se s, Ot o, const Ty& v, Pj p = {}) const;
  template<ranges::input_range Rg, weakly_incrementable Ot, typename Ty, typename Pj = identity>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> && indirect_binary_predicate<ranges::equal_to, projected<ranges::iterator_t<Rg>, Pj>, const Ty*>
  constexpr ranges::remove_copy_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o, const Ty& v, Pj p = {}) const {
    return (*this)(ranges::begin(r), ranges::end(r), _::move(o), v, _::move(p)); }
};

struct _remove_copy_if {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  requires indirectly_copyable<It, Ot> constexpr ranges::remove_copy_if_result<It, Ot> operator()(It i, Se s, Ot o, Fn f, Pj p = {}) const;
  template<ranges::input_range Rg, weakly_incrementable Ot, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> constexpr ranges::remove_copy_if_result<ranges::borrowed_iterator_t<Rg>, Ot>
  operator()(Rg&& r, Ot o, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(o), _::move(f), _::move(p)); }
};

struct _replace {
    template<input_iterator It, sentinel_for<It> Se, typename Ty1, typename Ty2, typename Pj = identity>
  requires indirectly_writable<It, const Ty2&> && indirect_binary_predicate<ranges::equal_to, projected<It, Pj>, const Ty1*>
  constexpr It operator()(It i, Se s, const Ty1& Old, const Ty2& New, Pj p = {}) const;
  template<ranges::input_range Rg, typename Ty1, typename Ty2, typename Pj = identity>
  requires indirectly_writable<ranges::iterator_t<Rg>, const Ty2&> && iter_comparable<ranges::equal_to, ranges::iterator_t<Rg>, const Ty1*, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, const Ty1& Old, const Ty2& New, Pj p = {}) const;
};

struct _replace_if {
  template<input_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  requires indirectly_writable<It, const Ty&> constexpr It operator()(It i, Se s, Fn f, const Ty& New, Pj p = {}) const;
  template<ranges::input_range Rg, typename Ty, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires indirectly_writable<ranges::iterator_t<Rg>, const Ty&>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f, const Ty& New, Pj p = {}) const;
};

struct _replace_copy {
  template<input_iterator It, sentinel_for<It> Se, typename Ty1, typename Ty2, output_iterator<const Ty2&> Ot, typename Pj = identity>
  requires indirectly_copyable<It, Ot> && indirect_binary_predicate<ranges::equal_to, projected<It, Pj>, const Ty1*>
  constexpr ranges::replace_copy_result<It, Ot> operator()(It i, Se s, Ot o, const Ty1& Old, const Ty2& New, Pj p = {}) const;
  template<ranges::input_range Rg, typename Ty1, typename Ty2, output_iterator<const Ty2&> Ot, typename Pj = identity>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> && indirect_binary_predicate<ranges::equal_to, projected<ranges::iterator_t<Rg>, Pj>, const Ty1*>
  constexpr ranges::replace_copy_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o, const Ty1& Old, const Ty2& New, Pj p = {}) const;
};

struct _replace_copy_if {
  template<input_iterator It, sentinel_for<It> Se, typename Ty, output_iterator<const Ty&> Ot, typename Pj = identity,
            indirect_unary_predicate<projected<It, Pj>> Fn> requires indirectly_copyable<It, Ot>
  constexpr ranges::replace_copy_if_result<It, Ot> operator()(It i, Se s, Ot o, Fn f, const Ty& New, Pj p = {}) const;
  template<ranges::input_range Rg, typename Ty, output_iterator<const Ty&> Ot, typename Pj = identity,
            indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn> requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
  constexpr ranges::replace_copy_if_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o, Fn f, const Ty& New, Pj p = {}) const;
};

struct _swap_range {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2> requires indirectly_swappable<I1, I2>
  constexpr ranges::swap_ranges_result<I1, I2> operator()(I1 i1, S1 s1, I2 i2, S2 s2) const;
  template<ranges::input_range R1, ranges::input_range R2> requires indirectly_swappable<ranges::iterator_t<R1>, ranges::iterator_t<R2>>
  constexpr ranges::swap_ranges_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>>
  operator()(R1&& r1, R2&& r2) const { return (*this)(ranges::begin(r1), ranges::end(r1), ranges::begin(r2), ranges::end(r2)); }
};

struct _reverse {
  template<bidirectional_iterator It, sentinel_for<It> Se> requires permutable<It> constexpr It operator()(It i, Se s) const;
  template<ranges::bidirectional_range Rg> requires permutable<ranges::iterator_t<Rg>> constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r) const;
};

struct _reverse_copy {
  template<bidirectional_iterator It, sentinel_for<It> Se, weakly_incrementable Ot> requires indirectly_copyable<It, Ot>
  constexpr ranges::reverse_copy_result<It, Ot> operator()(It i, Se s, Ot o) const;
  template<ranges::bidirectional_range Rg, weakly_incrementable Ot> requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
  constexpr ranges::reverse_copy_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o) const;
};

struct _rotate {
  template<permutable It, sentinel_for<It> Se> constexpr ranges::subrange<It> operator()(It i, It middle, Se s) const;
  template<ranges::forward_range Rg> requires permutable<ranges::iterator_t<Rg>>
  constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, ranges::iterator_t<Rg> middle) const;
};

struct _rotate_copy {
  template<forward_iterator It, sentinel_for<It> Se, weakly_incrementable Ot> requires indirectly_copyable<It, Ot>
  constexpr ranges::rotate_copy_result<It, Ot> operator()(It i, It middle, Se s, Ot o) const;
  template<ranges::forward_range Rg, weakly_incrementable Ot> requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
  constexpr ranges::rotate_copy_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, ranges::iterator_t<Rg> middle, Ot o) const;
};

struct _shift_left {
  template<permutable It, sentinel_for<It> Se> constexpr ranges::subrange<It> operator()(It i, Se s, iter_difference_t<It> n) const;
  template<ranges::forward_range Rg> requires permutable<ranges::iterator_t<Rg>> constexpr ranges::borrowed_subrange_t<Rg>
  operator()(Rg&& r, ranges::range_difference_t<Rg> n) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(n)); }
};

struct _shift_right {
  template<permutable It, sentinel_for<It> Se> constexpr ranges::subrange<It> operator()(It i, Se s, iter_difference_t<It> n) const;
  template<ranges::forward_range Rg> requires permutable<ranges::iterator_t<Rg>> constexpr ranges::borrowed_subrange_t<Rg>
  operator()(Rg&& r, ranges::range_difference_t<Rg> n) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(n)); }
};

struct _sample {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, typename Fn>
  requires (forward_iterator<It> || random_access_iterator<Ot>) && indirectly_copyable<It, Ot> && uniform_random_bit_generator<remove_reference_t<Fn>>
  Ot operator()(It i, Se s, Ot out, iter_difference_t<It> n, Fn&& g) const;
  template<ranges::input_range Rg, weakly_incrementable Ot, typename Fn>
  requires (ranges::forward_range<Rg> || random_access_iterator<Ot>) && indirectly_copyable<ranges::iterator_t<Rg>, Ot> && uniform_random_bit_generator<remove_reference_t<Fn>>
  Ot operator()(Rg&& r, Ot out, ranges::range_difference_t<Rg> n, Fn&& g) const;
};

struct _shuffle {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn> requires permutable<It> && uniform_random_bit_generator<remove_reference_t<Fn>>
  It operator()(It i, Se s, Fn&& g) const;
  template<ranges::random_access_range Rg, typename Fn> requires permutable<ranges::iterator_t<Rg>> && uniform_random_bit_generator<remove_reference_t<Fn>>
  ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn&& g) const { return (*this)(ranges::begin(r), ranges::end(r), _::forward<Fn>(g)); }
};

struct _unique {
  template<permutable It, sentinel_for<It> Se, typename Pj = identity, indirect_equivalence_relation<projected<It, Pj>> Fn = ranges::equal_to>
  constexpr ranges::subrange<It> operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_equivalence_relation<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::equal_to>
  requires permutable<ranges::iterator_t<Rg>> constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _unique_copy {
  template<input_iterator In, sentinel_for<In> Se, weakly_incrementable Ot, typename Pj = identity,
           indirect_equivalence_relation<projected<In, Pj>> Fn = ranges::equal_to>
  requires indirectly_copyable<In, Ot> &&
           (forward_iterator<In> || (input_iterator<Ot> && same_as<iter_value_t<In>, iter_value_t<Ot>>) || indirectly_copyable<In, Ot>)
  constexpr ranges::unique_copy_result<In, Ot> operator()(In i, Se s, Ot o, Fn f = {}, Pj p = {}) const {
    if (i != s) {
      iter_value_t<In> v = *i;
      *o = v; ++o;
      for (; ++i != o;) if (!std::invoke(f, std::invoke(p, *i), std::invoke(p, v))) *o = v = *i; o++;
    }
    return {_::move(i), _::move(o)};
  }
};

}

namespace std::ranges {

inline constexpr _::_copy copy;
inline constexpr _::_copy_n copy_n;
inline constexpr _::_copy_if copy_if;
inline constexpr _::_copy_backward copy_backward;
inline constexpr _::_move move;
inline constexpr _::_move_backward move_backward;
inline constexpr _::_fill fill;
inline constexpr _::_fill_n fill_n;
inline constexpr _::_transform transform;
inline constexpr _::_generate generate;
inline constexpr _::_generate_n generate_n;
inline constexpr _::_remove remove;
inline constexpr _::_remove_if remove_if;
inline constexpr _::_remove_copy remove_copy;
inline constexpr _::_remove_copy_if remove_copy_if;
inline constexpr _::_replace replace;
inline constexpr _::_replace_if replace_if;
inline constexpr _::_replace_copy replace_copy;
inline constexpr _::_replace_copy_if replace_copy_if;
inline constexpr _::_swap_range swap_range;
inline constexpr _::_reverse reverse;
inline constexpr _::_reverse_copy reverse_copy;
inline constexpr _::_rotate rotate;
inline constexpr _::_rotate_copy rotate_copy;
inline constexpr _::_shift_left shift_left;
inline constexpr _::_shift_right shift_right;
inline constexpr _::_sample sample;
inline constexpr _::_shuffle shuffle;
inline constexpr _::_unique unique;
inline constexpr _::_unique_copy unique_copy;

}

//==============================================================================
// partitioning operations

namespace std::_ {

struct _is_partitioned {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr bool operator()(It i, Se s, Fn f, Pj p = {}) const;
  template<ranges::input_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr bool operator()(Rg&& r, Fn f, Pj p = {}) const;
};

struct _partition {
  template<permutable It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr ranges::subrange<It> operator()(It i, Se s, Fn f, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires permutable<ranges::iterator_t<Rg>> constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const;
};

struct _partition_copy {
  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable O1, weakly_incrementable O2, typename Pj = identity,
           indirect_unary_predicate<projected<It, Pj>> Fn> requires indirectly_copyable<It, O1> && indirectly_copyable<It, O2>
  constexpr ranges::partition_copy_result<It, O1, O2> operator()(It i, Se s, O1 o1, O2 o2, Fn f, Pj p = {}) const;
  template<ranges::input_range Rg, weakly_incrementable O1, weakly_incrementable O2, typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires indirectly_copyable<ranges::iterator_t<Rg>, O1> && indirectly_copyable<ranges::iterator_t<Rg>, O2>
  constexpr ranges::partition_copy_result<ranges::borrowed_iterator_t<Rg>, O1, O2> operator()(Rg&& r, O1 o1, O2 o2, Fn f, Pj p = {}) const;
};

struct _stable_partition {
  template<bidirectional_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn> requires permutable<It>
  ranges::subrange<It> operator()(It i, Se s, Fn f, Pj p = {}) const;
  template<ranges::bidirectional_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires permutable<ranges::iterator_t<Rg>> ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const;
};

struct _partition_point {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr It operator()(It i, Se s, Fn f, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const;
};

}

namespace std::ranges {
  inline constexpr _::_is_partitioned is_partitioned;
  inline constexpr _::_partition partition;
  inline constexpr _::_partition_copy partition_copy;
  inline constexpr _::_stable_partition stable_partition;
  inline constexpr _::_partition_point partition_point;
}

//==============================================================================
// sorting operations

namespace std::_ {

struct _is_sorted {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_strict_weak_order<projected<It, Pj>> Fn = ranges::less>
  constexpr bool operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr bool operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _is_sorted_until {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_strict_weak_order<projected<It, Pj>> Fn = ranges::less>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _sort {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _partial_sort {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr It operator()(It i, It middle, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, ranges::iterator_t<Rg> middle, Fn comp = {}, Pj p = {}) const;
};

struct _partial_sort_copy {
  template<input_iterator I1, sentinel_for<I1> S1, random_access_iterator I2, sentinel_for<I2> S2,
           typename Fn = ranges::less, typename P1 = identity, typename P2 = identity>
  requires indirectly_copyable<I1, I2> && sortable<I2, Fn, P2> && indirect_strict_weak_order<Fn, projected<I1, P1>, projected<I2, P2>>
  constexpr ranges::partial_sort_copy_result<I1, I2> operator()(I1 i, S1 s, I2 o_i, S2 o_s, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::random_access_range R2, typename Fn = ranges::less, typename P1 = identity, typename P2 = identity>
  requires indirectly_copyable<ranges::iterator_t<R1>, ranges::iterator_t<R2>> && sortable<ranges::iterator_t<R2>, Fn, P2> &&
           indirect_strict_weak_order<Fn, projected<ranges::iterator_t<R1>, P1>, projected<ranges::iterator_t<R2>, P2>>
  constexpr ranges::partial_sort_copy_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>>
  operator()(R1&& r, R2&& o_r, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _stable_sort {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _nth_element {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr It operator()(It i, It nth, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, ranges::iterator_t<Rg> nth, Fn comp = {}, Pj p = {}) const;
};

}

namespace std::ranges {

inline constexpr _::_is_sorted is_sorted;
inline constexpr _::_is_sorted_until is_sorted_until;
inline constexpr _::_sort sort;
inline constexpr _::_partial_sort partial_sort;
inline constexpr _::_partial_sort_copy partial_sort_copy;
inline constexpr _::_stable_sort stable_sort;
inline constexpr _::_nth_element nth_element;

}

//==============================================================================
// binary search operations

namespace std::_ {

struct _lower_bound {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Fn = ranges::less>
  constexpr It operator()(It i, Se s, const Ty& v, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, const Ty& v, Fn comp = {}, Pj p = {}) const;
};

struct _upper_bound {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Fn = ranges::less>
  constexpr It operator()(It i, Se s, const Ty& v, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, const Ty& v, Fn comp = {}, Pj p = {}) const;
};

struct _binary_search {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Fn = ranges::less>
  constexpr bool operator()(It i, Se s, const Ty& v, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr bool operator()(Rg&& r, const Ty& v, Fn comp = {}, Pj p = {}) const;
};

struct _equal_range {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Fn = ranges::less>
  constexpr ranges::subrange<It> operator()(It i, Se s, const Ty& v, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, const Ty& v, Fn comp = {}, Pj p = {}) const;
};

}

namespace std::ranges {

inline constexpr _::_lower_bound lower_bound;
inline constexpr _::_upper_bound upper_bound;
inline constexpr _::_binary_search binary_search;
inline constexpr _::_equal_range equal_range;

}

//==============================================================================
// merge operations

namespace std::_ {

struct _merge {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, weakly_incrementable Ot,
           typename Fn = ranges::less, typename P1 = identity, typename P2 = identity> requires mergeable<I1, I2, Ot, Fn, P1, P2>
  constexpr ranges::merge_result<I1, I2, Ot> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, weakly_incrementable Ot, typename Fn = ranges::less,
           typename P1 = identity, typename P2 = identity> requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Fn, P1, P2>
  constexpr ranges::merge_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  operator()(R1&& r1, R2&& r2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _inplace_merge {
  template<bidirectional_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  It operator()(It i, It middle, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::bidirectional_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, ranges::iterator_t<Rg> middle, Fn comp = {}, Pj p = {}) const;
};

}

namespace std::ranges {

inline constexpr _::_merge merge;
inline constexpr _::_inplace_merge inplace_merge;

}

//==============================================================================
// set operations

namespace std::_ {

struct _includes {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
           indirect_strict_weak_order<projected<I1, P1>, projected<I2, P2>> Fn = ranges::less>
  constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, typename P1 = identity, typename P2 = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<R1>, P1>, projected<ranges::iterator_t<R2>, P2>> Fn = ranges::less>
  constexpr bool operator()(R1&& r1, R2&& r2, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _set_difference {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, weakly_incrementable Ot,
           typename Fn = ranges::less, typename P1 = identity, typename P2 = identity> requires mergeable<I1, I2, Ot, Fn, P1, P2>
  constexpr ranges::set_difference_result<I1, Ot> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, weakly_incrementable Ot, typename Fn = ranges::less, typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Fn, P1, P2>
  constexpr ranges::set_difference_result<ranges::borrowed_iterator_t<R1>, Ot> operator()(R1&& r1, R2&& r2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _set_intersection {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, weakly_incrementable Ot,
           typename Fn = ranges::less, typename P1 = identity, typename P2 = identity> requires mergeable<I1, I2, Ot, Fn, P1, P2>
  constexpr ranges::set_intersection_result<I1, I2, Ot> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, weakly_incrementable Ot, typename Fn = ranges::less, typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Fn, P1, P2>
  constexpr ranges::set_intersection_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  operator()(R1&& r1, R2&& r2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _set_symmetric_difference {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, weakly_incrementable Ot,
           typename Fn = ranges::less, typename P1 = identity, typename P2 = identity> requires mergeable<I1, I2, Ot, Fn, P1, P2>
  constexpr ranges::set_symmetric_difference_result<I1, I2, Ot> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, weakly_incrementable Ot, typename Fn = ranges::less,
           typename P1 = identity, typename P2 = identity> requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Fn, P1, P2>
  constexpr ranges::set_symmetric_difference_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  operator()(R1&& r1, R2&& r2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _set_union {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, weakly_incrementable Ot, typename Fn = ranges::less,
           typename P1 = identity, typename P2 = identity> requires mergeable<I1, I2, Ot, Fn, P1, P2>
  constexpr ranges::set_union_result<I1, I2, Ot> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::input_range R1, ranges::input_range R2, weakly_incrementable Ot, typename Fn = ranges::less, typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Fn, P1, P2>
  constexpr ranges::set_union_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  operator()(R1&& r1, R2&& r2, Ot o, Fn comp = {}, P1 p1 = {}, P2 p2 = {}) const;
};

}

namespace std::ranges {

inline constexpr _::_includes includes;
inline constexpr _::_set_difference set_difference;
inline constexpr _::_set_intersection set_intersection;
inline constexpr _::_set_symmetric_difference set_symmetric_difference;
inline constexpr _::_set_union set_union;

}

//==============================================================================
// heap operations

namespace std::_ {

struct _is_heap {
  template<random_access_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_strict_weak_order<projected<It, Pj>> Fn = ranges::less>
  constexpr bool operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr bool operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _is_heap_until {
  template<random_access_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_strict_weak_order<projected<It, Pj>> Fn = ranges::less>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _make_heap {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _push_heap {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _pop_heap {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _sort_heap {
  template<random_access_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::random_access_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

}

namespace std::ranges {

inline constexpr _::_is_heap is_heap;
inline constexpr _::_is_heap_until is_heap_until;
inline constexpr _::_make_heap make_heap;
inline constexpr _::_push_heap push_heap;
inline constexpr _::_pop_heap pop_heap;
inline constexpr _::_sort_heap sort_heap;
}

//==============================================================================
// min / max operations

namespace std::_ {

struct _max {
  template<typename Ty, typename Pj = identity,indirect_strict_weak_order<projected<const Ty*, Pj>> Fn = ranges::less>
  constexpr const Ty& operator()(const Ty& a, const Ty& b, Fn comp = {}, Pj p = {}) const;
  template<copyable Ty, typename Pj = identity,indirect_strict_weak_order<projected<const Ty*, Pj>> Fn = ranges::less>
  constexpr Ty operator()(initializer_list<Ty> r, Fn comp = {}, Pj p = {}) const;
  template<ranges::input_range Rg, typename Pj = identity,indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  requires indirectly_copyable_storable<ranges::iterator_t<Rg>, ranges::range_value_t<Rg>*>
  constexpr ranges::range_value_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _min {
  template<typename Ty, typename Pj = identity, indirect_strict_weak_order<projected<const Ty*, Pj>> Fn = ranges::less>
  constexpr const Ty& operator()(const Ty& a, const Ty& b, Fn comp = {}, Pj p = {}) const;
  template<copyable Ty, typename Pj = identity, indirect_strict_weak_order<projected<const Ty*, Pj>> Fn = ranges::less>
  constexpr Ty operator()(initializer_list<Ty> r, Fn comp = {}, Pj p = {}) const;
  template<ranges::input_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  requires indirectly_copyable_storable<ranges::iterator_t<Rg>, ranges::range_value_t<Rg>*>
  constexpr ranges::range_value_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _minmax {
  template<typename Ty, typename Pj = identity,indirect_strict_weak_order<projected<const Ty*, Pj>> Fn = ranges::less>
  constexpr ranges::minmax_result<const Ty&> operator()(const Ty& a, const Ty& b, Fn comp = {}, Pj p = {}) const;
  template<copyable Ty, typename Pj = identity,indirect_strict_weak_order<projected<const Ty*, Pj>> Fn = ranges::less>
  constexpr ranges::minmax_result<Ty> operator()(initializer_list<Ty> r, Fn comp = {}, Pj p = {}) const;
  template<ranges::input_range Rg, typename Pj = identity,indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  requires indirectly_copyable_storable<ranges::iterator_t<Rg>, ranges::range_value_t<Rg>*>
  constexpr ranges::minmax_result<ranges::range_value_t<Rg>> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _max_element {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_strict_weak_order<projected<It, Pj>> Fn = ranges::less>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _min_element {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_strict_weak_order<projected<It, Pj>> Fn = ranges::less>
  constexpr It operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _minmax_element {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_strict_weak_order<projected<It, Pj>> Fn = ranges::less>
  constexpr ranges::minmax_element_result<It> operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::forward_range Rg, typename Pj = identity, indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Fn = ranges::less>
  constexpr ranges::minmax_element_result<ranges::borrowed_iterator_t<Rg>> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _clamp {
  template<typename Ty, typename Pj = identity, indirect_strict_weak_order<projected<const Ty*, Pj>> Fn = ranges::less>
  constexpr const Ty& operator()(const Ty& v, const Ty& lo, const Ty& hi, Fn comp = {}, Pj p = {}) const;
};

}

namespace std::ranges {

inline constexpr _::_max max;
inline constexpr _::_min min;
inline constexpr _::_minmax minmax;
inline constexpr _::_max_element max_element;
inline constexpr _::_min_element min_element;
inline constexpr _::_minmax_element minmax_element;
inline constexpr _::_clamp clamp;

}

//==============================================================================
// permutaion operations

namespace std::_ {

struct _is_permutation {
  template<forward_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
          indirect_equivalence_relation<projected<I1, P1>, projected<I2, P2>> Fn = ranges::equal_to>
  constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  template<ranges::forward_range R1, ranges::forward_range R2, typename P1 = identity, typename P2 = identity,
          indirect_equivalence_relation<projected<ranges::iterator_t<R1>, P1>, projected<ranges::iterator_t<R2>, P2>> Fn = ranges::equal_to>
  constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
};

struct _next_permutation {
  template<bidirectional_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr ranges::next_permutation_result<It> operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::bidirectional_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::next_permutation_result<ranges::borrowed_iterator_t<Rg>> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

struct _prev_premutation {
  template<bidirectional_iterator It, sentinel_for<It> Se, typename Fn = ranges::less, typename Pj = identity> requires sortable<It, Fn, Pj>
  constexpr ranges::prev_permutation_result<It> operator()(It i, Se s, Fn comp = {}, Pj p = {}) const;
  template<ranges::bidirectional_range Rg, typename Fn = ranges::less, typename Pj = identity> requires sortable<ranges::iterator_t<Rg>, Fn, Pj>
  constexpr ranges::prev_permutation_result<ranges::borrowed_iterator_t<Rg>> operator()(Rg&& r, Fn comp = {}, Pj p = {}) const;
};

}

namespace std::ranges {

inline constexpr _::_is_permutation is_permutation;
inline constexpr _::_next_permutation next_permutation;
inline constexpr _::_prev_premutation prev_permutation;

}

#endif
