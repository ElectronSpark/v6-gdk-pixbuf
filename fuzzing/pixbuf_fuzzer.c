#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>

static const char fname[] = "./input.txt";

void write_file(const uint8_t *data, size_t size) {
        FILE *f;
        f = fopen(fname, "w");
        fwrite(data, sizeof(uint8_t), size, f);
        fclose(f);
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *error = NULL;
        GdkPixbuf *pixbuf;
        uint8_t ch = data[0];
        int width = ch & 0xF;
        int height = (ch >> 4) & 0xF;

        if ((height <= 0) || (width <= 0)) {
                return 0;
        }

        const gchar *in_file = (const gchar*) fname;
        write_file(data, size);
        
        pixbuf = gdk_pixbuf_new_from_file_at_scale(in_file, width, height, TRUE, &error);
        g_clear_object(&pixbuf);
        g_clear_error(&error);
        pixbuf = gdk_pixbuf_new_from_file_at_scale(in_file, width, height, FALSE, &error);
        g_clear_error(&error);
        g_clear_object(&pixbuf);
        return 0;
}
