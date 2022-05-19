// ywstd/cwchar.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <cwchar>
#else

#include "@/FILE.hh"
#include "@/mbstate_t.hh"
#include "@/tm.hh"

namespace std {

using size_t = decltype(sizeof(int));
using va_list = char*;
using wint_t = unsigned int;

wchar_t* wcscpy(wchar_t*, const wchar_t*);
wchar_t* wcsncpy(wchar_t*, const wchar_t*, size_t);
wchar_t* wcscat(wchar_t*, const wchar_t*);
wchar_t* wcsncat(wchar_t*, const wchar_t*, size_t);
size_t wcsxfrm(wchar_t*, const wchar_t*, size_t);
size_t wcslen(const wchar_t*);
int wcscmp(const wchar_t*, const wchar_t*);
int wcsncmp(const wchar_t*, const wchar_t*, size_t);
int wcscoll(const wchar_t*, const wchar_t*);
const wchar_t* wcschr(const wchar_t*, wchar_t);
wchar_t* wcschr(wchar_t*, wchar_t);
const wchar_t* wcsrchr(const wchar_t*, wchar_t);
wchar_t* wcsrchr(wchar_t*, wchar_t);
size_t wcsspn(const wchar_t*, const wchar_t*);
size_t wcscspn(const wchar_t*, const wchar_t*);
const wchar_t* wcspbrk(const wchar_t*, const wchar_t*);
wchar_t* wcspbrk(wchar_t*, const wchar_t*);
const wchar_t* wcsstr(const wchar_t*, const wchar_t*);
wchar_t* wcsstr(wchar_t*, const wchar_t*);
wchar_t* wcstok(wchar_t*, const wchar_t*, wchar_t**);
wchar_t* wmemcpy(wchar_t*, const wchar_t*, size_t);
wchar_t* wmemmove(wchar_t*, const wchar_t*, size_t);
int wmemcmp(const wchar_t*, const wchar_t*, size_t);
const wchar_t* wmemchr(const wchar_t*, wchar_t, size_t);
wchar_t* wmemchr(wchar_t*, wchar_t, size_t);
wchar_t* wmemset(wchar_t*, wchar_t, size_t);
int mbsinit(const mbstate_t*);
wint_t btowc(int);
int wctob(wint_t);
size_t mbrlen(const char*, size_t, mbstate_t*);
size_t mbrtowc(wchar_t*, const char*, size_t, mbstate_t*);
size_t wcrtomb(char*, wchar_t, mbstate_t*);
size_t mbsrtowcs(wchar_t*, const char**, size_t, mbstate_t*);
size_t wcsrtombs(char*, const wchar_t**, size_t, mbstate_t*);
wint_t fgetwc(FILE*);
wint_t getwc(FILE*);
wchar_t* fgetws(wchar_t*, int, FILE*);
wint_t fputwc(wchar_t, FILE*);
wint_t putwc(wchar_t, FILE*);
int fputws(const wchar_t*, FILE*);
wint_t getwchar();
wint_t putwchar(wchar_t);
wint_t ungetwc(wint_t, FILE*);
int fwide(FILE*, int);
int wscanf(const wchar_t*, ...);
int fwscanf(FILE*, const wchar_t*, ...);
int swscanf(const wchar_t*, const wchar_t*, ...);
int vwscanf(const wchar_t*, va_list);
int vfwscanf(FILE*, const wchar_t*, va_list);
int vswscanf(const wchar_t*, const wchar_t*, va_list);
int wprintf(const wchar_t*, ...);
int wprintf(const wchar_t*, ...);
int swprintf(wchar_t*, size_t size, const wchar_t*, ...);
int vwprintf(const wchar_t*, va_list);
int vfwprintf(FILE*, const wchar_t*, va_list);
int vswprintf(wchar_t*, size_t, const wchar_t*, va_list);
size_t wcsftime(wchar_t*, size_t, const wchar_t*, const tm*);
long wcstol(const wchar_t*, wchar_t**, int);
long long wcstoll(const wchar_t*, wchar_t**, int);
unsigned long wcstoul(const wchar_t*, wchar_t**, int);
unsigned long long wcstoull(const wchar_t*, wchar_t**, int);
float wcstof(const wchar_t*, wchar_t**);
double wcstod(const wchar_t*, wchar_t**);
long double wcstold(const wchar_t*, wchar_t**);

}

#endif
