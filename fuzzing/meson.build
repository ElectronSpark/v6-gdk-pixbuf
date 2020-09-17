fuzz_targets = [
  'animation_fuzzer',
  'loader_fuzzer',
  'pixdata_fuzzer',
]

deps = [gdk_pixbuf_deps, gdkpixbuf_dep]
fuzz_inc = include_directories(['/usr/include/glib-2.0', '/usr/include/gtk-2.0', '/usr/lib/x86_64-linux-gnu/glib-2.0/include'])
fuzz_args = ['-fsanitize=fuzzer,address']

foreach target_name : fuzz_targets
  exe = executable(target_name, [target_name + '.c'],
    include_directories: [root_inc, gdk_pixbuf_inc, fuzz_inc],
    c_args: fuzz_args,
    link_args: fuzz_args
    dependencies: deps,
    )
endforeach
