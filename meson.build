project('grim',
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
    version: '>=6.1.20180127',
    required: true
)

if cc.has_header('ncursesw/curses.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_CURSES_H', true)
elif cc.has_header('ncursesw.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_H', true)
elif cc.has_header('curses.h', dependencies: cursesdep)
    config.set('HAVE_CURSES_H', true)
else
    error('ncursesw found, but no header found')
endif

paneldep = dependency(
    'panelw',
    required: true
)

if cc.has_header('ncursesw/panel.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_PANEL_H', true)
elif cc.has_header('ncurses/panel.h', dependencies: cursesdep)
    config.set('HAVE_NCURSES_PANEL_H', true)
elif cc.has_header('panel.h', dependencies: cursesdep)
    config.set('HAVE_PANEL_H', true)
else
    error('ncursesw found, but panel.h not found')
endif

menudep = dependency(
    'menuw',
    required: true
)

if cc.has_header('ncursesw/menu.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_MENU_H', true)
elif cc.has_header('ncurses/menu.h', dependencies: cursesdep)
    config.set('HAVE_NCURSES_MENU_H', true)
elif cc.has_header('menu.h', dependencies: cursesdep)
    config.set('HAVE_MENU_H', true)
else
    error('ncursesw found, but menu.h not found')
endif

formdep = dependency(
    'formw',
    required: true
)

if cc.has_header('ncursesw/form.h', dependencies: cursesdep)
    config.set('HAVE_NCURSESW_FORM_H', true)
elif cc.has_header('ncurses/form.h', dependencies: cursesdep)
    config.set('HAVE_NCURSES_FORM_H', true)
elif cc.has_header('form.h', dependencies: cursesdep)
    config.set('HAVE_FORM_H', true)
else
    error('ncursesw found, but form.h not found')
endif

cdkdep = dependency('cdk', required: false)
if not cdkdep.found()
    cdkdep = cc.find_library('cdk', required: false)
    if not cdkdep.found()
        cdkdep = cc.find_library('cdkw', required: false)
        if not cdkdep.found()
            error('libcdk not found')
        endif
    endif
endif

if cc.has_header('cdk.h')
    config.set('HAVE_CDK_H', true)
elif cc.has_header('cdk/cdk.h')
    config.set('HAVE_CDK_CDK_H', true)
else
    error('libcdk found, but cdk.h not found')
endif

threads_dep = declare_dependency()
if cc.check_header('threads.h')
    config.set('HAVE_THREADS', 'HAVE_THREADS_C11')
else
    threads_dep = dependency('threads', required: false)
    if cc.check_header('threads.h', dependencies: cursesdep)
        config.set('HAVE_THREADS', 'HAVE_THREADS_C11')
    elif threads_dep.found()
        config.set('HAVE_THREADS', 'HAVE_THREADS_PTHREADS')
    else
        error('No thread support found; must have pthreads or C11 threads')
    endif
endif

configure_file(
    input: 'src/config.h.in',
    output: 'config.h',
    configuration: config
)

add_global_arguments('-DHAVE_CONFIG_H',
    language: 'c')

executable('grim',
    'src/main.c',
    'src/cursesutils.c',
    'src/threadutils.c',
    'src/grim_menus.c',
    'src/grim_forms.c',
    dependencies: [paneldep, menudep, formdep, cursesdep, cdkdep, threads_dep]
)

thread_test = executable('thread_test',
    'src/thread_test.c',
    'src/threadutils.c',
    dependencies: [threads_dep]
)

test('threading test', thread_test)
