#ifndef GGW_PLAT_WAYLAND_H
#define GGW_PLAT_WAYLAND_H

#include "../window.h"

GGWResult GGW_plat_wayland_createWindow(GGW_WindowCreateParams params,
                                        GGW_Window *out_window);

void GGW_plat_wayland_destroyWindow(GGW_Window window);

GGWResult GGW_plat_wayland_copyImageData(GGW_Window window, uint8_t *data,
                                         GGW_ImageRegion targetRegion);

void GGW_plat_wayland_pollEvents(GGW_Window window);

int GGW_plat_wayland_nextEvent(GGW_Window window, GGW_Event *out_event);

#endif
