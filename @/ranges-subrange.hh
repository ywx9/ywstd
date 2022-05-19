// ywstd/@/ranges-subrange.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#include "../@/_.hh"
#include "../@/pair.hh"
#include "../@/ranges-concepts.hh"
#include "../@/tuple_element.hh"

namespace std {

namespace ranges {
  enum class subrange_kind : bool { unsized, sized };

  template<input_or_output_iterator It, sentinel_for<It> Se = It, subrange_kind Ki = sized_sentinel_for<Se, It> ? subrange_kind::sized : subrange_kind::unsized>
  requires(Ki == subrange_kind::sized || !sized_sentinel_for<Se, It>) class subrange;
}

namespace _ {
  template<typename Ty> concept pair_like = !is_reference_v<Ty> && requires(Ty t) {
    typename tuple_size<Ty>::type;
    requires derived_from<tuple_size<Ty>, integral_constant<size_t, 2>>;
    typename tuple_element_t<0, remove_const_t<Ty>>;
    typename tuple_element_t<1, remove_const_t<Ty>>;
    { std::get<0>(t) } -> convertible_to<const tuple_element_t<0, Ty>&>;
    { std::get<1>(t) } -> convertible_to<const tuple_element_t<1, Ty>&>; };
  template<typename T1, typename T2> concept convertible_to_non_slicing =
    convertible_to<T1, T2> && !(is_pointer_v<decay_t<T1>> && is_pointer_v<decay_t<T2>> &&
    !same_as<remove_pointer_t<decay_t<T1>>, remove_pointer_t<decay_t<T2>>>);
  template<typename Ty, typename T1, typename T2> concept pair_like_convertible_from =
    !ranges::range<Ty> && pair_like<Ty> && constructible_from<Ty, T1, T2> &&
    convertible_to_non_slicing<T1, tuple_element_t<0, Ty>> &&
    convertible_to_non_slicing<T2, tuple_element_t<1, Ty>>;

  template<typename It, typename Se, ranges::subrange_kind Ki, bool Bx = Ki == ranges::subrange_kind::sized && !sized_sentinel_for<Se, It>>
  class subrange_base : public ranges::view_interface<ranges::subrange<It, Se, Ki>> {
  protected:
    using size_type = make_unsigned_integer_like_t<iter_difference_t<It>>;
    static constexpr bool _has_size = true;
    size_type _size = 0;
  public:
    subrange_base() = default;
    constexpr explicit subrange_base(const size_type& Size) noexcept : _size(Size) {}
  };
  template<typename It, typename Se, ranges::subrange_kind Ki>
  class subrange_base<It, Se, Ki, false> : public ranges::view_interface<ranges::subrange<It, Se, Ki>> {
  protected:
    using size_type = make_unsigned_integer_like_t<iter_difference_t<It>>;
    static constexpr bool _has_size = false;
  public:
    subrange_base() = default;
    constexpr explicit subrange_base(const size_type&) noexcept {}
  };
}

namespace ranges {
  template<input_or_output_iterator It, sentinel_for<It> Se, subrange_kind Ki>
  requires(Ki == subrange_kind::sized || !sized_sentinel_for<Se, It>)
  class subrange : public _::subrange_base<It, Se, Ki> {
  private:
    using _::subrange_base<It, Se, Ki>::_has_size;
    using typename _::subrange_base<It, Se, Ki>::size_type;
    It _first{};
    Se _last{};
    template<typename Rg> constexpr subrange(true_type, Rg&& r) : subrange{static_cast<Rg&&>(r), ranges::size(r)} {}
    template<typename Rg> constexpr subrange(false_type, Rg&& r) : subrange{ranges::begin(r), ranges::end(r)} {}
  public:
    subrange() requires default_initializable<It> = default;
    constexpr subrange(_::convertible_to_non_slicing<It> auto i, Se s) requires(!_has_size) : _first(_::move(i)), _last(_::move(s)) {}

    constexpr subrange(_::convertible_to_non_slicing<It> auto i, Se s, _::make_unsigned_integer_like_t<iter_difference_t<It>> n)
      requires(Ki == subrange_kind::sized) : _::subrange_base<It, Se, Ki>(n), _first(_::move(i)), _last(_::move(s)) {}

    template<_::different_from<subrange> Rg>
    requires borrowed_range<Rg> && _::convertible_to_non_slicing<iterator_t<Rg>, It> && convertible_to<sentinel_t<Rg>, Se>
    constexpr subrange(Rg&& r) requires(!_has_size || sized_range<Rg>) : subrange{bool_constant<_has_size>{}, static_cast<Rg&&>(r)} {}

    template<borrowed_range Rg> requires _::convertible_to_non_slicing<iterator_t<Rg>, It> && convertible_to<sentinel_t<Rg>, Se>
    constexpr subrange(Rg&& r, const size_type n) requires(Ki == subrange_kind::sized) : subrange{ranges::begin(r), ranges::end(r), n} {}

    template<_::different_from<subrange> PairLike> requires _::pair_like_convertible_from<PairLike, const It&, const Se&>
    constexpr operator PairLike() const { return PairLike{_first, _last}; }

    constexpr It begin() const requires copyable<It> { return _first; }
    constexpr It begin() requires(!copyable<It>) { return _::move(_first); }
    constexpr Se end() const { return _last; }
    [[nodiscard]] constexpr bool empty() const { return _first == _last; }

    constexpr size_type size() const requires(Ki == subrange_kind::sized) {
      if constexpr (_has_size) return this->_size;
      else return static_cast<size_type>(_last - _first);
    }
    constexpr subrange next() const& requires forward_iterator<It> {
      auto a = *this;
      if (a._first != a._last) {
        ++a._first;
        if constexpr (_has_size) --a._size;
      }
      return a;
    }
    constexpr subrange next(const iter_difference_t<It> n) const& requires forward_iterator<It> {
      auto a = *this;
      return a.advance(n), a;
    }
    constexpr subrange next() && {
      if (_first != _last) {
        ++_first;
        if constexpr (_has_size) --this->_size;
      }
      return _::move(*this);
    }
    constexpr subrange next(const iter_difference_t<It> n) && { return advance(n), _::move(*this); }

    constexpr subrange prev() const requires bidirectional_iterator<It> {
      auto a = *this;
      --a._first;
      if constexpr (_has_size) ++a._size;
      return a;
    }
    constexpr subrange prev(const iter_difference_t<It> n) const requires bidirectional_iterator<It> {
      auto a = *this;
      return a.advance(-n), a;
    }
    constexpr subrange& advance(const iter_difference_t<It> n) {
      if constexpr (bidirectional_iterator<It>) {
        if (n < 0) {
          ranges::advance(_first, n);
          if constexpr (_has_size) this->_size += static_cast<size_type>(-n);
          return *this;
        }
      }
      const auto a = ranges::advance(_first, n, _last);
      if constexpr (_has_size) this->_size -= static_cast<size_type>(n - a);
      return *this;
    }
  };

  template<input_or_output_iterator It, sentinel_for<It> Se>
  subrange(It, Se) -> subrange<It, Se>;

  template<input_or_output_iterator It, sentinel_for<It> Se>
  subrange(It, Se, _::make_unsigned_integer_like_t<iter_difference_t<It>>) -> subrange<It, Se, subrange_kind::sized>;

  template<borrowed_range Rg> subrange(Rg&&)
    -> subrange<iterator_t<Rg>, sentinel_t<Rg>,
                (sized_range<Rg> || sized_sentinel_for<sentinel_t<Rg>, iterator_t<Rg>>) ? subrange_kind::sized
                                                                                        : subrange_kind::unsized>;

  template<borrowed_range Rg> subrange(Rg&&, _::make_unsigned_integer_like_t<range_difference_t<Rg>>)
    -> subrange<iterator_t<Rg>, sentinel_t<Rg>, subrange_kind::sized>;

  template<typename It, typename Se, subrange_kind Ki> inline constexpr bool enable_borrowed_range<subrange<It, Se, Ki>> = true;

  template<size_t Ix, typename It, typename Se, subrange_kind Ki> requires(Ix < 2)
  constexpr auto get(const subrange<It, Se, Ki>& r) { if constexpr (Ix == 0) return r.begin(); else return r.end(); }
  template<size_t Ix, typename It, typename Se, subrange_kind Ki> requires(Ix < 2)
  constexpr auto get(subrange<It, Se, Ki>&& r) { if constexpr (Ix == 0) return r.begin(); else return r.end(); }

  struct dangling {
    constexpr dangling() noexcept = default;
    template<typename... Ts> constexpr dangling(Ts&&...) noexcept {}
  };
  template<range Rg> using borrowed_iterator_t = conditional_t<borrowed_range<Rg>, iterator_t<Rg>, dangling>;
  template<range Rg> using borrowed_subrange_t = conditional_t<borrowed_range<Rg>, subrange<iterator_t<Rg>>, dangling>;
}

using ranges::get;
template<typename It, typename Se, ranges::subrange_kind Ki> struct tuple_size<ranges::subrange<It, Se, Ki>> : integral_constant<size_t, 2> {};
template<typename It, typename Se, ranges::subrange_kind Ki> struct tuple_element<0, ranges::subrange<It, Se, Ki>> { using type = It; };
template<typename It, typename Se, ranges::subrange_kind Ki> struct tuple_element<1, ranges::subrange<It, Se, Ki>> { using type = Se; };
template<typename It, typename Se, ranges::subrange_kind Ki> struct tuple_element<0, const ranges::subrange<It, Se, Ki>> { using type = It; };
template<typename It, typename Se, ranges::subrange_kind Ki> struct tuple_element<1, const ranges::subrange<It, Se, Ki>> { using type = Se; };

}
