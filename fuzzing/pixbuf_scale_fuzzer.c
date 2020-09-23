#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>
#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GdkPixbuf *pixbuf;
        GError *error = NULL;
        uint8_t ch = data[0];
        int width = ch & 0xF;
        int height = (ch >> 4) & 0xF;
        if ((height <= 0) || (width <= 0)) {
                return 0;
        }
        char *tmpfile = fuzzer_get_tmpfile(data, size);
        pixbuf = gdk_pixbuf_new_from_file_at_scale(tmpfile, width, height, TRUE, &error);
        g_clear_error(&error);
        pixbuf = gdk_pixbuf_new_from_file_at_scale(tmpfile, width, height, FALSE, &error);
        g_clear_error(&error);
        g_clear_object(&pixbuf);
        fuzzer_release_tmpfile(tmpfile);
        return 0;
}
