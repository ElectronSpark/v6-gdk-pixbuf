#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>
#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *error = NULL;
        GdkPixbufAnimation *result;

        char *tmpfile = fuzzer_get_tmpfile(data, size);
        result = gdk_pixbuf_animation_new_from_file(tmpfile, &error);
        g_clear_error(&error);
        if (result != NULL) {
                g_object_unref(result);
        }
        fuzzer_release_tmpfile(tmpfile);
        return 0;
}
