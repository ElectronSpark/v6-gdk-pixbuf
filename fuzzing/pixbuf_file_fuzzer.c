#include <stdint.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    char *tmpfile = fuzzer_get_tmpfile(data, size);
    pixbuf = gdk_pixbuf_new_from_file(tmpfile, &error);
    if (pixbuf == NULL) {
        g_clear_error(&error);
        fuzzer_release_tmpfile(tmpfile);
        return 0;
    }
    gdk_pixbuf_get_width(pixbuf);
    gdk_pixbuf_get_height(pixbuf);
    gdk_pixbuf_get_bits_per_sample(pixbuf);
    g_clear_object(&pixbuf);
    fuzzer_release_tmpfile(tmpfile);
    return 0;
}
