// ywstd/scoped_allocator.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <scoped_allocator>
#else

#include "@/allocator.hh"

namespace std {

template<typename OuterAlloc, typename... InnerAllocs> class scoped_allocator_adaptor;

namespace _ {
  template<typename OuterAlloc, typename... InnerAllocs> struct inner_allocator_type { using type = scoped_allocator_adaptor<InnerAllocs...>; };
  template<typename OuterAlloc> struct inner_allocator_type<OuterAlloc> { using type = scoped_allocator_adaptor<OuterAlloc>; };
}

template<typename OuterAlloc, typename... InnerAllocs>
class scoped_allocator_adaptor : public OuterAlloc {
public:
  using outer_allocator_type = OuterAlloc;
  using inner_allocator_type = typename _::inner_allocator_type<OuterAlloc, InnerAllocs...>::type;
  using value_type = typename allocator_traits<OuterAlloc>::value_type;
  using size_type = typename allocator_traits<OuterAlloc>::size_type;
  using difference_type = typename allocator_traits<OuterAlloc>::difference_type;
  using pointer = typename allocator_traits<OuterAlloc>::pointer;
  using const_pointer = typename allocator_traits<OuterAlloc>::const_pointer;
  using void_pointer = typename allocator_traits<OuterAlloc>::void_pointer;
  using const_void_pointer = typename allocator_traits<OuterAlloc>::const_void_pointer;
  using propagate_on_container_copy_assignment = integral_constant<bool, allocator_traits<OuterAlloc>::propagate_on_container_copy_assignment::value ||
                                                                         (allocator_traits<InnerAllocs>::propagate_on_container_copy_assignment::value || ...)>;
  using propagate_on_container_move_assignment = integral_constant<bool, allocator_traits<OuterAlloc>::propagate_on_container_move_assignment::value ||
                                                                         (allocator_traits<InnerAllocs>::propagate_on_container_move_assignment::value || ...)>;
  using propagate_on_container_swap = integral_constant<bool, allocator_traits<OuterAlloc>::propagate_on_container_swap::value ||
                                                              (allocator_traits<InnerAllocs>::propagate_on_container_swap::value || ...)>;
  using is_always_equal = integral_constant<bool, allocator_traits<OuterAlloc>::propagate_on_container_copy_assignment::value &&
                                                  (allocator_traits<InnerAllocs>::propagate_on_container_copy_assignment::value && ...)>;
  template<typename Ty> struct rebind {
      using other = scoped_allocator_adaptor<typename allocator_traits<OuterAlloc>::template rebind_alloc<Ty>, InnerAllocs...>;
  };

  ~scoped_allocator_adaptor();
  scoped_allocator_adaptor();
  template<typename OuterA2> scoped_allocator_adaptor(OuterA2&& outerAlloc, const InnerAllocs&... innerAllocs) noexcept;
  scoped_allocator_adaptor(const scoped_allocator_adaptor& other) noexcept;
  scoped_allocator_adaptor(scoped_allocator_adaptor&& other) noexcept;
  template<typename OuterA2> scoped_allocator_adaptor(const scoped_allocator_adaptor<OuterA2, InnerAllocs...>& other) noexcept;
  template<typename OuterA2> scoped_allocator_adaptor(scoped_allocator_adaptor<OuterA2, InnerAllocs...>&& other) noexcept;
  scoped_allocator_adaptor& operator=(const scoped_allocator_adaptor&) = default;
  scoped_allocator_adaptor& operator=(scoped_allocator_adaptor&&) = default;

  inner_allocator_type& inner_allocator() noexcept;
  const inner_allocator_type& inner_allocator() const noexcept;
  outer_allocator_type& outer_allocator() noexcept;
  const outer_allocator_type& outer_allocator() const noexcept;
  [[nodiscard]] pointer allocate(size_type n);
  [[nodiscard]] pointer allocate(size_type n, const_void_pointer hint);
  void deallocate(pointer p, size_type n);
  size_type max_size() const;
  template<typename Ty, typename... As> void construct(Ty* p, As&&... args);
  template<typename Ty> void destroy(Ty* p);
  scoped_allocator_adaptor select_on_container_copy_construction() const;
};

template<typename OuterAlloc, typename... InnerAllocs>
scoped_allocator_adaptor(OuterAlloc, InnerAllocs...) -> scoped_allocator_adaptor<OuterAlloc, InnerAllocs...>;

template<typename OuterA1, typename OuterA2, typename... InnerAllocs>
bool operator==(const scoped_allocator_adaptor<OuterA1, InnerAllocs...>& a, const scoped_allocator_adaptor<OuterA2, InnerAllocs...>& b) noexcept;

}

#endif
