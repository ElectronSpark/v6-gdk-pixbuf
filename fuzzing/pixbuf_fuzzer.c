#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>

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
                g_clear_object(&pixbuf);
        }
        return 0;
}
