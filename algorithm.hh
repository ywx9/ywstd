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
#include "@/../ranges.hh"
#include "@/ranges-equal_to.hh"

namespace std {

namespace _ {
  template<typename Fn, typename I1, typename I2, typename P1 = identity, typename P2 = identity>
  concept iter_comparable = indirect_binary_predicate<Fn, projected<I1, P1>, projected<I2, P2>>;
  template<typename Fn, typename R1, typename R2, typename P1 = identity, typename P2 = identity>
  concept range_comparable = iter_comparable<Fn, ranges::iterator_t<R1>, ranges::iterator_t<R2>, P1, P2>;
}

namespace ranges {
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
  template<typename It, typename Ot> struct in_out_result {
    [[no_unique_address]] It in; [[no_unique_address]] Ot out;
    template<_::convertible_from<const It&> ItA, _::convertible_from<const Ot&> OtA> constexpr operator in_out_result<ItA, OtA>() const& { return {in, out}; }
    template<_::convertible_from<It> ItA, _::convertible_from<Ot> OtA> constexpr operator in_out_result<ItA, OtA>() && { return {_::move(in), _::move(out)}; }
  };
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
}

//##############################################################################################################################################################

template<typename InpIt, typename Ty> constexpr InpIt find(InpIt i, InpIt s, const Ty& v) { for (; i != s; ++i) if (*i == v) return i; return s; }
template<_::execution_policy Exec, typename FwdIt, typename Ty> FwdIt find(Exec&&, FwdIt i, FwdIt s, const Ty& v);

template<typename InpIt, typename Fn> constexpr InpIt find_if(InpIt i, InpIt s, Fn f) { for (; i != s; ++i) if (f(*i)) return i; return s; }
template<_::execution_policy Exec, typename FwdIt, typename Fn> FwdIt find_if(Exec&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr InpIt find_if_not(InpIt i, InpIt s, Fn f) { for (; i != s; ++i) if (!f(*i)) return i; return s; }
template<_::execution_policy Exec, typename FwdIt, typename Fn> FwdIt find_if_not(Exec&&, FwdIt i, FwdIt s, Fn f);

namespace _ {
  struct _find {
    template<input_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, It, const Ty*, Pj>
    constexpr It operator()(It i, Se s, const Ty& v, Pj p = {}) const { for (; i != s; ++i) if (std:::invoke(p, *i) == v) break; return i; }
    template<ranges::input_rage Rg, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, ranges::iterator_t<Rg>, const Ty*, Pj>
    constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, const Ty& v, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r),v,_::move(p));}
  };
  struct _find_if {
    template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    constexpr It operator()(It i, Se s, Fn f, Pj p = {}) const { for (; i != s; ++i) if (std::invoke(f, std::invoke(p, *i))) break; return i; }
    template<ranges::input_rage Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(p)); }
  };
  struct _find_if_not {
    template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    constexpr It operator()(It i, Se s, Fn f, Pj p = {}) const { for (; i != s; ++i) if (!std::invoke(f, std::invoke(p, *i))) break; return i; }
    template<ranges::input_rage Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), _::move(p)); }
  };
}

namespace ranges {
  inline constexpr _::_find        find;
  inline constexpr _::_find_if     find_if;
  inline constexpr _::_find_if_not find_if_not;
}

//##############################################################################################################################################################

template<typename InpIt, typename Fn> constexpr bool all_of(InpIt i, InpIt s, Fn f) { return std::find_if_not(i, s, f) == s; }
template<_::execution_policy Exec, typename FwdIt, typename Fn> bool all_of(Exec&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr bool any_of(InpIt i, InpIt s, Fn f) { return std::find_if(i, s, f) != s; }
template<_::execution_policy Exec, typename FwdIt, typename Fn> bool any_of(Exec&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Fn> constexpr bool none_of(InpIt i, InpIt s, Fn f) { return std::find_if(i, s, p) == s; }
template<_::execution_policy Exec, typename FwdIt, typename Fn> bool none_of(Exec&&, FwdIt i, FwdIt s, Fn f);

namespace _ {
  struct _all_of {
    template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    constexpr bool operator()(It i, Se s, Fn f, Pj p = {}) const { return ranges::find_if_not(i, s, move(f), move(p)) == s; }
    template<ranges::input_rage Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    constexpr bool operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), move(f), move(p)); }
  };
  struct _any_of {
    template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    constexpr bool operator()(It i, Se s, Fn f, Pj p = {}) const { return ranges::find_if(i, s, move(f), move(p)) != s; }
    template<ranges::input_rage Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    constexpr bool operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), move(f), move(p)); }
  };
  struct _none_of {
    template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    constexpr bool operator()(It i, Se s, Fn f, Pj p = {}) const { return ranges::find_if(i, s, move(f), move(p)) == s; }
    template<ranges::input_rage Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    constexpr bool operator()(Rg&& r, Fn f, Pj p = {}) const { return (*this)(ranges::begin(r), ranges::end(r), move(f), move(p)); }
  };
}

namespace ranges {
  inline constexpr _::_all_of  all_of;
  inline constexpr _::_any_of  any_of;
  inline constexpr _::_none_of none_of;
}

//##############################################################################################################################################################

template<typename InpIt, typename Fn> constexpr Fn for_each(InpIt i, InpIt s, Fn f) { for (; i != s; ++i) f(*i); return f; }
template<_::execution_policy Exec, typename FwdIt, typename Fn> void for_each(Exec&&, FwdIt i, FwdIt s, Fn f);

template<typename InpIt, typename Size, typename Fn> constexpr InpIt for_each_n(InpIt i, Size n, Fn f) { for (; n != 0; ++i, --n) f(*i); return i; }
template<_::execution_policy Exec, typename FwdIt, typename Size, typename Fn> FwdIt for_each_n(Exec&&, FwdIt i, Size n, Fn f);

namespace ranges {
  template<typename It, typename Fn> using for_each_result = in_fun_result<It, Fn>;
  template<typename It, typename Fn> using for_each_n_result = in_fun_result<It, Fn>;
}

namespace _ {
  struct _for_each {
    template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirectly_unary_invocable<projected<It, Pj>> Fn> constexpr for_each_result<It, Fn>
    operator()(It i, Se s, Fn f, Pj p = {}) const { for (; i != s; ++i) invoke(f, invoke(p, *i)); return {_::move(i), _::move(s)}; }
    template<ranges::input_rage Rg, typename Pj = identity, indirectly_unary_invocable<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    constexpr ranges::for_each_result<ranges::borrowed_iterator_t<Rg>, Fn> operator()(Rg&& r, Fn f, Pj p = {}) const
    { return (*this)(ranges::begin(r), ranges::end(r), _::move(f), _::move(p)); }
  };
  struct _for_each_n {
    template<input_iterator It, typename Pj = identity, indirectly_unary_invocable<projected<It, Pj>> Fn> constexpr ranges::for_each_n_result<It, Fn>
    operator()(It i, iter_difference_t<It> n, Fn f, Pj p = {}) const { for (; n != 0; ++i, --n) invoke(f, invoke(p, *i)); return {_::move(i), _::move(f)}; }
  };
}

namespace ranges {
  inline constexpr _::_for_each   for_each;
  inline constexpr _::_for_each_n for_each;
}

//##############################################################################################################################################################

template<typename FwdIt1, typename FwdIt2> constexpr FwdIt1 find_end(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<typename FwdIt1, typename FwdIt2, typename Fn> constexpr FwdIt1 find_end(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> FwdIt1 find_end(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> FwdIt1 find_end(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2, Fn f);

namespace _ {
  struct _find_end {
    template<forward_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
             iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
    constexpr subrange<I1> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::forward_range R1, ranges::forward_range R2, typename P1 = identity, typename P2 = identity,
             range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
    constexpr borrowed_subrange_t<R1> operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {});
  };
}

namespace ranges {
  inline constexpr _::_find_end find_end;
}

//##############################################################################################################################################################

template<typename InpIt, typename FwdIt> constexpr InpIt find_first_of(InpIt i1, InpIt s1, FwdIt i2, FwdIt s2);
template<typename InpIt, typename FwdIt, typename Fn> constexpr InpIt find_first_of(InpIt i1, InpIt s1, FwdIt i2, FwdIt s2, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> FwdIt1 find_first_of(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> FwdIt1 find_first_of(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2, Fn f);

namespace _ {
  struct _find_first_of {
    template<input_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2,
             typename P1 = identity, typename P2 = identity, iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
    constexpr I1 operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::input_rage R1, ranges::forward_range R2,
             typename P1 = identity, typename P2 = identity, range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
    constexpr ranges::borrowed_iterator_t<R1> find_first_of(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {});
  };
}

namespace ranges {
  inline constexpr _::_find_first_of find_first_of;
}

//##############################################################################################################################################################

template<typename FwdIt> constexpr FwdIt adjacent_find(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn> constexpr FwdIt adjacent_find(FwdIt i, FwdIt s, Fn f);
template<_::execution_policy Exec, typename FwdIt> FwdIt adjacent_find(Exec&&, FwdIt i, FwdIt s);
template<_::execution_policy Exec, typename FwdIt, typename Fn> FwdIt adjacent_find(Exec&&, FwdIt i, FwdIt s, Fn f);

namespace _ {
  struct _adjacent_find {
    template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity, iter_comparable<It, It, Pj, Pj> Fn = ranges::equal_to>
    constexpr It operator()(It i, Se s, Fn f = {}, Pj p = {}) const;
    template<ranges::forward_range Rg, typename Pj = identity, range_comparable<Rg, Pj, Rg, Pj> Fn = ranges::equal_to>
    constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f = {}, Pj p = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_adjacent_find adjacent_find;
}

//##############################################################################################################################################################

template<typename InpIt, typename Ty> constexpr typename ranges::iterator_traits<InpIt>::difference_type count(InpIt i, InpIt s, const Ty& v);
template<_::execution_policy Exec,typename FwdIt,typename Ty>typename ranges::iterator_traits<FwdIt>::difference_type count(Exec&&,FwdIt i,FwdIt s,const Ty& v);
template<typename InpIt, typename Fn> constexpr typename ranges::iterator_traits<InpIt>::difference_type count_if(InpIt i, InpIt s, Fn f);
template<_::execution_policy Exec, typename FwdIt, typename Fn> typename ranges::iterator_traits<FwdIt>::difference_type count_if(Exec&&, FwdIt i,FwdIt s,Fn f);

namespace _ {
  struct count {
    template<input_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, It, const Ty*, Pj>
    constexpr iter_difference_t<It> operator()(It i, Se s, const Ty& v, Pj p = {}) const;
    template<ranges::input_rage Rg, typename Ty, typename Pj = identity> requires iter_comparable<ranges::equal_to, ranges::iterator_t<Rg>, const Ty*, Pj>
    constexpr ranges::range_difference_t<Rg> operator()(Rg&& r, const Ty& v, Pj p = {}) const;
  };
  struct count_if {
    template<input_iterator It, sentinel_for<It> Se, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    constexpr iter_difference_t<It> operator()(It i, Se s, Fn f, Pj p = {}) const;
    template<ranges::input_rage Rg, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    constexpr ranges::range_difference_t<Rg> operator()(Rg&& r, Fn f, Pj p = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_count count;
  inline constexpr _::_count_if count_if;
}

//##############################################################################################################################################################

template<typename InpIt1, typename InpIt2> constexpr pair<InpIt1, InpIt2> mismatch(InpIt1 i1, InpIt1 s1, InpIt2 i2);
template<typename InpIt1, typename InpIt2, typename Fn> constexpr pair<InpIt1, InpIt2> mismatch(InpIt1 i1, InpIt1 s1, InpIt2 i2, Fn f);
template<typename InpIt1, typename InpIt2> constexpr pair<InpIt1, InpIt2> mismatch(InpIt1 i1, InpIt1 s1, InpIt2 i2, InpIt2 s2);
template<typename InpIt1, typename InpIt2, typename Fn> constexpr pair<InpIt1, InpIt2> mismatch(InpIt1 i1, InpIt1 s1, InpIt2 i2, InpIt2 s2, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> pair<FwdIt1, FwdIt2> mismatch(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> pair<FwdIt1, FwdIt2> mismatch(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> pair<FwdIt1, FwdIt2> mismatch(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<_::execution_policy Exec,typename FwdIt1,typename FwdIt2,typename Fn>pair<FwdIt1,FwdIt2> mismatch(Exec&&,FwdIt1 i1,FwdIt1 s1,FwdIt2 i2,FwdIt2 s2,Fn f);

namespace ranges { template<typename I1, typename I2> using mismatch_result = in_in_result<I1, I2>; }

namespace _ {
  struct _mismatch {
    template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
             iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
    constexpr ranges::mismatch_result<I1, I2> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::input_rage R1, ranges::input_rage R2, typename P1 = identity, typename P2 = identity,
             range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
    constexpr ranges::mismatch_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>>
    operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_mismatch mismatch;
}

//##############################################################################################################################################################

template<typename InpIt1, typename InpIt2> constexpr bool equal(InpIt1 i1, InpIt1 s1, InpIt2 i2);
template<typename InpIt1, typename InpIt2, typename Fn> constexpr bool equal(InpIt1 i1, InpIt1 s1, InpIt2 i2, Fn f);
template<typename InpIt1, typename InpIt2> constexpr bool equal(InpIt1 i1, InpIt1 s1, InpIt2 i2, InpIt2 s2);
template<typename InpIt1, typename InpIt2, typename Fn> constexpr bool equal(InpIt1 i1, InpIt1 s1, InpIt2 i2, InpIt2 s2, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> bool equal(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> bool equal(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> bool equal(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> bool equal(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2, Fn f);

namespace _ {
  struct _equal {
    template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
             iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
    constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::input_rage R1, ranges::input_rage R2,typename P1 = identity, typename P2 = identity,
             range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
    constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_equal equal;
}

//##############################################################################################################################################################

template<typename FwdIt1, typename FwdIt2> constexpr bool is_permutation(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2);
template<typename FwdIt1, typename FwdIt2, typename Fn> constexpr bool is_permutation(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, Fn f);
template<typename FwdIt1, typename FwdIt2> constexpr bool is_permutation(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<typename FwdIt1, typename FwdIt2, typename Fn> constexpr bool is_permutation(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2, Fn f);

namespace _ {
  struct _is_permutation {
    template<forward_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
            indirect_equivalence_relation<projected<I1, P1>, projected<I2, P2>> Fn = ranges::equal_to>
    constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::forward_range R1, ranges::forward_range R2, typename P1 = identity, typename P2 = identity,
            indirect_equivalence_relation<projected<ranges::iterator_t<R1>, P1>, projected<ranges::iterator_t<R2>, P2>> Fn = ranges::equal_to>
    constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_is_permutation is_permutation;
}

//##############################################################################################################################################################

template<typename FwdIt1, typename FwdIt2> constexpr FwdIt1 search(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<typename FwdIt1, typename FwdIt2, typename Fn> constexpr FwdIt1 search(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> FwdIt1 search(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> FwdIt1 search(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdIt2 s2, Fn f);
template<typename FwdIt, typename Seearcher> constexpr FwdIt search(FwdIt i, FwdIt s, const Seearcher& searcher);

template<typename FwdIt, typename Size, typename Ty> constexpr FwdIt search_n(FwdIt i, FwdIt s, Size n, const Ty& v);
template<typename FwdIt, typename Size, typename Ty, typename Fn> constexpr FwdIt search_n(FwdIt i, FwdIt s, Size n, const Ty& v, Fn f);
template<_::execution_policy Exec, typename FwdIt, typename Size, typename Ty> FwdIt search_n(Exec&&, FwdIt i, FwdIt s, Size n, const Ty& v);
template<_::execution_policy Exec, typename FwdIt, typename Size, typename Ty, typename Fn> FwdIt search_n(Exec&&, FwdIt i, FwdIt s, Size n, const Ty& v, Fn f);


namespace _ {
  struct _search {
    template<forward_iterator I1, sentinel_for<I1> S1, forward_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
             iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
    constexpr ranges::subrange<I1> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::forward_range R1, ranges::forward_range R2, typename P1 = identity, typename P2 = identity,
             range_comparable<R1, R2, P1, p2> Fn = ranges::equal_to>
    constexpr ranges::borrowed_subrange_t<R1> operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  };
  struct _search_n {
    template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity, iter_comparable<It, const Ty*, Pj> Fn = ranges::equal_to>
    constexpr ranges::subrange<It> operator()(It i, Se s, iter_difference_t<It> n, const Ty& v, Fn f = {}, Pj p = {}) const;
    template<ranges::forward_range Rg, typename Ty, typename Pj = identity, iter_comparable<ranges::iterator_t<Rg>, const Ty*, Pj> Fn = ranges::equal_to>
    constexpr ranges::borrowed_subrange_t<Rg> operator()(Rg&& r, ranges::range_difference_t<Rg> n, const Ty& v, Fn f = {}, Pj p = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_search   search;
  inline constexpr _::_search_n search_n;
}

//##############################################################################################################################################################

namespace _ {
  struct _starts_with {
    template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
             iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
    constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::input_rage R1, ranges::input_rage R2, typename P1 = identity, typename P2 = identity,
             range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
    constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  };
  struct _ends_with {
    template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, typename P1 = identity, typename P2 = identity,
             iter_comparable<I1, I2, P1, P2> Fn = ranges::equal_to>
    requires (forward_iterator<I1> || sized_sentinel_for<S1, I1>) && (forward_iterator<I2> || sized_sentinel_for<S2, I2>)
    constexpr bool operator()(I1 i1, S1 s1, I2 i2, S2 s2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
    template<ranges::input_rage R1, ranges::input_rage R2, typename P1 = identity, typename P2 = identity,
             range_comparable<R1, R2, P1, P2> Fn = ranges::equal_to>
    requires (ranges::forward_range<R1> || ranges::sized_range<R1>) && (ranges::forward_range<R2> || ranges::sized_range<R2>)
    constexpr bool operator()(R1&& r1, R2&& r2, Fn f = {}, P1 p1 = {}, P2 p2 = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_starts_with starts_with;
  inline constexpr _::_ends_with ends_with;
}

//##############################################################################################################################################################

template<typename InpIt, typename OutIt> constexpr OutIt copy(InpIt i, InpIt s, OutIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> FwdIt2 copy(Exec&&, FwdIt1 i, FwdIt1 s, FwdIt2 o);

template<typename InpIt, typename Size, typename OutIt> constexpr OutIt copy_n(InpIt i, Size n, OutIt o);
template<_::execution_policy Exec, typename FwdIt1, typename Size, typename FwdIt2> FwdIt2 copy_n(Exec&&, FwdIt1 i, Size n, FwdIt2 o);

template<typename InpIt, typename OutIt, typename Fn> constexpr OutIt copy_if(InpIt i, InpIt s, OutIt o, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> FwdIt2 copy_if(Exec&&, FwdIt1 i, FwdIt1 s, FwdIt2 o, Fn f);

template<typename BidIt1, typename BidIt2> constexpr BidIt2 copy_backward(BidIt1 i, BidIt1 s, BidIt2 o);

namespace ranges {
  template<typename It, typename Ot> using copy_result          = in_out_result<It, Ot>;
  template<typename It, typename Ot> using copy_n_result        = in_out_result<It, Ot>;
  template<typename It, typename Ot> using copy_if_result       = in_out_result<It, Ot>;
  template<typename It, typename Ot> using copy_backward_result = in_out_result<It, Ot>;
}

namespace _ {
  struct _copy {
    template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot> requires indirectly_copyable<It, Ot>
    constexpr ranges::copy_result<It, Ot> operator()(It i, Se s, Ot o) const;
    template<ranges::input_rage Rg, weakly_incrementable Ot> requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
    constexpr ranges::copy_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o) const;
  };
  struct _copy_n {
    template<input_iterator It, weakly_incrementable Ot> requires indirectly_copyable<It, Ot>
    constexpr copy_n_result<It, Ot> operator()(It i, iter_difference_t<It> n, Ot o) const;
  };
  struct _copy_if {
    template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    requires indirectly_copyable<It, Ot> constexpr ranges::copy_if_result<It, Ot> operator()(It i, Se s, Ot o, Fn f, Pj p = {}) const;
    template<ranges::input_rage Rg, weakly_incrementable Ot, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> constexpr ranges::copy_if_result<ranges::borrowed_iterator_t<Rg>, Ot>
    operator()(Rg&& r, Ot o, Fn f, Pj p = {}) const;
  };
  struct _copy_backward {
    template<bidirectional_iterator I1, sentinel_for<I1> S1, bidirectional_iterator I2> requires indirectly_copyable<I1, I2>
    constexpr ranges::copy_backward_result<I1, I2> operator()(I1 i, S1 s, I2 o) const;
    template<bidirectional_range Rg, bidirectional_iterator It> requires indirectly_copyable<ranges::iterator_t<Rg>, It>
    constexpr ranges::copy_backward_result<ranges::borrowed_iterator_t<Rg>, It> operator()(Rg&& r, It o) const;
  };
}

namespace ranges {
  inline constexpr _::_copy          copy;
  inline constexpr _::_copy_n        copy_n;
  inline constexpr _::_copy_if       copy_if;
  inline constexpr _::_copy_backward copy_backward;
}

//##############################################################################################################################################################

template<typename InpIt, typename OutIt> constexpr OutIt move(InpIt i, InpIt s, OutIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> FwdIt2 move(Exec&&, FwdIt1 i, FwdIt1 s, FwdIt2 o);

template<typename BidIt1, typename BidIt2> constexpr BidIt2 move_backward(BidIt1 i, BidIt1 s, BidIt2 o);

namespace ranges {
  template<typename It, typename Ot> using move_result          = in_out_result<It, Ot>;
  template<typename I1, typename I2> using move_backward_result = in_out_result<I1, I2>;
}

namespace _ {
  struct _move {
    template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot> requires indirectly_movable<It, Ot>
    constexpr ranges::move_result<It, Ot> operator()(It i, Se s, Ot o) const;
    template<ranges::input_rage Rg, weakly_incrementable Ot> requires indirectly_movable<ranges::iterator_t<Rg>, Ot>
    constexpr ranges::move_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o) const;
  };
  struct _move_backward {
    template<bidirectional_iterator I1, sentinel_for<I1> S1, bidirectional_iterator I2> requires indirectly_movable<I1, I2>
    constexpr ranges::move_backward_result<I1, I2> operator()(I1 i, S1 s, I2 o) const;
    template<bidirectional_range Rg, bidirectional_iterator It> requires indirectly_movable<ranges::iterator_t<Rg>, It>
    constexpr ranges::move_backward_result<ranges::borrowed_iterator_t<Rg>, It> operator()(Rg&& r, It o) const;
  };
}

namespace ranges {
  inline constexpr _::_move          move;
  inline constexpr _::_move_backward move_backward;
}

//##############################################################################################################################################################

template<typename FwdIt1, typename FwdIt2> constexpr void iter_swap(FwdIt1 a, FwdIt2 b);
template<typename FwdIt1, typename FwdIt2> constexpr FwdIt2 swap_ranges(FwdIt1 i1, FwdIt1 s1, FwdIt2 i2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2> FwdIt2 swap_ranges(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2);

namespace ranges { template<typename I1, typename I2> using swap_ranges_result = in_in_result<I1, I2>; }

namespace _ {
  struct _swap_range {
    template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2> requires indirectly_swappable<I1, I2>
    constexpr ranges::swap_ranges_result<I1, I2> operator()(I1 i1, S1 s1, I2 i2, S2 s2) const;
    template<ranges::input_rage R1, ranges::input_rage R2> requires indirectly_swappable<ranges::iterator_t<R1>, ranges::iterator_t<R2>>
    constexpr ranges::swap_ranges_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>>
    operator()(R1&& r1, R2&& r2) const { return (*this)(ranges::begin(r1), ranges::end(r1), ranges::begin(r2), ranges::end(r2)); }
  };
}

namespace ranges {
  inline constexpr _::_swap_range swap_range;
}

//##############################################################################################################################################################

template<typename InpIt, typename OutIt, typename Fn> constexpr OutIt transform(InpIt i1, InpIt s1, OutIt o, Fn f);
template<typename InpIt1, typename InpIt2, typename OutIt, typename Fn> constexpr OutIt transform(InpIt1 i1, InpIt1 s1, InpIt2 i2, OutIt o, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn> FwdIt2 transform(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 o, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename FwdOt, typename Fn>
FwdIt transform(Exec&&, FwdIt1 i1, FwdIt1 s1, FwdIt2 i2, FwdOt o, Fn f);

namespace ranges {
  template<typename It, typename Ot> using unary_transform_result = in_out_result<It, Ot>;
  template<typename I1, typename I2, typename Ot> using binary_transform_result = in_in_out_result<I1, I2, Ot>;
}

namespace _ {
  struct _transform {
    template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, copy_constructible Fn, typename Pj = identity>
    requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<It, Pj>>>
    constexpr ranges::unary_transform_result<It, Ot> operator()(It i, Se s1, Ot o, Fn f, Pj p = {}) const;
    template<ranges::input_rage Rg, weakly_incrementable Ot, copy_constructible Fn, typename Pj = identity>
    requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<ranges::iterator_t<Rg>, Pj>>>
    constexpr ranges::unary_transform_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o, Fn f, Pj p = {}) const;
    template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2, weakly_incrementable Ot, copy_constructible Fn,
             typename P1 = identity, typename P2 = identity> requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<I1, P1>, projected<I2, P2>>>
    constexpr ranges::binary_transform_result<I1, I2, Ot> operator()(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Fn f, P1 p1 = {}, P2 p2 = {});
    template<ranges::input_rage R1, ranges::input_rage R2, weakly_incrementable Ot, copy_constructible Fn, typename P1 = identity, typename P2 = identity>
    requires indirectly_writable<Ot, indirect_result_t<Fn&, projected<ranges::iterator_t<R1>, P1>, projected<ranges::iterator_t<R2>, P2>>>
    constexpr ranges::binary_transform_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
    operator()(R1&& r1, R2&& r2, Ot o, Fn f, P1 p1 = {}, P2 p2 = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_transform transform;
}

//##############################################################################################################################################################

template<typename FwdIt, typename Ty> constexpr void replace(FwdIt i, FwdIt s, const Ty& old_v, const Ty& new_v);
template<_::execution_policy Exec, typename FwdIt, typename Ty> void replace(Exec&&, FwdIt i, FwdIt s, const Ty& old_v, const Ty& new_v);

template<typename FwdIt, typename Fn, typename Ty> constexpr void replace_if(FwdIt i, FwdIt s, Fn f, const Ty& new_v);
template<_::execution_policy Exec, typename FwdIt, typename Fn, typename Ty> void replace_if(Exec&&, FwdIt i, FwdIt s, Fn f, const Ty& new_v);

template<typename InpIt, typename OutIt, typename Ty> constexpr OutIt replace_copy(InpIt i, InpIt s, OutIt o, const Ty& old_v, const Ty& new_v);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Ty>
FwdIt2 replace_copy(Exec&&, FwdIt1 i, FwdIt1 s, FwdIt2 o, const Ty& old_v, const Ty& new_v);

template<typename InpIt, typename OutIt, typename Fn, typename Ty> constexpr OutIt replace_copy_if(InpIt i, InpIt s, OutIt o, Fn f, const Ty& new_v);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2, typename Fn, typename Ty>
FwdIt2 replace_copy_if(Exec&&, FwdIt1 i, FwdIt1 s, FwdIt2 o, Fn f, const Ty& new_v);

namespace ranges {
  template<typename It, typename Ot> using replace_copy_result = in_out_result<It, Ot>;
  template<typename It, typename Ot> using replace_copy_if_result = in_out_result<It, Ot>;
}

namespace _ {
  struct _replace {
      template<input_iterator It, sentinel_for<It> Se, typename Ty1, typename Ty2, typename Pj = identity>
    requires indirectly_writable<It, const Ty2&> && indirect_binary_predicate<ranges::equal_to, projected<It, Pj>, const Ty1*>
    constexpr It operator()(It i, Se s, const Ty1& old_v, const Ty2& new_v, Pj p = {}) const;
    template<ranges::input_rage Rg, typename Ty1, typename Ty2, typename Pj = identity>
    requires indirectly_writable<ranges::iterator_t<Rg>, const Ty2&> && iter_comparable<ranges::equal_to, ranges::iterator_t<Rg>, const Ty1*, Pj>
    constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, const Ty1& old_v, const Ty2& new_v, Pj p = {}) const;
  };
  struct _replace_if {
    template<input_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
    requires indirectly_writable<It, const Ty&> constexpr It operator()(It i, Se s, Fn f, const Ty& new_v, Pj p = {}) const;
    template<ranges::input_rage Rg, typename Ty, typename Pj = identity, indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
    requires indirectly_writable<ranges::iterator_t<Rg>, const Ty&>
    constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, Fn f, const Ty& new_v, Pj p = {}) const;
  };
  struct _replace_copy {
    template<input_iterator It, sentinel_for<It> Se, typename Ty1, typename Ty2, output_iterator<const Ty2&> Ot, typename Pj = identity>
    requires indirectly_copyable<It, Ot> && indirect_binary_predicate<ranges::equal_to, projected<It, Pj>, const Ty1*>
    constexpr ranges::replace_copy_result<It, Ot> operator()(It i, Se s, Ot o, const Ty1& old_v, const Ty2& new_v, Pj p = {}) const;
    template<ranges::input_rage Rg, typename Ty1, typename Ty2, output_iterator<const Ty2&> Ot, typename Pj = identity>
    requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> && indirect_binary_predicate<ranges::equal_to, projected<ranges::iterator_t<Rg>, Pj>, const Ty1*>
    constexpr ranges::replace_copy_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o, const Ty1& old_v, const Ty2& new_v, Pj p = {}) const;
  };
  struct _replace_copy_if {
    template<input_iterator It, sentinel_for<It> Se, typename Ty, output_iterator<const Ty&> Ot, typename Pj = identity,
             indirect_unary_predicate<projected<It, Pj>> Fn> requires indirectly_copyable<It, Ot>
    constexpr ranges::replace_copy_if_result<It, Ot> operator()(It i, Se s, Ot o, Fn f, const Ty& new_v, Pj p = {}) const;
    template<ranges::input_rage Rg, typename Ty, output_iterator<const Ty&> Ot, typename Pj = identity,
             indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn> requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
    constexpr ranges::replace_copy_if_result<ranges::borrowed_iterator_t<Rg>, Ot> operator()(Rg&& r, Ot o, Fn f, const Ty& new_v, Pj p = {}) const;
  };
}

namespace ranges {
  inline constexpr _::_replace replace;
  inline constexpr _::_replace_if replace_if;
  inline constexpr _::_replace_copy replace_copy;
  inline constexpr _::_replace_copy_if replace_copy_if;
}

//##############################################################################################################################################################

template<typename FwdIt, typename Ty> constexpr void fill(FwdIt i, FwdIt s, const Ty& v);
template<_::execution_policy Exec, typename FwdIt, typename Ty> void fill(Exec&&, FwdIt i, FwdIt s, const Ty& v);

template<typename OutIt, typename Size, typename Ty> constexpr OutIt fill_n(OutIt i, Size n, const Ty& v);
template<_::execution_policy Exec, typename FwdIt, typename Size, typename Ty> FwdIt fill_n(Exec&&, FwdIt i, Size n, const Ty& v);

namespace _ {
  struct _fill {
    template<typename Ty, output_iterator<const Ty&> Ot, sentinel_for<Ot> Se>
    constexpr Ot operator()(Ot i, Se s, const Ty& v) const { for (;; *i++ = v) if (i == s) return i; }
    template<typename Ty, output_range<const Ty&> Rg>
    constexpr ranges::borrowed_iterator_t<Rg> operator()(Rg&& r, const Ty& v) const { return (*this)(ranges::begin(r), ranges::end(r), v); }
  };
  struct _fill_n {
    template<typename Ty, output_iterator<const Ty&> Ot> constexpr Ot operator()(Ot i, iter_difference_t<Ot> n, const Ty& v) const;
  };
}

namespace ranges {
  inline constexpr _::_fill   fill;
  inline constexpr _::_fill_n fill_n;
}

//##############################################################################################################################################################

template<typename FwdIt, typename Generator>
constexpr void generate(FwdIt i, FwdIt s,
                        Generator gen);
template<_::execution_policy Exec, typename FwdIt, typename Generator>
void generate(Exec&&,
              FwdIt i, FwdIt s,
              Generator gen);
template<typename OutIt, typename Size, typename Generator>
constexpr OutIt generate_n(OutIt i, Size n, Generator gen);
template<_::execution_policy Exec, typename FwdIt, typename Size, typename Generator>
FwdIt generate_n(Exec&&,
                       FwdIt i, Size n, Generator gen);

namespace ranges {
  template<input_or_output_iterator Ot, sentinel_for<Ot> Se, copy_constructible Fn>
  requires invocable<Fn&> && indirectly_writable<Ot, invoke_o_t<Fn&>>
  constexpr Ot generate(Ot i, Se s, Fn gen);
  template<typename Rg, copy_constructible Fn>
  requires invocable<Fn&> && output_range<Rg, invoke_o_t<Fn&>>
  constexpr ranges::borrowed_iterator_t<Rg> generate(Rg&& r, Fn gen);
  template<input_or_output_iterator Ot, copy_constructible Fn>
  requires invocable<Fn&> && indirectly_writable<Ot, invoke_o_t<Fn&>>
  constexpr Ot generate_n(Ot i, iter_difference_t<Ot> n, Fn gen);
}

// remove
template<typename FwdIt, typename Ty>
constexpr FwdIt remove(FwdIt i, FwdIt s,
                             const Ty& v);
template<_::execution_policy Exec, typename FwdIt, typename Ty>
FwdIt remove(Exec&&,
                   FwdIt i, FwdIt s,
                   const Ty& v);
template<typename FwdIt, typename Fn>
constexpr FwdIt remove_if(FwdIt i, FwdIt s,
                                Fn f);
template<_::execution_policy Exec, typename FwdIt, typename Fn>
FwdIt remove_if(Exec&&,
                      FwdIt i, FwdIt s,
                      Fn f);

namespace ranges {
  template<permutable It, sentinel_for<It> Se, typename Ty, typename Pj = identity>
  requires indirect_binary_predicate < ranges::equal_to, projected<It, Pj>,
  const Ty* >
    constexpr subrange<It> remove(It i, Se s, const Ty& v, Pj p = {});
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity>
  requires permutable<ranges::iterator_t<Rg>> &&
    indirect_binary_predicate < ranges::equal_to,
    projected<ranges::iterator_t<Rg>, Pj>,
  const Ty* >
    constexpr borrowed_subrange_t<Rg>
    remove(Rg&& r, const Ty& v, Pj p = {});
  template<permutable It, sentinel_for<It> Se, typename Pj = identity,
           indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr subrange<It> remove_if(It i, Se s, Fn f, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires permutable<ranges::iterator_t<Rg>>
  constexpr borrowed_subrange_t<Rg>
  remove_if(Rg&& r, Fn f, Pj p = {});
}

template<typename InpIt, typename OutIt, typename Ty>
constexpr OutIt
remove_copy(InpIt i, InpIt s,
            OutIt o, const Ty& v);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename Ty>
FwdIt2
remove_copy(Exec&&,
            FwdIt1 i, FwdIt1 s,
            FwdIt2 o, const Ty& v);
template<typename InpIt, typename OutIt, typename Fn>
constexpr OutIt
remove_copy_if(InpIt i, InpIt s,
               OutIt o, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename Fn>
FwdIt2
remove_copy_if(Exec&&,
               FwdIt1 i, FwdIt1 s,
               FwdIt2 o, Fn f);

namespace ranges {
  template<typename It, typename Ot>
  using remove_copy_result = in_out_result<It, Ot>;

  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, typename Ty,
           typename Pj = identity>
  requires indirectly_copyable<It, Ot> &&
    indirect_binary_predicate < ranges::equal_to,
    projected<It, Pj>,
  const Ty* >
    constexpr remove_copy_result<It, Ot>
    remove_copy(It i, Se s, Ot o, const Ty& v, Pj p = {});
  template<ranges::input_rage Rg, weakly_incrementable Ot, typename Ty, typename Pj = identity>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> &&
    indirect_binary_predicate < ranges::equal_to,
    projected<ranges::iterator_t<Rg>, Pj>,
  const Ty* >
    constexpr remove_copy_result<ranges::borrowed_iterator_t<Rg>, Ot>
    remove_copy(Rg&& r, Ot o, const Ty& v, Pj p = {});

  template<typename It, typename Ot>
  using remove_copy_if_result = in_out_result<It, Ot>;

  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot,
           typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  requires indirectly_copyable<It, Ot>
  constexpr remove_copy_if_result<It, Ot>
  remove_copy_if(It i, Se s, Ot o, Fn f, Pj p = {});
  template<ranges::input_rage Rg, weakly_incrementable Ot, typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
  constexpr remove_copy_if_result<ranges::borrowed_iterator_t<Rg>, Ot>
  remove_copy_if(Rg&& r, Ot o, Fn f, Pj p = {});
}

// unique
template<typename FwdIt>
constexpr FwdIt unique(FwdIt i, FwdIt s);
template<typename FwdIt, typename Fn>
constexpr FwdIt unique(FwdIt i, FwdIt s,
                             Fn f);
template<_::execution_policy Exec, typename FwdIt>
FwdIt unique(Exec&&,
                   FwdIt i, FwdIt s);
template<_::execution_policy Exec, typename FwdIt, typename Fn>
FwdIt unique(Exec&&,
                   FwdIt i, FwdIt s,
                   Fn f);

namespace ranges {
  template<permutable It, sentinel_for<It> Se, typename Pj = identity,
           indirect_equivalence_relation<projected<It, Pj>> C = ranges::equal_to>
  constexpr subrange<It> unique(It i, Se s, C comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_equivalence_relation<projected<ranges::iterator_t<Rg>, Pj>> C = ranges::equal_to>
  requires permutable<ranges::iterator_t<Rg>>
  constexpr borrowed_subrange_t<Rg>
  unique(Rg&& r, C comp = {}, Pj p = {});
}

template<typename InpIt, typename OutIt>
constexpr OutIt
unique_copy(InpIt i, InpIt s,
            OutIt o);
template<typename InpIt, typename OutIt, typename Fn>
constexpr OutIt
unique_copy(InpIt i, InpIt s,
            OutIt o, Fn f);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2>
FwdIt2
unique_copy(Exec&&,
            FwdIt1 i, FwdIt1 s,
            FwdIt2 o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename Fn>
FwdIt2
unique_copy(Exec&&,
            FwdIt1 i, FwdIt1 s,
            FwdIt2 o, Fn f);

namespace ranges {
  template<typename It, typename Ot>
  using unique_copy_result = in_out_result<It, Ot>;

  template<input_iterator It, sentinel_for<It> Se, weakly_incrementable Ot, typename Pj = identity,
           indirect_equivalence_relation<projected<It, Pj>> C = ranges::equal_to>
  requires indirectly_copyable<It, Ot> &&
    (forward_iterator<It> ||
     (input_iterator<Ot> && same_as<iter_v_t<It>, iter_v_t<Ot>>) ||
     indirectly_copyable_storable<It, Ot>)constexpr unique_copy_result<It, Ot> unique_copy(It i, Se s, Ot o, C comp = {}, Pj p = {});
  template<ranges::input_rage Rg, weakly_incrementable Ot, typename Pj = identity,
           indirect_equivalence_relation<projected<ranges::iterator_t<Rg>, Pj>> C = ranges::equal_to>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot> &&
    (forward_iterator<ranges::iterator_t<Rg>> ||
     (input_iterator<Ot> && same_as<range_v_t<Rg>, iter_v_t<Ot>>) ||
     indirectly_copyable_storable<ranges::iterator_t<Rg>, Ot>)constexpr unique_copy_result<ranges::borrowed_iterator_t<Rg>, Ot> unique_copy(Rg&& r, Ot o, C comp = {}, Pj p = {});
}

// reverse
template<typename BidIt>
constexpr void reverse(BidIt i, BidIt s);
template<_::execution_policy Exec, typename BidIt>
void reverse(Exec&&,
             BidIt i, BidIt s);

namespace ranges {
  template<bidirectional_iterator It, sentinel_for<It> Se>
  requires permutable<It>
  constexpr It reverse(It i, Se s);
  template<bidirectional_range Rg>
  requires permutable<ranges::iterator_t<Rg>>
  constexpr ranges::borrowed_iterator_t<Rg> reverse(Rg&& r);
}

template<typename BidIt, typename OutIt>
constexpr OutIt
reverse_copy(BidIt i, BidIt s,
             OutIt o);
template<_::execution_policy Exec, typename BidIt, typename FwdIt>
FwdIt
reverse_copy(Exec&&,
             BidIt i, BidIt s,
             FwdIt o);

namespace ranges {
  template<typename It, typename Ot>
  using reverse_copy_result = in_out_result<It, Ot>;

  template<bidirectional_iterator It, sentinel_for<It> Se, weakly_incrementable Ot>
  requires indirectly_copyable<It, Ot>
  constexpr reverse_copy_result<It, Ot>
  reverse_copy(It i, Se s, Ot o);
  template<bidirectional_range Rg, weakly_incrementable Ot>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
  constexpr reverse_copy_result<ranges::borrowed_iterator_t<Rg>, Ot>
  reverse_copy(Rg&& r, Ot o);
}

// rotate
template<typename FwdIt>
constexpr FwdIt rotate(FwdIt i,
                             FwdIt middle,
                             FwdIt s);
template<_::execution_policy Exec, typename FwdIt>
FwdIt rotate(Exec&&,
                   FwdIt i,
                   FwdIt middle,
                   FwdIt s);

namespace ranges {
  template<permutable It, sentinel_for<It> Se>
  constexpr subrange<It> rotate(It i, It middle, Se s);
  template<ranges::forward_range Rg>
  requires permutable<ranges::iterator_t<Rg>>
  constexpr borrowed_subrange_t<Rg> rotate(Rg&& r, ranges::iterator_t<Rg> middle);
}

template<typename FwdIt, typename OutIt>
constexpr OutIt
rotate_copy(FwdIt i, FwdIt middle,
            FwdIt s, OutIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2>
FwdIt2
rotate_copy(Exec&&,
            FwdIt1 i, FwdIt1 middle,
            FwdIt1 s, FwdIt2 o);

namespace ranges {
  template<typename It, typename Ot>
  using rotate_copy_result = in_out_result<It, Ot>;

  template<forward_iterator It, sentinel_for<It> Se, weakly_incrementable Ot>
  requires indirectly_copyable<It, Ot>
  constexpr rotate_copy_result<It, Ot>
  rotate_copy(It i, It middle, Se s, Ot o);
  template<ranges::forward_range Rg, weakly_incrementable Ot>
  requires indirectly_copyable<ranges::iterator_t<Rg>, Ot>
  constexpr rotate_copy_result<ranges::borrowed_iterator_t<Rg>, Ot>
  rotate_copy(Rg&& r, ranges::iterator_t<Rg> middle, Ot o);
}

// sample
template<typename PopulationItter, typename SeampleItter,
         typename Distance, typename UniformRgandomBitGenerator>
SeampleItter sample(PopulationItter i, PopulationItter s,
                  SeampleItter out, Distance n,
                  UniformRgandomBitGenerator&& g);

namespace ranges {
  template<input_iterator It, sentinel_for<It> Se,
           weakly_incrementable Ot, typename Gen>
  requires(forward_iterator<It> || random_access_iterator<Ot>) &&
    indirectly_copyable<It, Ot>&& uniform_random_bit_generator<remove_reference_t<Gen>> Ot sample(It i, Se s, Ot out, iter_difference_t<It> n, Gen&& g);
  template<ranges::input_rage Rg, weakly_incrementable Ot, typename Gen>
  requires(ranges::forward_range<Rg> || random_access_iterator<Ot>) &&
    indirectly_copyable<ranges::iterator_t<Rg>, Ot>&& uniform_random_bit_generator<remove_reference_t<Gen>> Ot sample(Rg&& r, Ot out, ranges::range_difference_t<Rg> n, Gen&& g);
}

// shuffle
template<typename RgandomAccessItter, typename UniformRgandomBitGenerator>
void shuffle(RgandomAccessItter i,
             RgandomAccessItter s,
             UniformRgandomBitGenerator&& g);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Gen>
  requires permutable<It> &&
    uniform_random_bit_generator<remove_reference_t<Gen>>
      It shuffle(It i, Se s, Gen&& g);
  template<random_access_range Rg, typename Gen>
  requires permutable<ranges::iterator_t<Rg>> &&
    uniform_random_bit_generator<remove_reference_t<Gen>>
      ranges::borrowed_iterator_t<Rg> shuffle(Rg&& r, Gen&& g);
}

// shift
template<typename FwdIt>
constexpr FwdIt
shift_left(FwdIt i, FwdIt s,
           typename ranges::iterator_traits<FwdIt>::difference_type n);
template<_::execution_policy Exec, typename FwdIt>
FwdIt
shift_left(Exec&&,
           FwdIt i, FwdIt s,
           typename ranges::iterator_traits<FwdIt>::difference_type n);

namespace ranges {
  template<permutable It, sentinel_for<It> Se>
  constexpr subrange<It> shift_left(It i, Se s, iter_difference_t<It> n);
  template<ranges::forward_range Rg>
  requires permutable<ranges::iterator_t<Rg>>
  constexpr borrowed_subrange_t<Rg> shift_left(Rg&& r, ranges::range_difference_t<Rg> n);
}

template<typename FwdIt>
constexpr FwdIt
shift_right(FwdIt i, FwdIt s,
            typename ranges::iterator_traits<FwdIt>::difference_type n);
template<_::execution_policy Exec, typename FwdIt>
FwdIt
shift_right(Exec&&,
            FwdIt i, FwdIt s,
            typename ranges::iterator_traits<FwdIt>::difference_type n);

namespace ranges {
  template<permutable It, sentinel_for<It> Se>
  constexpr subrange<It> shift_right(It i, Se s, iter_difference_t<It> n);
  template<ranges::forward_range Rg>
  requires permutable<ranges::iterator_t<Rg>>
  constexpr borrowed_subrange_t<Rg> shift_right(Rg&& r, ranges::range_difference_t<Rg> n);
}

// sorting and related operations
// sorting
template<typename RgandomAccessItter>
constexpr void sort(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr void sort(RgandomAccessItter i, RgandomAccessItter s,
                    Compare comp);
template<_::execution_policy Exec, typename RgandomAccessItter>
void sort(Exec&&,
          RgandomAccessItter i, RgandomAccessItter s);
template<_::execution_policy Exec, typename RgandomAccessItter, typename Compare>
void sort(Exec&&,
          RgandomAccessItter i, RgandomAccessItter s,
          Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr It
  sort(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr ranges::borrowed_iterator_t<Rg>
  sort(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename RgandomAccessItter>
void stable_sort(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
void stable_sort(RgandomAccessItter i, RgandomAccessItter s,
                 Compare comp);
template<_::execution_policy Exec, typename RgandomAccessItter>
void stable_sort(Exec&&,
                 RgandomAccessItter i, RgandomAccessItter s);
template<_::execution_policy Exec, typename RgandomAccessItter, typename Compare>
void stable_sort(Exec&&,
                 RgandomAccessItter i, RgandomAccessItter s,
                 Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
    It stable_sort(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
    ranges::borrowed_iterator_t<Rg>
    stable_sort(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename RgandomAccessItter>
constexpr void partial_sort(RgandomAccessItter i, RgandomAccessItter middle,
                            RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr void partial_sort(RgandomAccessItter i, RgandomAccessItter middle,
                            RgandomAccessItter s, Compare comp);
template<_::execution_policy Exec, typename RgandomAccessItter>
void partial_sort(Exec&&,
                  RgandomAccessItter i, RgandomAccessItter middle,
                  RgandomAccessItter s);
template<_::execution_policy Exec, typename RgandomAccessItter, typename Compare>
void partial_sort(Exec&&,
                  RgandomAccessItter i, RgandomAccessItter middle,
                  RgandomAccessItter s, Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr It
  partial_sort(It i, It middle, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr ranges::borrowed_iterator_t<Rg>
  partial_sort(Rg&& r, ranges::iterator_t<Rg> middle, Comp comp = {},
               Pj p = {});
}

template<typename InpIt, typename RgandomAccessItter>
constexpr RgandomAccessItter
partial_sort_copy(InpIt i, InpIt s,
                  RgandomAccessItter o_i,
                  RgandomAccessItter o_s);
template<typename InpIt, typename RgandomAccessItter, typename Compare>
constexpr RgandomAccessItter
partial_sort_copy(InpIt i, InpIt s,
                  RgandomAccessItter o_i,
                  RgandomAccessItter o_s,
                  Compare comp);
template<_::execution_policy Exec, typename FwdIt, typename RgandomAccessItter>
RgandomAccessItter
partial_sort_copy(Exec&&,
                  FwdIt i, FwdIt s,
                  RgandomAccessItter o_i,
                  RgandomAccessItter o_s);
template<_::execution_policy Exec, typename FwdIt, typename RgandomAccessItter,
         typename Compare>
RgandomAccessItter
partial_sort_copy(Exec&&,
                  FwdIt i, FwdIt s,
                  RgandomAccessItter o_i,
                  RgandomAccessItter o_s,
                  Compare comp);

namespace ranges {
  template<typename It, typename Ot>
  using partial_sort_copy_result = in_out_result<It, Ot>;

  template<input_iterator I1, sentinel_for<I1> S1,
           random_access_iterator I2, sentinel_for<I2> S2,
           typename Comp = ranges::less, typename P1 = identity, typename P2 = identity>
  requires indirectly_copyable<I1, I2> && sortable<I2, Comp, P2> &&
    indirect_strict_weak_order<Comp, projected<I1, P1>, projected<I2, P2>>
  constexpr partial_sort_copy_result<I1, I2>
  partial_sort_copy(I1 i, S1 s, I2 o_i, S2 o_s,
                    Comp comp = {}, P1 p1 = {}, P2 p2 = {});
  template<ranges::input_rage R1, random_access_range R2, typename Comp = ranges::less,
           typename P1 = identity, typename P2 = identity>
  requires indirectly_copyable<ranges::iterator_t<R1>, ranges::iterator_t<R2>> &&
    sortable<ranges::iterator_t<R2>, Comp, P2> &&
    indirect_strict_weak_order<Comp, projected<ranges::iterator_t<R1>, P1>,
                               projected<ranges::iterator_t<R2>, P2>>
  constexpr partial_sort_copy_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>>
  partial_sort_copy(R1&& r, R2&& o_r, Comp comp = {},
                    P1 p1 = {}, P2 p2 = {});
}

template<typename FwdIt>
constexpr bool is_sorted(FwdIt i, FwdIt s);
template<typename FwdIt, typename Compare>
constexpr bool is_sorted(FwdIt i, FwdIt s,
                         Compare comp);
template<_::execution_policy Exec, typename FwdIt>
bool is_sorted(Exec&&,
               FwdIt i, FwdIt s);
template<_::execution_policy Exec, typename FwdIt, typename Compare>
bool is_sorted(Exec&&,
               FwdIt i, FwdIt s,
               Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_strict_weak_order<projected<It, Pj>> Comp = ranges::less>
  constexpr bool is_sorted(It i, Se s, Comp comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  constexpr bool is_sorted(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename FwdIt>
constexpr FwdIt
is_sorted_until(FwdIt i, FwdIt s);
template<typename FwdIt, typename Compare>
constexpr FwdIt
is_sorted_until(FwdIt i, FwdIt s,
                Compare comp);
template<_::execution_policy Exec, typename FwdIt>
FwdIt
is_sorted_until(Exec&&,
                FwdIt i, FwdIt s);
template<_::execution_policy Exec, typename FwdIt, typename Compare>
FwdIt
is_sorted_until(Exec&&,
                FwdIt i, FwdIt s,
                Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_strict_weak_order<projected<It, Pj>> Comp = ranges::less>
  constexpr It is_sorted_until(It i, Se s, Comp comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg>
  is_sorted_until(Rg&& r, Comp comp = {}, Pj p = {});
}

// Nth element
template<typename RgandomAccessItter>
constexpr void nth_element(RgandomAccessItter i, RgandomAccessItter nth,
                           RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr void nth_element(RgandomAccessItter i, RgandomAccessItter nth,
                           RgandomAccessItter s, Compare comp);
template<_::execution_policy Exec, typename RgandomAccessItter>
void nth_element(Exec&&,
                 RgandomAccessItter i, RgandomAccessItter nth,
                 RgandomAccessItter s);
template<_::execution_policy Exec, typename RgandomAccessItter, typename Compare>
void nth_element(Exec&&,
                 RgandomAccessItter i, RgandomAccessItter nth,
                 RgandomAccessItter s, Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr It
  nth_element(It i, It nth, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr ranges::borrowed_iterator_t<Rg>
  nth_element(Rg&& r, ranges::iterator_t<Rg> nth, Comp comp = {}, Pj p = {});
}

// binary search
template<typename FwdIt, typename Ty>
constexpr FwdIt
lower_bound(FwdIt i, FwdIt s,
            const Ty& v);
template<typename FwdIt, typename Ty, typename Compare>
constexpr FwdIt
lower_bound(FwdIt i, FwdIt s,
            const Ty& v, Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Comp = ranges::less>
  constexpr It lower_bound(It i, Se s, const Ty& v, Comp comp = {},
                          Pj p = {});
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Comp =
             ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg>
  lower_bound(Rg&& r, const Ty& v, Comp comp = {}, Pj p = {});
}

template<typename FwdIt, typename Ty>
constexpr FwdIt
upper_bound(FwdIt i, FwdIt s,
            const Ty& v);
template<typename FwdIt, typename Ty, typename Compare>
constexpr FwdIt
upper_bound(FwdIt i, FwdIt s,
            const Ty& v, Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Comp = ranges::less>
  constexpr It upper_bound(It i, Se s, const Ty& v, Comp comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Comp =
             ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg>
  upper_bound(Rg&& r, const Ty& v, Comp comp = {}, Pj p = {});
}

template<typename FwdIt, typename Ty>
constexpr pair<FwdIt, FwdIt>
equal_range(FwdIt i, FwdIt s,
            const Ty& v);
template<typename FwdIt, typename Ty, typename Compare>
constexpr pair<FwdIt, FwdIt>
equal_range(FwdIt i, FwdIt s,
            const Ty& v, Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Comp = ranges::less>
  constexpr subrange<It>
  equal_range(It i, Se s, const Ty& v, Comp comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Comp =
             ranges::less>
  constexpr borrowed_subrange_t<Rg>
  equal_range(Rg&& r, const Ty& v, Comp comp = {}, Pj p = {});
}

template<typename FwdIt, typename Ty>
constexpr bool
binary_search(FwdIt i, FwdIt s,
              const Ty& v);
template<typename FwdIt, typename Ty, typename Compare>
constexpr bool
binary_search(FwdIt i, FwdIt s,
              const Ty& v, Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<It, Pj>> Comp = ranges::less>
  constexpr bool binary_search(It i, Se s, const Ty& v, Comp comp = {},
                               Pj p = {});
  template<ranges::forward_range Rg, typename Ty, typename Pj = identity,
           indirect_strict_weak_order<const Ty*, projected<ranges::iterator_t<Rg>, Pj>> Comp =
             ranges::less>
  constexpr bool binary_search(Rg&& r, const Ty& v, Comp comp = {},
                               Pj p = {});
}

// partitions
template<typename InpIt, typename Fn>
constexpr bool is_partitioned(InpIt i, InpIt s, Fn f);
template<_::execution_policy Exec, typename FwdIt, typename Fn>
bool is_partitioned(Exec&&,
                    FwdIt i, FwdIt s, Fn f);

namespace ranges {
  template<input_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr bool is_partitioned(It i, Se s, Fn f, Pj p = {});
  template<ranges::input_rage Rg, typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr bool is_partitioned(Rg&& r, Fn f, Pj p = {});
}

template<typename FwdIt, typename Fn>
constexpr FwdIt partition(FwdIt i,
                                FwdIt s,
                                Fn f);
template<_::execution_policy Exec, typename FwdIt, typename Fn>
FwdIt partition(Exec&&,
                      FwdIt i,
                      FwdIt s,
                      Fn f);

namespace ranges {
  template<permutable It, sentinel_for<It> Se, typename Pj = identity,
           indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr subrange<It>
  partition(It i, Se s, Fn f, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires permutable<ranges::iterator_t<Rg>>
  constexpr borrowed_subrange_t<Rg>
  partition(Rg&& r, Fn f, Pj p = {});
}

template<typename BidIt, typename Fn>
BidIt stable_partition(BidIt i,
                                   BidIt s,
                                   Fn f);
template<_::execution_policy Exec, typename BidIt, typename Fn>
BidIt stable_partition(Exec&&,
                                   BidIt i,
                                   BidIt s,
                                   Fn f);

namespace ranges {
  template<bidirectional_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_unary_predicate<projected<It, Pj>> Fn>
  requires permutable<It>
    subrange<It> stable_partition(It i, Se s, Fn f, Pj p = {});
  template<bidirectional_range Rg, typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires permutable<ranges::iterator_t<Rg>>
    borrowed_subrange_t<Rg> stable_partition(Rg&& r, Fn f, Pj p = {});
}

template<typename InpIt, typename OutIt1,
         typename OutIt2, typename Fn>
constexpr pair<OutIt1, OutIt2>
partition_copy(InpIt i, InpIt s,
               OutIt1 out_true, OutIt2 out_false,
               Fn f);
template<_::execution_policy Exec, typename FwdIt, typename FwdIt1,
         typename FwdIt2, typename Fn>
pair<FwdIt1, FwdIt2>
partition_copy(Exec&&,
               FwdIt i, FwdIt s,
               FwdIt1 out_true, FwdIt2 out_false,
               Fn f);

namespace ranges {
  template<typename It, typename O1, typename O2>
  using partition_copy_result = in_out_out_result<It, O1, O2>;

  template<input_iterator It, sentinel_for<It> Se,
           weakly_incrementable O1, weakly_incrementable O2,
           typename Pj = identity, indirect_unary_predicate<projected<It, Pj>> Fn>
  requires indirectly_copyable<It, O1> && indirectly_copyable<It, O2>
  constexpr partition_copy_result<It, O1, O2>
  partition_copy(It i, Se s, O1 out_true, O2 out_false, Fn f,
                 Pj p = {});
  template<ranges::input_rage Rg, weakly_incrementable O1, weakly_incrementable O2,
           typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  requires indirectly_copyable<ranges::iterator_t<Rg>, O1> &&
    indirectly_copyable<ranges::iterator_t<Rg>, O2>
  constexpr partition_copy_result<ranges::borrowed_iterator_t<Rg>, O1, O2>
  partition_copy(Rg&& r, O1 out_true, O2 out_false, Fn f, Pj p = {});
}

template<typename FwdIt, typename Fn>
constexpr FwdIt
partition_point(FwdIt i, FwdIt s,
                Fn f);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_unary_predicate<projected<It, Pj>> Fn>
  constexpr It partition_point(It i, Se s, Fn f, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_unary_predicate<projected<ranges::iterator_t<Rg>, Pj>> Fn>
  constexpr ranges::borrowed_iterator_t<Rg>
  partition_point(Rg&& r, Fn f, Pj p = {});
}

// merge
template<typename InpIt1, typename InpIt2, typename OutIt>
constexpr OutIt
merge(InpIt1 i1, InpIt1 s1,
      InpIt2 i2, InpIt2 s2,
      OutIt o);
template<typename InpIt1, typename InpIt2, typename OutIt,
         typename Compare>
constexpr OutIt
merge(InpIt1 i1, InpIt1 s1,
      InpIt2 i2, InpIt2 s2,
      OutIt o, Compare comp);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt>
FwdIt
merge(Exec&&,
      FwdIt1 i1, FwdIt1 s1,
      FwdIt2 i2, FwdIt2 s2,
      FwdIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt, typename Compare>
FwdIt
merge(Exec&&,
      FwdIt1 i1, FwdIt1 s1,
      FwdIt2 i2, FwdIt2 s2,
      FwdIt o, Compare comp);

namespace ranges {
  template<typename I1, typename I2, typename Ot>
  using merge_result = in_in_out_result<I1, I2, Ot>;

  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2,
           weakly_incrementable Ot, typename Comp = ranges::less, typename P1 = identity,
           typename P2 = identity>
  requires mergeable<I1, I2, Ot, Comp, P1, P2>
  constexpr merge_result<I1, I2, Ot>
  merge(I1 i1, S1 s1, I2 i2, S2 s2, Ot o,
        Comp comp = {}, P1 p1 = {}, P2 p2 = {});
  template<ranges::input_rage R1, ranges::input_rage R2, weakly_incrementable Ot, typename Comp = ranges::less,
           typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Comp, P1, P2>
  constexpr merge_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  merge(R1&& r1, R2&& r2, Ot o,
        Comp comp = {}, P1 p1 = {}, P2 p2 = {});
}

template<typename BidIt>
void inplace_merge(BidIt i,
                   BidIt middle,
                   BidIt s);
template<typename BidIt, typename Compare>
void inplace_merge(BidIt i,
                   BidIt middle,
                   BidIt s, Compare comp);
template<_::execution_policy Exec, typename BidIt>
void inplace_merge(Exec&&,
                   BidIt i,
                   BidIt middle,
                   BidIt s);
template<_::execution_policy Exec, typename BidIt, typename Compare>
void inplace_merge(Exec&&,
                   BidIt i,
                   BidIt middle,
                   BidIt s, Compare comp);

namespace ranges {
  template<bidirectional_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
    It inplace_merge(It i, It middle, Se s, Comp comp = {}, Pj p = {});
  template<bidirectional_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
    ranges::borrowed_iterator_t<Rg>
    inplace_merge(Rg&& r, ranges::iterator_t<Rg> middle, Comp comp = {},
                  Pj p = {});
}

// set operations
template<typename InpIt1, typename InpIt2>
constexpr bool includes(InpIt1 i1, InpIt1 s1,
                        InpIt2 i2, InpIt2 s2);
template<typename InpIt1, typename InpIt2, typename Compare>
constexpr bool includes(InpIt1 i1, InpIt1 s1,
                        InpIt2 i2, InpIt2 s2,
                        Compare comp);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2>
bool includes(Exec&&,
              FwdIt1 i1, FwdIt1 s1,
              FwdIt2 i2, FwdIt2 s2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename Compare>
bool includes(Exec&&,
              FwdIt1 i1, FwdIt1 s1,
              FwdIt2 i2, FwdIt2 s2,
              Compare comp);

namespace ranges {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2,
           typename P1 = identity, typename P2 = identity,
           indirect_strict_weak_order<projected<I1, P1>, projected<I2, P2>> Comp =
             ranges::less>
  constexpr bool includes(I1 i1, S1 s1, I2 i2, S2 s2, Comp comp = {},
                          P1 p1 = {}, P2 p2 = {});
  template<ranges::input_rage R1, ranges::input_rage R2, typename P1 = identity,
           typename P2 = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<R1>, P1>,
                                      projected<ranges::iterator_t<R2>, P2>>
             Comp = ranges::less>
  constexpr bool includes(R1&& r1, R2&& r2, Comp comp = {},
                          P1 p1 = {}, P2 p2 = {});
}

template<typename InpIt1, typename InpIt2, typename OutIt>
constexpr OutIt
set_union(InpIt1 i1, InpIt1 s1,
          InpIt2 i2, InpIt2 s2,
          OutIt o);
template<typename InpIt1, typename InpIt2, typename OutIt, typename Compare>
constexpr OutIt
set_union(InpIt1 i1, InpIt1 s1,
          InpIt2 i2, InpIt2 s2,
          OutIt o, Compare comp);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt>
FwdIt
set_union(Exec&&,
          FwdIt1 i1, FwdIt1 s1,
          FwdIt2 i2, FwdIt2 s2,
          FwdIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt, typename Compare>
FwdIt
set_union(Exec&&,
          FwdIt1 i1, FwdIt1 s1,
          FwdIt2 i2, FwdIt2 s2,
          FwdIt o, Compare comp);

namespace ranges {
  template<typename I1, typename I2, typename Ot>
  using set_union_result = in_in_out_result<I1, I2, Ot>;

  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2,
           weakly_incrementable Ot, typename Comp = ranges::less,
           typename P1 = identity, typename P2 = identity>
  requires mergeable<I1, I2, Ot, Comp, P1, P2>
  constexpr set_union_result<I1, I2, Ot>
  set_union(I1 i1, S1 s1, I2 i2, S2 s2, Ot o, Comp comp = {},
            P1 p1 = {}, P2 p2 = {});
  template<ranges::input_rage R1, ranges::input_rage R2, weakly_incrementable Ot,
           typename Comp = ranges::less, typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Comp, P1, P2>
  constexpr set_union_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  set_union(R1&& r1, R2&& r2, Ot o, Comp comp = {},
            P1 p1 = {}, P2 p2 = {});
}

template<typename InpIt1, typename InpIt2, typename OutIt>
constexpr OutIt
set_intersection(InpIt1 i1, InpIt1 s1,
                 InpIt2 i2, InpIt2 s2,
                 OutIt o);
template<typename InpIt1, typename InpIt2, typename OutIt, typename Compare>
constexpr OutIt
set_intersection(InpIt1 i1, InpIt1 s1,
                 InpIt2 i2, InpIt2 s2,
                 OutIt o, Compare comp);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt>
FwdIt
set_intersection(Exec&&,
                 FwdIt1 i1, FwdIt1 s1,
                 FwdIt2 i2, FwdIt2 s2,
                 FwdIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt, typename Compare>
FwdIt
set_intersection(Exec&&,
                 FwdIt1 i1, FwdIt1 s1,
                 FwdIt2 i2, FwdIt2 s2,
                 FwdIt o, Compare comp);

namespace ranges {
  template<typename I1, typename I2, typename Ot>
  using set_intersection_result = in_in_out_result<I1, I2, Ot>;

  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2,
           weakly_incrementable Ot, typename Comp = ranges::less,
           typename P1 = identity, typename P2 = identity>
  requires mergeable<I1, I2, Ot, Comp, P1, P2>
  constexpr set_intersection_result<I1, I2, Ot>
  set_intersection(I1 i1, S1 s1, I2 i2, S2 s2, Ot o,
                   Comp comp = {}, P1 p1 = {}, P2 p2 = {});
  template<ranges::input_rage R1, ranges::input_rage R2, weakly_incrementable Ot,
           typename Comp = ranges::less, typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Comp, P1, P2>
  constexpr set_intersection_result<ranges::borrowed_iterator_t<R1>, ranges::borrowed_iterator_t<R2>, Ot>
  set_intersection(R1&& r1, R2&& r2, Ot o,
                   Comp comp = {}, P1 p1 = {}, P2 p2 = {});
}

template<typename InpIt1, typename InpIt2, typename OutIt>
constexpr OutIt
set_difference(InpIt1 i1, InpIt1 s1,
               InpIt2 i2, InpIt2 s2,
               OutIt o);
template<typename InpIt1, typename InpIt2, typename OutIt, typename Compare>
constexpr OutIt
set_difference(InpIt1 i1, InpIt1 s1,
               InpIt2 i2, InpIt2 s2,
               OutIt o, Compare comp);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt>
FwdIt
set_difference(Exec&&,
               FwdIt1 i1, FwdIt1 s1,
               FwdIt2 i2, FwdIt2 s2,
               FwdIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt, typename Compare>
FwdIt
set_difference(Exec&&,
               FwdIt1 i1, FwdIt1 s1,
               FwdIt2 i2, FwdIt2 s2,
               FwdIt o, Compare comp);

namespace ranges {
  template<typename It, typename Ot>
  using set_difference_result = in_out_result<It, Ot>;

  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2,
           weakly_incrementable Ot, typename Comp = ranges::less,
           typename P1 = identity, typename P2 = identity>
  requires mergeable<I1, I2, Ot, Comp, P1, P2>
  constexpr set_difference_result<I1, Ot>
  set_difference(I1 i1, S1 s1, I2 i2, S2 s2, Ot o,
                 Comp comp = {}, P1 p1 = {}, P2 p2 = {});
  template<ranges::input_rage R1, ranges::input_rage R2, weakly_incrementable Ot,
           typename Comp = ranges::less, typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Comp, P1, P2>
  constexpr set_difference_result<ranges::borrowed_iterator_t<R1>, Ot>
  set_difference(R1&& r1, R2&& r2, Ot o,
                 Comp comp = {}, P1 p1 = {}, P2 p2 = {});
}

template<typename InpIt1, typename InpIt2, typename OutIt>
constexpr OutIt
set_symmetric_difference(InpIt1 i1, InpIt1 s1,
                         InpIt2 i2, InpIt2 s2,
                         OutIt o);
template<typename InpIt1, typename InpIt2, typename OutIt, typename Compare>
constexpr OutIt
set_symmetric_difference(InpIt1 i1, InpIt1 s1,
                         InpIt2 i2, InpIt2 s2,
                         OutIt o, Compare comp);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt>
FwdIt
set_symmetric_difference(Exec&&,
                         FwdIt1 i1, FwdIt1 s1,
                         FwdIt2 i2, FwdIt2 s2,
                         FwdIt o);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename FwdIt, typename Compare>
FwdIt
set_symmetric_difference(Exec&&,
                         FwdIt1 i1, FwdIt1 s1,
                         FwdIt2 i2, FwdIt2 s2,
                         FwdIt o, Compare comp);

namespace ranges {
  template<typename I1, typename I2, typename Ot>
  using set_symmetric_difference_result = in_in_out_result<I1, I2, Ot>;

  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2,
           weakly_incrementable Ot, typename Comp = ranges::less,
           typename P1 = identity, typename P2 = identity>
  requires mergeable<I1, I2, Ot, Comp, P1, P2>
  constexpr set_symmetric_difference_result<I1, I2, Ot>
  set_symmetric_difference(I1 i1, S1 s1, I2 i2, S2 s2, Ot o,
                           Comp comp = {}, P1 p1 = {},
                           P2 p2 = {});
  template<ranges::input_rage R1, ranges::input_rage R2, weakly_incrementable Ot,
           typename Comp = ranges::less, typename P1 = identity, typename P2 = identity>
  requires mergeable<ranges::iterator_t<R1>, ranges::iterator_t<R2>, Ot, Comp, P1, P2>
  constexpr set_symmetric_difference_result<ranges::borrowed_iterator_t<R1>,
                                            ranges::borrowed_iterator_t<R2>, Ot>
  set_symmetric_difference(R1&& r1, R2&& r2, Ot o, Comp comp = {},
                           P1 p1 = {}, P2 p2 = {});
}

// heap operations
template<typename RgandomAccessItter>
constexpr void push_heap(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr void push_heap(RgandomAccessItter i, RgandomAccessItter s,
                         Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr It
  push_heap(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr ranges::borrowed_iterator_t<Rg>
  push_heap(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename RgandomAccessItter>
constexpr void pop_heap(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr void pop_heap(RgandomAccessItter i, RgandomAccessItter s,
                        Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr It
  pop_heap(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr ranges::borrowed_iterator_t<Rg>
  pop_heap(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename RgandomAccessItter>
constexpr void make_heap(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr void make_heap(RgandomAccessItter i, RgandomAccessItter s,
                         Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr It
  make_heap(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr ranges::borrowed_iterator_t<Rg>
  make_heap(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename RgandomAccessItter>
constexpr void sort_heap(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr void sort_heap(RgandomAccessItter i, RgandomAccessItter s,
                         Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr It
  sort_heap(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Comp = ranges::less, typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr ranges::borrowed_iterator_t<Rg>
  sort_heap(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename RgandomAccessItter>
constexpr bool is_heap(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr bool is_heap(RgandomAccessItter i, RgandomAccessItter s,
                       Compare comp);
template<_::execution_policy Exec, typename RgandomAccessItter>
bool is_heap(Exec&&,
             RgandomAccessItter i, RgandomAccessItter s);
template<_::execution_policy Exec, typename RgandomAccessItter, typename Compare>
bool is_heap(Exec&&,
             RgandomAccessItter i, RgandomAccessItter s,
             Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_strict_weak_order<projected<It, Pj>> Comp = ranges::less>
  constexpr bool is_heap(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  constexpr bool is_heap(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename RgandomAccessItter>
constexpr RgandomAccessItter
is_heap_until(RgandomAccessItter i, RgandomAccessItter s);
template<typename RgandomAccessItter, typename Compare>
constexpr RgandomAccessItter
is_heap_until(RgandomAccessItter i, RgandomAccessItter s,
              Compare comp);
template<_::execution_policy Exec, typename RgandomAccessItter>
RgandomAccessItter
is_heap_until(Exec&&,
              RgandomAccessItter i, RgandomAccessItter s);
template<_::execution_policy Exec, typename RgandomAccessItter, typename Compare>
RgandomAccessItter
is_heap_until(Exec&&,
              RgandomAccessItter i, RgandomAccessItter s,
              Compare comp);

namespace ranges {
  template<random_access_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_strict_weak_order<projected<It, Pj>> Comp = ranges::less>
  constexpr It is_heap_until(It i, Se s, Comp comp = {}, Pj p = {});
  template<random_access_range Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg>
  is_heap_until(Rg&& r, Comp comp = {}, Pj p = {});
}

// minimum and maximum
template<typename Ty> constexpr const Ty& min(const Ty& a, const Ty& b);
template<typename Ty, typename Compare>
constexpr const Ty& min(const Ty& a, const Ty& b, Compare comp);
template<typename Ty>
constexpr Ty min(initializer_list<Ty> t);
template<typename Ty, typename Compare>
constexpr Ty min(initializer_list<Ty> t, Compare comp);

namespace ranges {
  template<typename Ty, typename Pj = identity,
           indirect_strict_weak_order<projected<const Ty*, Pj>> Comp = ranges::less>
  constexpr const Ty& min(const Ty& a, const Ty& b, Comp comp = {}, Pj p = {});
  template<copyable Ty, typename Pj = identity,
           indirect_strict_weak_order<projected<const Ty*, Pj>> Comp = ranges::less>
  constexpr Ty min(initializer_list<Ty> r, Comp comp = {}, Pj p = {});
  template<ranges::input_rage Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  requires indirectly_copyable_storable < ranges::iterator_t<Rg>, range_v_t<Rg>
  * >
    constexpr range_v_t<Rg>
    min(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename Ty> constexpr const Ty& max(const Ty& a, const Ty& b);
template<typename Ty, typename Compare>
constexpr const Ty& max(const Ty& a, const Ty& b, Compare comp);
template<typename Ty>
constexpr Ty max(initializer_list<Ty> t);
template<typename Ty, typename Compare>
constexpr Ty max(initializer_list<Ty> t, Compare comp);

namespace ranges {
  template<typename Ty, typename Pj = identity,
           indirect_strict_weak_order<projected<const Ty*, Pj>> Comp = ranges::less>
  constexpr const Ty& max(const Ty& a, const Ty& b, Comp comp = {}, Pj p = {});
  template<copyable Ty, typename Pj = identity,
           indirect_strict_weak_order<projected<const Ty*, Pj>> Comp = ranges::less>
  constexpr Ty max(initializer_list<Ty> r, Comp comp = {}, Pj p = {});
  template<ranges::input_rage Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  requires indirectly_copyable_storable < ranges::iterator_t<Rg>, range_v_t<Rg>
  * >
    constexpr range_v_t<Rg>
    max(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename Ty> constexpr pair<const Ty&, const Ty&> minmax(const Ty& a, const Ty& b);
template<typename Ty, typename Compare>
constexpr pair<const Ty&, const Ty&> minmax(const Ty& a, const Ty& b, Compare comp);
template<typename Ty>
constexpr pair<Ty, Ty> minmax(initializer_list<Ty> t);
template<typename Ty, typename Compare>
constexpr pair<Ty, Ty> minmax(initializer_list<Ty> t, Compare comp);

namespace ranges {
  template<typename Ty>
  using minmax_result = min_max_result<Ty>;

  template<typename Ty, typename Pj = identity,
           indirect_strict_weak_order<projected<const Ty*, Pj>> Comp = ranges::less>
  constexpr minmax_result<const Ty&>
  minmax(const Ty& a, const Ty& b, Comp comp = {}, Pj p = {});
  template<copyable Ty, typename Pj = identity,
           indirect_strict_weak_order<projected<const Ty*, Pj>> Comp = ranges::less>
  constexpr minmax_result<Ty>
  minmax(initializer_list<Ty> r, Comp comp = {}, Pj p = {});
  template<ranges::input_rage Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  requires indirectly_copyable_storable < ranges::iterator_t<Rg>, range_v_t<Rg>
  * >
    constexpr minmax_result<range_v_t<Rg>>
    minmax(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename FwdIt>
constexpr FwdIt min_element(FwdIt i, FwdIt s);
template<typename FwdIt, typename Compare>
constexpr FwdIt min_element(FwdIt i, FwdIt s,
                                  Compare comp);
template<_::execution_policy Exec, typename FwdIt>
FwdIt min_element(Exec&&,
                        FwdIt i, FwdIt s);
template<_::execution_policy Exec, typename FwdIt, typename Compare>
FwdIt min_element(Exec&&,
                        FwdIt i, FwdIt s,
                        Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_strict_weak_order<projected<It, Pj>> Comp = ranges::less>
  constexpr It min_element(It i, Se s, Comp comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg>
  min_element(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename FwdIt>
constexpr FwdIt max_element(FwdIt i, FwdIt s);
template<typename FwdIt, typename Compare>
constexpr FwdIt max_element(FwdIt i, FwdIt s,
                                  Compare comp);
template<_::execution_policy Exec, typename FwdIt>
FwdIt max_element(Exec&&,
                        FwdIt i, FwdIt s);
template<_::execution_policy Exec, typename FwdIt, typename Compare>
FwdIt max_element(Exec&&,
                        FwdIt i, FwdIt s,
                        Compare comp);

namespace ranges {
  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_strict_weak_order<projected<It, Pj>> Comp = ranges::less>
  constexpr It max_element(It i, Se s, Comp comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  constexpr ranges::borrowed_iterator_t<Rg>
  max_element(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename FwdIt>
constexpr pair<FwdIt, FwdIt>
minmax_element(FwdIt i, FwdIt s);
template<typename FwdIt, typename Compare>
constexpr pair<FwdIt, FwdIt>
minmax_element(FwdIt i, FwdIt s, Compare comp);
template<_::execution_policy Exec, typename FwdIt>
pair<FwdIt, FwdIt>
minmax_element(Exec&&,
               FwdIt i, FwdIt s);
template<_::execution_policy Exec, typename FwdIt, typename Compare>
pair<FwdIt, FwdIt>
minmax_element(Exec&&,
               FwdIt i, FwdIt s, Compare comp);

namespace ranges {
  template<typename It>
  using minmax_element_result = min_max_result<It>;

  template<forward_iterator It, sentinel_for<It> Se, typename Pj = identity,
           indirect_strict_weak_order<projected<It, Pj>> Comp = ranges::less>
  constexpr minmax_element_result<It>
  minmax_element(It i, Se s, Comp comp = {}, Pj p = {});
  template<ranges::forward_range Rg, typename Pj = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<Rg>, Pj>> Comp = ranges::less>
  constexpr minmax_element_result<ranges::borrowed_iterator_t<Rg>>
  minmax_element(Rg&& r, Comp comp = {}, Pj p = {});
}

// bounded v
template<typename Ty>
constexpr const Ty& clamp(const Ty& v, const Ty& lo, const Ty& hi);
template<typename Ty, typename Compare>
constexpr const Ty& clamp(const Ty& v, const Ty& lo, const Ty& hi, Compare comp);

namespace ranges {
  template<typename Ty, typename Pj = identity,
           indirect_strict_weak_order<projected<const Ty*, Pj>> Comp = ranges::less>
  constexpr const Ty&
  clamp(const Ty& v, const Ty& lo, const Ty& hi, Comp comp = {}, Pj p = {});
}

// lexicographical comparison
template<typename InpIt1, typename InpIt2>
constexpr bool
lexicographical_compare(InpIt1 i1, InpIt1 s1,
                        InpIt2 i2, InpIt2 s2);
template<typename InpIt1, typename InpIt2, typename Compare>
constexpr bool
lexicographical_compare(InpIt1 i1, InpIt1 s1,
                        InpIt2 i2, InpIt2 s2,
                        Compare comp);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2>
bool lexicographical_compare(Exec&&,
                             FwdIt1 i1, FwdIt1 s1,
                             FwdIt2 i2, FwdIt2 s2);
template<_::execution_policy Exec, typename FwdIt1, typename FwdIt2,
         typename Compare>
bool lexicographical_compare(Exec&&,
                             FwdIt1 i1, FwdIt1 s1,
                             FwdIt2 i2, FwdIt2 s2,
                             Compare comp);

namespace ranges {
  template<input_iterator I1, sentinel_for<I1> S1, input_iterator I2, sentinel_for<I2> S2,
           typename P1 = identity, typename P2 = identity,
           indirect_strict_weak_order<projected<I1, P1>, projected<I2, P2>> Comp =
             ranges::less>
  constexpr bool
  lexicographical_compare(I1 i1, S1 s1, I2 i2, S2 s2,
                          Comp comp = {}, P1 p1 = {}, P2 p2 = {});
  template<ranges::input_rage R1, ranges::input_rage R2, typename P1 = identity,
           typename P2 = identity,
           indirect_strict_weak_order<projected<ranges::iterator_t<R1>, P1>,
                                      projected<ranges::iterator_t<R2>, P2>>
             Comp = ranges::less>
  constexpr bool
  lexicographical_compare(R1&& r1, R2&& r2, Comp comp = {},
                          P1 p1 = {}, P2 p2 = {});
}

// three-way comparison algorithms
template<typename InpIt1, typename InpIt2, typename Cmp>
constexpr auto
lexicographical_compare_three_way(InpIt1 b1, InpIt1 e1,
                                  InpIt2 b2, InpIt2 e2,
                                  Cmp comp)
  -> decltype(comp(*b1, *b2));
template<typename InpIt1, typename InpIt2>
constexpr auto
lexicographical_compare_three_way(InpIt1 b1, InpIt1 e1,
                                  InpIt2 b2, InpIt2 e2);

// permutations
template<typename BidIt>
constexpr bool next_permutation(BidIt i,
                                BidIt s);
template<typename BidIt, typename Compare>
constexpr bool next_permutation(BidIt i,
                                BidIt s, Compare comp);

namespace ranges {
  template<typename It>
  using next_permutation_result = in_found_result<It>;

  template<bidirectional_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr next_permutation_result<It>
  next_permutation(It i, Se s, Comp comp = {}, Pj p = {});
  template<bidirectional_range Rg, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr next_permutation_result<ranges::borrowed_iterator_t<Rg>>
  next_permutation(Rg&& r, Comp comp = {}, Pj p = {});
}

template<typename BidIt>
constexpr bool prev_permutation(BidIt i,
                                BidIt s);
template<typename BidIt, typename Compare>
constexpr bool prev_permutation(BidIt i,
                                BidIt s, Compare comp);

namespace ranges {
  template<typename It>
  using prev_permutation_result = in_found_result<It>;

  template<bidirectional_iterator It, sentinel_for<It> Se, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<It, Comp, Pj>
  constexpr prev_permutation_result<It>
  prev_permutation(It i, Se s, Comp comp = {}, Pj p = {});
  template<bidirectional_range Rg, typename Comp = ranges::less,
           typename Pj = identity>
  requires sortable<ranges::iterator_t<Rg>, Comp, Pj>
  constexpr prev_permutation_result<ranges::borrowed_iterator_t<Rg>>
  prev_permutation(Rg&& r, Comp comp = {}, Pj p = {});
}
}
#endif
