#ifndef EWFIMAGER_SYSTEM_H
#define EWFIMAGER_SYSTEM_H

#if defined HAVE_NCURSESW_CURSES_H
# include <ncursesw/curses.h>
#elif defined HAVE_NCURSESW_H
# include <ncursesw.h>
#else
# error "ncursesw required"
#endif

#if defined HAVE_NCURSESW_PANEL_H
# include <ncursesw/panel.h>
#elif defined HAVE_NCURSES_PANEL_H
# include <ncurses/panel.h>
#elif defined HAVE_PANEL_H
# include <panel.h>
#else
# error "SysV-compatible Curses Panel header file required"
#endif

#if defined HAVE_NCURSESW_MENU_H
# include <ncursesw/menu.h>
#elif defined HAVE_NCURSES_MENU_H
# include <ncurses/menu.h>
#elif defined HAVE_MENU_H
# include <menu.h>
#else
# error "SysV-compatible Curses Menu header file required"
#endif

#if defined HAVE_NCURSESW_FORM_H
# include <ncursesw/form.h>
#elif defined HAVE_NCURSES_FORM_H
# include <ncurses/form.h>
#elif defined HAVE_FORM_H
# include <form.h>
#else
# error "SysV-compatible Curses Form header file required"
#endif

#endif
