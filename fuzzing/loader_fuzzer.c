#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *err = NULL;
        GdkPixbufLoader *loader = gdk_pixbuf_loader_new();

        if (!gdk_pixbuf_loader_write(loader, data, size, &err)) {
                g_clear_object(&loader);
                g_clear_error(&err);
                return 0;
        }
        gdk_pixbuf_loader_close(loader, &err);
        g_clear_object(&loader);
        g_clear_error(&err);
        return 0;
}

