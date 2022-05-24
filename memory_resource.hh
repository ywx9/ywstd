// ywstd/memory_resource.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <memory_resource>
#else

#include "@/polymorphic_allocator.hh"

namespace std::pmr {
using std::pmr::memory_resource;
using std::pmr::polymorphic_allocator;

bool operator==(const memory_resource&, const memory_resource&) noexcept;
template<typename T1, typename T2> bool operator==(const polymorphic_allocator<T1>&, const polymorphic_allocator<T2>&) noexcept;
}

namespace std::pmr {

memory_resource* new_delete_resource() noexcept;
memory_resource* null_memory_resource() noexcept;
memory_resource* set_default_resource(memory_resource* r) noexcept;
memory_resource* get_default_resource() noexcept;

struct pool_options {
  size_t max_blocks_per_chunk = 0;
  size_t largest_required_pool_block = 0;
};

class synchronized_pool_resource : public memory_resource {
public:
  virtual ~synchronized_pool_resource();
  synchronized_pool_resource(const pool_options& opts, memory_resource* upstream);
  synchronized_pool_resource() : synchronized_pool_resource(pool_options(), get_default_resource()) {}
  explicit synchronized_pool_resource(memory_resource* upstream) : synchronized_pool_resource(pool_options(), upstream) {}
  explicit synchronized_pool_resource(const pool_options& opts) : synchronized_pool_resource(opts, get_default_resource()) {}
  synchronized_pool_resource(const synchronized_pool_resource&) = delete;
  synchronized_pool_resource& operator=(const synchronized_pool_resource&) = delete;
  void release();
  memory_resource* upstream_resource() const;
  pool_options options() const;
protected:
  void* do_allocate(size_t bytes, size_t alignment) override;
  void do_deallocate(void* p, size_t bytes, size_t alignment) override;
  bool do_is_equal(const memory_resource& other) const noexcept override;
};

class unsynchronized_pool_resource : public memory_resource {
public:
  virtual ~unsynchronized_pool_resource();
  unsynchronized_pool_resource(const pool_options& opts, memory_resource* upstream);
  unsynchronized_pool_resource() : unsynchronized_pool_resource(pool_options(), get_default_resource()) {}
  explicit unsynchronized_pool_resource(memory_resource* upstream) : unsynchronized_pool_resource(pool_options(), upstream) {}
  explicit unsynchronized_pool_resource(const pool_options& opts) : unsynchronized_pool_resource(opts, get_default_resource()) {}
  unsynchronized_pool_resource(const unsynchronized_pool_resource&) = delete;
  unsynchronized_pool_resource& operator=(const unsynchronized_pool_resource&) = delete;
  void release();
  memory_resource* upstream_resource() const;
  pool_options options() const;
protected:
  void* do_allocate(size_t bytes, size_t alignment) override;
  void do_deallocate(void* p, size_t bytes, size_t alignment) override;
  bool do_is_equal(const memory_resource& other) const noexcept override;
};

class monotonic_buffer_resource : public memory_resource {
public:
  virtual ~monotonic_buffer_resource();
  explicit monotonic_buffer_resource(memory_resource* upstream);
  monotonic_buffer_resource(size_t initial_size, memory_resource* upstream);
  monotonic_buffer_resource(void* buffer, size_t buffer_size, memory_resource* upstream);
  monotonic_buffer_resource() : monotonic_buffer_resource(get_default_resource()) {}
  explicit monotonic_buffer_resource(size_t initial_size) : monotonic_buffer_resource(initial_size, get_default_resource()) {}
  monotonic_buffer_resource(void* buffer, size_t buffer_size) : monotonic_buffer_resource(buffer, buffer_size, get_default_resource()) {}
  monotonic_buffer_resource(const monotonic_buffer_resource&) = delete;
  monotonic_buffer_resource& operator=(const monotonic_buffer_resource&) = delete;
  void release();
  memory_resource* upstream_resource() const;
protected:
  void* do_allocate(size_t bytes, size_t alignment) override;
  void do_deallocate(void* p, size_t bytes, size_t alignment) override;
  bool do_is_equal(const memory_resource& other) const noexcept override;
};

}

#endif
