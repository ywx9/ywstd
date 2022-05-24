// ywstd/unordered_map.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#ifdef _ywstd_
#include <unordered_map>
#else

#include "@/../compare.hh"
#include "@/../initializer_list.hh"
#include "@/../iterator.hh"
#include "@/../type_traits.hh"

#include "@/allocator.hh"
#include "@/equal_to.hh"
#include "@/hash.hh"
#include "@/pair.hh"
#include "@/polymorphic_allocator.hh"

namespace std {

template<typename Key, typename Ty, typename Hash = hash<Key>, typename Pred = equal_to<Key>, typename Al = allocator<pair<const Key, Ty>>> class unordered_map;
template<typename Key, typename Ty, typename Hash = hash<Key>, typename Pred = equal_to<Key>, typename Al = allocator<pair<const Key, Ty>>> class unordered_multimap;

namespace _ {
  template<typename Key, typename Ty, typename Hash, typename Pred, typename Al> struct node_handler<unordered_map<Key, Ty, Hash, Pred, Al>> {
    using key_type = Key;
    using mapped_type = Ty;
    using allocator_type = Al;
    ~node_handler();
    constexpr node_handler() noexcept {}
    node_handler(node_handler&&) noexcept;
    node_handler& operator=(node_handler&&);
    [[nodiscard]] bool empty() const noexcept;
    explicit operator bool() const noexcept;
    allocator_type get_allocator() const;
    key_type& key() const;
    mapped_type& mapped() const;
    void swap(node_handler&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_swappable_v<Hash> && is_nothrow_swappable_v<Pred>);
    friend void swap(node_handler& x, node_handler& y) noexcept(noexcept(x.swap(y)));
  };
  template<typename Key, typename Ty, typename Hash, typename Pred, typename Al> struct node_handler<unordered_multimap<Key, Ty, Hash, Pred, Al>> {
    using key_type = Key;
    using mapped_type = Ty;
    using allocator_type = Al;
    ~node_handler();
    constexpr node_handler() noexcept {}
    node_handler(node_handler&&) noexcept;
    node_handler& operator=(node_handler&&);
    [[nodiscard]] bool empty() const noexcept;
    explicit operator bool() const noexcept;
    allocator_type get_allocator() const;
    key_type& key() const;
    mapped_type& mapped() const;
    void swap(node_handler&) noexcept(allocator_traits<Al>::is_always_equal::value && is_nothrow_swappable_v<Hash> && is_nothrow_swappable_v<Pred>);
    friend void swap(node_handler& x, node_handler& y) noexcept(noexcept(x.swap(y)));
  };
}

template<typename Key, typename Ty, typename Hash, typename Pred, typename Al> class unordered_map {
public:
  using key_type = Key;
  using mapped_type = Ty;
  using value_type = pair<const Key, Ty>;
  using hasher = Hash;
  using key_equal = Pred;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename unordered_map::value_type;
    using difference_type = typename unordered_map::difference_type;
    using pointer = typename unordered_map::pointer;
    using reference = typename unordered_map::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    iterator() = default;
    iterator(const iterator&) = default;
    iterator(iterator&&) = default;
    iterator(typename unordered_map::pointer p);
    iterator& operator=(const iterator&) = default;
    iterator& operator=(iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    iterator& operator++();
    iterator operator++(int);
    constexpr difference_type operator-(const iterator& i);
    bool operator==(const iterator& i) const;
    strong_ordering operator<=>(const iterator& i);
  };

  class const_iterator {
  public:
    using value_type = typename unordered_map::value_type;
    using difference_type = typename unordered_map::difference_type;
    using pointer = typename unordered_map::const_pointer;
    using reference = typename unordered_map::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
    const_iterator(typename unordered_map::pointer p);
    const_iterator& operator=(const const_iterator&) = default;
    const_iterator& operator=(const_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_iterator& operator++();
    const_iterator operator++(int);
    constexpr difference_type operator-(const const_iterator& i);
    bool operator==(const const_iterator& i) const;
    strong_ordering operator<=>(const const_iterator& i) const;
  };

  class local_iterator {
  public:
    using value_type = typename unordered_map::value_type;
    using difference_type = typename unordered_map::difference_type;
    using pointer = typename unordered_map::pointer;
    using reference = typename unordered_map::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    local_iterator() = default;
    local_iterator(const local_iterator&) = default;
    local_iterator(local_iterator&&) = default;
    local_iterator(typename unordered_map::pointer p);
    local_iterator& operator=(const local_iterator&) = default;
    local_iterator& operator=(local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    local_iterator& operator++();
    local_iterator operator++(int);
    constexpr difference_type operator-(const local_iterator& i);
    bool operator==(const local_iterator& i) const;
    strong_ordering operator<=>(const local_iterator& i);
  };

  class const_local_iterator {
  public:
    using value_type = typename unordered_map::value_type;
    using difference_type = typename unordered_map::difference_type;
    using pointer = typename unordered_map::const_pointer;
    using reference = typename unordered_map::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_local_iterator() = default;
    const_local_iterator(const const_local_iterator&) = default;
    const_local_iterator(const_local_iterator&&) = default;
    const_local_iterator(typename unordered_map::pointer p);
    const_local_iterator& operator=(const const_local_iterator&) = default;
    const_local_iterator& operator=(const_local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_local_iterator& operator++();
    const_local_iterator operator++(int);
    constexpr difference_type operator-(const const_local_iterator& i);
    bool operator==(const const_local_iterator& i) const;
    strong_ordering operator<=>(const const_local_iterator& i) const;
  };

  using node_type = _::node_handler<unordered_map>;
  using insert_return_type = _::insert_return_type<iterator, node_type>;

  ~unordered_map();
  unordered_map() : unordered_map{_::min_buckets} {}
  explicit unordered_map(size_type n, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  template<typename InpIt> unordered_map(InpIt f, InpIt l, size_type n = _::min_buckets, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_map(const unordered_map&);
  unordered_map(unordered_map&&);
  explicit unordered_map(const Al&);
  unordered_map(const unordered_map&, const Al&);
  unordered_map(unordered_map&&, const Al&);
  unordered_map(initializer_list<value_type> il, size_type n = _::min_buckets, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_map(size_type n, const allocator_type& a) : unordered_map(n, hasher(), key_equal(), a) {}
  unordered_map(size_type n, const hasher& hf, const allocator_type& a) : unordered_map(n, hf, key_equal(), a) {}
  template<typename InpIt> unordered_map(InpIt f, InpIt l, size_type n, const allocator_type& a) : unordered_map(f, l, n, hasher(), key_equal(), a) {}
  template<typename InpIt> unordered_map(InpIt f, InpIt l, size_type n, const hasher& hf, const allocator_type& a) : unordered_map(f, l, n, hf, key_equal(), a) {}
  unordered_map(initializer_list<value_type> il, size_type n, const allocator_type& a) : unordered_map(il, n, hasher(), key_equal(), a) {}
  unordered_map(initializer_list<value_type> il, size_type n, const hasher& hf, const allocator_type& a) : unordered_map(il, n, hf, key_equal(), a) {}
  unordered_map& operator=(const unordered_map&);
  unordered_map& operator=(unordered_map&&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_move_assignable_v<Hash> && _::is_nothrow_move_assignable_v<Pred>);
  unordered_map& operator=(initializer_list<value_type>);
  allocator_type get_allocator() const noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  template<typename... Args> pair<iterator, bool> emplace(Args&&... args);
  template<typename... Args> iterator emplace_hint(const_iterator position, Args&&... args);
  pair<iterator, bool> insert(const value_type& obj);
  pair<iterator, bool> insert(value_type&& obj);
  template<typename P> pair<iterator, bool> insert(P&& obj);
  iterator insert(const_iterator hint, const value_type& obj);
  iterator insert(const_iterator hint, value_type&& obj);
  template<typename P> iterator insert(const_iterator hint, P&& obj);
  template<typename InpIt> void insert(InpIt first, InpIt last);
  void insert(initializer_list<value_type>);

  node_type extract(const_iterator position);
  node_type extract(const key_type& x);
  template<typename K> node_type extract(K&& x);
  insert_return_type insert(node_type&& nh);
  iterator insert(const_iterator hint, node_type&& nh);

  template<typename... Args> pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);
  template<typename... Args> pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);
  template<typename... Args> iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args);
  template<typename... Args> iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);
  template<typename M> pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);
  template<typename M> pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);
  template<typename M> iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);
  template<typename M> iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);

  iterator erase(iterator position);
  iterator erase(const_iterator position);
  size_type erase(const key_type& k);
  template<typename K> size_type erase(K&& x);
  iterator erase(const_iterator first, const_iterator last);
  void swap(unordered_map&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_swappable_v<Hash>&& _::is_nothrow_swappable_v<Pred>);
  void clear() noexcept;

  template<typename H2, typename P2> void merge(unordered_map<Key, Ty, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_map<Key, Ty, H2, P2, Al>&& source);
  template<typename H2, typename P2> void merge(unordered_multimap<Key, Ty, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_multimap<Key, Ty, H2, P2, Al>&& source);

  hasher hash_function() const;
  key_equal key_eq() const;

  iterator find(const key_type& k);
  const_iterator find(const key_type& k) const;
  template<typename K> iterator find(const K& k);
  template<typename K> const_iterator find(const K& k) const;
  template<typename K> size_type count(const key_type& k) const;
  template<typename K> size_type count(const K& k) const;
  bool contains(const key_type& k) const;
  template<typename K> bool contains(const K& k) const;
  pair<iterator, iterator> equal_range(const key_type& k);
  pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
  template<typename K> pair<iterator, iterator> equal_range(const K& k);
  template<typename K> pair<const_iterator, const_iterator> equal_range(const K& k) const;

  mapped_type& operator[](const key_type& k);
  mapped_type& operator[](key_type&& k);
  mapped_type& at(const key_type& k);
  const mapped_type& at(const key_type& k) const;

  size_type bucket_count() const noexcept;
  size_type max_bucket_count() const noexcept;
  size_type bucket_size(size_type n) const;
  size_type bucket(const key_type& k) const;
  local_iterator begin(size_type n);
  const_local_iterator begin(size_type n) const;
  local_iterator end(size_type n);
  const_local_iterator end(size_type n) const;
  const_local_iterator cbegin(size_type n) const;
  const_local_iterator cend(size_type n) const;

  float load_factor() const noexcept;
  float max_load_factor() const noexcept;
  void max_load_factor(float z);
  void rehash(size_type n);
  void reserve(size_type n);
};

template<typename InpIt,
         typename Hash = hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
         typename Pred = equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
         typename Al = allocator<pair<typename add_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                      typename iterator_traits<InpIt>::value_type::second_type>>>
unordered_map(InpIt, InpIt,
              typename unordered_map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                     typename iterator_traits<InpIt>::value_type::second_type, Hash, Pred, Al >::size_type = _::min_buckets,
              Hash = Hash{}, Pred = Pred{}, Al = Al{})
  -> unordered_map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                   typename iterator_traits<InpIt>::value_type::second_type,
                   Hash, Pred, Al>;

template<typename Key, typename Ty, typename Hash = hash<Key>, typename Pred = equal_to<Key>, typename Al = allocator<pair<const Key, Ty>>>
unordered_map(initializer_list<pair<Key, Ty>>,
              typename unordered_map<Key, Ty, Hash, Pred, Al>::size_type = _::min_buckets,
              Hash = Hash{}, Pred = Pred{}, Al = Al())
  -> unordered_map<Key, Ty, Hash, Pred, Al>;

template<typename InpIt, typename Al>
unordered_map(InpIt, InpIt,
              typename unordered_map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                     typename iterator_traits<InpIt>::value_type::second_type,
                                     hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                                     equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                                     Al>::size_type,
              Al)
  -> unordered_map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                   typename iterator_traits<InpIt>::value_type::second_type,
                   hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                   equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                   Al>;

template<typename InpIt, typename Al>
unordered_map(InpIt, InpIt, Al)
  -> unordered_map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                   typename iterator_traits<InpIt>::value_type::second_type,
                   hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                   equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                   Al>;

template<typename InpIt, typename Hash, typename Al>
unordered_map(InpIt, InpIt,
              typename unordered_map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                     typename iterator_traits<InpIt>::value_type::second_type,
                                     Hash,
                                     equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                                     Al>::size_type,
              Hash, Al)
  -> unordered_map<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                   typename iterator_traits<InpIt>::value_type::second_type,
                   Hash,
                   equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                   Al>;

template<typename Key, typename Ty, typename Al>
unordered_map(initializer_list<pair<Key, Ty>>, typename unordered_map<Key, Ty, hash<Key>, equal_to<Key>, Al>::size_type, Al)
  -> unordered_map<Key, Ty, hash<Key>, equal_to<Key>, Al>;

template<typename Key, typename Ty, typename Al>
unordered_map(initializer_list<pair<Key, Ty>>, Al)
  -> unordered_map<Key, Ty, hash<Key>, equal_to<Key>, Al>;

template<typename Key, typename Ty, typename Hash, typename Al>
unordered_map(initializer_list<pair<Key, Ty>>, typename unordered_map<Key, Ty, Hash, equal_to<Key>, Al>::size_type, Hash, Al)
  -> unordered_map<Key, Ty, Hash, equal_to<Key>, Al>;

template<typename Key, typename Ty, typename Hash, typename Pred, typename Alloc>
bool operator==(const unordered_map<Key, Ty, Hash, Pred, Alloc>& a, const unordered_map<Key, Ty, Hash, Pred, Alloc>& b);

template<typename Key, typename Ty, typename Hash, typename Pred, typename Alloc>
void swap(unordered_map<Key, Ty, Hash, Pred, Alloc>& x, unordered_map<Key, Ty, Hash, Pred, Alloc>& y) noexcept(noexcept(x.swap(y)));

template<typename Key, typename Ty, typename Hash, typename Pred, typename Al, typename Pred2>
class unordered_map<Key, Ty, Hash, Pred, Al>::size_type erase_if(unordered_map<Key, Ty, Hash, Pred, Al>& c, Pred2 pred);

template<typename Key, typename Ty, typename Hash, typename Pred, typename Al>
class unordered_multimap {
public:
  using key_type = Key;
  using mapped_type = Ty;
  using value_type = pair<const Key, Ty>;
  using hasher = Hash;
  using key_equal = Pred;
  using allocator_type = Al;
  using pointer = typename allocator_traits<Al>::pointer;
  using const_pointer = typename allocator_traits<Al>::const_pointer;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  using difference_type = ptrdiff_t;

  class iterator {
  public:
    using value_type = typename unordered_multimap::value_type;
    using difference_type = typename unordered_multimap::difference_type;
    using pointer = typename unordered_multimap::pointer;
    using reference = typename unordered_multimap::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    iterator() = default;
    iterator(const iterator&) = default;
    iterator(iterator&&) = default;
    iterator(typename unordered_multimap::pointer p);
    iterator& operator=(const iterator&) = default;
    iterator& operator=(iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    iterator& operator++();
    iterator operator++(int);
    constexpr difference_type operator-(const iterator& i);
    bool operator==(const iterator& i) const;
    strong_ordering operator<=>(const iterator& i);
  };

  class const_iterator {
  public:
    using value_type = typename unordered_multimap::value_type;
    using difference_type = typename unordered_multimap::difference_type;
    using pointer = typename unordered_multimap::const_pointer;
    using reference = typename unordered_multimap::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_iterator() = default;
    const_iterator(const const_iterator&) = default;
    const_iterator(const_iterator&&) = default;
    const_iterator(typename unordered_multimap::pointer p);
    const_iterator& operator=(const const_iterator&) = default;
    const_iterator& operator=(const_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_iterator& operator++();
    const_iterator operator++(int);
    constexpr difference_type operator-(const const_iterator& i);
    bool operator==(const const_iterator& i) const;
    strong_ordering operator<=>(const const_iterator& i) const;
  };

  class local_iterator {
  public:
    using value_type = typename unordered_multimap::value_type;
    using difference_type = typename unordered_multimap::difference_type;
    using pointer = typename unordered_multimap::pointer;
    using reference = typename unordered_multimap::reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    local_iterator() = default;
    local_iterator(const local_iterator&) = default;
    local_iterator(local_iterator&&) = default;
    local_iterator(typename unordered_multimap::pointer p);
    local_iterator& operator=(const local_iterator&) = default;
    local_iterator& operator=(local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    local_iterator& operator++();
    local_iterator operator++(int);
    constexpr difference_type operator-(const local_iterator& i);
    bool operator==(const local_iterator& i) const;
    strong_ordering operator<=>(const local_iterator& i);
  };

  class const_local_iterator {
  public:
    using value_type = typename unordered_multimap::value_type;
    using difference_type = typename unordered_multimap::difference_type;
    using pointer = typename unordered_multimap::const_pointer;
    using reference = typename unordered_multimap::const_reference;
    using iterator_category = forward_iterator_tag;
    using iterator_concept = forward_iterator_tag;
    const_local_iterator() = default;
    const_local_iterator(const const_local_iterator&) = default;
    const_local_iterator(const_local_iterator&&) = default;
    const_local_iterator(typename unordered_multimap::pointer p);
    const_local_iterator& operator=(const const_local_iterator&) = default;
    const_local_iterator& operator=(const_local_iterator&&) = default;
    reference operator*() const;
    pointer operator->() const;
    const_local_iterator& operator++();
    const_local_iterator operator++(int);
    constexpr difference_type operator-(const const_local_iterator& i);
    bool operator==(const const_local_iterator& i) const;
    strong_ordering operator<=>(const const_local_iterator& i) const;
  };

  using node_type = _::node_handler<unordered_multimap>;

  ~unordered_multimap();
  unordered_multimap();
  explicit unordered_multimap(size_type n, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  template<typename InpIt> unordered_multimap(InpIt f, InpIt l, size_type n = _::min_buckets, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_multimap(const unordered_multimap&);
  unordered_multimap(unordered_multimap&&);
  explicit unordered_multimap(const Al&);
  unordered_multimap(const unordered_multimap&, const Al&);
  unordered_multimap(unordered_multimap&&, const Al&);
  unordered_multimap(initializer_list<value_type> il, size_type n = _::min_buckets, const hasher& hf = hasher(), const key_equal& eql = key_equal(), const allocator_type& a = allocator_type());
  unordered_multimap(size_type n, const allocator_type& a) : unordered_multimap(n, hasher(), key_equal(), a) {}
  unordered_multimap(size_type n, const hasher& hf, const allocator_type& a) : unordered_multimap(n, hf, key_equal(), a) {}
  template<typename InpIt> unordered_multimap(InpIt f, InpIt l, size_type n, const allocator_type& a) : unordered_multimap(f, l, n, hasher(), key_equal(), a) {}
  template<typename InpIt> unordered_multimap(InpIt f, InpIt l, size_type n, const hasher& hf, const allocator_type& a) : unordered_multimap(f, l, n, hf, key_equal(), a) {}
  unordered_multimap(initializer_list<value_type> il, size_type n, const allocator_type& a) : unordered_multimap(il, n, hasher(), key_equal(), a) {}
  unordered_multimap(initializer_list<value_type> il, size_type n, const hasher& hf, const allocator_type& a) : unordered_multimap(il, n, hf, key_equal(), a) {}
  unordered_multimap& operator=(const unordered_multimap&);
  unordered_multimap& operator=(unordered_multimap&&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_move_assignable_v<Hash> && _::is_nothrow_move_assignable_v<Pred>);
  unordered_multimap& operator=(initializer_list<value_type>);
  allocator_type get_allocator() const noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  [[nodiscard]] bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  template<typename... Args> iterator emplace(Args&&... args);
  template<typename... Args> iterator emplace_hint(const_iterator position, Args&&... args);
  iterator insert(const value_type& obj);
  iterator insert(value_type&& obj);
  template<typename P> iterator insert(P&& obj);
  iterator insert(const_iterator hint, const value_type& obj);
  iterator insert(const_iterator hint, value_type&& obj);
  template<typename P> iterator insert(const_iterator hint, P&& obj);
  template<typename InpIt> void insert(InpIt first, InpIt last);
  void insert(initializer_list<value_type>);

  node_type extract(const_iterator position);
  node_type extract(const key_type& x);
  template<typename K> node_type extract(K&& x);
  iterator insert(node_type&& nh);
  iterator insert(const_iterator hint, node_type&& nh);

  iterator erase(iterator position);
  iterator erase(const_iterator position);
  size_type erase(const key_type& k);
  template<typename K> size_type erase(K&& x);
  iterator erase(const_iterator first, const_iterator last);
  void swap(unordered_multimap&) noexcept(allocator_traits<Al>::is_always_equal::value && _::is_nothrow_swappable_v<Hash> && _::is_nothrow_swappable_v<Pred>);
  void clear() noexcept;

  template<typename H2, typename P2> void merge(unordered_multimap<Key, Ty, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_multimap<Key, Ty, H2, P2, Al>&& source);
  template<typename H2, typename P2> void merge(unordered_map<Key, Ty, H2, P2, Al>& source);
  template<typename H2, typename P2> void merge(unordered_map<Key, Ty, H2, P2, Al>&& source);

  hasher hash_function() const;
  key_equal key_eq() const;

  iterator find(const key_type& k);
  const_iterator find(const key_type& k) const;
  template<typename K> iterator find(const K& k);
  template<typename K> const_iterator find(const K& k) const;
  size_type count(const key_type& k) const;
  template<typename K> size_type count(const K& k) const;
  bool contains(const key_type& k) const;
  template<typename K> bool contains(const K& k) const;
  pair<iterator, iterator> equal_range(const key_type& k);
  pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
  template<typename K> pair<iterator, iterator> equal_range(const K& k);
  template<typename K> pair<const_iterator, const_iterator> equal_range(const K& k) const;

  size_type bucket_count() const noexcept;
  size_type max_bucket_count() const noexcept;
  size_type bucket_size(size_type n) const;
  size_type bucket(const key_type& k) const;
  local_iterator begin(size_type n);
  const_local_iterator begin(size_type n) const;
  local_iterator end(size_type n);
  const_local_iterator end(size_type n) const;
  const_local_iterator cbegin(size_type n) const;
  const_local_iterator cend(size_type n) const;

  float load_factor() const noexcept;
  float max_load_factor() const noexcept;
  void max_load_factor(float z);
  void rehash(size_type n);
  void reserve(size_type n);
};

template<typename InpIt,
         typename Hash = hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
         typename Pred = equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
         typename Al = allocator<pair<typename add_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                      typename iterator_traits<InpIt>::value_type::second_type>>>
unordered_multimap(InpIt, InpIt,
                   typename unordered_multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                               typename iterator_traits<InpIt>::value_type::second_type,
                                               Hash, Pred, Al>::size_type = _::min_buckets,
                   Hash = Hash(), Pred = Pred(), Al = Al())
  -> unordered_multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                        typename iterator_traits<InpIt>::value_type::second_type,
                        Hash, Pred, Al>;

template<typename Key, typename Ty, typename Hash = hash<Key>, typename Pred = equal_to<Key>, typename Al = allocator<pair<const Key, Ty>>>
unordered_multimap(initializer_list<pair<Key, Ty>>,
                   typename unordered_multimap<Key, Ty, Hash, Pred, Al>::size_type = _::min_buckets,
                   Hash = Hash(), Pred = Pred(), Al = Al())
  -> unordered_multimap<Key, Ty, Hash, Pred, Al>;

template<typename InpIt, typename Al>
unordered_multimap(InpIt, InpIt,
                   typename unordered_multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                               typename iterator_traits<InpIt>::value_type::second_type,
                                               hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                                               equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>, Al>::size_type,
                   Al)
  -> unordered_multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                        typename iterator_traits<InpIt>::value_type::second_type,
                        hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                        equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                        Al>;

template<typename InpIt, typename Al>
unordered_multimap(InpIt, InpIt, Al)
  -> unordered_multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                        typename iterator_traits<InpIt>::value_type::second_type,
                        hash<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                        equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>, Al>;

template<typename InpIt, typename Hash, typename Al>
unordered_multimap(InpIt, InpIt,
                   typename unordered_multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                                               typename iterator_traits<InpIt>::value_type::second_type,
                                               Hash,
                                               equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                                               Al>::size_type,
                   Hash, Al)
  -> unordered_multimap<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type,
                        typename iterator_traits<InpIt>::value_type::second_type,
                        Hash,
                        equal_to<typename remove_const<typename iterator_traits<InpIt>::value_type::first_type>::type>,
                        Al>;

template<typename Key, typename Ty, typename Al>
unordered_multimap(initializer_list<pair<Key, Ty>>, typename unordered_multimap<Key, Ty, hash<Key>, equal_to<Key>, Al>::size_type, Al)
  -> unordered_multimap<Key, Ty, hash<Key>, equal_to<Key>, Al>;

template<typename Key, typename Ty, typename Al>
unordered_multimap(initializer_list<pair<Key, Ty>>, Al)
  -> unordered_multimap<Key, Ty, hash<Key>, equal_to<Key>, Al>;

template<typename Key, typename Ty, typename Hash, typename Al>
unordered_multimap(initializer_list<pair<Key, Ty>>, typename unordered_multimap<Key, Ty, Hash, equal_to<Key>, Al>::size_type, Hash, Al)
  -> unordered_multimap<Key, Ty, Hash, equal_to<Key>, Al>;

template<typename Key, typename Ty, typename Hash, typename Pred, typename Alloc>
void swap(unordered_multimap<Key, Ty, Hash, Pred, Alloc>& x, unordered_multimap<Key, Ty, Hash, Pred, Alloc>& y) noexcept(noexcept(x.swap(y)));

template<typename Key, typename Ty, typename Hash, typename Pred, typename Alloc>
bool operator==(const unordered_multimap<Key, Ty, Hash, Pred, Alloc>& a, const unordered_multimap<Key, Ty, Hash, Pred, Alloc>& b);

template<typename K, typename Ty, typename H, typename P, typename A, typename Pred>
class unordered_multimap<K, Ty, H, P, A>::size_type
erase_if(unordered_multimap<K, Ty, H, P, A>& c, Pred pred);

namespace pmr {
  template<typename Key, typename Ty, typename Hash = hash<Key>, typename Pred = equal_to<Key>>
  using unordered_map = std::unordered_map<Key, Ty, Hash, Pred, polymorphic_allocator<pair<const Key, Ty>>>;

  template<typename Key, typename Ty, typename Hash = hash<Key>, typename Pred = equal_to<Key>>
  using unordered_multimap = std::unordered_multimap<Key, Ty, Hash, Pred, polymorphic_allocator<pair<const Key, Ty>>>;
}

}

#endif
