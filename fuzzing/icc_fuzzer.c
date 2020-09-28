#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *error = NULL;
        GdkPixbuf *pixbuf;
        const gchar *profile;

        GdkPixbufLoader *loader = gdk_pixbuf_loader_new();
        gdk_pixbuf_loader_write(loader, data, size, &error);
        if (error != NULL) {
                g_object_unref(loader);
                g_clear_error(&error);
                return 0;
        }
        gdk_pixbuf_loader_close(loader, &error);
        if (error != NULL) {
                g_object_unref(loader);
                g_clear_error(&error);
                return 0;
        }
        pixbuf = gdk_pixbuf_loader_get_pixbuf(loader);
        if (pixbuf == NULL) {
                g_object_unref(loader);
                g_clear_error(&error);
                return 0;
        }
        profile = gdk_pixbuf_get_option(pixbuf, "icc-profile");
        profile = gdk_pixbuf_get_option(pixbuf, data);
        g_object_unref(pixbuf);
        g_clear_error(&error);
        return 0;
}

