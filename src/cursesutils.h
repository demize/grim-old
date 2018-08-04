#ifndef GRIM_CURSES_H
#define GRIM_CURSES_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#else
# error config.h not found, please run configure
#endif

WINDOW *create_window(int height, int width, int starty, int startx);
WINDOW *create_window_border(int height, int width, int starty, int startx);
void destroy_window(WINDOW *win);

#endif
