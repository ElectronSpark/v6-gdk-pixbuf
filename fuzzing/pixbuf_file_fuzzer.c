#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>

#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GdkPixbuf *pixbuf;
        GError *error = NULL;
        char *tmpfile = fuzzer_get_tmpfile(data, size);
        pixbuf = gdk_pixbuf_new_from_file(tmpfile, &error);
        /*pixbuf = gdk_pixbuf_new_from_file(data, &error);*/
        fuzzer_release_tmpfile(tmpfile);
        g_clear_error(&error);
        g_clear_object(&pixbuf);
        return 0;
}
