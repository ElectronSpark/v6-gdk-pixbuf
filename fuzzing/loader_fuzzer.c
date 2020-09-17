#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *err = NULL;
        GdkPixbufLoader *loader;
        loader = gdk_pixbuf_loader_new();
        gdk_pixbuf_loader_write(loader, data, size, &err);
        if (err == NULL) {
                gdk_pixbuf_loader_close(loader, &err);
        }
        return 0;
}

