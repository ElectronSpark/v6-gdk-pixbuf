/* GdkPixbuf library - Glycin image loader
 *
 * Copyright (C) 2024 Red Hat, Inc.
 *
 * Authors: Matthias Clasen <mclasenredhat.com>
 * Authors: Jeremy Bícha <jbicha@debian.org>
 * Authors: 2007 Bastien Nocera <hadess@hadess.net>
 * Inspired by work by Ben Karel <web+moz@eschew.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include "io-glycin-utils.h"


#ifndef INCLUDE_glycin
#define MODULE_ENTRY(function) G_MODULE_EXPORT void function
#else
#define MODULE_ENTRY(function) void _gdk_pixbuf__glycin_jpeg2000_ ## function
#endif

MODULE_ENTRY (fill_vtable) (GdkPixbufModule *module)
{
  glycin_fill_vtable (module);
}

MODULE_ENTRY (fill_info) (GdkPixbufFormat *info)
{
  static const GdkPixbufModulePattern signature[] = {
    { "    jP", "!!!!  ", 100 },		/* file begins with 'jP' at offset 4 */
    { "\xff\x4f\xff\x51\x00", NULL, 100 },	/* file starts with FF 4F FF 51 00 */
    { NULL, NULL, 0 }
  };
  static const gchar *mime_types[] = {
    "image/jp2",
    "image/x-jp2-codestream",
    NULL
  };
  static const gchar *extensions[] = {
    "jp2",
    "j2c",
    "j2k",
    NULL
  };

  info->name = "jpeg2000";
  info->signature = (GdkPixbufModulePattern *) signature;
  info->description = "JPEG 2000";
  info->mime_types = (gchar **) mime_types;
  info->extensions = (gchar **) extensions;
  info->flags = GDK_PIXBUF_FORMAT_THREADSAFE;
  info->license = "LGPL";
}
