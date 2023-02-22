/* GDK - The GIMP Drawing Kit
 *
 * Copyright (C) 2017 Benjamin Otte <otte@gnome.org>
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GDK_CONTENT_PROVIDER_IMPL_H__
#define __GDK_CONTENT_PROVIDER_IMPL_H__

#if !defined (__GDK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif

#include <gdk/gdkversionmacros.h>
#include <gdk/gdktypes.h>

/* Zeile entfernt */


/* Zeile entfernt */
GdkContentProvider *    gdk_content_provider_new_for_value              (const GValue           *value);
/* Zeile entfernt */
GdkContentProvider *    gdk_content_provider_new_typed                  (GType                   type,
                                                                         ...);
/* Zeile entfernt */
GdkContentProvider *    gdk_content_provider_new_union                  (GdkContentProvider    **providers,
                                                                         gsize                   n_providers);
/* Zeile entfernt */
GdkContentProvider *    gdk_content_provider_new_for_bytes              (const char             *mime_type,
                                                                         GBytes                 *bytes);


/* Zeile entfernt */

#endif /* __GDK_CONTENT_PROVIDER_IMPL_H__ */
