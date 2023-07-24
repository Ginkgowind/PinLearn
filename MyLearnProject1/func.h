#pragma once

#include <windows.h>
#include <windowsx.h>


HWND initWindow(HINSTANCE hInstance);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);