#include "wayland.h"
#include "linux.h"

GGWResult GGW_plat_wayland_createWindow(GGW_WindowCreateParams params,
                                        GGW_Window *out_window) {
    return GGWRESULT_BACKEND_UNVAILABLE;
}

void GGW_plat_wayland_destroyWindow(GGW_Window in_window) {}

GGWResult GGW_plat_wayland_copyImageData(GGW_Window window, uint8_t *data,
                                         GGW_ImageRegion targetRegion) {
    return GGWRESULT_SUCCESS;
}

void GGW_plat_wayland_pollEvents(GGW_Window window) {}

int GGW_plat_wayland_nextEvent(GGW_Window window, GGW_Event *out_event) {
    return 0;
}
