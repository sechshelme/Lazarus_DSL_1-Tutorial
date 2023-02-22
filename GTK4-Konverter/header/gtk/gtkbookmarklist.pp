
  Type
  Pchar  = ^char;
  PGtkBookmarkList  = ^GtkBookmarkList;
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
{$ifndef __GTK_BOOKMARK_LIST_H__}
{$define __GTK_BOOKMARK_LIST_H__}  
{$if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)}
{$error "Only <gtk/gtk.h> can be included directly."}
{$endif}
{$include <gio/gio.h>}
  { Zeile entfernt  }
{$include <gdk/gdk.h>}
  { Zeile entfernt  }

  { was #define dname def_expr }
  function GTK_TYPE_BOOKMARK_LIST : longint; { return type might be wrong }

  { Zeile entfernt  }
  { Zeile entfernt  }
  { Zeile entfernt  }
(* Const before type ignored *)
(* Const before type ignored *)
  function gtk_bookmark_list_new(filename:Pchar; attributes:Pchar):^GtkBookmarkList;

  { Zeile entfernt  }
(* Const before type ignored *)
  function gtk_bookmark_list_get_filename(self:PGtkBookmarkList):^char;

  { Zeile entfernt  }
(* Const before type ignored *)
  procedure gtk_bookmark_list_set_attributes(self:PGtkBookmarkList; attributes:Pchar);

  { Zeile entfernt  }
(* Const before type ignored *)
  function gtk_bookmark_list_get_attributes(self:PGtkBookmarkList):^char;

  { Zeile entfernt  }
  procedure gtk_bookmark_list_set_io_priority(self:PGtkBookmarkList; io_priority:longint);

  { Zeile entfernt  }
  function gtk_bookmark_list_get_io_priority(self:PGtkBookmarkList):longint;

  { Zeile entfernt  }
  function gtk_bookmark_list_is_loading(self:PGtkBookmarkList):gboolean;

  { Zeile entfernt  }
{$endif}
  { __GTK_BOOKMARK_LIST_H__  }
  { was #define dname def_expr }
  function GTK_TYPE_BOOKMARK_LIST : longint; { return type might be wrong }
    begin
      GTK_TYPE_BOOKMARK_LIST:=gtk_bookmark_list_get_type;
    end;

  function gtk_bookmark_list_new(filename:Pchar; attributes:Pchar):PGtkBookmarkList;
  begin
    { You must implement this function }
  end;
  function gtk_bookmark_list_get_filename(self:PGtkBookmarkList):Pchar;
  begin
    { You must implement this function }
  end;
  procedure gtk_bookmark_list_set_attributes(self:PGtkBookmarkList; attributes:Pchar);
  begin
    { You must implement this function }
  end;
  function gtk_bookmark_list_get_attributes(self:PGtkBookmarkList):Pchar;
  begin
    { You must implement this function }
  end;
  procedure gtk_bookmark_list_set_io_priority(self:PGtkBookmarkList; io_priority:longint);
  begin
    { You must implement this function }
  end;
  function gtk_bookmark_list_get_io_priority(self:PGtkBookmarkList):longint;
  begin
    { You must implement this function }
  end;
  function gtk_bookmark_list_is_loading(self:PGtkBookmarkList):gboolean;
  begin
    { You must implement this function }
  end;

