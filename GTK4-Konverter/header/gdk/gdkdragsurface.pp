
  Type
  PGdkDragSurface  = ^GdkDragSurface;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  {
   * Copyright © 2020 Red Hat, Inc.
   *
   * This library is free software; you can redistribute it and/or
   * modify it under the terms of the GNU Lesser General Public
   * License as published by the Free Software Foundation; either
   * version 2.1 of the License, or (at your option) any later version.
   *
   * This library is distributed in the hope that it will be useful,
   * but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   * Lesser General Public License for more details.
   *
   * You should have received a copy of the GNU Lesser General Public
   * License along with this library. If not, see <http://www.gnu.org/licenses/>.
   *
   * Authors: Matthias Clasen <mclasen@redhat.com>
    }
{$ifndef __GDK_DRAG_SURFACE_H__}
{$define __GDK_DRAG_SURFACE_H__}  
{$if !defined(__GDK_H_INSIDE__) && !defined(GTK_COMPILATION)}
{$error "Only <gdk/gdk.h> can be included directly."}
{$endif}
{$include <gdk/gdksurface.h>}
  { Zeile entfernt  }

  { was #define dname def_expr }
  function GDK_TYPE_DRAG_SURFACE : longint; { return type might be wrong }

  { Zeile entfernt  }
  { Zeile entfernt  }
  { Zeile entfernt  }
  function gdk_drag_surface_present(drag_surface:PGdkDragSurface; width:longint; height:longint):gboolean;

  { Zeile entfernt  }
{$endif}
  { __GDK_DRAG_SURFACE_H__  }
  { was #define dname def_expr }
  function GDK_TYPE_DRAG_SURFACE : longint; { return type might be wrong }
    begin
      GDK_TYPE_DRAG_SURFACE:=gdk_drag_surface_get_type;
    end;

  function gdk_drag_surface_present(drag_surface:PGdkDragSurface; width:longint; height:longint):gboolean;
  begin
    { You must implement this function }
  end;

