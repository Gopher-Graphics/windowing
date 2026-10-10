#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include "../window.h"
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

#define GGWCHECK(f)                                                            \
    GGWResult res = (f);                                                       \
    if (res != GGWRESULT_SUCCESS) {                                            \
        fprintf(stderr, "Error occured while executing expression " #f);       \
        return 1;                                                              \
    }

int main(void) {
    // sigset_t mask;
    // sigfillset(&mask);
    // sigprocmask(SIG_SETMASK, &mask, NULL);

    GGW_Window window;
    GGWCHECK(GGW_createWindow(
        (GGW_WindowCreateParams){
            .name = "Test!",
        },
        &window));
    
    bool close_requested = false;
    while(!close_requested) {
        GGW_pollEvents(window);
        GGW_Event event;
        while(GGW_nextEvent(window, &event)) {
            if(event.event_type == CLOSE_REQUESTED) {
                close_requested = true;
            }
        }
        struct timespec sleep_time = {
            .tv_sec = 0,
            .tv_nsec = 1000000,
        };
        nanosleep(&sleep_time, NULL);
    }

    GGW_destroyWindow(window);
}
