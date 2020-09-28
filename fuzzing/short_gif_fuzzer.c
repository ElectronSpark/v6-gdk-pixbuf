#include <stddef.h>
#include <stdint.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *error = NULL;
        GdkPixbufLoader *loader;
        GIOStatus read_status;

        char *tmpfile = fuzzer_get_tmpfile(data, size);
        GIOChannel* channel = g_io_channel_new_file(tmpfile, "r", NULL);
        fuzzer_release_tmpfile(tmpfile);

        g_io_channel_set_encoding(channel, NULL, NULL);
        loader = gdk_pixbuf_loader_new_with_type("gif", &error);
        if (error != NULL) {
                g_object_unref(loader);
                g_io_channel_unref(channel);
                g_clear_error(&error);
                return 0;
        }
        gsize bytes_read = 0;
        guchar* buffer = g_malloc(size);
        if (buffer != NULL) {
                read_status = g_io_channel_read_chars(channel, (gchar*)buffer, size, &bytes_read, NULL);
                gdk_pixbuf_loader_write(loader, buffer, bytes_read, &error);
        }
        g_free(buffer);
        g_io_channel_unref(channel);
        gdk_pixbuf_loader_close(loader, NULL);
        g_object_unref(loader);
        g_clear_error(&error);
        return 0;
}
