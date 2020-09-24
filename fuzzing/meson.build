fuzz_targets = [
  'animation_fuzzer',
  'icc_fuzzer',
  'pixbuf_file_fuzzer',
  'pixbuf_scale_fuzzer',
  'short_gif_fuzzer',
  'stream_fuzzer'
]

deps = [gdk_pixbuf_deps, gdkpixbuf_dep]
fuzz_args = ['-fsanitize=fuzzer,address']
#fuzz_args = ['-fprofile-instr-generate', '-fcoverage-mapping']

foreach target_name : fuzz_targets
  exe = executable(target_name, [target_name + '.c'],
  #exe = executable(target_name, ['/usr/local/google/home/ceyhunalp/workspace/Fuzzer/standalone/StandaloneFuzzTargetMain.c', target_name + '.c'],
    include_directories: [root_inc, gdk_pixbuf_inc],
    c_args: fuzz_args,
    link_args: fuzz_args,
    dependencies: deps,
    )
endforeach
