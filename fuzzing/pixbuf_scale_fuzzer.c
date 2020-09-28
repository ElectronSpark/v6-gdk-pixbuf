#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>
#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        if (size <= 4) {
                return 0;
        }
        int scale;
        GError *error = NULL;
        GdkPixbuf *pixbuf;
        memcpy(&scale, data, sizeof(scale));

        char *tmpfile = fuzzer_get_tmpfile(data, size);
        pixbuf = gdk_pixbuf_new_from_file_at_scale(tmpfile, scale, scale, TRUE, &error);
        g_clear_error(&error);
        pixbuf = gdk_pixbuf_new_from_file_at_scale(tmpfile, scale, scale, FALSE, &error);
        g_clear_error(&error);
        fuzzer_release_tmpfile(tmpfile);
        if (pixbuf != NULL) {
                g_clear_object(&pixbuf);
        }
        return 0;
}
