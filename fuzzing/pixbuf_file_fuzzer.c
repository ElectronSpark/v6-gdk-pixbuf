#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GdkPixbuf *pixbuf;
        GError *error = NULL;
        pixbuf = gdk_pixbuf_new_from_file(data, &error);
        g_clear_error(&error);
        g_clear_object(&pixbuf);
        return 0;
}
