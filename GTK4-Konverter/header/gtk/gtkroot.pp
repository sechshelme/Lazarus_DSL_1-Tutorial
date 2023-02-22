
  Type
  PGdkDisplay  = ^GdkDisplay;
  PGtkRoot  = ^GtkRoot;
  PGtkWidget  = ^GtkWidget;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  {
   * Copyright © 2018 Benjamin Otte
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
   * Authors: Benjamin Otte <otte@gnome.org>
    }
{$ifndef __GTK_ROOT_H__}
{$define __GTK_ROOT_H__}  
{$if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)}
{$error "Only <gtk/gtk.h> can be included directly."}
{$endif}
{$include <gdk/gdk.h>}
{$include <gtk/gtkwidget.h>}
  { Zeile entfernt  }

  { was #define dname def_expr }
  function GTK_TYPE_ROOT : longint; { return type might be wrong }

  { Zeile entfernt  }
  { Zeile entfernt  }
  { Zeile entfernt  }
  function gtk_root_get_display(self:PGtkRoot):^GdkDisplay;

  { Zeile entfernt  }
  procedure gtk_root_set_focus(self:PGtkRoot; focus:PGtkWidget);

  { Zeile entfernt  }
  function gtk_root_get_focus(self:PGtkRoot):^GtkWidget;

  { Zeile entfernt  }
{$endif}
  { __GTK_ROOT_H__  }
  { was #define dname def_expr }
  function GTK_TYPE_ROOT : longint; { return type might be wrong }
    begin
      GTK_TYPE_ROOT:=gtk_root_get_type;
    end;

  function gtk_root_get_display(self:PGtkRoot):PGdkDisplay;
  begin
    { You must implement this function }
  end;
  procedure gtk_root_set_focus(self:PGtkRoot; focus:PGtkWidget);
  begin
    { You must implement this function }
  end;
  function gtk_root_get_focus(self:PGtkRoot):PGtkWidget;
  begin
    { You must implement this function }
  end;

