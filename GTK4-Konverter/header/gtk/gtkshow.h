/*
 * GTK - The GIMP Toolkit
 * Copyright (C) 2008  Jaap Haitsma <jaap@haitsma.org>
 *
 * All rights reserved.
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

#ifndef __GTK_SHOW_H__
#define __GTK_SHOW_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkwindow.h>

/* Zeile entfernt */

/* Zeile entfernt */
void gtk_show_uri_full (GtkWindow           *parent,
                        const char          *uri,
                        guint32              timestamp,
                        GCancellable        *cancellable,
                        GAsyncReadyCallback  callback,
                        gpointer             user_data);

/* Zeile entfernt */
gboolean gtk_show_uri_full_finish (GtkWindow     *parent,
                                   GAsyncResult  *result,
                                   GError       **error);

/* Zeile entfernt */
void gtk_show_uri (GtkWindow  *parent,
                   const char *uri,
                   guint32     timestamp);

/* Zeile entfernt */

#endif /* __GTK_SHOW_H__ */
