#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *error = NULL;
        GdkPixbufAnimation * result; 
        const gchar *tmp = data;
        result = gdk_pixbuf_animation_new_from_file(tmp, &error);
        return 0;
}
