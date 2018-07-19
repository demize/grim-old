#ifndef EWFIMAGER_CURSES_H
#define EWFIMAGER_CURSES_H

#include "config.h"

WINDOW *create_window(int height, int width, int starty, int startx);
WINDOW *create_window_border(int height, int width, int starty, int startx);
void destroy_window(WINDOW *win);

#endif