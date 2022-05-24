// ywstd/@/ranges-concepts.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "../@/_.hh"
#include "../@/iterator-concepts.hh"

namespace std {

namespace ranges {
  struct view_base {};
  template<typename Rg> inline constexpr bool disable_sized_range = false;
  template<typename Rg> inline constexpr bool enable_borrowed_range = false;
  template<typename Rg> inline constexpr bool enable_view = derived_from<Rg, view_base>;
}

namespace _ {
  template<typename Ty> concept has_complete_elements = requires { sizeof(declval<Ty&>()[0]); };
  template<typename Rg> concept _borrowed_range = is_lvalue_reference_v<Rg> || ranges::enable_borrowed_range<remove_cvref_t<Rg>>;
  namespace _begin {
    template<typename Rg> void begin(Rg&) = delete;
    template<typename Rg> void begin(const Rg&) = delete;
    template<typename Rg> concept c2 = requires { { std::_::decay_copy(declval<Rg>().begin()) } -> input_or_output_iterator; };
    template<typename Rg> concept c3 = requires { { std::_::decay_copy(begin(declval<Rg>())) } -> input_or_output_iterator; };
    template<typename Rg> inline constexpr auto cs = []() -> call_style {
      if constexpr (is_array_v<remove_reference_t<Rg>>) { static_assert(has_complete_elements<Rg>); return {1, true, true}; }
      else if constexpr (c2<Rg>) return {2, true, noexcept(std::_::decay_copy(declval<Rg>().begin()))};
      else if constexpr (c3<Rg>) return {3, true, noexcept(std::_::decay_copy(begin(declval<Rg>())))};
      else return {}; }();
    struct _ {
      template<_borrowed_range Rg> requires (cs<Rg&>.able) constexpr auto operator()(Rg&& r) const noexcept(cs<Rg&>.nothrow) {
        if constexpr (cs<Rg&>.style == 1) return r;
        else if constexpr (cs<Rg&>.style == 2) return r.begin();
        else if constexpr (cs<Rg&>.style == 3) return begin(r);
      }
    };
  }
}

namespace ranges {
  inline namespace _cpo {
    inline constexpr _::_begin::_ begin;
  }
  template<typename Rg> using iterator_t = decltype(ranges::begin(declval<Rg&>()));
}

namespace _::_end {
  template<typename Rg> void end(Rg&) = delete;
  template<typename Rg> void end(const Rg&) = delete;
  template<typename Rg> concept c2 = requires { { std::_::decay_copy(declval<Rg>().end()) } -> sentinel_for<ranges::iterator_t<Rg>>; };
  template<typename Rg> concept c3 = requires { { std::_::decay_copy(end(declval<Rg>())) } -> sentinel_for<ranges::iterator_t<Rg>>; };
  template<typename Rg> inline constexpr auto cs = []() -> call_style {
    if constexpr (is_array_v<remove_reference_t<Rg>>) { static_assert(has_complete_elements<Rg>);
      if constexpr (extent_v<remove_reference_t<Rg>> != 0) return {1, true, true}; else return {}; }
    else if constexpr (c2<Rg>) return {2, true, noexcept(std::_::decay_copy(declval<Rg>().end()))};
    else if constexpr (c3<Rg>) return {3, true, noexcept(std::_::decay_copy(end(declval<Rg>())))};
    else return {}; }();
  struct _ {
    template<_borrowed_range Rg> requires (cs<Rg&>.able) constexpr auto operator()(Rg&& r) const noexcept(cs<Rg&>.nothrow) {
      if constexpr (cs<Rg&>.style == 1) return r + extent_v<remove_reference_t<Rg>>;
      else if constexpr (cs<Rg&>.style == 2) return r.end();
      else if constexpr (cs<Rg&>.style == 3) return end(r);
    }
  };
}

namespace ranges {
  inline namespace _cpo {
    inline constexpr _::_end::_ end;
  }
  template<typename Rg> concept range = requires(Rg& r) { ranges::begin(r); ranges::end(r); };
  template<typename Rg> concept borrowed_range = range<Rg> && _::_borrowed_range<Rg>;
  template<typename Rg> concept view = range<Rg> && movable<Rg> && default_initializable<Rg> && enable_view<Rg>;

  template<typename Rg> concept viewable_range =
    range<Rg> &&((view<remove_cvref_t<Rg>> && constructible_from<remove_cvref_t<Rg>, Rg>) || (!view<remove_cvref_t<Rg>> && borrowed_range<Rg>));

  template<range Rg> using sentinel_t = decltype(ranges::end(declval<Rg&>()));
  template<range Rg> using range_difference_t = iter_difference_t<iterator_t<Rg>>;
  template<range Rg> using range_value_t = iter_value_t<iterator_t<Rg>>;
  template<range Rg> using range_reference_t = iter_reference_t<iterator_t<Rg>>;
  template<range Rg> using range_rvalue_reference_t = iter_rvalue_reference_t<iterator_t<Rg>>;

  template<typename Rg> concept common_range = range<Rg> && same_as<iterator_t<Rg>, sentinel_t<Rg>>;
  template<typename Rg> concept input_range = range<Rg> && input_iterator<iterator_t<Rg>>;
  template<typename Rg> concept forward_range = range<Rg> && forward_iterator<iterator_t<Rg>>;
  template<typename Rg> concept bidirectional_range = range<Rg> && bidirectional_iterator<iterator_t<Rg>>;
  template<typename Rg> concept random_access_range = range<Rg> && random_access_iterator<iterator_t<Rg>>;
  template<typename Rg, typename Ty> concept output_range = range<Rg> && output_iterator<iterator_t<Rg>, Ty>;
}

namespace _::_size {
  void size(auto&) = delete;
  void size(const auto&) = delete;
  template<typename Rg> concept c2 = !ranges::disable_sized_range<remove_cvref_t<Rg>> && is_integer_like<decltype(std::_::decay_copy(declval<Rg>().size()))>;
  template<typename Rg> concept c3 = !ranges::disable_sized_range<remove_cvref_t<Rg>> && is_integer_like<decltype(std::_::decay_copy(size(declval<Rg>())))>;
  template<typename Rg> concept c4 = forward_iterator<ranges::iterator_t<Rg>> && sized_sentinel_for<ranges::sentinel_t<Rg>, ranges::iterator_t<Rg>>;
  template<typename Rg> using t4 = remove_cvref_t<decltype(_end::_{}(declval<Rg&>()) - _begin::_{}(declval<Rg&>()))>;
  template<typename Rg> inline constexpr auto cs = []() -> call_style {
    if constexpr (is_array_v<remove_cvref_t<Rg>>) { if constexpr (extent_v<remove_cvref_t<Rg>> != 0) return {1, true, true}; else return {}; }
    else if constexpr (c2<Rg>) return {2, true, noexcept(std::_::decay_copy(declval<Rg>().size()))};
    else if constexpr (c3<Rg>) return {3, true, noexcept(std::_::decay_copy(size(declval<Rg>())))};
    else if constexpr (c4<Rg>) return {4, true, noexcept(_end::_{}(declval<Rg>()) - _begin::_{}(declval<Rg>()))};
    else return {}; }();
  struct _ {
    template<typename Rg> requires (cs<Rg&>.able) constexpr auto operator()(Rg&& r) const noexcept(cs<Rg&>.nothrow) {
      if constexpr (cs<Rg&>.style == 1) return extent_v<remove_cvref_t<Rg&>>;
      else if constexpr (cs<Rg&>.style == 2) return r.size();
      else if constexpr (cs<Rg&>.style == 3) return size(r);
      else if constexpr (cs<Rg&>.style == 4) return static_cast<make_unsigned_t<t4<Rg>>>(r);
    }
  };
}

namespace _::_data {
  template<typename Rg> using t1 = decltype(std::_::decay_copy(declval<Rg&>().data()));
  template<typename Rg> concept c1 = requires { typename t1<Rg>; requires is_pointer_v<t1<Rg>> && is_object_v<remove_pointer_t<Rg>>; };
  template<typename Rg> concept c2 = contiguous_iterator<ranges::iterator_t<Rg>>;
  template<typename Rg> inline constexpr auto cs = []() -> call_style {
    if constexpr (c1<Rg>) return {1, true, noexcept(std::_::decay_copy(declval<Rg>().data()))};
    else if constexpr (c2<Rg>) return {2, true, noexcept(std::_::to_address(ranges::begin(declval<Rg>())))};
    else return {}; }();
  struct _ {
    template<_borrowed_range Rg> requires (cs<Rg&>.able) constexpr auto operator()(Rg&& r) const noexcept(cs<Rg&>.nothrow) {
      if constexpr (cs<Rg&>.style == 1) return r.data();
      else if constexpr (cs<Rg&>.style == 2) return std::_::to_address(ranges::begin(r));
    }
  };
}


namespace ranges {
  inline namespace _cpo {
    inline constexpr std::_::_size::_ size;
    inline constexpr std::_::_data::_ data;
  }
  template<typename Rg> concept sized_range = range<Rg> && requires(Rg&& r) { ranges::size(r); };
  template<sized_range Rg> using range_size_t = decltype(ranges::size(declval<Rg&>()));

  template<typename Rg> concept contiguous_range =
    range<Rg> && contiguous_iterator<iterator_t<Rg>> &&
    requires(Rg& r) { { ranges::data(r) } -> same_as<add_pointer_t<range_difference_t<Rg>>>; };
}

namespace _ {
  template<typename Ty> constexpr decltype(auto) cforward(remove_reference_t<Ty>& x) noexcept { return static_cast<const remove_reference_t<Ty>&>(x); }
  template<typename Ty> constexpr decltype(auto) cforward(remove_reference_t<Ty>&& x) noexcept { return static_cast<const remove_reference_t<Ty>&&>(x); }
  struct _cbegin {
    template<typename Rg> constexpr auto operator()(Rg&& r) noexcept(noexcept(ranges::begin(_::cforward<Rg>(r))))
      requires requires { ranges::begin(_::cforward<Rg>(r)); } { return ranges::begin(_::cforward<Rg>(r)); }
  };
  struct _cend {
    template<typename Rg> constexpr auto operator()(Rg&& r) noexcept(noexcept(ranges::end(_::cforward<Rg>(r))))
      requires requires { ranges::end(_::cforward<Rg>(r)); } { return ranges::end(_::cforward<Rg>(r)); }
  };
  struct _cdata {
    template<typename Rg> constexpr auto operator()(Rg&& r) noexcept(noexcept(ranges::data(_::cforward<Rg>(r))))
      requires requires { ranges::data(_::cforward<Rg>(r)); } { return ranges::data(_::cforward<Rg>(r)); }
  };
  struct _ssize {
    template<typename Rg> constexpr auto operator()(Rg&& r)
      noexcept(noexcept(static_cast<common_type_t<ptrdiff_t, make_signed_integer_like_t<ranges::range_size_t<Rg>>>>(ranges::size(static_cast<Rg&&>(r)))))
      requires common_with<ptrdiff_t, make_signed_integer_like_t<ranges::range_size_t<Rg>>>
    { return static_cast<common_type_t<ptrdiff_t, make_signed_integer_like_t<ranges::range_size_t<Rg>>>>(ranges::size(static_cast<Rg&&>(r))); }
  };
  struct _empty {
    template<typename Rg> static constexpr bool c1 = requires { bool{declval<Rg>().empty()}; };
    template<typename Rg> static constexpr bool c2 = requires { ranges::size(declval<Rg>()) == 0; };
    template<typename Rg> static constexpr bool c3 = requires { bool{ranges::begin(declval<Rg>()) == ranges::end(declval<Rg>())}; };
    template<typename Rg> static constexpr bool n3 = noexcept(bool{ranges::begin(declval<Rg>()) == ranges::end(declval<Rg>())});
    template<typename Rg> static constexpr auto cs = []() -> call_style {
      if constexpr (c1<Rg>) return {1, true, noexcept(bool{declval<Rg>().empty()})};
      else if constexpr (c2<Rg>) return {2, true, noexcept(ranges::size(declval<Rg>()) == 0)};
      else if constexpr (c3<Rg>) return {3, forward_iterator<ranges::iterator_t<Rg>>, n3<Rg>}; }();
    template<typename Rg> requires (cs<Rg&>.able) constexpr auto operator()(Rg&& r) const noexcept(cs<Rg&>.nothrow) {
      if constexpr (cs<Rg&>.style == 1) return bool{r.empty()};
      else if constexpr (cs<Rg&>.style == 2) return ranges::size(r) == 0;
      else if constexpr (cs<Rg&>.style == 3) return bool(ranges::begin(r) == ranges::end(r));
    }
  };
  struct _advance {
    template<input_or_output_iterator It> constexpr void operator()(It& i, iter_difference_t<It> n) const {
      if constexpr (random_access_iterator<It>) i += n;
      else {
        if constexpr (!bidirectional_iterator<It>) if (n < 0) return;
        if constexpr (bidirectional_iterator<It>) for (; n < 0; ++n) --i;
        for (; n > 0; --n) ++i;
      }
    }
    template<input_or_output_iterator It, sentinel_for<It> Se> constexpr void operator()(It& i, Se s) const {
      if constexpr (assignable_from<It&, Se>) i = std::_::move(s);
      else if constexpr (sized_sentinel_for<Se, It>) (*this)(i, s - i);
      else while (i != s) ++i;
    }
    template<input_or_output_iterator It, sentinel_for<It> Se> constexpr iter_difference_t<It> operator()(It& i, iter_difference_t<It> n, Se s) const {
      if constexpr (sized_sentinel_for<Se, It>) {
        const iter_difference_t<It> d = s - i;
        if ((n < 0 && n <= d) || (n > 0 && n >= d)) {
          if constexpr (assignable_from<It&, Se>) i = std::_::move(s);
          else (*this)(i, d);
          return n - d;
        }
        return (*this)(i, n), 0;
      } else {
        if constexpr (bidirectional_iterator<It>) for (; n < 0 && i != s; ++n) --i;
        else { if (n < 0) return n; }
      }
      for (; n > 0 && i != s; --n) ++i;
      return n;
    }
  };
  struct _distance {
    template<input_or_output_iterator It, sentinel_for<It> Se> constexpr iter_difference_t<It> operator()(It i, Se s) const {
      if constexpr (sized_sentinel_for<Se, It>) return s - i;
      else for (iter_difference<It> n = 0;; ++i, ++n) if (i == s) return n;
    }
    template<ranges::range Rg> constexpr ranges::range_difference_t<Rg> operator()(Rg&& r) const {
        if constexpr (ranges::sized_range<Rg>) return static_cast<ranges::range_difference_t<Rg>>(ranges::size(r));
        else return (*this)(ranges::begin(r), ranges::end(r));
    }
  };
  struct _next {
    template<input_or_output_iterator It> constexpr It operator()(It i) const { return ++i, i; }
    template<input_or_output_iterator It> constexpr It operator()(It i, iter_difference_t<It> n) const { return _advance{}(i, std::_::move(n)), i; }
    template<input_or_output_iterator It, sentinel_for<It> Se> constexpr It operator()(It i, Se s) const { return _advance{}(i, std::_::move(s)), i; }
    template<input_or_output_iterator It, sentinel_for<It> Se> constexpr It operator()(It i, iter_difference_t<It> n, Se s) const
    { return _advance{}(i, std::_::move(n), std::_::move(s)), i; }
  };
  struct _prev {
    template<bidirectional_iterator It> constexpr It operator()(It i) const { return --i, i; }
    template<bidirectional_iterator It> constexpr It operator()(It i, iter_difference_t<It> n) const { return _advance{}(i, -n), i; }
    template<bidirectional_iterator It> constexpr It operator()(It i, iter_difference_t<It> n, It s) const { return _advance{}(i, -n, std::_::move(s)), i; }
  };
}

namespace ranges::inline _cpo {
  inline constexpr _::_cbegin cbegin;
  inline constexpr _::_cend   cend;
  inline constexpr _::_cdata  cdata;
  inline constexpr _::_ssize  ssize;
  inline constexpr _::_empty  empty;
}

namespace ranges {
  inline constexpr _::_advance  advance;
  inline constexpr _::_distance distance;
  inline constexpr _::_next     next;
  inline constexpr _::_prev     prev;

  template<typename Dt> requires is_class_v<Dt> && same_as<Dt, remove_cv_t<Dt>> class view_interface {
    constexpr Dt& derived() noexcept { return static_cast<Dt&>(*this); }
    constexpr const Dt& derived() const noexcept { return static_cast<const Dt&>(*this); }
  public:
    constexpr explicit operator bool() requires requires { ranges::empty(derived()); } { return !ranges::empty(derived()); }
    constexpr explicit operator bool() const requires requires { ranges::empty(derived()); } { return !ranges::empty(derived()); }
    constexpr bool empty() requires forward_range<Dt> { return ranges::begin(derived()) == ranges::end(derived()); }
    constexpr bool empty() const requires forward_range<const Dt> { return ranges::begin(derived()) == ranges::end(derived()); }
    constexpr auto data() requires contiguous_iterator<iterator_t<Dt>> { return _::to_address(ranges::begin(derived())); }
    constexpr auto data() const requires range<const Dt> && contiguous_iterator<iterator_t<const Dt>> { return _::to_address(ranges::begin(derived())); }

    constexpr auto size() requires forward_range<Dt> && sized_sentinel_for<sentinel_t<Dt>, iterator_t<Dt>>
    { return ranges::end(derived()) - ranges::begin(derived()); }

    constexpr auto size() const requires forward_range<const Dt> && sized_sentinel_for<sentinel_t<const Dt>, iterator_t<const Dt>>
    { return ranges::end(derived()) - ranges::begin(derived()); }

    constexpr decltype(auto) front() requires forward_range<Dt> { return *ranges::begin(derived()); }
    constexpr decltype(auto) front() const requires forward_range<const Dt> { return *ranges::begin(derived()); }
    constexpr decltype(auto) back() requires bidirectional_range<Dt> && common_range<Dt> { auto i = derived(); return *--i; }
    constexpr decltype(auto) back() const requires bidirectional_range<const Dt> && common_range<const Dt> { auto i = derived(); return *--i; }
    template<random_access_range Rg = Dt> constexpr decltype(auto) operator[](range_difference_t<Rg> n) { return ranges::begin(derived())[n]; }
    template<random_access_range Rg = const Dt> constexpr decltype(auto) operator[](range_difference_t<Rg> n) const { return ranges::begin(derived())[n]; }
  };
}

}
