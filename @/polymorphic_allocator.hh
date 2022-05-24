// ywstd/@/polymorphic_allocator.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "byte.hh"

namespace std {

using max_align_t = long double;
using size_t = decltype(sizeof(int));

}

namespace std::pmr {

class memory_resource {
  static constexpr size_t max_align = alignof(max_align_t);
public:
  virtual ~memory_resource();
  memory_resource() = default;
  memory_resource(const memory_resource&) = default;
  memory_resource& operator=(const memory_resource&) = default;
  [[nodiscard]] void* allocate(size_t bytes, size_t alignment = max_align);
  void deallocate(void* p, size_t bytes, size_t alignment = max_align);
  bool is_equal(const memory_resource& other) const noexcept;
private:
  virtual void* do_allocate(size_t bytes, size_t alignment) = 0;
  virtual void do_deallocate(void* p, size_t bytes, size_t alignment) = 0;
  virtual bool do_is_equal(const memory_resource& other) const noexcept = 0;
};

template<typename Tp = byte> class polymorphic_allocator {
  memory_resource* memory_rsrc;
public:
  using value_type = Tp;
  polymorphic_allocator() noexcept;
  polymorphic_allocator(memory_resource* r);
  polymorphic_allocator(const polymorphic_allocator& other) = default;
  template<typename Up> polymorphic_allocator(const polymorphic_allocator<Up>& other) noexcept;
  polymorphic_allocator& operator=(const polymorphic_allocator&) = delete;
  [[nodiscard]] Tp* allocate(size_t n);
  void deallocate(Tp* p, size_t n);
  [[nodiscard]] void* allocate_bytes(size_t nbytes, size_t alignment = alignof(max_align_t));
  void deallocate_bytes(void* p, size_t nbytes, size_t alignment = alignof(max_align_t));
  template<typename Ty> [[nodiscard]] Ty* allocate_object(size_t n = 1);
  template<typename Ty> void deallocate_object(Ty* p, size_t n = 1);
  template<typename Ty, typename... As> [[nodiscard]] Ty* new_object(As&&... as);
  template<typename Ty> void delete_object(Ty* p);
  template<typename Ty, typename... As> void construct(Ty* p, As&&... as);
  polymorphic_allocator select_on_container_copy_construction() const;
  memory_resource* resource() const;
};

}
