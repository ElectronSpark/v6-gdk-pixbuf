#include <stddef.h>
#include <stdint.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "gdk-pixbuf/gdk-pixdata.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GIcon *icon;
        GInputStream *stream;
        GdkPixdata pixdata;
        GdkPixbuf *pixbuf;
        GError *error = NULL;

        gdk_pixdata_deserialize(&pixdata, size, data, &error);
        if (error != NULL) {
                g_clear_error(&error);
                return 0;
        }
        pixbuf = gdk_pixbuf_from_pixdata(&pixdata, FALSE, &error);
        if (error != NULL) {
                g_clear_error(&error);
                return 0;
        }
        icon = g_icon_deserialize(G_ICON(pixbuf));
        stream = g_loadable_icon_load (G_LOADABLE_ICON (icon), 0, NULL, NULL, &error);
        g_clear_object(&pixbuf);
        g_clear_object(&stream);
        g_clear_error(&error);
        return 0;
}

