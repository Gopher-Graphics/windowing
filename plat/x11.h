#ifndef GGW_PLAT_X11_H
#define GGW_PLAT_X11_H

#include "../window.h"

GGWResult GGW_plat_X11_createWindow(GGW_WindowCreateParams params,
                                    GGW_Window *out_window);

void GGW_plat_X11_destroyWindow(GGW_Window window);

GGWResult GGW_plat_X11_copyImageData(GGW_Window window, uint8_t *data,
                                     GGW_ImageRegion targetRegion);

void GGW_plat_X11_pollEvents(GGW_Window window);

int GGW_plat_X11_nextEvent(GGW_Window window, GGW_Event *out_event);

#endif
