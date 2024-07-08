/* GDK - The GIMP Drawing Kit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
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

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __GDK_DND_H__
#define __GDK_DND_H__

#if !defined (__GDK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif

#include <gdk/gdkdevice.h>
#include <gdk/gdkenums.h>
#include <gdk/gdkevents.h>
#include <gdk/gdktypes.h>

// // // // 

#define GDK_TYPE_DRAG              (gdk_drag_get_type ())
#define GDK_DRAG(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_DRAG, GdkDrag))
#define GDK_IS_DRAG(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_DRAG))

/**
 * GdkDragCancelReason:
 * @GDK_DRAG_CANCEL_NO_TARGET: There is no suitable drop target.
 * @GDK_DRAG_CANCEL_USER_CANCELLED: Drag cancelled by the user
 * @GDK_DRAG_CANCEL_ERROR: Unspecified error.
 *
 * Used in `GdkDrag` to the reason of a cancelled DND operation.
 */
typedef enum {
  GDK_DRAG_CANCEL_NO_TARGET,
  GDK_DRAG_CANCEL_USER_CANCELLED,
  GDK_DRAG_CANCEL_ERROR
} GdkDragCancelReason;


GType            gdk_drag_get_type             (void) ;


GdkDisplay *     gdk_drag_get_display          (GdkDrag *drag);

GdkDevice *      gdk_drag_get_device           (GdkDrag *drag);


GdkContentFormats *gdk_drag_get_formats        (GdkDrag *drag);

GdkDragAction    gdk_drag_get_actions          (GdkDrag *drag);

GdkDragAction    gdk_drag_get_selected_action  (GdkDrag *drag);


gboolean         gdk_drag_action_is_unique     (GdkDragAction   action) ;


GdkDrag *        gdk_drag_begin                (GdkSurface         *surface,
                                                GdkDevice          *device,
                                                GdkContentProvider *content,
                                                GdkDragAction       actions,
                                                double              dx,
                                                double              dy);


void            gdk_drag_drop_done   (GdkDrag  *drag,
                                      gboolean  success);


GdkSurface      *gdk_drag_get_drag_surface (GdkDrag *drag);


void            gdk_drag_set_hotspot (GdkDrag *drag,
                                      int      hot_x,
                                      int      hot_y);


GdkContentProvider *
                gdk_drag_get_content (GdkDrag *drag);


GdkSurface *    gdk_drag_get_surface (GdkDrag *drag);

// // // // 

#endif /* __GDK_DND_H__ */
