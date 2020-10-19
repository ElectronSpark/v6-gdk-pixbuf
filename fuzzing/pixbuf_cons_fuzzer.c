#include <stdint.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#define WIDTH 1
#define HEIGHT 2
#define ROWSTRIDE (WIDTH * 4)

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (!(size >= WIDTH * HEIGHT * 4)) {
        return 0;
    }
    GdkPixbuf *pixbuf;
    GBytes *bytes;
    bytes = g_bytes_new_with_free_func(data, size, g_free, NULL);
    pixbuf = g_object_new(GDK_TYPE_PIXBUF,
            "width", WIDTH,
            "height", HEIGHT,
            "rowstride", ROWSTRIDE,
            "bits-per-sample", 8,"n-channels", 3,
            "has-alpha", TRUE,
            "pixel-bytes", bytes,
            NULL);
    if (pixbuf != NULL) {
        gdk_pixbuf_get_pixels(pixbuf);
        gdk_pixbuf_get_width(pixbuf);
        gdk_pixbuf_get_height(pixbuf);
        gdk_pixbuf_get_rowstride(pixbuf);
        g_object_unref(pixbuf);
    }
    return 0;
}
