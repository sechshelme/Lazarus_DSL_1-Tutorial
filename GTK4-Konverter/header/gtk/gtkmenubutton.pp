
  Type
  Pchar  = ^char;
  PGMenuModel  = ^GMenuModel;
  PGtkMenuButton  = ^GtkMenuButton;
  PGtkPopover  = ^GtkPopover;
  PGtkWidget  = ^GtkWidget;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { GTK - The GIMP Toolkit
   *
   * Copyright (C) 2003 Ricardo Fernandez Pascual
   * Copyright (C) 2004 Paolo Borelli
   * Copyright (C) 2012 Bastien Nocera
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
    }
{$ifndef __GTK_MENU_BUTTON_H__}
{$define __GTK_MENU_BUTTON_H__}  
{$if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)}
{$error "Only <gtk/gtk.h> can be included directly."}
{$endif}
{$include <gtk/gtktogglebutton.h>}
{$include <gtk/gtkpopover.h>}
  { Zeile entfernt  }

  { was #define dname def_expr }
  function GTK_TYPE_MENU_BUTTON : longint; { return type might be wrong }

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GTK_MENU_BUTTON(obj : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GTK_IS_MENU_BUTTON(obj : longint) : longint;  


  type
    _GtkMenuButton = GtkMenuButton;
  {*
   * GtkMenuButtonCreatePopupFunc:
   * @menu_button: the `GtkMenuButton`
   * @user_data: User data passed to gtk_menu_button_set_create_popup_func()
   *
   * User-provided callback function to create a popup for a
   * `GtkMenuButton` on demand.
   *
   * This function is called when the popup of @menu_button is shown,
   * but none has been provided via [method@Gtk.MenuButton.set_popover]
   * or [method@Gtk.MenuButton.set_menu_model].
    }

    GtkMenuButtonCreatePopupFunc = procedure (menu_button:PGtkMenuButton; user_data:gpointer);cdecl;
  { Zeile entfernt  }

  function gtk_menu_button_get_type:GType;

  { Zeile entfernt  }
  function gtk_menu_button_new:^GtkWidget;

  { Zeile entfernt  }
  procedure gtk_menu_button_set_popover(menu_button:PGtkMenuButton; popover:PGtkWidget);

  { Zeile entfernt  }
  function gtk_menu_button_get_popover(menu_button:PGtkMenuButton):^GtkPopover;

  { Zeile entfernt  }
  procedure gtk_menu_button_set_direction(menu_button:PGtkMenuButton; direction:GtkArrowType);

  { Zeile entfernt  }
  function gtk_menu_button_get_direction(menu_button:PGtkMenuButton):GtkArrowType;

  { Zeile entfernt  }
  procedure gtk_menu_button_set_menu_model(menu_button:PGtkMenuButton; menu_model:PGMenuModel);

  { Zeile entfernt  }
  function gtk_menu_button_get_menu_model(menu_button:PGtkMenuButton):^GMenuModel;

  { Zeile entfernt  }
(* Const before type ignored *)
  procedure gtk_menu_button_set_icon_name(menu_button:PGtkMenuButton; icon_name:Pchar);

  { Zeile entfernt  }
(* Const before type ignored *)
  function gtk_menu_button_get_icon_name(menu_button:PGtkMenuButton):^char;

  { Zeile entfernt  }
  procedure gtk_menu_button_set_always_show_arrow(menu_button:PGtkMenuButton; always_show_arrow:gboolean);

  { Zeile entfernt  }
  function gtk_menu_button_get_always_show_arrow(menu_button:PGtkMenuButton):gboolean;

  { Zeile entfernt  }
(* Const before type ignored *)
  procedure gtk_menu_button_set_label(menu_button:PGtkMenuButton; _label:Pchar);

  { Zeile entfernt  }
(* Const before type ignored *)
  function gtk_menu_button_get_label(menu_button:PGtkMenuButton):^char;

  { Zeile entfernt  }
  procedure gtk_menu_button_set_use_underline(menu_button:PGtkMenuButton; use_underline:gboolean);

  { Zeile entfernt  }
  function gtk_menu_button_get_use_underline(menu_button:PGtkMenuButton):gboolean;

  { Zeile entfernt  }
  procedure gtk_menu_button_set_has_frame(menu_button:PGtkMenuButton; has_frame:gboolean);

  { Zeile entfernt  }
  function gtk_menu_button_get_has_frame(menu_button:PGtkMenuButton):gboolean;

  { Zeile entfernt  }
  procedure gtk_menu_button_popup(menu_button:PGtkMenuButton);

  { Zeile entfernt  }
  procedure gtk_menu_button_popdown(menu_button:PGtkMenuButton);

  { Zeile entfernt  }
  procedure gtk_menu_button_set_create_popup_func(menu_button:PGtkMenuButton; func:GtkMenuButtonCreatePopupFunc; user_data:gpointer; destroy_notify:GDestroyNotify);

  { Zeile entfernt  }
  procedure gtk_menu_button_set_primary(menu_button:PGtkMenuButton; primary:gboolean);

  { Zeile entfernt  }
  function gtk_menu_button_get_primary(menu_button:PGtkMenuButton):gboolean;

  { Zeile entfernt  }
  procedure gtk_menu_button_set_child(menu_button:PGtkMenuButton; child:PGtkWidget);

  { Zeile entfernt  }
  function gtk_menu_button_get_child(menu_button:PGtkMenuButton):^GtkWidget;

  { Zeile entfernt  }
{$endif}
  { __GTK_MENU_BUTTON_H__  }
  { was #define dname def_expr }
  function GTK_TYPE_MENU_BUTTON : longint; { return type might be wrong }
    begin
      GTK_TYPE_MENU_BUTTON:=gtk_menu_button_get_type;
    end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GTK_MENU_BUTTON(obj : longint) : longint;
  begin
    GTK_MENU_BUTTON:=G_TYPE_CHECK_INSTANCE_CAST(obj,GTK_TYPE_MENU_BUTTON,GtkMenuButton);
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GTK_IS_MENU_BUTTON(obj : longint) : longint;
  begin
    GTK_IS_MENU_BUTTON:=G_TYPE_CHECK_INSTANCE_TYPE(obj,GTK_TYPE_MENU_BUTTON);
  end;

  function gtk_menu_button_get_type:GType;
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_new:PGtkWidget;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_popover(menu_button:PGtkMenuButton; popover:PGtkWidget);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_popover(menu_button:PGtkMenuButton):PGtkPopover;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_direction(menu_button:PGtkMenuButton; direction:GtkArrowType);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_direction(menu_button:PGtkMenuButton):GtkArrowType;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_menu_model(menu_button:PGtkMenuButton; menu_model:PGMenuModel);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_menu_model(menu_button:PGtkMenuButton):PGMenuModel;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_icon_name(menu_button:PGtkMenuButton; icon_name:Pchar);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_icon_name(menu_button:PGtkMenuButton):Pchar;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_always_show_arrow(menu_button:PGtkMenuButton; always_show_arrow:gboolean);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_always_show_arrow(menu_button:PGtkMenuButton):gboolean;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_label(menu_button:PGtkMenuButton; _label:Pchar);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_label(menu_button:PGtkMenuButton):Pchar;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_use_underline(menu_button:PGtkMenuButton; use_underline:gboolean);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_use_underline(menu_button:PGtkMenuButton):gboolean;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_has_frame(menu_button:PGtkMenuButton; has_frame:gboolean);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_has_frame(menu_button:PGtkMenuButton):gboolean;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_popup(menu_button:PGtkMenuButton);
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_popdown(menu_button:PGtkMenuButton);
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_create_popup_func(menu_button:PGtkMenuButton; func:GtkMenuButtonCreatePopupFunc; user_data:gpointer; destroy_notify:GDestroyNotify);
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_primary(menu_button:PGtkMenuButton; primary:gboolean);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_primary(menu_button:PGtkMenuButton):gboolean;
  begin
    { You must implement this function }
  end;
  procedure gtk_menu_button_set_child(menu_button:PGtkMenuButton; child:PGtkWidget);
  begin
    { You must implement this function }
  end;
  function gtk_menu_button_get_child(menu_button:PGtkMenuButton):PGtkWidget;
  begin
    { You must implement this function }
  end;

