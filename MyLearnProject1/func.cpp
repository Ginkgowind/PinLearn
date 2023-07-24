#include <assert.h>
#include "func.h"

HWND hwndWindow;
HWND hwndTogglePinBtn;
HWND hwndCloseBtn;

HWND initWindow(HINSTANCE hInstance)
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    // 创建窗口
    hwndWindow = CreateWindowEx(WS_EX_NOACTIVATE, CLASS_NAME, L"", WS_CHILDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, GetDesktopWindow(), NULL, hInstance, NULL);
    assert(hwndWindow != NULL);

    // 创建子控件-切换pin状态按钮
    hwndTogglePinBtn = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Toggle",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        350,         // x position 
        250,         // y position 
        80,        // Button width
        60,        // Button height
        hwndWindow,     // Parent window
        NULL,       // No menu.
        hInstance,
        NULL);      // Pointer not needed.
    assert(hwndTogglePinBtn != NULL);

    // 创建子控件-关闭窗口按钮
    hwndCloseBtn = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Close",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        600,         // x position 
        50,         // y position 
        60,        // Button width
        40,        // Button height
        hwndWindow,     // Parent window
        NULL,       // No menu.
        hInstance,
        NULL);      // Pointer not needed.
    assert(hwndCloseBtn != NULL);

    return hwndWindow;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static POINT pt, pe;
    static RECT rt, re;
    static bool bPin = false, bDraging = false;

    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
        SetCapture(hwnd);
        bDraging = true;

        GetCursorPos(&pt);      // 获取鼠标光标指针当前位置
        GetWindowRect(hwnd, &rt);  // 获取窗口位置与大小
        re.right = rt.right - rt.left;    // 保存窗口宽度
        re.bottom = rt.bottom - rt.top; // 保存窗口高度

        return 0;

    case WM_LBUTTONUP:
        ReleaseCapture();
        bDraging = false;
        return 0;

    case WM_MOUSEMOVE:
        if (!bPin && bDraging) {
            // 计算鼠标移动距离
            GetCursorPos(&pe);     // 获取光标指针的新位置
            re.left = rt.left + (pe.x - pt.x);  // 窗口新的水平位置
            re.top = rt.top + (pe.y - pt.y); // 窗口新的垂直位置
            MoveWindow(hwnd, re.left, re.top, re.right, re.bottom, true); // 移动窗口   

            return 0;
        }

    // 点击按钮
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED) {
            if (HWND(lParam) == hwndTogglePinBtn)
            {
                bPin = !bPin;
                return 0;
            }
            else if (HWND(lParam) == hwndCloseBtn) {
                PostQuitMessage(0);
                return 0;
            }
        }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
