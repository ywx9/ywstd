// ywstd/windows.hh

// Copyright (c) Yw Ninefold @ Ywx9
// SPDX-License-Identifier: Apache-2.0

// clang-format off

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once
#pragma clang diagnostic pop

#ifdef _ywstd_
#include "windows.h"
#define YW_WINDOWS_FUNC(Ret, Func, ...) using ::Func;
#define YW_WINDOWS_VOID(Ret, Func, ...) using ::Func;
#define YW_WINDOWS_TYPE(Alias, ...) using ::Alias;
#define YW_WINDOWS_STRUCT(Struct, ...) using ::Struct;
#else
#define YW_WINDOWS_FUNC(Ret, Func, ...) inline Ret Func(__VA_ARGS__) { return Ret{}; }
#define YW_WINDOWS_VOID(Ret, Func, ...) inline Ret Func(__VA_ARGS__) {}
#define YW_WINDOWS_TYPE(Alias, ...) using Alias = __VA_ARGS__;
#define YW_WINDOWS_STRUCT(Struct, ...) struct Struct { __VA_ARGS__; };
#endif

#ifdef BroadcastSystemMessage
#undef BroadcastSystemMessage
#undef BroadcastSystemMessageEx
#undef CallMsgFilter
#undef CallWindowProc
#undef CreateMDIWindow
#undef CreateWindow
#undef CreateWindowA
#undef CreateWindowW
#undef CreateWindowEx
#undef DefFrameProc
#undef DefMDIChildProc
#undef DefWindowProc
#undef DispatchMessage
#undef EnumProps
#undef EnumPropsEx
#undef FindWindow
#undef FindWindowEx
#undef GetAltTabInfo
#undef GetClassInfo
#undef GetClassInfoEx
#undef GetClassLong
#undef GetClassLongPtr
#undef GetClassName
#undef GetMessage
#undef GetNextWindow
#undef GetProp
#undef GetWindowLong
#undef GetWindowLongPtr
#undef GetWindowModuleFileName
#undef GetWindowText
#undef GetWindowTextLength
#undef PeekMessage
#undef PostMessage
#undef PostThreadMessage
#undef RealGetWindowClass
#undef RegisterClass
#undef RegisterClassEx
#undef RegisterWindowMessage
#undef RemoveProp
#undef SendMessage
#undef SendMessageCallback
#undef SendMessageTimeout
#undef SendNotifyMessage
#undef SetClassLong
#undef SetClassLongPtr
#undef SetProp
#undef SetWindowLong
#undef SetWindowLongPtr
#undef SetWindowsHookEx
#undef SetWindowText
#undef SystemParametersInfo
#undef UnregisterClass
#endif

namespace yw::windows {
#ifdef UNICODE
using TCHAR = wchar_t;
inline constexpr bool unicode = true;
#define YW_WINDOWS_AWFN(Func, ...) { return Func##W(__VA_ARGS__); }
#else
using TCHAR = char;
inline constexpr bool unicode = false;
#define YW_WINDOWS_AWFN(Func, ...) { return Func##A(__VA_ARGS__); }
#endif
inline constexpr int cchildren_scrollbar = 5;
template<int Number> struct _module { int _; };
template<typename T1, typename T2, bool = sizeof(sizeof(int)) == 4> struct _switch { using type = T2; };
template<typename T1, typename T2> struct _switch<T1, T2, true> { using type = T1; };

YW_WINDOWS_TYPE(ATOM, unsigned short)
YW_WINDOWS_TYPE(BOOL, int)
YW_WINDOWS_TYPE(BYTE, unsigned char)
YW_WINDOWS_TYPE(COLORREF, DWORD)
YW_WINDOWS_TYPE(DWORD, unsigned long)
YW_WINDOWS_TYPE(DWORD_PTR, typename _switch<DWORD, unsigned long long>::type)
YW_WINDOWS_TYPE(HANDLE, void*)
YW_WINDOWS_TYPE(HBRUSH, _module<__LINE__>)
YW_WINDOWS_TYPE(HCURSOR, _module<__LINE__>)
YW_WINDOWS_TYPE(HDC, _module<__LINE__>)
YW_WINDOWS_TYPE(HDESK, _module<__LINE__>)
YW_WINDOWS_TYPE(HDWP, HANDLE)
YW_WINDOWS_TYPE(HHOOK, _module<__LINE__>)
YW_WINDOWS_TYPE(HICON, _module<__LINE__>)
YW_WINDOWS_TYPE(HINSTANCE, _module<__LINE__>)
YW_WINDOWS_TYPE(HMENU, _module<__LINE__>)
YW_WINDOWS_TYPE(HWND, _module<__LINE__>)
YW_WINDOWS_TYPE(INT_PTR, typename _switch<int, long long>::type)
YW_WINDOWS_TYPE(LONG_PTR, typename _switch<long, long long>::type)
YW_WINDOWS_TYPE(LPARAM, LONG_PTR)
YW_WINDOWS_TYPE(LRESULT, LONG_PTR)
YW_WINDOWS_TYPE(UINT, unsigned int)
YW_WINDOWS_TYPE(UINT_PTR, typename _switch<UINT, unsigned long long>::type)
YW_WINDOWS_TYPE(ULONG, unsigned long)
YW_WINDOWS_TYPE(ULONG_PTR, typename _switch<ULONG, unsigned long long>::type)
YW_WINDOWS_TYPE(WORD, unsigned short)
YW_WINDOWS_TYPE(WPARAM, UINT_PTR)

YW_WINDOWS_TYPE(FARPROC, INT_PTR (*)())
YW_WINDOWS_TYPE(HOOKPROC, FARPROC)
YW_WINDOWS_TYPE(PROPENUMPROCA, BOOL (*)(HWND, const char*, HANDLE))
YW_WINDOWS_TYPE(PROPENUMPROCW, BOOL (*)(HWND, const wchar_t*, HANDLE))
using PROPENUMPROC = typename _switch<PROPENUMPROCW, PROPENUMPROCA, unicode>::type;
YW_WINDOWS_TYPE(PROPENUMPROCEXA, BOOL (*)(HWND, const char*, HANDLE, ULONG_PTR))
YW_WINDOWS_TYPE(PROPENUMPROCEXW, BOOL (*)(HWND, const wchar_t*, HANDLE, ULONG_PTR))
using PROPENUMPROCEX = typename _switch<PROPENUMPROCEXW, PROPENUMPROCEXA, unicode>::type;
YW_WINDOWS_TYPE(SENDASYNCPROC, void (*)(HWND, UINT, ULONG_PTR, LRESULT))
YW_WINDOWS_TYPE(TIMERPROC, void (*)(HWND, UINT, UINT_PTR, DWORD))
YW_WINDOWS_TYPE(WNDPROC, LRESULT (*)(HWND, UINT, WPARAM, LPARAM))
YW_WINDOWS_TYPE(WNDENUMPROC, BOOL (*)(HWND, LPARAM))

YW_WINDOWS_STRUCT(POINT, long x, y)
YW_WINDOWS_STRUCT(ALTTABINFO, DWORD cbSize; BOOL cItems, cColumns, cRows, iColFocus, iRowFocus, cxItem, cyItem; POINT ptStart)
YW_WINDOWS_STRUCT(BLENDFUNCTION, BYTE BlendOp, BlendFlags, SourceConstantAlpha, AlphaFormat)
YW_WINDOWS_STRUCT(LUID, DWORD LowPart; long HighPart)
YW_WINDOWS_STRUCT(BSMINFO, UINT cbSize; HDESK hdesk; HWND hwnd; LUID luid)
YW_WINDOWS_STRUCT(CHANGEFILTERSTRUCT, DWORD cbSize, ExtStatus)
YW_WINDOWS_STRUCT(RECT, long left, top, right, bottom)
YW_WINDOWS_STRUCT(GUITHREADINFO, DWORD cbSize, flags; HWND hwndActive, hwndFocus, hwndCapture, hwndMenuOwner, hwndMoveSize, hwndCaret; RECT rcCaret)
YW_WINDOWS_STRUCT(MSG, HWND hwnd; UINT message; WPARAM wParam; LPARAM lParam; DWORD time; POINT pt)
YW_WINDOWS_STRUCT(SIZE, long cx, cy)
YW_WINDOWS_STRUCT(TITLEBARINFO, DWORD cbSize; RECT rcTitleBar; DWORD rgstate[cchildren_scrollbar + 1])
YW_WINDOWS_STRUCT(WINDOWINFO, DWORD cbSize; RECT rcWindow, rcClient; DWORD dwStyle, dwExStyle, dwWindowStatus;
                              UINT cxWindowBorders, cyWindowBorders; ATOM atomWindowType; WORD wCreatorVersion)
YW_WINDOWS_STRUCT(WINDOWPLACEMENT, UINT length, flags, showCmd; POINT ptMinPosition, ptMaxPosition; RECT rcNormalPosition)
YW_WINDOWS_STRUCT(WNDCLASSA, UINT style; WNDPROC lpfnWndProc; BOOL cbClsExtra, cbWndExtra; HINSTANCE hInstance;
                             HICON hIcon; HCURSOR hCursor; HBRUSH hbrBackground; const char* lpszMenuName; const char* lpszClassName)
YW_WINDOWS_STRUCT(WNDCLASSW, UINT style; WNDPROC lpfnWndProc; BOOL cbClsExtra, cbWndExtra; HINSTANCE hInstance;
                             HICON hIcon; HCURSOR hCursor; HBRUSH hbrBackground; const wchar_t* lpszMenuName; const wchar_t* lpszClassName)
using WNDCLASS = typename _switch<WNDCLASSW, WNDCLASSA, unicode>::type;
YW_WINDOWS_STRUCT(WNDCLASSEXA, UINT cbSize; UINT style; WNDPROC lpfnWndProc; BOOL cbClsExtra, cbWndExtra;
                               HINSTANCE hInstance; HICON hIcon; HCURSOR hCursor; HBRUSH hbrBackground;
                               const char* lpszMenuName; const char* lpszClassName; HICON hIconSm)
YW_WINDOWS_STRUCT(WNDCLASSEXW, UINT cbSize; UINT style; WNDPROC lpfnWndProc; BOOL cbClsExtra, cbWndExtra;
                               HINSTANCE hInstance; HICON hIcon; HCURSOR hCursor; HBRUSH hbrBackground;
                               const wchar_t* lpszMenuName; const wchar_t* lpszClassName; HICON hIconSm)
using WNDCLASSEX = typename _switch<WNDCLASSEXW, WNDCLASSEXA, unicode>::type;

YW_WINDOWS_FUNC(BOOL, AdjustWindowRect, RECT*, DWORD, BOOL)
YW_WINDOWS_FUNC(BOOL, AdjustWindowRectEx, RECT*, DWORD, BOOL, DWORD)
YW_WINDOWS_FUNC(BOOL, AllowSetForegroundWindow, DWORD)
YW_WINDOWS_FUNC(BOOL, AllowSetForegroundWindow, DWORD)
YW_WINDOWS_FUNC(BOOL, AnimateWindow, HWND, DWORD, DWORD);
YW_WINDOWS_FUNC(BOOL, AnyPopup)
YW_WINDOWS_FUNC(UINT, ArrangeIconicWindows, HWND)
YW_WINDOWS_FUNC(HDWP, BeginDeferWindowPos, BOOL)
YW_WINDOWS_FUNC(BOOL, BringWindowToTop, HWND)
YW_WINDOWS_FUNC(long, BroadcastSystemMessageA, DWORD, DWORD*, UINT, WPARAM, LPARAM)
YW_WINDOWS_FUNC(long, BroadcastSystemMessageW, DWORD, DWORD*, UINT, WPARAM, LPARAM)
inline long BroadcastSystemMessage(DWORD Flags, DWORD* Info, UINT Msg, WPARAM wparam, LPARAM lparam)
  YW_WINDOWS_AWFN(BroadcastSystemMessage, Flags, Info, Msg, wparam, lparam)
YW_WINDOWS_FUNC(long, BroadcastSystemMessageExA, DWORD, DWORD*, UINT, WPARAM, LPARAM, BSMINFO*)
YW_WINDOWS_FUNC(long, BroadcastSystemMessageExW, DWORD, DWORD*, UINT, WPARAM, LPARAM, BSMINFO*)
inline long BroadcastSystemMessageEx(DWORD Flags, DWORD* Info, UINT Msg, WPARAM wparam, LPARAM lparam, BSMINFO* bsminfo)
  YW_WINDOWS_AWFN(BroadcastSystemMessageEx, Flags, Info, Msg, wparam, lparam, bsminfo)
YW_WINDOWS_FUNC(BOOL, CalculatePopupWindowPosition, const POINT*, const SIZE*, UINT, RECT*, RECT*)
YW_WINDOWS_FUNC(BOOL, CallMsgFilterA, MSG*, BOOL);
YW_WINDOWS_FUNC(BOOL, CallMsgFilterW, MSG*, BOOL);
inline BOOL CallMsgFilter(MSG* msg, BOOL Code) YW_WINDOWS_AWFN(CallMsgFilter, msg, Code)
YW_WINDOWS_FUNC(LRESULT, CallNextHookEx, HHOOK, BOOL, WPARAM, LPARAM);
YW_WINDOWS_FUNC(LRESULT, CallWindowProcA, WNDPROC, HWND, UINT, WPARAM, LPARAM)
YW_WINDOWS_FUNC(LRESULT, CallWindowProcW, WNDPROC, HWND, UINT, WPARAM, LPARAM)
inline LRESULT CallWindowProc(WNDPROC fn, HWND hwnd, UINT Msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(CallWindowProc, fn, hwnd, Msg, wparam, lparam)
YW_WINDOWS_FUNC(WORD, CascadeWindows, HWND, UINT, const RECT*, UINT, const HWND*)
YW_WINDOWS_FUNC(BOOL, ChangeWindowMessageFilter, UINT, DWORD)
YW_WINDOWS_FUNC(BOOL, ChangeWindowMessageFilterEx, HWND, UINT, DWORD, CHANGEFILTERSTRUCT*)
YW_WINDOWS_FUNC(HWND, ChildWindowFromPoint, HWND, POINT)
YW_WINDOWS_FUNC(HWND, ChildWindowFromPointEx, HWND, POINT, UINT)
YW_WINDOWS_FUNC(BOOL, CloseWindow, HWND)
YW_WINDOWS_FUNC(HWND, CreateMDIWindowA, const char*, const char*, DWORD, BOOL, BOOL, BOOL, BOOL, HWND, HINSTANCE, LPARAM)
YW_WINDOWS_FUNC(HWND, CreateMDIWindowW, const wchar_t*, const wchar_t*, DWORD, BOOL, BOOL, BOOL, BOOL, HWND, HINSTANCE, LPARAM)
inline HWND CreateMDIWindow(const TCHAR* ClassName, const TCHAR* WindowName, DWORD Style, BOOL x, BOOL y, BOOL Width,
                            BOOL Height, HWND Parent, HINSTANCE hinstance, LPARAM lparam)
  YW_WINDOWS_AWFN(CreateMDIWindow, ClassName, WindowName, Style, x, y, Width, Height, Parent, hinstance, lparam)

YW_WINDOWS_FUNC(HWND, CreateWindowExA, DWORD, const char*, const char*, DWORD, BOOL, BOOL, BOOL, BOOL, HWND, HMENU, HINSTANCE, void*)
YW_WINDOWS_FUNC(HWND, CreateWindowExW, DWORD, const wchar_t*, const wchar_t*, DWORD, BOOL, BOOL, BOOL, BOOL, HWND, HMENU, HINSTANCE, void*)
inline HWND CreateWindowA(const char* ClassName, const char* WindowName, DWORD Style, BOOL x, BOOL y, BOOL Width,
                          BOOL Height, HWND Parent, HMENU hmenu, HINSTANCE hinstance, void* Param)
{ return CreateWindowExA(0ul, ClassName, WindowName, Style, x, y, Width, Height, Parent, hmenu, hinstance, Param); }
inline HWND CreateWindowW(const wchar_t* ClassName, const wchar_t* WindowName, DWORD Style, BOOL x, BOOL y, BOOL Width,
                          BOOL Height, HWND Parent, HMENU hmenu, HINSTANCE hinstance, void* Param)
{ return CreateWindowExW(0ul, ClassName, WindowName, Style, x, y, Width, Height, Parent, hmenu, hinstance, Param); }
inline HWND CreateWindow(const TCHAR* ClassName, const TCHAR* WindowName, DWORD Style, BOOL x, BOOL y, BOOL Width,
                         BOOL Height, HWND Parent, HMENU hmenu, HINSTANCE hinstance, void* Param)
  YW_WINDOWS_AWFN(CreateWindow, ClassName, WindowName, Style, x, y, Width, Height, Parent, hmenu, hinstance, Param)
inline HWND CreateWindowEx(DWORD ExStyle, const TCHAR* ClassName, const TCHAR* WindowName, DWORD Style, BOOL x, BOOL y,
                           BOOL Width, BOOL Height, HWND Parent, HMENU hmenu, HINSTANCE hinstance, void* Param)
  YW_WINDOWS_AWFN(CreateWindowEx, ExStyle, ClassName, WindowName, Style, x, y, Width, Height, Parent, hmenu, hinstance, Param)

YW_WINDOWS_FUNC(HDWP, DeferWindowPos, HDWP, HWND, HWND, BOOL, BOOL, BOOL, BOOL, UINT)
YW_WINDOWS_FUNC(LRESULT, DefFrameProcA, HWND, HWND, UINT, WPARAM, LPARAM)
YW_WINDOWS_FUNC(LRESULT, DefFrameProcW, HWND, HWND, UINT, WPARAM, LPARAM)
inline LRESULT DefFrameProc(HWND hwnd, HWND client, UINT msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(DefFrameProc, hwnd, client, msg, wparam, lparam)
YW_WINDOWS_FUNC(LRESULT, DefMDIChildProcA, HWND, UINT, WPARAM, WPARAM)
YW_WINDOWS_FUNC(LRESULT, DefMDIChildProcW, HWND, UINT, WPARAM, WPARAM)
inline LRESULT DefMDIChildProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(DefMDIChildProc, hwnd, msg, wparam, lparam)
YW_WINDOWS_FUNC(LRESULT, DefWindowProcA, HWND, UINT, WPARAM, WPARAM)
YW_WINDOWS_FUNC(LRESULT, DefWindowProcW, HWND, UINT, WPARAM, WPARAM)
inline LRESULT DefWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(DefWindowProc, hwnd, msg, wparam, lparam)
YW_WINDOWS_FUNC(BOOL, DeregisterShellHookWindow, HWND)
YW_WINDOWS_FUNC(BOOL, DestroyWindow, HWND)
YW_WINDOWS_FUNC(LRESULT, DispatchMessageA, const MSG*)
YW_WINDOWS_FUNC(LRESULT, DispatchMessageW, const MSG*)
inline LRESULT DispatchMessage(const MSG* msg) YW_WINDOWS_AWFN(DispatchMessage, msg)
YW_WINDOWS_FUNC(BOOL, EndDeferWindowPos, HDWP)
YW_WINDOWS_FUNC(BOOL, EnumChildWindows, HWND, WNDENUMPROC)
YW_WINDOWS_FUNC(BOOL, EnumPropsA, HWND, PROPENUMPROCA)
YW_WINDOWS_FUNC(BOOL, EnumPropsW, HWND, PROPENUMPROCW)
inline BOOL EnumProps(HWND hwnd, PROPENUMPROC a) YW_WINDOWS_AWFN(EnumProps, hwnd, a)
YW_WINDOWS_FUNC(BOOL, EnumPropsExA, HWND, PROPENUMPROCEXA, LPARAM)
YW_WINDOWS_FUNC(BOOL, EnumPropsExW, HWND, PROPENUMPROCEXW, LPARAM)
inline BOOL EnumPropsEx(HWND hwnd, PROPENUMPROCEX a, LPARAM lparam) YW_WINDOWS_AWFN(EnumPropsEx, hwnd, a, lparam)
YW_WINDOWS_FUNC(BOOL, EnumThreadWindows, DWORD, WNDENUMPROC, LPARAM)
YW_WINDOWS_FUNC(BOOL, EnumWindows, WNDENUMPROC, LPARAM)
YW_WINDOWS_FUNC(HWND, FindWindowA, const char* ClassName, const char* WindowName)
YW_WINDOWS_FUNC(HWND, FindWindowW, const wchar_t* ClassName, const wchar_t* WindowName)
inline HWND FindWindow(const TCHAR* ClassName, const TCHAR* WindowName) YW_WINDOWS_AWFN(FindWindow, ClassName, WindowName)
YW_WINDOWS_FUNC(HWND, FindWindowExA, HWND Parent, HWND ChildAfter, const char* ClassName, const char* WindowName)
YW_WINDOWS_FUNC(HWND, FindWindowExW, HWND Parent, HWND ChildAfter, const wchar_t* ClassName, const wchar_t* WindowName)
inline HWND FindWindowEx(HWND Parent, HWND ChildAfter, const TCHAR* ClassName, const TCHAR* WindowName)
  YW_WINDOWS_AWFN(FindWindowEx, Parent, ChildAfter, ClassName, WindowName)
YW_WINDOWS_FUNC(BOOL, GetAltTabInfoA, HWND, BOOL, ALTTABINFO*, char*, UINT)
YW_WINDOWS_FUNC(BOOL, GetAltTabInfoW, HWND, BOOL, ALTTABINFO*, wchar_t*, UINT)
inline BOOL GetAltTabInfo(HWND hwnd, BOOL Item, ALTTABINFO* a, TCHAR* ItemText, UINT ItemTextLen)
  YW_WINDOWS_AWFN(GetAltTabInfo, hwnd, Item, a, ItemText, ItemTextLen)
YW_WINDOWS_FUNC(HWND, GetAncestor, HWND, UINT)
YW_WINDOWS_FUNC(BOOL, GetClassInfoA, HINSTANCE, const char*, WNDCLASSA*)
YW_WINDOWS_FUNC(BOOL, GetClassInfoW, HINSTANCE, const wchar_t*, WNDCLASSW*)
inline BOOL GetClassInfo(HINSTANCE hinstance, const TCHAR* ClassName, WNDCLASS* a) YW_WINDOWS_AWFN(GetClassInfo, hinstance, ClassName, a)
YW_WINDOWS_FUNC(BOOL, GetClassInfoExA, HINSTANCE, const char*, WNDCLASSEXA*)
YW_WINDOWS_FUNC(BOOL, GetClassInfoExW, HINSTANCE, const wchar_t*, WNDCLASSEXW*)
inline BOOL GetClassInfoEx(HINSTANCE hinstance, const TCHAR* ClassName, WNDCLASSEX* a) YW_WINDOWS_AWFN(GetClassInfoEx, hinstance, ClassName, a)
YW_WINDOWS_FUNC(DWORD, GetClassLongA, HWND, BOOL)
YW_WINDOWS_FUNC(DWORD, GetClassLongW, HWND, BOOL)
inline DWORD GetClassLong(HWND hwnd, BOOL Index) YW_WINDOWS_AWFN(GetClassLong, hwnd, Index)
YW_WINDOWS_FUNC(ULONG_PTR, GetClassLongPtrA, HWND, BOOL)
YW_WINDOWS_FUNC(ULONG_PTR, GetClassLongPtrW, HWND, BOOL)
inline ULONG_PTR GetClassLongPtr(HWND hwnd, BOOL Index) YW_WINDOWS_AWFN(GetClassLongPtr, hwnd, Index)
YW_WINDOWS_FUNC(BOOL, GetClassNameA, HWND, char*, BOOL)
YW_WINDOWS_FUNC(BOOL, GetClassNameW, HWND, wchar_t*, BOOL)
inline BOOL GetClassName(HWND hwnd, TCHAR* ClassName, BOOL MaxCount) YW_WINDOWS_AWFN(GetClassName, hwnd, ClassName, MaxCount)
YW_WINDOWS_FUNC(WORD, GetClassWord, HWND, BOOL)
YW_WINDOWS_FUNC(BOOL, GetClientRect, HWND, RECT*)
YW_WINDOWS_FUNC(HWND, GetDesktopWindow)
YW_WINDOWS_FUNC(HWND, GetForegroundWindow)
YW_WINDOWS_FUNC(BOOL, GetGUIThreadInfo, DWORD, GUITHREADINFO*)
YW_WINDOWS_FUNC(BOOL, GetInputState)
YW_WINDOWS_FUNC(HWND, GetLastActivePopup, HWND)
YW_WINDOWS_FUNC(BOOL, GetLayeredWindowAttributes, HWND, COLORREF*, BYTE*, DWORD*)
YW_WINDOWS_FUNC(BOOL, GetMessageA, MSG*, HWND, UINT, UINT)
YW_WINDOWS_FUNC(BOOL, GetMessageW, MSG*, HWND, UINT, UINT)
inline BOOL GetMessage(MSG* msg, HWND hwnd, UINT MsgFilterMin, UINT MsgFilterMax) YW_WINDOWS_AWFN(GetMessage, msg, hwnd, MsgFilterMin, MsgFilterMax)
YW_WINDOWS_FUNC(LPARAM, GetMessageExtraInfo)
YW_WINDOWS_FUNC(DWORD, GetMessagePos)
YW_WINDOWS_FUNC(long, GetMessageTime)
YW_WINDOWS_VOID(void, GetWindow, HWND, UINT)
inline void GetNextWindow(HWND hwnd, UINT Cmd) { GetWindow(hwnd, Cmd); }
YW_WINDOWS_FUNC(HWND, GetParent, HWND)
YW_WINDOWS_FUNC(BOOL, GetProcessDefaultLayout, DWORD*)
YW_WINDOWS_FUNC(HANDLE, GetPropA, HWND, const char*)
YW_WINDOWS_FUNC(HANDLE, GetPropW, HWND, const wchar_t*)
inline HANDLE GetProp(HWND hwnd, const TCHAR* String) YW_WINDOWS_AWFN(GetProp, hwnd, String)
YW_WINDOWS_FUNC(DWORD, GetQueueStatus, UINT)
YW_WINDOWS_FUNC(HWND, GetShellWindow)
YW_WINDOWS_FUNC(DWORD, GetSysColor, BOOL)
YW_WINDOWS_FUNC(BOOL, GetSystemMetrics, BOOL)
YW_WINDOWS_FUNC(BOOL, GetTitleBarInfo, HWND, TITLEBARINFO*)
YW_WINDOWS_FUNC(HWND, GetTopWindow, HWND)
YW_WINDOWS_FUNC(BOOL, GetWindowDisplayAffinity, HWND, DWORD*)
YW_WINDOWS_FUNC(BOOL, GetWindowInfo, HWND, WINDOWINFO*)
YW_WINDOWS_FUNC(long, GetWindowLongA, HWND, BOOL)
YW_WINDOWS_FUNC(long, GetWindowLongW, HWND, BOOL)
inline long GetWindowLong(HWND hwnd, BOOL Index) YW_WINDOWS_AWFN(GetWindowLong, hwnd, Index)
YW_WINDOWS_FUNC(LONG_PTR, GetWindowLongPtrA, HWND, BOOL)
YW_WINDOWS_FUNC(LONG_PTR, GetWindowLongPtrW, HWND, BOOL)
inline LONG_PTR GetWindowLongPtr(HWND hwnd, BOOL Index) YW_WINDOWS_AWFN(GetWindowLongPtr, hwnd, Index)
YW_WINDOWS_FUNC(UINT, GetWindowModuleFileNameA, HWND, char*, UINT)
YW_WINDOWS_FUNC(UINT, GetWindowModuleFileNameW, HWND, wchar_t*, UINT)
inline UINT GetWindowModuleFileName(HWND hwnd, TCHAR* FileNameBuf, UINT BufSize) YW_WINDOWS_AWFN(GetWindowModuleFileName, hwnd, FileNameBuf, BufSize)
YW_WINDOWS_FUNC(BOOL, GetWindowPlacement, HWND, WINDOWPLACEMENT*)
YW_WINDOWS_FUNC(BOOL, GetWindowRect, HWND, RECT*)
YW_WINDOWS_FUNC(BOOL, GetWindowTextA, HWND, char*, BOOL)
YW_WINDOWS_FUNC(BOOL, GetWindowTextW, HWND, wchar_t*, BOOL)
inline BOOL GetWindowText(HWND hwnd, TCHAR* Buffer, BOOL BufSize) YW_WINDOWS_AWFN(GetWindowText, hwnd, Buffer, BufSize)
YW_WINDOWS_FUNC(BOOL, GetWindowTextLengthA, HWND)
YW_WINDOWS_FUNC(BOOL, GetWindowTextLengthW, HWND)
inline BOOL GetWindowTextLength(HWND hwnd) YW_WINDOWS_AWFN(GetWindowTextLength, hwnd)
YW_WINDOWS_FUNC(DWORD, GetWindowThreadProcessId, HWND, DWORD*)
YW_WINDOWS_FUNC(BOOL, InSendMessage)
YW_WINDOWS_FUNC(DWORD, InSendMessageEx, void*)
YW_WINDOWS_FUNC(BOOL, InternalGetWindowText, HWND, wchar_t*, BOOL)
YW_WINDOWS_FUNC(BOOL, IsChild, HWND, HWND)
YW_WINDOWS_FUNC(BOOL, IsGUIThread, BOOL)
YW_WINDOWS_FUNC(BOOL, IsHungAppWindow, HWND)
YW_WINDOWS_FUNC(BOOL, IsIconic, HWND)
YW_WINDOWS_FUNC(BOOL, IsProcessDPIAware)
YW_WINDOWS_FUNC(BOOL, IsWindow, HWND)
YW_WINDOWS_FUNC(BOOL, IsWindowUnicode, HWND)
YW_WINDOWS_FUNC(BOOL, IsWindowVisible, HWND)
YW_WINDOWS_FUNC(BOOL, IsZoomed, HWND)
YW_WINDOWS_FUNC(BOOL, KillTimer, HWND, UINT_PTR)
YW_WINDOWS_FUNC(BOOL, LockSetForegroundWindow, UINT)
YW_WINDOWS_FUNC(BOOL, LogicalToPhysicalPoint, HWND, POINT*)
constexpr long makelong(auto a, auto b) { return (long)((((DWORD)a) & 0xff) | ((((DWORD)b) & 0xff) << 16)); }
constexpr LPARAM makelparam(auto l, auto h) { return (LPARAM)(DWORD)makelong(l, h); }
constexpr LRESULT makelresult(auto l, auto h) { return (LRESULT)(DWORD)makelong(l, h); }
constexpr WPARAM makewparam(auto l, auto h) { return (WPARAM)(DWORD)makelong(l, h); }
YW_WINDOWS_FUNC(BOOL, MoveWindow, HWND, BOOL, BOOL, BOOL, BOOL, BOOL)
YW_WINDOWS_FUNC(BOOL, OpenIcon, HWND)
YW_WINDOWS_FUNC(BOOL, PeekMessageA, MSG*, HWND, UINT, UINT, UINT)
YW_WINDOWS_FUNC(BOOL, PeekMessageW, MSG*, HWND, UINT, UINT, UINT)
inline BOOL PeekMessage(MSG* msg, HWND hwnd, UINT MsgFilterMin, UINT MsgFilterMax, UINT RemoveMsg)
  YW_WINDOWS_AWFN(PeekMessage, msg, hwnd, MsgFilterMin, MsgFilterMax, RemoveMsg)
YW_WINDOWS_FUNC(BOOL, PhysicalToLogicalPoint, HWND, POINT*)
YW_WINDOWS_FUNC(BOOL, PostMessageA, HWND, UINT, WPARAM, LPARAM)
YW_WINDOWS_FUNC(BOOL, PostMessageW, HWND, UINT, WPARAM, LPARAM)
inline BOOL PostMessage(HWND hwnd, UINT Msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(PostMessage, hwnd, Msg, wparam, lparam)
YW_WINDOWS_VOID(void, PostQuitMessage, BOOL)
YW_WINDOWS_FUNC(BOOL, PostThreadMessageA, DWORD, UINT, WPARAM, LPARAM)
YW_WINDOWS_FUNC(BOOL, PostThreadMessageW, DWORD, UINT, WPARAM, LPARAM)
inline BOOL PostThreadMessage(DWORD Thread, UINT Msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(PostThreadMessage, Thread, Msg, wparam, lparam)
YW_WINDOWS_FUNC(HWND, RealChildWindowFromPoint, HWND, POINT)
YW_WINDOWS_FUNC(UINT, RealGetWindowClassA, HWND, char*, UINT)
YW_WINDOWS_FUNC(UINT, RealGetWindowClassW, HWND, wchar_t*, UINT)
inline UINT RealGetWindowClass(HWND hwnd, TCHAR* ClassNameBuf, UINT BufSize) YW_WINDOWS_AWFN(RealGetWindowClass, hwnd, ClassNameBuf, BufSize)
YW_WINDOWS_FUNC(ATOM, RegisterClassA, const WNDCLASSA*)
YW_WINDOWS_FUNC(ATOM, RegisterClassW, const WNDCLASSW*)
inline ATOM RegisterClass(const WNDCLASS* wndclass) YW_WINDOWS_AWFN(RegisterClass, wndclass)
YW_WINDOWS_FUNC(ATOM, RegisterClassExA, const WNDCLASSEXA*)
YW_WINDOWS_FUNC(ATOM, RegisterClassExW, const WNDCLASSEXW*)
inline ATOM RegisterClassEx(const WNDCLASSEX* wndclass) YW_WINDOWS_AWFN(RegisterClassEx, wndclass)
YW_WINDOWS_FUNC(BOOL, RegisterShellHookWindow, HWND)
YW_WINDOWS_FUNC(UINT, RegisterWindowMessageA, const char*)
YW_WINDOWS_FUNC(UINT, RegisterWindowMessageW, const wchar_t*)
inline UINT RegisterWindowMessage(const TCHAR* String) YW_WINDOWS_AWFN(RegisterWindowMessage, String)
YW_WINDOWS_FUNC(HANDLE, RemovePropA, HWND, const char*)
YW_WINDOWS_FUNC(HANDLE, RemovePropW, HWND, const wchar_t*)
inline HANDLE RemoveProp(HWND hwnd, const TCHAR* String) YW_WINDOWS_AWFN(RemoveProp, hwnd, String)
YW_WINDOWS_FUNC(BOOL, ReplyMessage, LRESULT)
YW_WINDOWS_FUNC(LRESULT, SendMessageA, HWND, UINT, WPARAM, LPARAM)
YW_WINDOWS_FUNC(LRESULT, SendMessageW, HWND, UINT, WPARAM, LPARAM)
inline LRESULT SendMessage(HWND hwnd, UINT Msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(SendMessage, hwnd, Msg, wparam, lparam)
YW_WINDOWS_FUNC(BOOL, SendMessageCallbackA, HWND, UINT, WPARAM, LPARAM, SENDASYNCPROC, ULONG_PTR);
YW_WINDOWS_FUNC(BOOL, SendMessageCallbackW, HWND, UINT, WPARAM, LPARAM, SENDASYNCPROC, ULONG_PTR);
inline BOOL SendMessageCallback(HWND hwnd, UINT Msg, WPARAM wparam, LPARAM lparam, SENDASYNCPROC Callback, ULONG_PTR Data)
  YW_WINDOWS_AWFN(SendMessageCallback, hwnd, Msg, wparam, lparam, Callback, Data)
YW_WINDOWS_FUNC(LRESULT, SendMessageTimeoutA, HWND, UINT, WPARAM, LPARAM, UINT, UINT, DWORD_PTR*)
YW_WINDOWS_FUNC(LRESULT, SendMessageTimeoutW, HWND, UINT, WPARAM, LPARAM, UINT, UINT, DWORD_PTR*)
inline LRESULT SendMessageTimeout(HWND hwnd, UINT Msg, WPARAM wparam, LPARAM lparam, UINT Flags, UINT Timeout, DWORD_PTR* Result)
  YW_WINDOWS_AWFN(SendMessageTimeout, hwnd, Msg, wparam, lparam, Flags, Timeout, Result)
YW_WINDOWS_FUNC(BOOL, SendNotifyMessageA, HWND, UINT, WPARAM, LPARAM)
YW_WINDOWS_FUNC(BOOL, SendNotifyMessageW, HWND, UINT, WPARAM, LPARAM)
inline BOOL SendNotifyMessage(HWND hwnd, UINT Msg, WPARAM wparam, LPARAM lparam) YW_WINDOWS_AWFN(SendNotifyMessage, hwnd, Msg, wparam, lparam)
YW_WINDOWS_FUNC(DWORD, SetClassLongA, HWND, int, long)
YW_WINDOWS_FUNC(DWORD, SetClassLongW, HWND, int, long)
inline DWORD SetClassLong(HWND hwnd, int Index, long NewLong) YW_WINDOWS_AWFN(SetClassLong, hwnd, Index, NewLong)
YW_WINDOWS_FUNC(ULONG_PTR, SetClassLongPtrA, HWND, int, LONG_PTR)
YW_WINDOWS_FUNC(ULONG_PTR, SetClassLongPtrW, HWND, int, LONG_PTR)
inline ULONG_PTR SetClassLongPtr(HWND hwnd, int Index, LONG_PTR NewLong) YW_WINDOWS_AWFN(SetClassLongPtr, hwnd, Index, NewLong)
YW_WINDOWS_FUNC(WORD, SetClassWord, HWND, int, WORD)
YW_WINDOWS_FUNC(UINT_PTR, SetCoalescableTimer, HWND, UINT_PTR, UINT, TIMERPROC, ULONG)
YW_WINDOWS_FUNC(BOOL, SetForegroundWindow, HWND)
YW_WINDOWS_FUNC(BOOL, SetLayeredWindowAttributes, HWND, COLORREF, BYTE, DWORD)
YW_WINDOWS_FUNC(LPARAM, SetMessageExtraInfo, LPARAM)
YW_WINDOWS_FUNC(HWND, SetParent, HWND, HWND)
YW_WINDOWS_FUNC(BOOL, SetProcessDefaultLayout, DWORD)
YW_WINDOWS_FUNC(BOOL, SetProcessDPIAware)
YW_WINDOWS_FUNC(BOOL, SetPropA, HWND, const char*, HANDLE)
YW_WINDOWS_FUNC(BOOL, SetPropW, HWND, const wchar_t*, HANDLE)
inline BOOL SetProp(HWND hwnd, const TCHAR* String, HANDLE Data) YW_WINDOWS_AWFN(SetProp, hwnd, String, Data)
YW_WINDOWS_FUNC(BOOL, SetSysColors, int, const int*, const COLORREF*)
YW_WINDOWS_FUNC(UINT_PTR, SetTimer, HWND, UINT_PTR, UINT, TIMERPROC)
YW_WINDOWS_FUNC(BOOL, SetWindowDisplayAffinity, HWND, DWORD)
YW_WINDOWS_FUNC(long, SetWindowLongA, HWND, int, long)
YW_WINDOWS_FUNC(long, SetWindowLongW, HWND, int, long)
inline long SetWindowLong(HWND hwnd, int Index, long NewLong) YW_WINDOWS_AWFN(SetWindowLong, hwnd, Index, NewLong)
YW_WINDOWS_FUNC(LONG_PTR, SetWindowLongPtrA, HWND, int, LONG_PTR)
YW_WINDOWS_FUNC(LONG_PTR, SetWindowLongPtrW, HWND, int, LONG_PTR)
inline LONG_PTR SetWindowLongPtr(HWND hwnd, int Index, LONG_PTR NewLong) YW_WINDOWS_AWFN(SetWindowLongPtr, hwnd, Index, NewLong)
YW_WINDOWS_FUNC(BOOL, SetWindowPlacement, HWND, const WINDOWPLACEMENT*)
YW_WINDOWS_FUNC(BOOL, SetWindowPos, HWND, HWND, int, int, int, int, UINT)
YW_WINDOWS_FUNC(HHOOK, SetWindowsHookExA, int, HOOKPROC, HINSTANCE, DWORD)
YW_WINDOWS_FUNC(HHOOK, SetWindowsHookExW, int, HOOKPROC, HINSTANCE, DWORD)
inline HHOOK SetWindowsHookEx(int Hook, HOOKPROC fn, HINSTANCE hmod, DWORD ThreadId) YW_WINDOWS_AWFN(SetWindowsHookEx, Hook, fn, hmod, ThreadId)
YW_WINDOWS_FUNC(BOOL, SetWindowTextA, HWND, const char*)
YW_WINDOWS_FUNC(BOOL, SetWindowTextW, HWND, const wchar_t*)
inline BOOL SetWindowText(HWND hwnd, const TCHAR* String) YW_WINDOWS_AWFN(SetWindowText, hwnd, String)
YW_WINDOWS_FUNC(BOOL, ShowOwnedPopups, HWND, BOOL)
YW_WINDOWS_FUNC(BOOL, ShowWindow, HWND, int)
YW_WINDOWS_FUNC(BOOL, ShowWindowAsync, HWND, int)
YW_WINDOWS_FUNC(BOOL, SoundSentry)
YW_WINDOWS_VOID(void, SwitchToThisWindow, HWND, bool)
YW_WINDOWS_FUNC(BOOL, SystemParametersInfoA, UINT, UINT, void*, UINT)
YW_WINDOWS_FUNC(BOOL, SystemParametersInfoW, UINT, UINT, void*, UINT)
inline BOOL SystemParametersInfo(UINT Action, UINT uiParam, void* pvParam, UINT WinIni) YW_WINDOWS_AWFN(SystemParametersInfo, Action, uiParam, pvParam, WinIni)
YW_WINDOWS_FUNC(WORD, TileWindows, HWND, UINT, const RECT*, UINT, const HWND*)
YW_WINDOWS_FUNC(BOOL, TranslateMDISysAccel, HWND, MSG*)
YW_WINDOWS_FUNC(BOOL, TranslateMessage, const MSG*)
YW_WINDOWS_FUNC(BOOL, UnhookWindowsHookEx, HHOOK)
YW_WINDOWS_FUNC(BOOL, UnregisterClassA, const char*, HINSTANCE)
YW_WINDOWS_FUNC(BOOL, UnregisterClassW, const wchar_t*, HINSTANCE)
inline BOOL UnregisterClass(const TCHAR* ClassName, HINSTANCE hinstance) YW_WINDOWS_AWFN(UnregisterClass, ClassName, hinstance)
YW_WINDOWS_FUNC(BOOL, UpdateLayeredWindow, HWND, HDC, POINT*, SIZE*, HDC, POINT*, COLORREF, BLENDFUNCTION*, DWORD)
YW_WINDOWS_FUNC(BOOL, WaitMessage)
YW_WINDOWS_FUNC(HWND, WindowFromPhysicalPoint, POINT)
YW_WINDOWS_FUNC(HWND, WindowFromPoint, POINT)

}
