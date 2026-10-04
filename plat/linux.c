#include "../window.h"
#include "wayland.h"
#include "x11.h"

#define SWITCH_BACKEND(window, WL, X11)                                        \
    switch (*((GGW_Linux_Backend *)window)) {                                  \
    case GGW_BACKEND_WAYLAND:                                                  \
        return (WL);                                                           \
    case GGW_BACKEND_X11:                                                      \
        return (X11);                                                          \
    }

typedef enum {
    GGW_BACKEND_WAYLAND,
    GGW_BACKEND_X11,
} GGW_Linux_Backend;

GGWResult
GGW_createWindow(GGW_WindowCreateParams params, GGW_Window *out_window) {
    GGWResult wl_res = GGW_plat_wayland_createWindow(params, out_window);
    if (wl_res != GGWRESULT_BACKEND_UNVAILABLE) {
        return wl_res;
    }

    return GGW_plat_X11_createWindow(params, out_window);
}

void GGW_destroyWindow(GGW_Window window){SWITCH_BACKEND(
    window, GGW_plat_wayland_destroyWindow(window),
    GGW_plat_X11_destroyWindow(window)
)}

GGWResult GGW_copyImageData(
    GGW_Window window, uint8_t *data, GGW_ImageRegion targetRegion
) {
    SWITCH_BACKEND(
        window, GGW_plat_wayland_copyImageData(window, data, targetRegion),
        GGW_plat_X11_copyImageData(window, data, targetRegion)
    )
}

void GGW_pollEvents(GGW_Window window) {
    SWITCH_BACKEND(
        window, GGW_plat_wayland_pollEvents(window),
        GGW_plat_X11_pollEvents(window)
    )
}

int GGW_nextEvent(GGW_Window window, GGW_Event *out_event) {
    SWITCH_BACKEND(
        window, GGW_plat_wayland_nextEvent(window, out_event),
        GGW_plat_X11_nextEvent(window, out_event)
    )
}
