#include "../window.h"
#include "x11.h"
#include "wayland.h"

typedef enum {
  GGW_Frontend_Wayland,
  GGW_Frontend_X11,
} GGW_Linux_Frontend;

GGWResult GGW_createWindow(GGW_WindowCreateParams params, GGW_Window* out_window) {
  return GGWRESULT_SUCCESS;
}

void GGW_destroyWindow(GGW_Window window) {
  
}

GGWResult GGW_copyImageData(uint8_t* data, GGW_ImageRegion targetRegion) {
  return GGWRESULT_SUCCESS;
}

void GGW_pollEvents(void) {}

int GGW_nextEvent(GGW_Event* out_event) {
  return 0;
}
