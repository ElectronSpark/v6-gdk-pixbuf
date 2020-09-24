#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stddef.h>
#include <stdint.h>
#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        GError *error = NULL;
        GdkPixbuf *pbuf_f, *pbuf_s;
        GFile *file;
        GInputStream *stream;

        char *tmpfile = fuzzer_get_tmpfile(data, size);
        pbuf_f = gdk_pixbuf_new_from_file((const gchar*)tmpfile, &error);
        if (error != NULL) {
                fuzzer_release_tmpfile(tmpfile);
                g_clear_error(&error);
                return 0;
        }

        file = g_file_new_for_path((const char*)tmpfile);
        stream = (GInputStream *)g_file_read(file, NULL, &error);
        if (error != NULL) {
                fuzzer_release_tmpfile(tmpfile);
                g_object_unref(file);
                g_clear_error(&error);
                return 0;
        }

        pbuf_s = gdk_pixbuf_new_from_stream (stream, NULL, &error);
        fuzzer_release_tmpfile(tmpfile);
        g_object_unref (pbuf_f);
        g_object_unref (pbuf_s);
        g_object_unref (stream);
        g_object_unref (file);
        g_clear_error(&error);
        return 0;
}
