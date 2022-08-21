#include "x11.h"

void x11_init(void) {
    disp = XOpenDisplay(0);
	rwin = XRootWindow(disp, XDefaultScreen(disp));
}

void mouse_move(uint16_t x, uint16_t y) {
    XTestFakeMotionEvent(disp, 0, x, y, CurrentTime);
    XFlush(disp);
}

void mouse_event(ic_mouse_c in) {
    switch (in) {
        case icmc_leftd:
            XTestFakeButtonEvent(disp, 1, True, CurrentTime);
            break;
        case icmc_leftu:
            XTestFakeButtonEvent(disp, 1, False, CurrentTime);
            break;
        case icmc_rightd:
            XTestFakeButtonEvent(disp, 3, True, CurrentTime);
            break;
        case icmc_rightu:
            XTestFakeButtonEvent(disp, 3, False, CurrentTime);
            break;
        default:
            break;
    }

    XFlush(disp);
}

ic_cur_pos mouse_get_cursor(void) {
    int win_x, win_y, root_x, root_y = 0;
    unsigned int mask = 0;
    Window child_win, root_win;
    XQueryPointer(disp, rwin, &child_win, &root_win, &root_x, &root_y, &win_x, &win_y, &mask);

    ic_cur_pos cursor_pos = {
        .x = root_x,
        .y = root_y
    };

    return cursor_pos;
}