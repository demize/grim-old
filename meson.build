project('grim',
    'c',
    version: '0.1',
    license: 'MIT',
    default_options: ['c_std=c11']
)

cc = meson.get_compiler('c')
config = configuration_data()
config.set('PACKAGE_VERSION', meson.project_version())

newtdep = dependency(
    'libnewt',
    required: true
)

threads_dep = declare_dependency()
if cc.check_header('threads.h')
    config.set('HAVE_THREADS', 'HAVE_THREADS_C11')
else
    threads_dep = dependency('threads', required: false)
    if cc.check_header('threads.h', dependencies: threads_dep)
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
    'src/windowutils.c',
    'src/threadutils.c',
    'src/grim_menus.c',
    'src/grim_forms.c',
    dependencies: [newtdep, threads_dep]
)

thread_test = executable('thread_test',
    'src/thread_test.c',
    'src/threadutils.c',
    dependencies: [threads_dep]
)

test('threading test', thread_test)
