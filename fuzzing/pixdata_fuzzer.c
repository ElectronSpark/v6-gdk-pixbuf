#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "gdk-pixbuf/gdk-pixdata.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        const int SIZE = 2;
        gboolean flags[] = {TRUE, FALSE};

        GdkPixdata pixdata;
        GdkPixbuf *pixbuf;
        GError *error = NULL;

        if (size < GDK_PIXDATA_HEADER_LENGTH) {
                return 0;
        }
        gdk_pixdata_deserialize(&pixdata, size, data, &error);
        if (error != NULL) {
                g_clear_error(&error);
                return 0;
        }
        for (int i = 0; i < SIZE; i++) {
                pixbuf = gdk_pixbuf_from_pixdata(&pixdata, flags[i], &error);
                g_clear_object(&pixbuf);
                g_clear_error(&error);
        }
        return 0;
}

