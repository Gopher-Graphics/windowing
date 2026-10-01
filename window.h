#ifndef GGW_WINDOW_H
#define GGW_WINDOW_H

#include "keycodes.h"
#include <stdint.h>

typedef struct GGW_Window_s *GGW_Window;

typedef enum {
    GGWRESULT_SUCCESS,
    GGWRESULT_OUT_OF_MEMORY,
    GGWRESULT_INVALID_TARGET_REGION,
    GGWRESULT_BACKEND_UNVAILABLE,
} GGWResult;

typedef uint16_t GGW_ImageDimension;

typedef struct {
    GGW_ImageDimension offsetX;
    GGW_ImageDimension offsetY;
    GGW_ImageDimension width;
    GGW_ImageDimension height;
} GGW_ImageRegion;

/**
 * Params required to create a window
 * name:   the name of the window
 * width:  the width of the window
 * height: the height of the window
 */
typedef struct {
    const char *name;
    GGW_ImageDimension width;
    GGW_ImageDimension height;
} GGW_WindowCreateParams;

/**
 * Creates a window.
 *
 * params:     The parameters for the window that will be created.
 * out_window: A pointer to the place where the window handle will be placed
 *
 * Possible errors: (TODO fill this out)
 */
GGWResult GGW_createWindow(GGW_WindowCreateParams params,
                           GGW_Window *out_window);

/**
 * Destroys a window. Cannot error.
 *
 * window: The window to be destroyed.
 */
void GGW_destroyWindow(GGW_Window window);

/**
 * Copies image data onto a window.
 *
 * data:         The data to be copied onto the window. This is in BGRA format.
 * targetRegion: The region of the window that the data will be copied to.
 */
GGWResult GGW_copyImageData(GGW_Window window, uint8_t *data,
                            GGW_ImageRegion targetRegion);

typedef enum {
    REDRAW_REQUESTED,
    KEY_PRESSED,
    KEY_RELEASED,
    MOUSE_MOVED,
    MOUSE_CLICKED,
} GGW_EventType;

typedef union {
    GGW_Keycode event_key;
} GGW_EventPayload;

typedef struct {
    GGW_EventType event_type;
    GGW_EventPayload payload;
} GGW_Event;

/**
 * Function that tells the backend that this is a good time to check for events.
 * The backend can ignore this if it is unnecessary.
 */
void GGW_pollEvents(GGW_Window window);

/**
 * Gets a single event and writes it to out_event.
 * If there is no event, returns 0 and the data in out_event is undefined.
 *
 * out_event: a pointer to the location to write the next event to.
 * Returns: non-zero if there was an event on execution, and zero if there was
 * no event on execution.
 */
int GGW_nextEvent(GGW_Window window, GGW_Event *out_event);

#endif // GGW_WINDOW_H
