#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "fuzzer_temp_file.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        const gchar *profile;
        GdkPixbuf *pixbuf;
        GError *error = NULL;
        char *tmpfile = fuzzer_get_tmpfile(data, size);

        GdkPixbufLoader *loader = gdk_pixbuf_loader_new();
        gdk_pixbuf_loader_write(loader, (const guchar*) tmpfile, size, &error);
        if (error != NULL) {
                fuzzer_release_tmpfile(tmpfile);
                g_clear_object(&loader);
                g_clear_error(&error);
                return 0;
        }
        gdk_pixbuf_loader_close(loader, &error);

        pixbuf = gdk_pixbuf_loader_get_pixbuf (loader);
        profile = gdk_pixbuf_get_option (pixbuf, "icc-profile");

        fuzzer_release_tmpfile(tmpfile);
        g_clear_object(&loader);
        g_clear_error(&error);
        return 0;
}

