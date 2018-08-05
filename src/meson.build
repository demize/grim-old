project('ewfimager',
    'c',
    version: '0.1',
    license: 'MIT',
    default_options: ['c_std=c11']
)

cc = meson.get_compiler('c')
config = configuration_data()
config.set('PACKAGE_VERSION', meson.project_version())

cursesdep = dependency(
    'ncursesw',
    version: '>=6.1.20180127'
)

if not cursesdep.found()
    error('ncursesw not found')
endif

if cc.has_header('ncursesw/curses.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_CURSES_H', true)
elif cc.has_header('ncursesw.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_H', true)
else
    error('ncursesw found, but no header found')
endif

if cc.has_header('ncursesw/panel.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_PANEL_H', true)
elif cc.has_header('ncurses/panel.h', dependencies: cursesdep)
    config.set('HAVE_NCURSES_PANEL_H', true)
elif cc.has_header('panel.h', dependencies: cursesdep)
    config.set('HAVE_PANEL_H', true)
else
    error('ncursesw found, but panel.h not found')
endif

if cc.has_header('ncursesw/menu.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_MENU_H', true)
elif cc.has_header('ncurses/menu.h', dependencies: cursesdep)
    config.set('HAVE_NCURSES_MENU_H', true)
elif cc.has_header('menu.h', dependencies: cursesdep)
    config.set('HAVE_MENU_H', true)
else
    error('ncursesw found, but menu.h not found')
endif

if cc.has_header('ncursesw/form.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_FORM_H', true)
elif cc.has_header('ncurses/form.h', dependencies: cursesdep)
    config.set('HAVE_NCURSES_FORM_H', true)
elif cc.has_header('form.h', dependencies: cursesdep)
    config.set('HAVE_FORM_H', true)
else
    error('ncursesw found, but form.h not found')
endif

threads_dep = declare_dependency()
if cc.check_header('threads.h')
    config.set('HAVE_THREADS', 'HAVE_THREADS_C11')
else
    threads_dep = dependency('threads')
    if not threads_dep.found()
        error('No thread support found; must have pthreads or C11 threads')
    else
        config.set('HAVE_THREADS', 'HAVE_THREADS_PTHREADS')
    endif
endif

configure_file(
    input: 'config.h.in',
    output: 'config.h',
    configuration: config
)

add_global_arguments('-DHAVE_CONFIG_H',
    language: 'c')

executable('ewfimager',
    'main.c',
    'cursesutils.c',
    'threadutils.c',
    dependencies: [cursesdep, threads_dep]
)