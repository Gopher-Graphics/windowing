#include "../window.h"

#include <minwindef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windef.h>
#include <windows.h>
#include <winnt.h>

// The best way to get the GGW_Window in the window procedure is to set a
// property on the window, and get it later in the window procedure. This is the
// key of that property.
#define PROPERTY_LIST_NAME L"GGW"

// The name of the window class that all GGW windows use.
#define WINDOW_CLASS_NAME L"GGW"

// The Win32 definition for the opaque type in window.h. Includes everything
// necessary to interact with the window.
struct GGW_Window_s {
    HINSTANCE hInstance; // The calling exe's module instance
    HWND hWnd;           // The handle to the window
    GGW_Event event;     // the event set by the window procedure
    bool event_set;      // Whether the window procedure set a message
};

// Widen a NUL-terminated utf8 string to a NUL-terminated utf-16 string that can
// be passed to win32 functions.
LPWSTR win32Widen(const char *utf8) {
    // TODO: error checking
    int count = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);

    LPWSTR utf16 = malloc(count * sizeof(WCHAR));

    // TODO: error checking
    MultiByteToWideChar(CP_UTF8, 0, utf8, -1, utf16, count);

    return utf16;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
    // Get the GGW_Window from the property set in GGW_createWindow.
    GGW_Window window = (GGW_Window)GetProp(hWnd, PROPERTY_LIST_NAME);

    switch (uMsg) {
    case WM_CLOSE: {
        // Generate a CLOSE_REQUESTED event
        window->event = (GGW_Event){.event_type = CLOSE_REQUESTED};
        window->event_set = true;
        return 0;
    }

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hDC = BeginPaint(hWnd, &ps);

        FillRect(hDC, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hWnd, &ps);
        return 0;
    }
    default: {
        // All unhandled messages get handled by the default window procedure.
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    }

    // No return to ensure all cases return a value
}

GGWResult GGW_createWindow(GGW_WindowCreateParams params,
                           GGW_Window *out_window) {
    // Get the module of the calling .exe file.
    // TODO: look into using GetModuleHandleEx to prevent race conditions if the
    // driver code is multithreaded.
    // TODO: Error handling.
    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASS wc = {
        .lpfnWndProc = WindowProc,
        .hInstance = hInstance,
        .lpszClassName = WINDOW_CLASS_NAME,
    };

    // TODO: look into using RegisterClassEx
    // TODO: Error handling
    RegisterClass(&wc);

    LPWSTR name_widened = win32Widen(params.name);

    HWND hWnd = CreateWindowEx(0,                   // window styles
                               WINDOW_CLASS_NAME,   // name of the window class
                               name_widened,        // name of the window
                               WS_OVERLAPPEDWINDOW, // window style
                               CW_USEDEFAULT, CW_USEDEFAULT, // window position
                               params.width, params.height,  // window size
                               NULL,                         // Parent window
                               NULL,                         // Menu
                               hInstance,                    // instance handle
                               NULL // additional application data
    );

    if (hWnd == NULL) {
        return GGWRESULT_WIN32_WINDOW_CREATION_FAILED;
    }

    free(name_widened);

    // TODO: change in the future to allow for the window to not always be
    // shown https://stackoverflow.com/questions/15240036/what-is-ncmdshow
    ShowWindow(hWnd, SW_SHOW);

    GGW_Window ggw_window = malloc(sizeof(struct GGW_Window_s));
    if (ggw_window == NULL) {
        return GGWRESULT_OUT_OF_MEMORY;
    }
    ggw_window->hInstance = hInstance;
    ggw_window->hWnd = hWnd;

    // This prop will later be read in the window procedure.
    SetProp(hWnd, PROPERTY_LIST_NAME, (HANDLE)ggw_window);

    *out_window = ggw_window;

    return GGWRESULT_SUCCESS;
}

void GGW_destroyWindow(GGW_Window window) { DestroyWindow(window->hWnd); }

GGWResult GGW_copyImageData(GGW_Window window, uint8_t *data,
                            GGW_ImageRegion targetRegion) {
    // TODO
    return GGWRESULT_SUCCESS;
}

void GGW_pollEvents(GGW_Window window) {}

int GGW_nextEvent(GGW_Window window, GGW_Event *out_event) {
    MSG msg = {};

    // Check if the message queue has a message, but don't wait for one if not.
    if (PeekMessage(&msg, window->hWnd, 0, 0, PM_REMOVE) > 0) {
        // Translate virtual key messages into character messages. Doesn't
        // modify msg, but sends a new message to be read later.
        TranslateMessage(&msg);

        // Send the message to the window procedure synchronously.
        DispatchMessage(&msg);

        // If the window sent back a GGW message, set out_event.
        if (window->event_set) {
            *out_event = window->event;
            window->event_set = false;
            return 1;
        }
    }
    return 0;
}
