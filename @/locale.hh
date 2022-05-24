// ywstd/@/locale.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma once

#include "basic_string.hh"

namespace std {

class locale {
public:
  class id {
  public:
    id();
    id(const id&) = delete;
    id& operator=(const id&) = delete;
  };
  class facet {
  protected:
    virtual ~facet();
    explicit facet(size_t = 0);
    facet(const facet&) = delete;
    facet& operator=(const facet&) = delete;
  };
  using category = int;;
  static const category none = 0, collate = 0x010, ctype = 0x020, monetary = 0x040, numeric = 0x080, time = 0x100,
                        messages = 0x200, all = collate | ctype | monetary | numeric | time | messages;

  ~locale();
  locale() noexcept;
  locale(const locale& other) noexcept;
  explicit locale(const char* std_name);
  explicit locale(const string& std_name);
  locale(const locale& other, const char* std_name, category);
  locale(const locale& other, const string& std_name, category);
  template<typename Facet> locale(const locale& other, Facet* f);
  locale(const locale& other, const locale& one, category);
  const locale& operator=(const locale& other) noexcept;
  template<typename Facet> locale combine(const locale& other) const;
  basic_string<char> name() const;
  bool operator==(const locale& other) const;
  bool operator!=(const locale& other) const;
  template<typename Ct, typename Tr, typename Al> bool operator()(const basic_string<Ct, Tr, Al>&, const basic_string<Ct, Tr, Al>&) const;
  static locale global(const locale&);
  static const locale& classic();
};

}
