// ywstd/cstring.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include <cstring>
#else

namespace sld {

using size_t = decltype(sizeof(int));

char* strcpy(char* dst, const char* src);
char* strncpy(char* dst, const char* src, size_t n);
char* strcat(char* dst, const char* src);
char* strncat(char* dst, const char* src, size_t n);
size_t strxfrm(char* dst, const char* src, size_t n);

size_t strlen(const char* str);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);
int strcoll(const char* s1, const char* s2);
const char* strchr(const char* str, int ch);
char* strchr(char* str, int ch);
const char* strrchr(const char* str, int ch);
char* strrchr(char* str, int ch);
size_t strspn(const char* dst, const char* src);
size_t strcspn(const char* dst, const char* src);
const char* strpbrk(const char* dst, const char* breakset);
char* strpbrk(char* dst, const char* breakset);
const char* strstr(const char* haystack, const char* needle);
char* strstr(char* haystack, const char* needle);
char* strtok(char* str, const char* delim);

const void* memchr(const void* ptr, int ch, size_t n);
void* memchr(void* ptr, int ch, size_t n);
int memcmp(const void* s1, const void* s2, size_t n);
void* memset(void* dst, int ch, size_t n);
void* memcpy(void* dst, const void* src, size_t n);
void* memmove(void* dst, const void* src, size_t n);

char* strerror(int errnum);

}

#ifndef NULL
#define NULL 0
#endif

#endif
