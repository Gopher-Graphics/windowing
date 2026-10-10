#include "../window.h"
#include "linux.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xcb/xcb.h>

struct GGW_Window_XCB_Atoms {
    xcb_atom_t wm_protocols_atom;
    xcb_atom_t wm_delete_window_atom;
};

struct GGW_Window_XCB {
    GGW_Linux_Backend backend;
    xcb_connection_t *connection;
    xcb_screen_t *screen;
    xcb_window_t window;
    struct GGW_Window_XCB_Atoms atoms;
};

GGWResult GGW_plat_X11_createWindow(GGW_WindowCreateParams params,
                                    GGW_Window *out_window) {
    if (((params.width == 0) != (params.height == 0)) || params.name == NULL) {
        return GGWRESULT_INVALID_PARAMS;
    }

    // connect to x11
    xcb_connection_t *connection = xcb_connect(NULL, NULL);

    if (xcb_connection_has_error(connection)) {
        xcb_disconnect(connection);
        return GGWRESULT_BACKEND_UNVAILABLE;
    }

    // request atoms for delete window and protocols
    const char *const WM_PROTOCOLS = "WM_PROTOCOLS";
    xcb_intern_atom_cookie_t wmproto_atom_cookie =
        xcb_intern_atom(connection, 0, strlen(WM_PROTOCOLS), WM_PROTOCOLS);

    const char *const WM_DELETE_WINDOW = "WM_DELETE_WINDOW";
    xcb_intern_atom_cookie_t wmdw_atom_cookie = xcb_intern_atom(
        connection, 0, strlen(WM_DELETE_WINDOW), WM_DELETE_WINDOW);

    const xcb_setup_t *setup = xcb_get_setup(connection);
    xcb_screen_iterator_t sc_iter = xcb_setup_roots_iterator(setup);
    xcb_screen_t *screen_data = sc_iter.data;

    if (params.width == 0 && params.height == 0) {
        params.width = screen_data->width_in_pixels / 2;
        params.height = screen_data->height_in_pixels / 2;
    }

    xcb_window_t window = xcb_generate_id(connection);

    // declare mask for events: only expose events for now
    uint32_t mask = XCB_CW_EVENT_MASK;
    uint32_t valwin[1] = {XCB_EVENT_MASK_EXPOSURE};
    xcb_create_window(connection, XCB_COPY_FROM_PARENT, window,
                      screen_data->root, 0, 0, params.width, params.height, 10,
                      XCB_WINDOW_CLASS_INPUT_OUTPUT, screen_data->root_visual,
                      mask, valwin);

    xcb_change_property(connection, XCB_PROP_MODE_REPLACE, window,
                        XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
                        strlen(params.name), params.name);

    // recieve atoms for delete window and protocols
    xcb_intern_atom_reply_t *wmproto_atom_reply =
        xcb_intern_atom_reply(connection, wmproto_atom_cookie, NULL);
    xcb_atom_t wm_protocols_atom = wmproto_atom_reply->atom;
    free(wmproto_atom_reply);

    xcb_intern_atom_reply_t *wmdw_atom_reply =
        xcb_intern_atom_reply(connection, wmdw_atom_cookie, NULL);
    xcb_atom_t wm_delete_window_atom = wmdw_atom_reply->atom;
    free(wmdw_atom_reply);

    // add WM_DELETE_WINDOW to list of protocols
    xcb_change_property(connection, XCB_PROP_MODE_REPLACE, window,
                        wm_protocols_atom, XCB_ATOM_ATOM, 32, 1,
                        &wm_delete_window_atom);

    // show the window
    xcb_map_window(connection, window);

    xcb_flush(connection);

    struct GGW_Window_XCB *window_s = malloc(sizeof(struct GGW_Window_XCB));

    *window_s = (struct GGW_Window_XCB){
        .backend = GGW_BACKEND_X11,
        .connection = connection,
        .screen = screen_data,
        .window = window,
        .atoms =
            (struct GGW_Window_XCB_Atoms){
                .wm_protocols_atom = wm_protocols_atom,
                .wm_delete_window_atom = wm_delete_window_atom,
            },
    };
    *out_window = (GGW_Window)window_s;

    return GGWRESULT_SUCCESS;
}

void GGW_plat_X11_destroyWindow(GGW_Window in_window) {
    struct GGW_Window_XCB *window = (struct GGW_Window_XCB *)in_window;
    xcb_destroy_window(window->connection, window->window);
    xcb_disconnect(window->connection);
    free(window);
}

GGWResult GGW_plat_X11_copyImageData(GGW_Window window, uint8_t *data,
                                     GGW_ImageRegion targetRegion) {
    return GGWRESULT_SUCCESS;
}

void GGW_plat_X11_pollEvents(GGW_Window window) {
    // TODO implement this
}

int GGW_plat_X11_nextEvent(GGW_Window in_window, GGW_Event *out_event) {
    struct GGW_Window_XCB *window = (struct GGW_Window_XCB *)in_window;
    xcb_generic_event_t *event = xcb_poll_for_event(window->connection);
    if (event == NULL) {
        return 0;
    }

    switch (event->response_type & ~0x80) {
    case XCB_EXPOSE:
        // TODO draw to the screen
        break;

    case XCB_CLIENT_MESSAGE:
        xcb_client_message_event_t *cm_ev = (xcb_client_message_event_t *)event;
        if (cm_ev->type != window->atoms.wm_protocols_atom) {
            break;
        }
        if (cm_ev->data.data32[0] == window->atoms.wm_protocols_atom) {
            break;
        }
        *out_event = (GGW_Event){
            .event_type = CLOSE_REQUESTED,
        };
        return 1;

    default:
        break;
    }

    return 0;
}
