fuzz_targets = [
  'animation_fuzzer',
  'loader_fuzzer',
  'pixdata_fuzzer',
]

deps = [gdk_pixbuf_deps, gdkpixbuf_dep]

extra_sources = ['driver.c']
extra_c_args = cc.get_supported_link_arguments('-Werror=unused-function')
#fuzzer_ldflags = ['-fsanitize=fuzzer,address']

fuzz_inc = include_directories(['/usr/include/glib-2.0', '/usr/include/gtk-2.0', '/usr/lib/x86_64-linux-gnu/glib-2.0/include'])

foreach target_name : fuzz_targets
  exe = executable(target_name, [extra_sources, target_name + '.c'],
  #exe = executable(target_name, [target_name + '.c'],
    include_directories: [root_inc, gdk_pixbuf_inc, fuzz_inc],
    c_args: extra_c_args,
    dependencies: deps,
    #link_args: fuzzer_ldflags,
    )
endforeach
