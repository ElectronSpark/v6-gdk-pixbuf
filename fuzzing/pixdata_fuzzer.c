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

        gdk_pixdata_deserialize(&pixdata, size, data, &error);
        if (error != NULL) {
                return 0;
        }
        for (int i = 0; i < SIZE; i++) {
                pixbuf = gdk_pixbuf_from_pixdata(&pixdata, flags[i], &error);
                if (error != NULL) {
                        continue;
                }
                g_clear_object(&pixbuf);
        }
        return 0;
}

