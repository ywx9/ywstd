// ywstd/DirectXMath.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off/

#pragma once

#ifdef _ywstd_
#include <DirectXMath.h>
#else

#include "@/../immintrin.hh"

namespace std {

using size_t = decltype(sizeof(int));
using int32_t = int;
using uint8_t = unsigned char;
using uint32_t = unsigned int;

}

namespace DirectX {

using std::int32_t;
using std::size_t;
using std::uint32_t;
using std::uint8_t;

inline constexpr float XM_PI = 3.141592654f;
inline constexpr float XM_2PI = 6.283185307f;
inline constexpr float XM_1DIVPI = 0.318309886f;
inline constexpr float XM_1DIV2PI = 0.159154943f;
inline constexpr float XM_PIDIV2 = 1.570796327f;
inline constexpr float XM_PIDIV4 = 0.785398163f;

inline constexpr uint32_t XM_SELECT_0 = 0x00000000;
inline constexpr uint32_t XM_SELECT_1 = 0xFFFFFFFF;

inline constexpr uint32_t XM_PERMUTE_0X = 0;
inline constexpr uint32_t XM_PERMUTE_0Y = 1;
inline constexpr uint32_t XM_PERMUTE_0Z = 2;
inline constexpr uint32_t XM_PERMUTE_0W = 3;
inline constexpr uint32_t XM_PERMUTE_1X = 4;
inline constexpr uint32_t XM_PERMUTE_1Y = 5;
inline constexpr uint32_t XM_PERMUTE_1Z = 6;
inline constexpr uint32_t XM_PERMUTE_1W = 7;

inline constexpr uint32_t XM_SWIZZLE_X = 0;
inline constexpr uint32_t XM_SWIZZLE_Y = 1;
inline constexpr uint32_t XM_SWIZZLE_Z = 2;
inline constexpr uint32_t XM_SWIZZLE_W = 3;

inline constexpr uint32_t XM_CRMASK_CR6 = 0x000000F0;
inline constexpr uint32_t XM_CRMASK_CR6TRUE = 0x00000080;
inline constexpr uint32_t XM_CRMASK_CR6FALSE = 0x00000020;
inline constexpr uint32_t XM_CRMASK_CR6BOUNDS = XM_CRMASK_CR6FALSE;

inline constexpr size_t XM_CACHE_LINE_SIZE = 64;

inline constexpr float XMConvertToRadians(float fDegrees) { return fDegrees * (XM_PI / 180.0f); }
inline constexpr float XMConvertToDegrees(float fRadians) { return fRadians * (180.0f / XM_PI); }

inline bool XMComparisonAllTrue(uint32_t CR) { return (((CR)&XM_CRMASK_CR6TRUE) == XM_CRMASK_CR6TRUE); }
inline bool XMComparisonAnyTrue(uint32_t CR) { return (((CR)&XM_CRMASK_CR6FALSE) != XM_CRMASK_CR6FALSE); }
inline bool XMComparisonAllFalse(uint32_t CR) { return (((CR)&XM_CRMASK_CR6FALSE) == XM_CRMASK_CR6FALSE); }
inline bool XMComparisonAnyFalse(uint32_t CR) { return (((CR)&XM_CRMASK_CR6TRUE) != XM_CRMASK_CR6TRUE); }
inline bool XMComparisonMixed(uint32_t CR) { return (((CR)&XM_CRMASK_CR6) == 0); }
inline bool XMComparisonAllInBounds(uint32_t CR) { return (((CR)&XM_CRMASK_CR6BOUNDS) == XM_CRMASK_CR6BOUNDS); }
inline bool XMComparisonAnyOutOfBounds(uint32_t CR) { return (((CR)&XM_CRMASK_CR6BOUNDS) != XM_CRMASK_CR6BOUNDS); }

using XMVECTOR = yw::intrin::__m128;
using FXMVECTOR = const XMVECTOR&;
using GXMVECTOR = const XMVECTOR&;
using HXMVECTOR = const XMVECTOR&;
using CXMVECTOR = const XMVECTOR&;

struct alignas(16) XMVECTORF32 {
  union {
    float f[4];
    XMVECTOR v;
  };
  inline operator XMVECTOR() const { return v; }
  inline operator const float*() const { return f; }
};

struct alignas(16) XMVECTORI32 {
  union {
    int32_t i[4];
    XMVECTOR v;
  };
  inline operator XMVECTOR() const { return v; }
};

struct alignas(16) XMVECTORU8 {
  union {
    uint8_t u[16];
    XMVECTOR v;
  };
  inline operator XMVECTOR() const { return v; }
};

struct alignas(16) XMVECTORU32 {
  union {
    uint32_t u[4];
    XMVECTOR v;
  };
  inline operator XMVECTOR() const { return v; }
};

struct alignas(16) XMMATRIX;
using FXMMATRIX = const XMMATRIX&;
using CXMMATRIX = const XMMATRIX&;

struct alignas(16) XMMATRIX {
  XMVECTOR r[4];
  XMMATRIX() = default;
  XMMATRIX(const XMMATRIX&) = default;
  XMMATRIX(XMMATRIX&&) = default;
  XMMATRIX& operator=(const XMMATRIX&) = default;
  XMMATRIX& operator=(XMMATRIX&&) = default;
  constexpr XMMATRIX(FXMVECTOR R0, FXMVECTOR R1, FXMVECTOR R2, CXMVECTOR R3) : r{R0, R1, R2, R3} {}
  XMMATRIX(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
           float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
  explicit XMMATRIX(const float* pArray);
  XMMATRIX operator+() const { return *this; }
  XMMATRIX operator-() const;
  XMMATRIX& operator+=(FXMMATRIX M);
  XMMATRIX& operator-=(FXMMATRIX M);
  XMMATRIX& operator*=(FXMMATRIX M);
  XMMATRIX& operator*=(float S);
  XMMATRIX& operator/=(float S);
  XMMATRIX operator+(FXMMATRIX M) const;
  XMMATRIX operator-(FXMMATRIX M) const;
  XMMATRIX operator*(FXMMATRIX M) const;
  XMMATRIX operator*(float S) const;
  XMMATRIX operator/(float S) const;
  friend XMMATRIX operator*(float S, FXMMATRIX M);
};

struct XMFLOAT2 {
  float x, y;
  XMFLOAT2() = default;
  XMFLOAT2(const XMFLOAT2&) = default;
  XMFLOAT2(XMFLOAT2&&) = default;
  constexpr XMFLOAT2(float _x, float _y) : x(_x), y(_y) {}
  explicit XMFLOAT2(const float* pArray) : x(pArray[0]), y(pArray[1]) {}
  XMFLOAT2& operator=(const XMFLOAT2&) = default;
  XMFLOAT2& operator=(XMFLOAT2&&) = default;
};

struct alignas(16) XMFLOAT2A : public XMFLOAT2 {
  XMFLOAT2A() = default;
  XMFLOAT2A(const XMFLOAT2A&) = default;
  XMFLOAT2A(XMFLOAT2A&&) = default;
  constexpr XMFLOAT2A(float _x, float _y) : XMFLOAT2(_x, _y) {}
  explicit XMFLOAT2A(const float* pArray) : XMFLOAT2(pArray) {}
  XMFLOAT2A& operator=(const XMFLOAT2A&) = default;
  XMFLOAT2A& operator=(XMFLOAT2A&&) = default;
};

struct XMINT2 {
  int32_t x, y;
  XMINT2() = default;
  XMINT2(const XMINT2&) = default;
  XMINT2(XMINT2&&) = default;
  constexpr XMINT2(int32_t _x, int32_t _y) : x(_x), y(_y) {}
  explicit XMINT2(const int32_t* pArray) : x(pArray[0]), y(pArray[1]) {}
  XMINT2& operator=(const XMINT2&) = default;
  XMINT2& operator=(XMINT2&&) = default;
};

struct XMUINT2 {
  uint32_t x, y;
  XMUINT2() = default;
  XMUINT2(const XMUINT2&) = default;
  XMUINT2(XMUINT2&&) = default;
  constexpr XMUINT2(uint32_t _x, uint32_t _y) : x(_x), y(_y) {}
  explicit XMUINT2(const uint32_t* pArray) : x(pArray[0]), y(pArray[1]) {}
  XMUINT2& operator=(const XMUINT2&) = default;
  XMUINT2& operator=(XMUINT2&&) = default;
};

struct XMFLOAT3 {
  float x, y, z;
  XMFLOAT3() = default;
  XMFLOAT3(const XMFLOAT3&) = default;
  XMFLOAT3(XMFLOAT3&&) = default;
  constexpr XMFLOAT3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
  explicit XMFLOAT3(const float* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
  XMFLOAT3& operator=(const XMFLOAT3&) = default;
  XMFLOAT3& operator=(XMFLOAT3&&) = default;
};

struct alignas(16) XMFLOAT3A : public XMFLOAT3 {
  XMFLOAT3A() = default;
  XMFLOAT3A(const XMFLOAT3A&) = default;
  XMFLOAT3A(XMFLOAT3A&&) = default;
  constexpr XMFLOAT3A(float _x, float _y, float _z) : XMFLOAT3(_x, _y, _z) {}
  explicit XMFLOAT3A(const float* pArray) : XMFLOAT3(pArray) {}
  XMFLOAT3A& operator=(const XMFLOAT3A&) = default;
  XMFLOAT3A& operator=(XMFLOAT3A&&) = default;
};

struct XMINT3 {
  int32_t x, y, z;
  XMINT3() = default;
  XMINT3(const XMINT3&) = default;
  XMINT3(XMINT3&&) = default;
  constexpr XMINT3(int32_t _x, int32_t _y, int32_t _z) : x(_x), y(_y), z(_z) {}
  explicit XMINT3(const int32_t* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
  XMINT3& operator=(const XMINT3&) = default;
  XMINT3& operator=(XMINT3&&) = default;
};

struct XMUINT3 {
  uint32_t x, y, z;
  XMUINT3() = default;
  XMUINT3(const XMUINT3&) = default;
  XMUINT3(XMUINT3&&) = default;
  constexpr XMUINT3(uint32_t _x, uint32_t _y, uint32_t _z) : x(_x), y(_y), z(_z) {}
  explicit XMUINT3(const uint32_t* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]) {}
  XMUINT3& operator=(const XMUINT3&) = default;
  XMUINT3& operator=(XMUINT3&&) = default;
};

struct XMFLOAT4 {
  float x, y, z, w;
  XMFLOAT4() = default;
  XMFLOAT4(const XMFLOAT4&) = default;
  XMFLOAT4(XMFLOAT4&&) = default;
  constexpr XMFLOAT4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
  explicit XMFLOAT4(const float* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
  XMFLOAT4& operator=(const XMFLOAT4&) = default;
  XMFLOAT4& operator=(XMFLOAT4&&) = default;
};

struct alignas(16) XMFLOAT4A : public XMFLOAT4 {
  XMFLOAT4A() = default;
  XMFLOAT4A(const XMFLOAT4A&) = default;
  XMFLOAT4A(XMFLOAT4A&&) = default;
  constexpr XMFLOAT4A(float _x, float _y, float _z, float _w) : XMFLOAT4(_x, _y, _z, _w) {}
  explicit XMFLOAT4A(const float* pArray) : XMFLOAT4(pArray) {}
  XMFLOAT4A& operator=(const XMFLOAT4A&) = default;
  XMFLOAT4A& operator=(XMFLOAT4A&&) = default;
};

struct XMINT4 {
  int32_t x, y, z, w;
  XMINT4() = default;
  XMINT4(const XMINT4&) = default;
  XMINT4(XMINT4&&) = default;
  constexpr XMINT4(int32_t _x, int32_t _y, int32_t _z, int32_t _w) : x(_x), y(_y), z(_z), w(_w) {}
  explicit XMINT4(const int32_t* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
  XMINT4& operator=(const XMINT4&) = default;
  XMINT4& operator=(XMINT4&&) = default;
};

struct XMUINT4 {
  uint32_t x, y, z, w;
  XMUINT4() = default;
  XMUINT4(const XMUINT4&) = default;
  XMUINT4(XMUINT4&&) = default;
  constexpr XMUINT4(uint32_t _x, uint32_t _y, uint32_t _z, uint32_t _w) : x(_x), y(_y), z(_z), w(_w) {}
  explicit XMUINT4(const uint32_t* pArray) : x(pArray[0]), y(pArray[1]), z(pArray[2]), w(pArray[3]) {}
  XMUINT4& operator=(const XMUINT4&) = default;
  XMUINT4& operator=(XMUINT4&&) = default;
};

struct XMFLOAT3X3 {
  union {
    struct {
      float _11, _12, _13, _21, _22, _23, _31, _32, _33;
    };
    float m[3][3];
  };
  XMFLOAT3X3() = default;
  XMFLOAT3X3(const XMFLOAT3X3&) = default;
  XMFLOAT3X3(XMFLOAT3X3&&) = default;
  XMFLOAT3X3& operator=(const XMFLOAT3X3&) = default;
  XMFLOAT3X3& operator=(XMFLOAT3X3&&) = default;
  constexpr XMFLOAT3X3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
    : _11(m00), _12(m01), _13(m02), _21(m10), _22(m11), _23(m12), _31(m20), _32(m21), _33(m22) {}
  explicit XMFLOAT3X3(const float* pArray);
  float operator()(size_t Row, size_t Column) const { return m[Row][Column]; }
  float& operator()(size_t Row, size_t Column) { return m[Row][Column]; }
};

struct XMFLOAT4X3 {
  union {
    struct {
      float _11, _12, _13, _21, _22, _23, _31, _32, _33, _41, _42, _43;
    };
    float m[4][3];
    float f[12];
  };
  XMFLOAT4X3() = default;
  XMFLOAT4X3(const XMFLOAT4X3&) = default;
  XMFLOAT4X3(XMFLOAT4X3&&) = default;
  XMFLOAT4X3& operator=(const XMFLOAT4X3&) = default;
  XMFLOAT4X3& operator=(XMFLOAT4X3&&) = default;
  constexpr XMFLOAT4X3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22, float m30, float m31, float m32)
    : _11(m00), _12(m01), _13(m02), _21(m10), _22(m11), _23(m12), _31(m20), _32(m21), _33(m22), _41(m30), _42(m31), _43(m32) {}
  explicit XMFLOAT4X3(const float* pArray);
  float operator()(size_t Row, size_t Column) const { return m[Row][Column]; }
  float& operator()(size_t Row, size_t Column) { return m[Row][Column]; }
};

struct alignas(16) XMFLOAT4X3A : public XMFLOAT4X3 {
  XMFLOAT4X3A() = default;
  XMFLOAT4X3A(const XMFLOAT4X3A&) = default;
  XMFLOAT4X3A(XMFLOAT4X3A&&) = default;
  XMFLOAT4X3A& operator=(const XMFLOAT4X3A&) = default;
  XMFLOAT4X3A& operator=(XMFLOAT4X3A&&) = default;
  constexpr XMFLOAT4X3A(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22, float m30, float m31, float m32)
    : XMFLOAT4X3(m00, m01, m02, m10, m11, m12, m20, m21, m22, m30, m31, m32) {}
  explicit XMFLOAT4X3A(const float* pArray) : XMFLOAT4X3(pArray) {}
};

struct XMFLOAT3X4 {
  union {
    struct {
      float _11, _12, _13, _14, _21, _22, _23, _24, _31, _32, _33, _34;
    };
    float m[3][4];
    float f[12];
  };
  XMFLOAT3X4() = default;
  XMFLOAT3X4(const XMFLOAT3X4&) = default;
  XMFLOAT3X4(XMFLOAT3X4&&) = default;
  XMFLOAT3X4& operator=(const XMFLOAT3X4&) = default;
  XMFLOAT3X4& operator=(XMFLOAT3X4&&) = default;
  constexpr XMFLOAT3X4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23)
    : _11(m00), _12(m01), _13(m02), _14(m03), _21(m10), _22(m11), _23(m12), _24(m13), _31(m20), _32(m21), _33(m22), _34(m23) {}
  explicit XMFLOAT3X4(const float* pArray);
  float operator()(size_t Row, size_t Column) const { return m[Row][Column]; }
  float& operator()(size_t Row, size_t Column) { return m[Row][Column]; }
};

struct alignas(16) XMFLOAT3X4A : public XMFLOAT3X4 {
  XMFLOAT3X4A() = default;
  XMFLOAT3X4A(const XMFLOAT3X4A&) = default;
  XMFLOAT3X4A(XMFLOAT3X4A&&) = default;
  XMFLOAT3X4A& operator=(const XMFLOAT3X4A&) = default;
  XMFLOAT3X4A& operator=(XMFLOAT3X4A&&) = default;
  constexpr XMFLOAT3X4A(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23)
    : XMFLOAT3X4(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23) {}
  explicit XMFLOAT3X4A(const float* pArray) : XMFLOAT3X4(pArray) {}
};

struct XMFLOAT4X4 {
  union {
    struct {
      float _11, _12, _13, _14, _21, _22, _23, _24, _31, _32, _33, _34, _41, _42, _43, _44;
    };
    float m[4][4];
  };
  XMFLOAT4X4() = default;
  XMFLOAT4X4(const XMFLOAT4X4&) = default;
  XMFLOAT4X4(XMFLOAT4X4&&) = default;
  XMFLOAT4X4& operator=(const XMFLOAT4X4&) = default;
  XMFLOAT4X4& operator=(XMFLOAT4X4&&) = default;
  constexpr XMFLOAT4X4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                       float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
    : _11(m00), _12(m01), _13(m02), _14(m03), _21(m10), _22(m11), _23(m12), _24(m13),
      _31(m20), _32(m21), _33(m22), _34(m23), _41(m30), _42(m31), _43(m32), _44(m33) {}
  explicit XMFLOAT4X4(const float* pArray);
  float operator()(size_t Row, size_t Column) const { return m[Row][Column]; }
  float& operator()(size_t Row, size_t Column) { return m[Row][Column]; }
};

struct alignas(16) XMFLOAT4X4A : public XMFLOAT4X4 {
  XMFLOAT4X4A() = default;
  XMFLOAT4X4A(const XMFLOAT4X4A&) = default;
  XMFLOAT4X4A(XMFLOAT4X4A&&) = default;
  XMFLOAT4X4A& operator=(const XMFLOAT4X4A&) = default;
  XMFLOAT4X4A& operator=(XMFLOAT4X4A&&) = default;
  constexpr XMFLOAT4X4A(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                        float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
    : XMFLOAT4X4(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33) {}
  explicit XMFLOAT4X4A(const float* pArray) : XMFLOAT4X4(pArray) {}
};

//==============================================================================================================================================================
// DirectXMathConvert.inl

inline XMVECTOR XMConvertVectorIntToFloat(FXMVECTOR VInt, uint32_t DivExponent) { return {}; }
inline XMVECTOR XMConvertVectorFloatToInt(FXMVECTOR VFloat, uint32_t MulExponent) { return {}; }
inline XMVECTOR XMConvertVectorUIntToFloat(FXMVECTOR VUInt, uint32_t DivExponent) { return {}; }
inline XMVECTOR XMConvertVectorFloatToUInt(FXMVECTOR VFloat, uint32_t MulExponent) { return {}; }
inline XMVECTOR XMLoadInt(const uint32_t* pSource) { return {}; }
inline XMVECTOR XMLoadFloat(const float* pSource) { return {}; }
inline XMVECTOR XMLoadInt2(const uint32_t* pSource) { return {}; }
inline XMVECTOR XMLoadInt2A(const uint32_t* pSource) { return {}; }
inline XMVECTOR XMLoadFloat2(const XMFLOAT2* pSource) { return {}; }
inline XMVECTOR XMLoadFloat2A(const XMFLOAT2A* pSource) { return {}; }
inline XMVECTOR XMLoadSInt2(const XMINT2* pSource) { return {}; }
inline XMVECTOR XMLoadUInt2(const XMUINT2* pSource) { return {}; }
inline XMVECTOR XMLoadInt3(const uint32_t* pSource) { return {}; }
inline XMVECTOR XMLoadInt3A(const uint32_t* pSource) { return {}; }
inline XMVECTOR XMLoadFloat3(const XMFLOAT3* pSource) { return {}; }
inline XMVECTOR XMLoadFloat3A(const XMFLOAT3A* pSource) { return {}; }
inline XMVECTOR XMLoadSInt3(const XMINT3* pSource) { return {}; }
inline XMVECTOR XMLoadUInt3(const XMUINT3* pSource) { return {}; }
inline XMVECTOR XMLoadInt4(const uint32_t* pSource) { return {}; }
inline XMVECTOR XMLoadInt4A(const uint32_t* pSource) { return {}; }
inline XMVECTOR XMLoadFloat4(const XMFLOAT4* pSource) { return {}; }
inline XMVECTOR XMLoadFloat4A(const XMFLOAT4A* pSource) { return {}; }
inline XMVECTOR XMLoadSInt4(const XMINT4* pSource) { return {}; }
inline XMVECTOR XMLoadUInt4(const XMUINT4* pSource) { return {}; }
inline XMMATRIX XMLoadFloat3x3(const XMFLOAT3X3* pSource) { return {}; }
inline XMMATRIX XMLoadFloat4x3(const XMFLOAT4X3* pSource) { return {}; }
inline XMMATRIX XMLoadFloat4x3A(const XMFLOAT4X3A* pSource) { return {}; }
inline XMMATRIX XMLoadFloat3x4(const XMFLOAT3X4* pSource) { return {}; }
inline XMMATRIX XMLoadFloat3x4A(const XMFLOAT3X4A* pSource) { return {}; }
inline XMMATRIX XMLoadFloat4x4(const XMFLOAT4X4* pSource) { return {}; }
inline XMMATRIX XMLoadFloat4x4A(const XMFLOAT4X4A* pSource) { return {}; }
inline void XMStoreInt(uint32_t* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat(float* pDestination, FXMVECTOR V) {}
inline void XMStoreInt2(uint32_t* pDestination, FXMVECTOR V) {}
inline void XMStoreInt2A(uint32_t* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat2(XMFLOAT2* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat2A(XMFLOAT2A* pDestination, FXMVECTOR V) {}
inline void XMStoreSInt2(XMINT2* pDestination, FXMVECTOR V) {}
inline void XMStoreUInt2(XMUINT2* pDestination, FXMVECTOR V) {}
inline void XMStoreInt3(uint32_t* pDestination, FXMVECTOR V) {}
inline void XMStoreInt3A(uint32_t* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat3(XMFLOAT3* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat3A(XMFLOAT3A* pDestination, FXMVECTOR V) {}
inline void XMStoreSInt3(XMINT3* pDestination, FXMVECTOR V) {}
inline void XMStoreUInt3(XMUINT3* pDestination, FXMVECTOR V) {}
inline void XMStoreInt4(uint32_t* pDestination, FXMVECTOR V) {}
inline void XMStoreInt4A(uint32_t* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat4(XMFLOAT4* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat4A(XMFLOAT4A* pDestination, FXMVECTOR V) {}
inline void XMStoreSInt4(XMINT4* pDestination, FXMVECTOR V) {}
inline void XMStoreUInt4(XMUINT4* pDestination, FXMVECTOR V) {}
inline void XMStoreFloat3x3(XMFLOAT3X3* pDestination, FXMMATRIX M) {}
inline void XMStoreFloat4x3(XMFLOAT4X3* pDestination, FXMMATRIX M) {}
inline void XMStoreFloat4x3A(XMFLOAT4X3A* pDestination, FXMMATRIX M) {}
inline void XMStoreFloat3x4(XMFLOAT3X4* pDestination, FXMMATRIX M) {}
inline void XMStoreFloat3x4A(XMFLOAT3X4A* pDestination, FXMMATRIX M) {}
inline void XMStoreFloat4x4(XMFLOAT4X4* pDestination, FXMMATRIX M) {}
inline void XMStoreFloat4x4A(XMFLOAT4X4A* pDestination, FXMMATRIX M) {}

//==============================================================================================================================================================
// DirectXMathVector.inl

inline XMVECTOR XMVectorZero() { return {}; };
inline XMVECTOR XMVectorSet(float x, float y, float z, float w) { return {}; }
inline XMVECTOR XMVectorSetInt(uint32_t x, uint32_t y, uint32_t z, uint32_t w) { return {}; }
inline XMVECTOR XMVectorReplicate(float Value) { return {}; }
inline XMVECTOR XMVectorReplicatePtr(const float* pValue) { return {}; }
inline XMVECTOR XMVectorReplicateInt(uint32_t Value) { return {}; }
inline XMVECTOR XMVectorReplicateIntPtr(const uint32_t* pValue) { return {}; }
inline XMVECTOR XMVectorTrueInt() { return {}; }
inline XMVECTOR XMVectorFalseInt() { return {}; }
inline XMVECTOR XMVectorSplatX(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorSplatY(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorSplatZ(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorSplatW(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorSplatOne() { return {}; }
inline XMVECTOR XMVectorSplatInfinity() { return {}; }
inline XMVECTOR XMVectorSplatQNaN() { return {}; }
inline XMVECTOR XMVectorSplatEpsilon() { return {}; }
inline XMVECTOR XMVectorSplatSignMask() { return {}; }
inline float XMVectorGetByIndex(FXMVECTOR V, size_t i) { return {}; }
inline float XMVectorGetX(FXMVECTOR V) { return {}; }
inline float XMVectorGetY(FXMVECTOR V) { return {}; }
inline float XMVectorGetZ(FXMVECTOR V) { return {}; }
inline float XMVectorGetW(FXMVECTOR V) { return {}; }
inline void XMVectorGetByIndexPtr(float* f, FXMVECTOR V, size_t i) {}
inline void XMVectorGetXPtr(float* x, FXMVECTOR V) {}
inline void XMVectorGetYPtr(float* y, FXMVECTOR V) {}
inline void XMVectorGetZPtr(float* z, FXMVECTOR V) {}
inline void XMVectorGetWPtr(float* w, FXMVECTOR V) {}
inline uint32_t XMVectorGetIntByIndex(FXMVECTOR V, size_t i) { return {}; }
inline uint32_t XMVectorGetIntX(FXMVECTOR V) { return {}; }
inline uint32_t XMVectorGetIntY(FXMVECTOR V) { return {}; }
inline uint32_t XMVectorGetIntZ(FXMVECTOR V) { return {}; }
inline uint32_t XMVectorGetIntW(FXMVECTOR V) { return {}; }
inline void XMVectorGetIntByIndexPtr(uint32_t* x, FXMVECTOR V, size_t i) {}
inline void XMVectorGetIntXPtr(uint32_t* x, FXMVECTOR V) {}
inline void XMVectorGetIntYPtr(uint32_t* y, FXMVECTOR V) {}
inline void XMVectorGetIntZPtr(uint32_t* z, FXMVECTOR V) {}
inline void XMVectorGetIntWPtr(uint32_t* w, FXMVECTOR V) {}
inline XMVECTOR XMVectorSetByIndex(FXMVECTOR V, float f, size_t i) { return {}; }
inline XMVECTOR XMVectorSetX(FXMVECTOR V, float x) { return {}; }
inline XMVECTOR XMVectorSetY(FXMVECTOR V, float y) { return {}; }
inline XMVECTOR XMVectorSetZ(FXMVECTOR V, float z) { return {}; }
inline XMVECTOR XMVectorSetW(FXMVECTOR V, float w) { return {}; }
inline XMVECTOR XMVectorSetByIndexPtr(FXMVECTOR V, const float* f, size_t i) { return {}; }
inline XMVECTOR XMVectorSetXPtr(FXMVECTOR V, const float* x) { return {}; }
inline XMVECTOR XMVectorSetYPtr(FXMVECTOR V, const float* y) { return {}; }
inline XMVECTOR XMVectorSetZPtr(FXMVECTOR V, const float* z) { return {}; }
inline XMVECTOR XMVectorSetWPtr(FXMVECTOR V, const float* w) { return {}; }
inline XMVECTOR XMVectorSetIntByIndex(FXMVECTOR V, uint32_t x, size_t i) { return {}; }
inline XMVECTOR XMVectorSetIntX(FXMVECTOR V, uint32_t x) { return {}; }
inline XMVECTOR XMVectorSetIntY(FXMVECTOR V, uint32_t y) { return {}; }
inline XMVECTOR XMVectorSetIntZ(FXMVECTOR V, uint32_t z) { return {}; }
inline XMVECTOR XMVectorSetIntW(FXMVECTOR V, uint32_t w) { return {}; }
inline XMVECTOR XMVectorSetIntByIndexPtr(FXMVECTOR V, const uint32_t* x, size_t i) { return {}; }
inline XMVECTOR XMVectorSetIntXPtr(FXMVECTOR V, const uint32_t* x) { return {}; }
inline XMVECTOR XMVectorSetIntYPtr(FXMVECTOR V, const uint32_t* y) { return {}; }
inline XMVECTOR XMVectorSetIntZPtr(FXMVECTOR V, const uint32_t* z) { return {}; }
inline XMVECTOR XMVectorSetIntWPtr(FXMVECTOR V, const uint32_t* w) { return {}; }
inline XMVECTOR XMVectorSwizzle(FXMVECTOR V, uint32_t E0, uint32_t E1, uint32_t E2, uint32_t E3) { return {}; }
inline XMVECTOR XMVectorPermute(FXMVECTOR V1, FXMVECTOR V2, uint32_t PermuteX, uint32_t PermuteY, uint32_t PermuteZ, uint32_t PermuteW) { return {}; }
inline XMVECTOR XMVectorSelectControl(uint32_t VectorIndex0, uint32_t VectorIndex1, uint32_t VectorIndex2, uint32_t VectorIndex3) { return {}; }
inline XMVECTOR XMVectorSelect(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Control) { return {}; }
inline XMVECTOR XMVectorMergeXY(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorMergeZW(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorShiftLeft(FXMVECTOR V1, FXMVECTOR V2, uint32_t Elements) { return {}; }
inline XMVECTOR XMVectorRotateLeft(FXMVECTOR V, uint32_t Elements) { return {}; }
inline XMVECTOR XMVectorRotateRight(FXMVECTOR V, uint32_t Elements) { return {}; }
inline XMVECTOR XMVectorInsert(FXMVECTOR VD, FXMVECTOR VS, uint32_t VSLeftRotateElements,
                               uint32_t Select0, uint32_t Select1, uint32_t Select2, uint32_t Select3) { return {}; }
inline XMVECTOR XMVectorEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorEqualR(uint32_t* pCR, FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorEqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorEqualIntR(uint32_t* pCR, FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorNearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon) { return {}; }
inline XMVECTOR XMVectorNotEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorNotEqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorGreater(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorGreaterR(uint32_t* pCR, FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorGreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorGreaterOrEqualR(uint32_t* pCR, FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorLess(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorLessOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorInBounds(FXMVECTOR V, FXMVECTOR Bounds) { return {}; }
inline XMVECTOR XMVectorInBoundsR(uint32_t* pCR, FXMVECTOR V, FXMVECTOR Bounds) { return {}; }
inline XMVECTOR XMVectorIsNaN(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorIsInfinite(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorMin(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorMax(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorRound(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorTruncate(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorFloor(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorCeiling(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorClamp(FXMVECTOR V, FXMVECTOR Min, FXMVECTOR Max) { return {}; }
inline XMVECTOR XMVectorSaturate(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorAndInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorAndCInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorOrInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorNorInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorXorInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorNegate(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorAdd(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorSum(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorAddAngles(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorSubtract(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorSubtractAngles(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorMultiply(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorMultiplyAdd(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR V3) { return {}; }
inline XMVECTOR XMVectorDivide(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorNegativeMultiplySubtract(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR V3) { return {}; }
inline XMVECTOR XMVectorScale(FXMVECTOR V, float ScaleFactor) { return {}; }
inline XMVECTOR XMVectorReciprocalEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorReciprocal(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorSqrtEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorSqrt(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorReciprocalSqrtEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorReciprocalSqrt(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorExp2(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorExpE(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorExp(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorLog2(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorLogE(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorLog(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorPow(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorAbs(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorMod(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVectorModAngles(FXMVECTOR Angles) { return {}; }
inline XMVECTOR XMVectorSin(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorCos(FXMVECTOR V) { return {}; }
inline void XMVectorSinCos(XMVECTOR* pSin, XMVECTOR* pCos, FXMVECTOR V) {}
inline XMVECTOR XMVectorTan(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorSinH(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorCosH(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorTanH(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorASin(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorACos(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorATan(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorATan2(FXMVECTOR Y, FXMVECTOR X) { return {}; }
inline XMVECTOR XMVectorSinEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorCosEst(FXMVECTOR V) { return {}; }
inline void XMVectorSinCosEst(XMVECTOR* pSin, XMVECTOR* pCos, FXMVECTOR V) {}
inline XMVECTOR XMVectorTanEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorASinEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorACosEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorATanEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVectorATan2Est(FXMVECTOR Y, FXMVECTOR X) { return {}; }
inline XMVECTOR XMVectorLerp(FXMVECTOR V0, FXMVECTOR V1, float t) { return {}; }
inline XMVECTOR XMVectorLerpV(FXMVECTOR V0, FXMVECTOR V1, FXMVECTOR T) { return {}; }
inline XMVECTOR XMVectorHermite(FXMVECTOR Position0, FXMVECTOR Tangent0, FXMVECTOR Position1, GXMVECTOR Tangent1, float t) { return {}; }
inline XMVECTOR XMVectorHermiteV(FXMVECTOR Position0, FXMVECTOR Tangent0, FXMVECTOR Position1, GXMVECTOR Tangent1, HXMVECTOR T) { return {}; }
inline XMVECTOR XMVectorCatmullRom(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, GXMVECTOR Position3, float t) { return {}; }
inline XMVECTOR XMVectorCatmullRomV(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, GXMVECTOR Position3, HXMVECTOR T) { return {}; }
inline XMVECTOR XMVectorBaryCentric(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, float f, float g) { return {}; }
inline XMVECTOR XMVectorBaryCentricV(FXMVECTOR Position0, FXMVECTOR Position1, FXMVECTOR Position2, GXMVECTOR F, HXMVECTOR G) { return {}; }
inline bool XMVector2Equal(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector2EqualR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2EqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector2EqualIntR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2NearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon) { return {}; }
inline bool XMVector2NotEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2NotEqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2Greater(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector2GreaterR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2GreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector2GreaterOrEqualR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2Less(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2LessOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector2InBounds(FXMVECTOR V, FXMVECTOR Bounds) { return {}; }
inline bool XMVector2IsNaN(FXMVECTOR V) { return {}; }
inline bool XMVector2IsInfinite(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2Dot(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector2Cross(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector2LengthSq(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2ReciprocalLengthEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2ReciprocalLength(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2LengthEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2Length(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2NormalizeEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2Normalize(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2ClampLength(FXMVECTOR V, float LengthMin, float LengthMax) { return {}; }
inline XMVECTOR XMVector2ClampLengthV(FXMVECTOR V, FXMVECTOR LengthMin, FXMVECTOR LengthMax) { return {}; }
inline XMVECTOR XMVector2Reflect(FXMVECTOR Incident, FXMVECTOR Normal) { return {}; }
inline XMVECTOR XMVector2Refract(FXMVECTOR Incident, FXMVECTOR Normal, float RefractionIndex) { return {}; }
inline XMVECTOR XMVector2RefractV(FXMVECTOR Incident, FXMVECTOR Normal, FXMVECTOR RefractionIndex) { return {}; }
inline XMVECTOR XMVector2Orthogonal(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector2AngleBetweenNormalsEst(FXMVECTOR N1, FXMVECTOR N2) { return {}; }
inline XMVECTOR XMVector2AngleBetweenNormals(FXMVECTOR N1, FXMVECTOR N2) { return {}; }
inline XMVECTOR XMVector2AngleBetweenVectors(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector2LinePointDistance(FXMVECTOR LinePoint1, FXMVECTOR LinePoint2, FXMVECTOR Point) { return {}; }
inline XMVECTOR XMVector2IntersectLine(FXMVECTOR Line1Point1, FXMVECTOR Line1Point2, FXMVECTOR Line2Point1, GXMVECTOR Line2Point2) { return {}; }
inline XMVECTOR XMVector2Transform(FXMVECTOR V, FXMMATRIX M) { return {}; }
inline XMFLOAT4* XMVector2TransformStream(XMFLOAT4* pOutputStream, size_t OutputStride, const XMFLOAT2* pInputStream,
                                          size_t InputStride, size_t VectorCount, FXMMATRIX M) { return {}; }
inline XMVECTOR XMVector2TransformCoord(FXMVECTOR V, FXMMATRIX M) { return {}; }
inline XMFLOAT2* XMVector2TransformCoordStream(XMFLOAT2* pOutputStream, size_t OutputStride, const XMFLOAT2* pInputStream,
                                               size_t InputStride, size_t VectorCount, FXMMATRIX M) { return {}; }
inline XMVECTOR XMVector2TransformNormal(FXMVECTOR V, FXMMATRIX M) { return {}; }
inline XMFLOAT2* XMVector2TransformNormalStream(XMFLOAT2* pOutputStream, size_t OutputStride,
                                                const XMFLOAT2* pInputStream, size_t InputStride, size_t VectorCount, FXMMATRIX M) { return {}; }
inline bool XMVector3Equal(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector3EqualR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3EqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector3EqualIntR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3NearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon) { return {}; }
inline bool XMVector3NotEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3NotEqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3Greater(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector3GreaterR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3GreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector3GreaterOrEqualR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3Less(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3LessOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector3InBounds(FXMVECTOR V, FXMVECTOR Bounds) { return {}; }
inline bool XMVector3IsNaN(FXMVECTOR V) { return {}; }
inline bool XMVector3IsInfinite(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3Dot(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector3Cross(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector3LengthSq(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3ReciprocalLengthEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3ReciprocalLength(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3LengthEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3Length(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3NormalizeEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3Normalize(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3ClampLength(FXMVECTOR V, float LengthMin, float LengthMax) { return {}; }
inline XMVECTOR XMVector3ClampLengthV(FXMVECTOR V, FXMVECTOR LengthMin, FXMVECTOR LengthMax) { return {}; }
inline XMVECTOR XMVector3Reflect(FXMVECTOR Incident, FXMVECTOR Normal) { return {}; }
inline XMVECTOR XMVector3Refract(FXMVECTOR Incident, FXMVECTOR Normal, float RefractionIndex) { return {}; }
inline XMVECTOR XMVector3RefractV(FXMVECTOR Incident, FXMVECTOR Normal, FXMVECTOR RefractionIndex) { return {}; }
inline XMVECTOR XMVector3Orthogonal(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector3AngleBetweenNormalsEst(FXMVECTOR N1, FXMVECTOR N2) { return {}; }
inline XMVECTOR XMVector3AngleBetweenNormals(FXMVECTOR N1, FXMVECTOR N2) { return {}; }
inline XMVECTOR XMVector3AngleBetweenVectors(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector3LinePointDistance(FXMVECTOR LinePoint1, FXMVECTOR LinePoint2, FXMVECTOR Point) { return {}; }
inline void XMVector3ComponentsFromNormal(XMVECTOR* pParallel, XMVECTOR* pPerpendicular, FXMVECTOR V, FXMVECTOR Normal) {}
inline XMVECTOR XMVector3Rotate(FXMVECTOR V, FXMVECTOR RotationQuaternion) { return {}; }
inline XMVECTOR XMVector3InverseRotate(FXMVECTOR V, FXMVECTOR RotationQuaternion) { return {}; }
inline XMVECTOR XMVector3Transform(FXMVECTOR V, FXMMATRIX M) { return {}; }
inline XMFLOAT4* XMVector3TransformStream(XMFLOAT4* pOutputStream, size_t OutputStride, const XMFLOAT3* pInputStream,
                                          size_t InputStride, size_t VectorCount, FXMMATRIX M) { return {}; }
inline XMVECTOR XMVector3TransformCoord(FXMVECTOR V, FXMMATRIX M) { return {}; }
inline XMFLOAT3* XMVector3TransformCoordStream(XMFLOAT3* pOutputStream, size_t OutputStride, const XMFLOAT3* pInputStream,
                                               size_t InputStride, size_t VectorCount, FXMMATRIX M) { return {}; }
inline XMVECTOR XMVector3TransformNormal(FXMVECTOR V, FXMMATRIX M) { return {}; }
inline XMFLOAT3* XMVector3TransformNormalStream(XMFLOAT3* pOutputStream, size_t OutputStride, const XMFLOAT3* pInputStream,
                                                size_t InputStride, size_t VectorCount, FXMMATRIX M) { return {}; }
inline XMVECTOR XMVector3Project(FXMVECTOR V, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight,
                                 float ViewportMinZ, float ViewportMaxZ, FXMMATRIX Projection, CXMMATRIX View, CXMMATRIX World) { return {}; }
inline XMFLOAT3* XMVector3ProjectStream(XMFLOAT3* pOutputStream, size_t OutputStride, const XMFLOAT3* pInputStream, size_t InputStride,
                                        size_t VectorCount, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight,
                                        float ViewportMinZ, float ViewportMaxZ, FXMMATRIX Projection, CXMMATRIX View, CXMMATRIX World) { return {}; }
inline XMVECTOR XMVector3Unproject(FXMVECTOR V, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight,
                                   float ViewportMinZ, float ViewportMaxZ, FXMMATRIX Projection, CXMMATRIX View, CXMMATRIX World) { return {}; }
inline XMFLOAT3* XMVector3UnprojectStream(XMFLOAT3* pOutputStream, size_t OutputStride, const XMFLOAT3* pInputStream, size_t InputStride,
                                          size_t VectorCount, float ViewportX, float ViewportY, float ViewportWidth, float ViewportHeight,
                                          float ViewportMinZ, float ViewportMaxZ, FXMMATRIX Projection, CXMMATRIX View, CXMMATRIX World) { return {}; }
inline bool XMVector4Equal(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector4EqualR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4EqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector4EqualIntR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4NearEqual(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR Epsilon) { return {}; }
inline bool XMVector4NotEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4NotEqualInt(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4Greater(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector4GreaterR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4GreaterOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline uint32_t XMVector4GreaterOrEqualR(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4Less(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4LessOrEqual(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline bool XMVector4InBounds(FXMVECTOR V, FXMVECTOR Bounds) { return {}; }
inline bool XMVector4IsNaN(FXMVECTOR V) { return {}; }
inline bool XMVector4IsInfinite(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4Dot(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector4Cross(FXMVECTOR V1, FXMVECTOR V2, FXMVECTOR V3) { return {}; }
inline XMVECTOR XMVector4LengthSq(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4ReciprocalLengthEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4ReciprocalLength(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4LengthEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4Length(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4NormalizeEst(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4Normalize(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4ClampLength(FXMVECTOR V, float LengthMin, float LengthMax) { return {}; }
inline XMVECTOR XMVector4ClampLengthV(FXMVECTOR V, FXMVECTOR LengthMin, FXMVECTOR LengthMax) { return {}; }
inline XMVECTOR XMVector4Reflect(FXMVECTOR Incident, FXMVECTOR Normal) { return {}; }
inline XMVECTOR XMVector4Refract(FXMVECTOR Incident, FXMVECTOR Normal, float RefractionIndex) { return {}; }
inline XMVECTOR XMVector4RefractV(FXMVECTOR Incident, FXMVECTOR Normal, FXMVECTOR RefractionIndex) { return {}; }
inline XMVECTOR XMVector4Orthogonal(FXMVECTOR V) { return {}; }
inline XMVECTOR XMVector4AngleBetweenNormalsEst(FXMVECTOR N1, FXMVECTOR N2) { return {}; }
inline XMVECTOR XMVector4AngleBetweenNormals(FXMVECTOR N1, FXMVECTOR N2) { return {}; }
inline XMVECTOR XMVector4AngleBetweenVectors(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
inline XMVECTOR XMVector4Transform(FXMVECTOR V, FXMMATRIX M) { return {}; }
inline XMFLOAT4* XMVector4TransformStream(XMFLOAT4* pOutputStream, size_t OutputStride, const XMFLOAT4* pInputStream,
                                          size_t InputStride, size_t VectorCount, FXMMATRIX M) { return {}; }
inline XMVECTOR operator+(FXMVECTOR V) { return V; }
inline XMVECTOR operator-(FXMVECTOR V) { return XMVectorNegate(V); }
inline XMVECTOR& operator+=(XMVECTOR& V1, FXMVECTOR V2) { return V1 = XMVectorAdd(V1, V2); }
inline XMVECTOR& operator-=(XMVECTOR& V1, FXMVECTOR V2) { return V1 = XMVectorSubtract(V1, V2); }
inline XMVECTOR& operator*=(XMVECTOR& V1, FXMVECTOR V2) { return V1 = XMVectorMultiply(V1, V2); }
inline XMVECTOR& operator/=(XMVECTOR& V1, FXMVECTOR V2) { return V1 = XMVectorDivide(V1, V2); }
inline XMVECTOR& operator*=(XMVECTOR& V, const float S) { return V = XMVectorScale(V, S); }
inline XMVECTOR& operator/=(XMVECTOR& V, const float S) { return V; }
inline XMVECTOR operator+(FXMVECTOR V1, FXMVECTOR V2) { return XMVectorAdd(V1, V2); }
inline XMVECTOR operator-(FXMVECTOR V1, FXMVECTOR V2) { return XMVectorSubtract(V1, V2); }
inline XMVECTOR operator*(FXMVECTOR V1, FXMVECTOR V2) { return XMVectorMultiply(V1, V2); }
inline XMVECTOR operator/(FXMVECTOR V1, FXMVECTOR V2) { return XMVectorDivide(V1, V2); }
inline XMVECTOR operator*(FXMVECTOR V, const float S) { return XMVectorScale(V, S); }
inline XMVECTOR operator/(FXMVECTOR V, const float S) { return {}; }
inline XMVECTOR operator*(float S, FXMVECTOR V) { return XMVectorScale(V, S); }

//==============================================================================================================================================================
// DirectXMathMatrix.inl

inline bool XMMatrixIsNaN(FXMMATRIX M) { return {}; }
inline bool XMMatrixIsInfinite(FXMMATRIX M) { return {}; }
inline bool XMMatrixIsIdentity(FXMMATRIX M) { return {}; }
inline XMMATRIX XMMatrixMultiply(FXMMATRIX M1, CXMMATRIX M2) { return {}; }
inline XMMATRIX XMMatrixMultiplyTranspose(FXMMATRIX M1, CXMMATRIX M2) { return {}; }
inline XMMATRIX XMMatrixTranspose(FXMMATRIX M) { return {}; }
inline XMMATRIX XMMatrixInverse(XMVECTOR* pDeterminant, FXMMATRIX M) { return {}; }
inline XMVECTOR XMMatrixDeterminant(FXMMATRIX M) { return {}; }
inline XMMATRIX XMMatrixIdentity() { return {}; }
inline XMMATRIX XMMatrixSet(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                            float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) { return {}; }
inline XMMATRIX XMMatrixTranslation(float OffsetX, float OffsetY, float OffsetZ) { return {}; }
inline XMMATRIX XMMatrixTranslationFromVector(FXMVECTOR Offset) { return {}; }
inline XMMATRIX XMMatrixScaling(float ScaleX, float ScaleY, float ScaleZ) { return {}; }
inline XMMATRIX XMMatrixScalingFromVector(FXMVECTOR Scale) { return {}; }
inline XMMATRIX XMMatrixRotationX(float Angle) { return {}; }
inline XMMATRIX XMMatrixRotationY(float Angle) { return {}; }
inline XMMATRIX XMMatrixRotationZ(float Angle) { return {}; }
inline XMMATRIX XMMatrixRotationRollPitchYaw(float Pitch, float Yaw, float Roll) { return {}; }
inline XMMATRIX XMMatrixRotationRollPitchYawFromVector(FXMVECTOR Angles) { return {}; }
inline XMMATRIX XMMatrixRotationNormal(FXMVECTOR NormalAxis, float Angle) { return {}; }
inline XMMATRIX XMMatrixRotationAxis(FXMVECTOR Axis, float Angle) { return {}; }
inline XMMATRIX XMMatrixRotationQuaternion(FXMVECTOR Quaternion) { return {}; }
inline XMMATRIX XMMatrixTransformation2D(FXMVECTOR ScalingOrigin, float ScalingOrientation, FXMVECTOR Scaling,
                                         FXMVECTOR RotationOrigin, float Rotation, GXMVECTOR Translation) { return {}; }
inline XMMATRIX XMMatrixTransformation(FXMVECTOR ScalingOrigin, FXMVECTOR ScalingOrientationQuaternion, FXMVECTOR Scaling,
                                       GXMVECTOR RotationOrigin, HXMVECTOR RotationQuaternion, HXMVECTOR Translation) { return {}; }
inline XMMATRIX XMMatrixAffineTransformation2D(FXMVECTOR Scaling, FXMVECTOR RotationOrigin, float Rotation, FXMVECTOR Translation) { return {}; }
inline XMMATRIX XMMatrixAffineTransformation(FXMVECTOR Scaling, FXMVECTOR RotationOrigin, FXMVECTOR RotationQuaternion, GXMVECTOR Translation) { return {}; }
inline XMMATRIX XMMatrixReflect(FXMVECTOR ReflectionPlane) { return {}; }
inline XMMATRIX XMMatrixShadow(FXMVECTOR ShadowPlane, FXMVECTOR LightPosition) { return {}; }
inline XMMATRIX XMMatrixLookAtLH(FXMVECTOR EyePosition, FXMVECTOR FocusPosition, FXMVECTOR UpDirection) { return {}; }
inline XMMATRIX XMMatrixLookAtRH(FXMVECTOR EyePosition, FXMVECTOR FocusPosition, FXMVECTOR UpDirection) { return {}; }
inline XMMATRIX XMMatrixLookToLH(FXMVECTOR EyePosition, FXMVECTOR EyeDirection, FXMVECTOR UpDirection) { return {}; }
inline XMMATRIX XMMatrixLookToRH(FXMVECTOR EyePosition, FXMVECTOR EyeDirection, FXMVECTOR UpDirection) { return {}; }
inline XMMATRIX XMMatrixPerspectiveLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixPerspectiveRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixPerspectiveFovLH(float FovAngleY, float AspectRatio, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixPerspectiveFovRH(float FovAngleY, float AspectRatio, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixPerspectiveOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixPerspectiveOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixOrthographicLH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixOrthographicRH(float ViewWidth, float ViewHeight, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixOrthographicOffCenterLH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) { return {}; }
inline XMMATRIX XMMatrixOrthographicOffCenterRH(float ViewLeft, float ViewRight, float ViewBottom, float ViewTop, float NearZ, float FarZ) { return {}; }
inline XMMATRIX::XMMATRIX(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                          float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) {}
inline XMMATRIX::XMMATRIX(const float* pArray) {}
inline XMMATRIX XMMATRIX::operator-() const { return {}; }
inline XMMATRIX& XMMATRIX::operator+=(FXMMATRIX M) { return *this; }
inline XMMATRIX& XMMATRIX::operator-=(FXMMATRIX M) { return *this; }
inline XMMATRIX& XMMATRIX::operator*=(FXMMATRIX M) { return *this; }
inline XMMATRIX& XMMATRIX::operator*=(float S) { return *this; }
inline XMMATRIX& XMMATRIX::operator/=(float S) { return *this; }
inline XMMATRIX XMMATRIX::operator+(FXMMATRIX M) const { return {}; }
inline XMMATRIX XMMATRIX::operator-(FXMMATRIX M) const { return {}; }
inline XMMATRIX XMMATRIX::operator*(FXMMATRIX M) const { return {}; }
inline XMMATRIX XMMATRIX::operator*(float S) const { return {}; }
inline XMMATRIX XMMATRIX::operator/(float S) const { return {}; }
inline XMMATRIX operator*(float S, FXMMATRIX M) { return {}; }
inline XMFLOAT3X3::XMFLOAT3X3(const float* pArray) {}
inline XMFLOAT4X3::XMFLOAT4X3(const float* pArray) {}
inline XMFLOAT3X4::XMFLOAT3X4(const float* pArray) {}
inline XMFLOAT4X4::XMFLOAT4X4(const float* pArray) {}

//==============================================================================================================================================================
// DirectXMathMisc.inl

inline bool XMQuaternionEqual(FXMVECTOR Q1, FXMVECTOR Q2) { return {}; }
inline bool XMQuaternionNotEqual(FXMVECTOR Q1, FXMVECTOR Q2) { return {}; }
inline bool XMQuaternionIsNaN(FXMVECTOR Q) { return {}; }
inline bool XMQuaternionIsInfinite(FXMVECTOR Q) { return {}; }
inline bool XMQuaternionIsIdentity(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionDot(FXMVECTOR Q1, FXMVECTOR Q2) { return {}; }
inline XMVECTOR XMQuaternionMultiply(FXMVECTOR Q1, FXMVECTOR Q2) { return {}; }
inline XMVECTOR XMQuaternionLengthSq(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionReciprocalLength(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionLength(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionNormalizeEst(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionNormalize(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionConjugate(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionInverse(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionLn(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionExp(FXMVECTOR Q) { return {}; }
inline XMVECTOR XMQuaternionSlerp(FXMVECTOR Q0, FXMVECTOR Q1, float t) { return {}; }
inline XMVECTOR XMQuaternionSlerpV(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR T) { return {}; }
inline XMVECTOR XMQuaternionSquad(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, GXMVECTOR Q3, float t) { return {}; }
inline XMVECTOR XMQuaternionSquadV(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, GXMVECTOR Q3, HXMVECTOR T) { return {}; }
inline void XMQuaternionSquadSetup(XMVECTOR* pA, XMVECTOR* pB, XMVECTOR* pC, FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, GXMVECTOR Q3) {}
inline XMVECTOR XMQuaternionBaryCentric(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, float f, float g) { return {}; }
inline XMVECTOR XMQuaternionBaryCentricV(FXMVECTOR Q0, FXMVECTOR Q1, FXMVECTOR Q2, GXMVECTOR F, HXMVECTOR G) { return {}; }
inline XMVECTOR XMQuaternionIdentity() { return {}; }
inline XMVECTOR XMQuaternionRotationRollPitchYaw(float Pitch, float Yaw, float Roll) { return {}; }
inline XMVECTOR XMQuaternionRotationRollPitchYawFromVector(FXMVECTOR Angles) { return {}; }
inline XMVECTOR XMQuaternionRotationNormal(FXMVECTOR NormalAxis, float Angle) { return {}; }
inline XMVECTOR XMQuaternionRotationAxis(FXMVECTOR Axis, float Angle) { return {}; }
inline XMVECTOR XMQuaternionRotationMatrix(FXMMATRIX M) { return {}; }
inline void XMQuaternionToAxisAngle(XMVECTOR* pAxis, float* pAngle, FXMVECTOR Q) {}
inline bool XMPlaneEqual(FXMVECTOR P1, FXMVECTOR P2) { return {}; }
inline bool XMPlaneNearEqual(FXMVECTOR P1, FXMVECTOR P2, FXMVECTOR Epsilon) { return {}; }
inline bool XMPlaneNotEqual(FXMVECTOR P1, FXMVECTOR P2) { return {}; }
inline bool XMPlaneIsNaN(FXMVECTOR P) { return {}; }
inline bool XMPlaneIsInfinite(FXMVECTOR P) { return {}; }
inline XMVECTOR XMPlaneDot(FXMVECTOR P, FXMVECTOR V) { return {}; }
inline XMVECTOR XMPlaneDotCoord(FXMVECTOR P, FXMVECTOR V) { return {}; }
inline XMVECTOR XMPlaneDotNormal(FXMVECTOR P, FXMVECTOR V) { return {}; }
inline XMVECTOR XMPlaneNormalizeEst(FXMVECTOR P) { return {}; }
inline XMVECTOR XMPlaneNormalize(FXMVECTOR P) { return {}; }
inline XMVECTOR XMPlaneIntersectLine(FXMVECTOR P, FXMVECTOR LinePoint1, FXMVECTOR LinePoint2) { return {}; }
inline void XMPlaneIntersectPlane(XMVECTOR* pLinePoint1, XMVECTOR* pLinePoint2, FXMVECTOR P1, FXMVECTOR P2) {}
inline XMVECTOR XMPlaneTransform(FXMVECTOR P, FXMMATRIX M) { return {}; }
inline XMFLOAT4* XMPlaneTransformStream(XMFLOAT4* pOutputStream, size_t OutputStride, const XMFLOAT4* pInputStream,
                                        size_t InputStride, size_t PlaneCount, FXMMATRIX M) { return {}; }
inline XMVECTOR XMPlaneFromPointNormal(FXMVECTOR Point, FXMVECTOR Normal) { return {}; }
inline XMVECTOR XMPlaneFromPoints(FXMVECTOR Point1, FXMVECTOR Point2, FXMVECTOR Point3) { return {}; }
inline bool XMColorEqual(FXMVECTOR C1, FXMVECTOR C2) { return {}; }
inline bool XMColorNotEqual(FXMVECTOR C1, FXMVECTOR C2) { return {}; }
inline bool XMColorGreater(FXMVECTOR C1, FXMVECTOR C2) { return {}; }
inline bool XMColorGreaterOrEqual(FXMVECTOR C1, FXMVECTOR C2) { return {}; }
inline bool XMColorLess(FXMVECTOR C1, FXMVECTOR C2) { return {}; }
inline bool XMColorLessOrEqual(FXMVECTOR C1, FXMVECTOR C2) { return {}; }
inline bool XMColorIsNaN(FXMVECTOR C) { return {}; }
inline bool XMColorIsInfinite(FXMVECTOR C) { return {}; }
inline XMVECTOR XMColorNegative(FXMVECTOR vColor) { return {}; }
inline XMVECTOR XMColorModulate(FXMVECTOR C1, FXMVECTOR C2) { return {}; }
inline XMVECTOR XMColorAdjustSaturation(FXMVECTOR vColor, float fSaturation) { return {}; }
inline XMVECTOR XMColorAdjustContrast(FXMVECTOR vColor, float fContrast) { return {}; }
inline XMVECTOR XMColorRGBToHSL(FXMVECTOR rgb) { return {}; }
inline XMVECTOR XMColorHSLToRGB(FXMVECTOR hsl) { return {}; }
inline XMVECTOR XMColorRGBToHSV(FXMVECTOR rgb) { return {}; }
inline XMVECTOR XMColorHSVToRGB(FXMVECTOR hsv) { return {}; }
inline XMVECTOR XMColorRGBToYUV(FXMVECTOR rgb) { return {}; }
inline XMVECTOR XMColorYUVToRGB(FXMVECTOR yuv) { return {}; }
inline XMVECTOR XMColorRGBToYUV_HD(FXMVECTOR rgb) { return {}; }
inline XMVECTOR XMColorYUVToRGB_HD(FXMVECTOR yuv) { return {}; }
inline XMVECTOR XMColorRGBToXYZ(FXMVECTOR rgb) { return {}; }
inline XMVECTOR XMColorXYZToRGB(FXMVECTOR xyz) { return {}; }
inline XMVECTOR XMColorXYZToSRGB(FXMVECTOR xyz) { return {}; }
inline XMVECTOR XMColorSRGBToXYZ(FXMVECTOR srgb) { return {}; }
inline XMVECTOR XMColorRGBToSRGB(FXMVECTOR rgb) { return {}; }
inline XMVECTOR XMColorSRGBToRGB(FXMVECTOR srgb) { return {}; }
inline bool XMVerifyCPUSupport() { return {}; }
inline XMVECTOR XMFresnelTerm(FXMVECTOR CosIncidentAngle, FXMVECTOR RefractionIndex) { return {}; }
inline bool XMScalarNearEqual(float S1, float S2, float Epsilon) { return {}; }
inline float XMScalarModAngle(float Angle) { return {}; }
inline float XMScalarSin(float Value) { return {}; }
inline float XMScalarSinEst(float Value) { return {}; }
inline float XMScalarCos(float Value) { return {}; }
inline float XMScalarCosEst(float Value) { return {}; }
inline void XMScalarSinCos(float* pSin, float* pCos, float Value) {}
inline void XMScalarSinCosEst(float* pSin, float* pCos, float Value) {}
inline float XMScalarASinEst(float Value) { return {}; }
inline float XMScalarACos(float Value) { return {}; }
inline float XMScalarACosEst(float Value) { return {}; }
template<class T> inline T XMMin(T a, T b) { return (a < b) ? a : b; }
template<class T> inline T XMMax(T a, T b) { return (a > b) ? a : b; }

//==============================================================================================================================================================
// clang-format off

template<uint32_t PermuteX, uint32_t PermuteY, uint32_t PermuteZ, uint32_t PermuteW>
requires ((PermuteX | PermuteY | PermuteZ | PermuteW) < 8)
inline XMVECTOR XMVectorPermute(FXMVECTOR V1, FXMVECTOR V2) { return {}; }

template<uint32_t SwizzleX, uint32_t SwizzleY, uint32_t SwizzleZ, uint32_t SwizzleW>
requires ((SwizzleX | SwizzleY | SwizzleZ | SwizzleW) < 4)
inline XMVECTOR XMVectorSwizzle(FXMVECTOR V) { return {}; }

template<uint32_t Elements> inline XMVECTOR XMVectorShiftLeft(FXMVECTOR V1, FXMVECTOR V2) { return {}; }
template<uint32_t Elements> inline XMVECTOR XMVectorRotateLeft(FXMVECTOR V) { return {}; }
template<uint32_t Elements> inline XMVECTOR XMVectorRotateRight(FXMVECTOR V) { return {}; }

template<uint32_t VSLeftRotateElements, uint32_t Select0, uint32_t Select1, uint32_t Select2, uint32_t Select3>
inline XMVECTOR XMVectorInsert(FXMVECTOR VD, FXMVECTOR VS) { return {}; }

inline const XMVECTORF32 g_XMSinCoefficients0 = {{{-0.16666667f, +0.0083333310f, -0.00019840874f, +2.7525562e-06f}}};
inline const XMVECTORF32 g_XMSinCoefficients1 = {{{-2.3889859e-08f, -0.16665852f /*Est1*/, +0.0083139502f /*Est2*/, -0.00018524670f /*Est3*/}}};
inline const XMVECTORF32 g_XMCosCoefficients0 = {{{-0.5f, +0.041666638f, -0.0013888378f, +2.4760495e-05f}}};
inline const XMVECTORF32 g_XMCosCoefficients1 = {{{-2.6051615e-07f, -0.49992746f /*Est1*/, +0.041493919f /*Est2*/, -0.0012712436f /*Est3*/}}};
inline const XMVECTORF32 g_XMTanCoefficients0 = {{{1.0f, 0.333333333f, 0.133333333f, 5.396825397e-2f}}};
inline const XMVECTORF32 g_XMTanCoefficients1 = {{{2.186948854e-2f, 8.863235530e-3f, 3.592128167e-3f, 1.455834485e-3f}}};
inline const XMVECTORF32 g_XMTanCoefficients2 = {{{5.900274264e-4f, 2.391290764e-4f, 9.691537707e-5f, 3.927832950e-5f}}};
inline const XMVECTORF32 g_XMArcCoefficients0 = {{{+1.5707963050f, -0.2145988016f, +0.0889789874f, -0.0501743046f}}};
inline const XMVECTORF32 g_XMArcCoefficients1 = {{{+0.0308918810f, -0.0170881256f, +0.0066700901f, -0.0012624911f}}};
inline const XMVECTORF32 g_XMATanCoefficients0 = {{{-0.3333314528f, +0.1999355085f, -0.1420889944f, +0.1065626393f}}};
inline const XMVECTORF32 g_XMATanCoefficients1 = {{{-0.0752896400f, +0.0429096138f, -0.0161657367f, +0.0028662257f}}};
inline const XMVECTORF32 g_XMATanEstCoefficients0 = {{{+0.999866f, +0.999866f, +0.999866f, +0.999866f}}};
inline const XMVECTORF32 g_XMATanEstCoefficients1 = {{{-0.3302995f, +0.180141f, -0.085133f, +0.0208351f}}};
inline const XMVECTORF32 g_XMTanEstCoefficients = {{{2.484f, -1.954923183e-1f, 2.467401101f, XM_1DIVPI}}};
inline const XMVECTORF32 g_XMArcEstCoefficients = {{{+1.5707288f, -0.2121144f, +0.0742610f, -0.0187293f}}};
inline const XMVECTORF32 g_XMPiConstants0 = {{{XM_PI, XM_2PI, XM_1DIVPI, XM_1DIV2PI}}};
inline const XMVECTORF32 g_XMIdentityR0 = {{{1.0f, 0.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMIdentityR1 = {{{0.0f, 1.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMIdentityR2 = {{{0.0f, 0.0f, 1.0f, 0.0f}}};
inline const XMVECTORF32 g_XMIdentityR3 = {{{0.0f, 0.0f, 0.0f, 1.0f}}};
inline const XMVECTORF32 g_XMNegIdentityR0 = {{{-1.0f, 0.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMNegIdentityR1 = {{{0.0f, -1.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMNegIdentityR2 = {{{0.0f, 0.0f, -1.0f, 0.0f}}};
inline const XMVECTORF32 g_XMNegIdentityR3 = {{{0.0f, 0.0f, 0.0f, -1.0f}}};
inline const XMVECTORU32 g_XMNegativeZero = {{{0x80000000, 0x80000000, 0x80000000, 0x80000000}}};
inline const XMVECTORU32 g_XMNegate3 = {{{0x80000000, 0x80000000, 0x80000000, 0x00000000}}};
inline const XMVECTORU32 g_XMMaskXY = {{{0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000}}};
inline const XMVECTORU32 g_XMMask3 = {{{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}}};
inline const XMVECTORU32 g_XMMaskX = {{{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000}}};
inline const XMVECTORU32 g_XMMaskY = {{{0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000}}};
inline const XMVECTORU32 g_XMMaskZ = {{{0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000}}};
inline const XMVECTORU32 g_XMMaskW = {{{0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF}}};
inline const XMVECTORF32 g_XMOne = {{{1.0f, 1.0f, 1.0f, 1.0f}}};
inline const XMVECTORF32 g_XMOne3 = {{{1.0f, 1.0f, 1.0f, 0.0f}}};
inline const XMVECTORF32 g_XMZero = {{{0.0f, 0.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMTwo = {{{2.f, 2.f, 2.f, 2.f}}};
inline const XMVECTORF32 g_XMFour = {{{4.f, 4.f, 4.f, 4.f}}};
inline const XMVECTORF32 g_XMSix = {{{6.f, 6.f, 6.f, 6.f}}};
inline const XMVECTORF32 g_XMNegativeOne = {{{-1.0f, -1.0f, -1.0f, -1.0f}}};
inline const XMVECTORF32 g_XMOneHalf = {{{0.5f, 0.5f, 0.5f, 0.5f}}};
inline const XMVECTORF32 g_XMNegativeOneHalf = {{{-0.5f, -0.5f, -0.5f, -0.5f}}};
inline const XMVECTORF32 g_XMNegativeTwoPi = {{{-XM_2PI, -XM_2PI, -XM_2PI, -XM_2PI}}};
inline const XMVECTORF32 g_XMNegativePi = {{{-XM_PI, -XM_PI, -XM_PI, -XM_PI}}};
inline const XMVECTORF32 g_XMHalfPi = {{{XM_PIDIV2, XM_PIDIV2, XM_PIDIV2, XM_PIDIV2}}};
inline const XMVECTORF32 g_XMPi = {{{XM_PI, XM_PI, XM_PI, XM_PI}}};
inline const XMVECTORF32 g_XMReciprocalPi = {{{XM_1DIVPI, XM_1DIVPI, XM_1DIVPI, XM_1DIVPI}}};
inline const XMVECTORF32 g_XMTwoPi = {{{XM_2PI, XM_2PI, XM_2PI, XM_2PI}}};
inline const XMVECTORF32 g_XMReciprocalTwoPi = {{{XM_1DIV2PI, XM_1DIV2PI, XM_1DIV2PI, XM_1DIV2PI}}};
inline const XMVECTORF32 g_XMEpsilon = {{{1.192092896e-7f, 1.192092896e-7f, 1.192092896e-7f, 1.192092896e-7f}}};
inline const XMVECTORI32 g_XMInfinity = {{{0x7F800000, 0x7F800000, 0x7F800000, 0x7F800000}}};
inline const XMVECTORI32 g_XMQNaN = {{{0x7FC00000, 0x7FC00000, 0x7FC00000, 0x7FC00000}}};
inline const XMVECTORI32 g_XMQNaNTest = {{{0x007FFFFF, 0x007FFFFF, 0x007FFFFF, 0x007FFFFF}}};
inline const XMVECTORI32 g_XMAbsMask = {{{0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF}}};
inline const XMVECTORI32 g_XMFltMin = {{{0x00800000, 0x00800000, 0x00800000, 0x00800000}}};
inline const XMVECTORI32 g_XMFltMax = {{{0x7F7FFFFF, 0x7F7FFFFF, 0x7F7FFFFF, 0x7F7FFFFF}}};
inline const XMVECTORU32 g_XMNegOneMask = {{{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}}};
inline const XMVECTORU32 g_XMMaskA8R8G8B8 = {{{0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000}}};
inline const XMVECTORU32 g_XMFlipA8R8G8B8 = {{{0x00000000, 0x00000000, 0x00000000, 0x80000000}}};
inline const XMVECTORF32 g_XMFixAA8R8G8B8 = {{{0.0f, 0.0f, 0.0f, float(0x80000000U)}}};
inline const XMVECTORF32 g_XMNormalizeA8R8G8B8 = {{{1.0f / (255.0f * float(0x10000)), 1.0f / (255.0f * float(0x100)), 1.0f / 255.0f, 1.0f / (255.0f * float(0x1000000))}}};
inline const XMVECTORU32 g_XMMaskA2B10G10R10 = {{{0x000003FF, 0x000FFC00, 0x3FF00000, 0xC0000000}}};
inline const XMVECTORU32 g_XMFlipA2B10G10R10 = {{{0x00000200, 0x00080000, 0x20000000, 0x80000000}}};
inline const XMVECTORF32 g_XMFixAA2B10G10R10 = {{{-512.0f, -512.0f * float(0x400), -512.0f * float(0x100000), float(0x80000000U)}}};
inline const XMVECTORF32 g_XMNormalizeA2B10G10R10 = {{{1.0f / 511.0f, 1.0f / (511.0f * float(0x400)), 1.0f / (511.0f * float(0x100000)), 1.0f / (3.0f * float(0x40000000))}}};
inline const XMVECTORU32 g_XMMaskX16Y16 = {{{0x0000FFFF, 0xFFFF0000, 0x00000000, 0x00000000}}};
inline const XMVECTORI32 g_XMFlipX16Y16 = {{{0x00008000, 0x00000000, 0x00000000, 0x00000000}}};
inline const XMVECTORF32 g_XMFixX16Y16 = {{{-32768.0f, 0.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMNormalizeX16Y16 = {{{1.0f / 32767.0f, 1.0f / (32767.0f * 65536.0f), 0.0f, 0.0f}}};
inline const XMVECTORU32 g_XMMaskX16Y16Z16W16 = {{{0x0000FFFF, 0x0000FFFF, 0xFFFF0000, 0xFFFF0000}}};
inline const XMVECTORI32 g_XMFlipX16Y16Z16W16 = {{{0x00008000, 0x00008000, 0x00000000, 0x00000000}}};
inline const XMVECTORF32 g_XMFixX16Y16Z16W16 = {{{-32768.0f, -32768.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMNormalizeX16Y16Z16W16 = {{{1.0f / 32767.0f, 1.0f / 32767.0f, 1.0f / (32767.0f * 65536.0f), 1.0f / (32767.0f * 65536.0f)}}};
inline const XMVECTORF32 g_XMNoFraction = {{{8388608.0f, 8388608.0f, 8388608.0f, 8388608.0f}}};
inline const XMVECTORI32 g_XMMaskByte = {{{0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF}}};
inline const XMVECTORF32 g_XMNegateX = {{{-1.0f, 1.0f, 1.0f, 1.0f}}};
inline const XMVECTORF32 g_XMNegateY = {{{1.0f, -1.0f, 1.0f, 1.0f}}};
inline const XMVECTORF32 g_XMNegateZ = {{{1.0f, 1.0f, -1.0f, 1.0f}}};
inline const XMVECTORF32 g_XMNegateW = {{{1.0f, 1.0f, 1.0f, -1.0f}}};
inline const XMVECTORU32 g_XMSelect0101 = {{{XM_SELECT_0, XM_SELECT_1, XM_SELECT_0, XM_SELECT_1}}};
inline const XMVECTORU32 g_XMSelect1010 = {{{XM_SELECT_1, XM_SELECT_0, XM_SELECT_1, XM_SELECT_0}}};
inline const XMVECTORI32 g_XMOneHalfMinusEpsilon = {{{0x3EFFFFFD, 0x3EFFFFFD, 0x3EFFFFFD, 0x3EFFFFFD}}};
inline const XMVECTORU32 g_XMSelect1000 = {{{XM_SELECT_1, XM_SELECT_0, XM_SELECT_0, XM_SELECT_0}}};
inline const XMVECTORU32 g_XMSelect1100 = {{{XM_SELECT_1, XM_SELECT_1, XM_SELECT_0, XM_SELECT_0}}};
inline const XMVECTORU32 g_XMSelect1110 = {{{XM_SELECT_1, XM_SELECT_1, XM_SELECT_1, XM_SELECT_0}}};
inline const XMVECTORU32 g_XMSelect1011 = {{{XM_SELECT_1, XM_SELECT_0, XM_SELECT_1, XM_SELECT_1}}};
inline const XMVECTORF32 g_XMFixupY16 = {{{1.0f, 1.0f / 65536.0f, 0.0f, 0.0f}}};
inline const XMVECTORF32 g_XMFixupY16W16 = {{{1.0f, 1.0f, 1.0f / 65536.0f, 1.0f / 65536.0f}}};
inline const XMVECTORU32 g_XMFlipY = {{{0, 0x80000000, 0, 0}}};
inline const XMVECTORU32 g_XMFlipZ = {{{0, 0, 0x80000000, 0}}};
inline const XMVECTORU32 g_XMFlipW = {{{0, 0, 0, 0x80000000}}};
inline const XMVECTORU32 g_XMFlipYZ = {{{0, 0x80000000, 0x80000000, 0}}};
inline const XMVECTORU32 g_XMFlipZW = {{{0, 0, 0x80000000, 0x80000000}}};
inline const XMVECTORU32 g_XMFlipYW = {{{0, 0x80000000, 0, 0x80000000}}};
inline const XMVECTORI32 g_XMMaskDec4 = {{{0x3FF, 0x3FF << 10, 0x3FF << 20, static_cast<int>(0xC0000000)}}};
inline const XMVECTORI32 g_XMXorDec4 = {{{0x200, 0x200 << 10, 0x200 << 20, 0}}};
inline const XMVECTORF32 g_XMAddUDec4 = {{{0, 0, 0, 32768.0f * 65536.0f}}};
inline const XMVECTORF32 g_XMAddDec4 = {{{-512.0f, -512.0f * 1024.0f, -512.0f * 1024.0f * 1024.0f, 0}}};
inline const XMVECTORF32 g_XMMulDec4 = {{{1.0f, 1.0f / 1024.0f, 1.0f / (1024.0f * 1024.0f), 1.0f / (1024.0f * 1024.0f * 1024.0f)}}};
inline const XMVECTORU32 g_XMMaskByte4 = {{{0xFF, 0xFF00, 0xFF0000, 0xFF000000}}};
inline const XMVECTORI32 g_XMXorByte4 = {{{0x80, 0x8000, 0x800000, 0x00000000}}};
inline const XMVECTORF32 g_XMAddByte4 = {{{-128.0f, -128.0f * 256.0f, -128.0f * 65536.0f, 0}}};
inline const XMVECTORF32 g_XMFixUnsigned = {{{32768.0f * 65536.0f, 32768.0f * 65536.0f, 32768.0f * 65536.0f, 32768.0f * 65536.0f}}};
inline const XMVECTORF32 g_XMMaxInt = {{{65536.0f * 32768.0f - 128.0f, 65536.0f * 32768.0f - 128.0f, 65536.0f * 32768.0f - 128.0f, 65536.0f * 32768.0f - 128.0f}}};
inline const XMVECTORF32 g_XMMaxUInt = {{{65536.0f * 65536.0f - 256.0f, 65536.0f * 65536.0f - 256.0f, 65536.0f * 65536.0f - 256.0f, 65536.0f * 65536.0f - 256.0f}}};
inline const XMVECTORF32 g_XMUnsignedFix = {{{32768.0f * 65536.0f, 32768.0f * 65536.0f, 32768.0f * 65536.0f, 32768.0f * 65536.0f}}};
inline const XMVECTORF32 g_XMsrgbScale = {{{12.92f, 12.92f, 12.92f, 1.0f}}};
inline const XMVECTORF32 g_XMsrgbA = {{{0.055f, 0.055f, 0.055f, 0.0f}}};
inline const XMVECTORF32 g_XMsrgbA1 = {{{1.055f, 1.055f, 1.055f, 1.0f}}};
inline const XMVECTORI32 g_XMExponentBias = {{{127, 127, 127, 127}}};
inline const XMVECTORI32 g_XMSubnormalExponent = {{{-126, -126, -126, -126}}};
inline const XMVECTORI32 g_XMNumTrailing = {{{23, 23, 23, 23}}};
inline const XMVECTORI32 g_XMMinNormal = {{{0x00800000, 0x00800000, 0x00800000, 0x00800000}}};
inline const XMVECTORU32 g_XMNegInfinity = {{{0xFF800000, 0xFF800000, 0xFF800000, 0xFF800000}}};
inline const XMVECTORU32 g_XMNegQNaN = {{{0xFFC00000, 0xFFC00000, 0xFFC00000, 0xFFC00000}}};
inline const XMVECTORI32 g_XMBin128 = {{{0x43000000, 0x43000000, 0x43000000, 0x43000000}}};
inline const XMVECTORU32 g_XMBinNeg150 = {{{0xC3160000, 0xC3160000, 0xC3160000, 0xC3160000}}};
inline const XMVECTORI32 g_XM253 = {{{253, 253, 253, 253}}};
inline const XMVECTORF32 g_XMExpEst1 = {{{-6.93147182e-1f, -6.93147182e-1f, -6.93147182e-1f, -6.93147182e-1f}}};
inline const XMVECTORF32 g_XMExpEst2 = {{{+2.40226462e-1f, +2.40226462e-1f, +2.40226462e-1f, +2.40226462e-1f}}};
inline const XMVECTORF32 g_XMExpEst3 = {{{-5.55036440e-2f, -5.55036440e-2f, -5.55036440e-2f, -5.55036440e-2f}}};
inline const XMVECTORF32 g_XMExpEst4 = {{{+9.61597636e-3f, +9.61597636e-3f, +9.61597636e-3f, +9.61597636e-3f}}};
inline const XMVECTORF32 g_XMExpEst5 = {{{-1.32823968e-3f, -1.32823968e-3f, -1.32823968e-3f, -1.32823968e-3f}}};
inline const XMVECTORF32 g_XMExpEst6 = {{{+1.47491097e-4f, +1.47491097e-4f, +1.47491097e-4f, +1.47491097e-4f}}};
inline const XMVECTORF32 g_XMExpEst7 = {{{-1.08635004e-5f, -1.08635004e-5f, -1.08635004e-5f, -1.08635004e-5f}}};
inline const XMVECTORF32 g_XMLogEst0 = {{{+1.442693f, +1.442693f, +1.442693f, +1.442693f}}};
inline const XMVECTORF32 g_XMLogEst1 = {{{-0.721242f, -0.721242f, -0.721242f, -0.721242f}}};
inline const XMVECTORF32 g_XMLogEst2 = {{{+0.479384f, +0.479384f, +0.479384f, +0.479384f}}};
inline const XMVECTORF32 g_XMLogEst3 = {{{-0.350295f, -0.350295f, -0.350295f, -0.350295f}}};
inline const XMVECTORF32 g_XMLogEst4 = {{{+0.248590f, +0.248590f, +0.248590f, +0.248590f}}};
inline const XMVECTORF32 g_XMLogEst5 = {{{-0.145700f, -0.145700f, -0.145700f, -0.145700f}}};
inline const XMVECTORF32 g_XMLogEst6 = {{{+0.057148f, +0.057148f, +0.057148f, +0.057148f}}};
inline const XMVECTORF32 g_XMLogEst7 = {{{-0.010578f, -0.010578f, -0.010578f, -0.010578f}}};
inline const XMVECTORF32 g_XMLgE = {{{+1.442695f, +1.442695f, +1.442695f, +1.442695f}}};
inline const XMVECTORF32 g_XMInvLgE = {{{+6.93147182e-1f, +6.93147182e-1f, +6.93147182e-1f, +6.93147182e-1f}}};
inline const XMVECTORF32 g_UByteMax = {{{255.0f, 255.0f, 255.0f, 255.0f}}};
inline const XMVECTORF32 g_ByteMin = {{{-127.0f, -127.0f, -127.0f, -127.0f}}};
inline const XMVECTORF32 g_ByteMax = {{{127.0f, 127.0f, 127.0f, 127.0f}}};
inline const XMVECTORF32 g_ShortMin = {{{-32767.0f, -32767.0f, -32767.0f, -32767.0f}}};
inline const XMVECTORF32 g_ShortMax = {{{32767.0f, 32767.0f, 32767.0f, 32767.0f}}};
inline const XMVECTORF32 g_UShortMax = {{{65535.0f, 65535.0f, 65535.0f, 65535.0f}}};

inline XMVECTOR XMVectorSetBinaryConstant(uint32_t C0, uint32_t C1, uint32_t C2, uint32_t C3) { return {}; }
inline XMVECTOR XMVectorSplatConstant(int32_t IntConstant, uint32_t DivExponent) { return {}; }
inline XMVECTOR XMVectorSplatConstantInt(int32_t IntConstant) { return {}; }

}

#endif
