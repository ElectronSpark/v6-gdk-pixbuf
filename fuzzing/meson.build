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
    include_directories: [root_inc, gdk_pixbuf_inc, fuzz_inc],
    c_args: extra_c_args,
    dependencies: deps,
    #link_args: fuzzer_ldflags,
    )
endforeach

#anim_fuzzer = executable('anim_fuzzer',
  #'./animation_fuzzer.c',
  ##include_directories: [root_inc, '../gdk-pixbuf', fuzz_inc],
  #include_directories: [root_inc, '../../gdk-pixbuf', fuzz_inc],
  #dependencies: test_deps,
  #link_args: fuzzer_ldflags,
  #c_args: common_cflags,
  #)

#loader_fuzzer = executable('loader_fuzzer',
  ##'libfuzzer/loader_fuzzer.c',
  #'./loader_fuzzer.c',
  ##include_directories: [root_inc, '../gdk-pixbuf', fuzz_inc],
  #include_directories: [root_inc, '../../gdk-pixbuf', fuzz_inc],
  #dependencies: test_deps,
  #link_args: fuzzer_ldflags,
  #c_args: common_cflags,
  #)

#pixdata_fuzzer = executable('pixdata_fuzzer',
  #'./pixdata_fuzzer.c',
  ##include_directories: [root_inc, '../gdk-pixbuf', fuzz_inc],
  #include_directories: [root_inc, '../../gdk-pixbuf', fuzz_inc],
  #dependencies: test_deps,
  #link_args: fuzzer_ldflags,
  #c_args: common_cflags,
  #)
