#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>
#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *error = NULL;
        GdkPixbufAnimation *result;

        char *tmpfile = fuzzer_get_tmpfile(data, size);
        result = gdk_pixbuf_animation_new_from_file(tmpfile, &error);
        fuzzer_release_tmpfile(tmpfile);
        if (error != NULL) {
                g_clear_error(&error);
                return 0;
        }
        g_object_unref(result);
        return 0;
}
