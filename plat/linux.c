#include "../window.h"
#include "x11.h"
#include "wayland.h"

typedef enum {
  GGW_Frontend_Wayland,
  GGW_Frontend_X11,
} GGW_Linux_Frontend;

GGWError GGW_createWindow(GGW_WindowCreateParams params, GGW_Window* out_window) {
  
}
