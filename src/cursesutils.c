#ifdef HAVE_CONFIG_H
# include "config.h"
#else
# error config.h not found, please run configure
#endif
#include "cursesutils.h"

WINDOW *create_window(int height, int width, int starty, int startx)
{
	WINDOW *win = newwin(height, width, starty, startx);
	wrefresh(win);

	return win;
}

WINDOW *create_window_border(int height, int width, int starty, int startx)
{
	WINDOW *win = newwin(height, width, starty, startx);
	box(win, 0, 0);
	wrefresh(win);

	return win;
}

void destroy_window(WINDOW *win)
{	
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
}
