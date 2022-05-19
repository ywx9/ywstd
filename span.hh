// ywstd/span.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <span>
#else

#include "@/../array.hh"
#include "@/../limits.hh"
#include "@/byte.hh"
#include "@/ranges-concepts.hh"
#include "@/ranges-subrange.hh"

namespace std {

inline constexpr size_t dynamic_extent = numeric_limits<size_t>::max();

template<typename Ty, size_t Extent = dynamic_extent> class span {
  template<size_t Offset, size_t Count> static constexpr size_t subspan_extent =
    Count != dynamic_extent ? Count : (Extent != dynamic_extent ? Extent - Offset : dynamic_extent);
public:
  using element_type = Ty;
  using value_type = typename remove_cv<Ty>::type;
  using size_type = size_t;
  using difference_type = ptrdiff_t;
  using pointer = element_type*;
  using const_pointer = const element_type*;
  using reference = element_type&;
  using const_reference = const element_type&;

  class iterator {
    typename span::pointer _ptr;
  public:
    using value_type = typename span::value_type;
    using difference_type = typename span::difference_type;
    using pointer = typename span::pointer;
    using reference = typename span::reference;
    using iterator_category = random_access_iterator_tag;
    using iterator_concept = contiguous_iterator_tag;
    constexpr iterator() = default;
    constexpr iterator(const iterator&) = default;
    constexpr iterator(iterator&&) = default;
    constexpr iterator(typename span::pointer p) : _ptr{p} {}
    constexpr iterator& operator=(const iterator&) = default;
    constexpr iterator& operator=(iterator&&) = default;
    constexpr reference operator*() const { return *_ptr; }
    constexpr pointer operator->() const { return _ptr; }
    constexpr reference operator[](difference_type n) const { return *(_ptr + n); }
    constexpr iterator& operator++() { return ++_ptr, *this; }
    constexpr iterator& operator--() { return --_ptr, *this; }
    constexpr iterator operator++(int) { return {_ptr++}; }
    constexpr iterator operator--(int) { return {_ptr--}; }
    constexpr iterator& operator+=(difference_type n) { return _ptr += n, *this; }
    constexpr iterator& operator-=(difference_type n) { return _ptr -= n, *this; }
    constexpr iterator operator+(difference_type n) { return {_ptr + n}; }
    constexpr iterator operator-(difference_type n) { return {_ptr + n}; }
    constexpr difference_type operator-(iterator i) { return _ptr - i._ptr; }
    friend constexpr iterator operator+(difference_type n, iterator i) { return i + n; }
    constexpr bool operator==(const iterator& i) const { return _ptr == i._ptr; }
    constexpr strong_ordering operator<=>(const iterator& i) const { return _ptr <=> i._ptr; };
  };

  using reverse_iterator = std::reverse_iterator<iterator>;
  static constexpr size_type extent = Extent;

  ~span() noexcept = default;
  constexpr span() noexcept;
  template<typename It> constexpr explicit(extent != dynamic_extent) span(It first, size_type count);
  template<typename It, typename End> constexpr explicit(extent != dynamic_extent) span(It first, End last);
  template<size_t Nx> constexpr span(typename type_identity<element_type>::type (&arr)[Nx]) noexcept;
  template<typename Uy, size_t Nx> constexpr span(array<Uy, Nx>& arr) noexcept;
  template<typename Uy, size_t Nx> constexpr span(const array<Uy, Nx>& arr) noexcept;
  template<typename Rg> constexpr explicit(extent != dynamic_extent) span(Rg&& r);
  constexpr span(const span& other) noexcept = default;
  template<typename Ty2, size_t Ex2>
  constexpr explicit(extent != dynamic_extent && Ex2 == dynamic_extent) span(const span<Ty2, Ex2>& s) noexcept;


  constexpr span& operator=(const span& other) noexcept = default;

  template<size_t Count> constexpr span<element_type, Count> first() const;
  template<size_t Count> constexpr span<element_type, Count> last() const;
  template<size_t Offset, size_t Count = dynamic_extent> constexpr span<element_type, subspan_extent<Offset, Count>> subspan() const;

  constexpr span<element_type, dynamic_extent> first(size_type count) const;
  constexpr span<element_type, dynamic_extent> last(size_type count) const;
  constexpr span<element_type, dynamic_extent> subspan( size_type offset, size_type count = dynamic_extent) const;

  constexpr size_type size() const noexcept;
  constexpr size_type size_bytes() const noexcept;
  [[nodiscard]] constexpr bool empty() const noexcept;

  constexpr reference operator[](size_type idx) const;
  constexpr reference front() const;
  constexpr reference back() const;
  constexpr pointer data() const noexcept;

  constexpr iterator begin() const noexcept;
  constexpr iterator end() const noexcept;
  constexpr reverse_iterator rbegin() const noexcept;
  constexpr reverse_iterator rend() const noexcept;

private:
  pointer _ptr;
  size_type _size;
};

template<typename It, typename EndOrSize> span(It, EndOrSize) -> span<typename remove_reference<iter_reference_t<It>>::type>;
template<typename Ty, size_t Nx> span(Ty (&)[Nx]) -> span<Ty, Nx>;
template<typename Ty, size_t Nx> span(array<Ty, Nx>&) -> span<Ty, Nx>;
template<typename Ty, size_t Nx> span(const array<Ty, Nx>&) -> span<const Ty, Nx>;
template<typename Rg> span(Rg&&) -> span<typename remove_reference<ranges::range_reference_t<Rg>>::type>;

}


namespace std {

template<typename Ty, size_t Extent> inline constexpr bool ranges::enable_borrowed_range<span<Ty, Extent>> = true;

template<typename Ty, size_t Extent>
span<const byte, Extent == dynamic_extent ? dynamic_extent : sizeof(Ty) * Extent> as_bytes(span<Ty, Extent> s) noexcept;

template<typename Ty, size_t Extent>
span<byte, Extent == dynamic_extent ? dynamic_extent : sizeof(Ty) * Extent>
as_writable_bytes(span<Ty, Extent> s) noexcept;

}

#endif
