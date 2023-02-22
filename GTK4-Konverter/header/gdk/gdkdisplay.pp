
  Type
  Pchar  = ^char;
  PGdkAppLaunchContext  = ^GdkAppLaunchContext;
  PGdkClipboard  = ^GdkClipboard;
  PGdkDevice  = ^GdkDevice;
  PGdkDisplay  = ^GdkDisplay;
  PGdkEvent  = ^GdkEvent;
  PGdkGLContext  = ^GdkGLContext;
  PGdkKeymapKey  = ^GdkKeymapKey;
  PGdkModifierType  = ^GdkModifierType;
  PGdkMonitor  = ^GdkMonitor;
  PGdkSeat  = ^GdkSeat;
  PGdkSurface  = ^GdkSurface;
  PGError  = ^GError;
  PGList  = ^GList;
  PGListModel  = ^GListModel;
  Pguint  = ^guint;
  PGValue  = ^GValue;
  Plongint  = ^longint;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  {
   * gdkdisplay.h
   *
   * Copyright 2001 Sun Microsystems Inc.
   *
   * Erwann Chenede <erwann.chenede@sun.com>
   *
   * This library is free software; you can redistribute it and/or
   * modify it under the terms of the GNU Library General Public
   * License as published by the Free Software Foundation; either
   * version 2 of the License, or (at your option) any later version.
   *
   * This library is distributed in the hope that it will be useful,
   * but WITHOUT ANY WARRANTY; without even the implied warranty of
   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   * Library General Public License for more details.
   *
   * You should have received a copy of the GNU Library General Public
   * License along with this library. If not, see <http://www.gnu.org/licenses/>.
    }
{$ifndef __GDK_DISPLAY_H__}
{$define __GDK_DISPLAY_H__}  
{$if !defined (__GDK_H_INSIDE__) && !defined (GTK_COMPILATION)}
{$error "Only <gdk/gdk.h> can be included directly."}
{$endif}
{$include <gdk/gdkversionmacros.h>}
{$include <gdk/gdktypes.h>}
{$include <gdk/gdkevents.h>}
{$include <gdk/gdkseat.h>}
{$include <gdk/gdkmonitor.h>}
  { Zeile entfernt  }

  { was #define dname def_expr }
  function GDK_TYPE_DISPLAY : longint; { return type might be wrong }

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GDK_DISPLAY(object : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GDK_IS_DISPLAY(object : longint) : longint;  

  { Zeile entfernt  }
  function gdk_display_get_type:GType;

  { Zeile entfernt  }
(* Const before type ignored *)
  function gdk_display_open(display_name:Pchar):^GdkDisplay;

  { Zeile entfernt  }
(* Const before type ignored *)
  function gdk_display_get_name(display:PGdkDisplay):^char;

  { Zeile entfernt  }
  function gdk_display_device_is_grabbed(display:PGdkDisplay; device:PGdkDevice):gboolean;

  { Zeile entfernt  }
  procedure gdk_display_beep(display:PGdkDisplay);

  { Zeile entfernt  }
  procedure gdk_display_sync(display:PGdkDisplay);

  { Zeile entfernt  }
  procedure gdk_display_flush(display:PGdkDisplay);

  { Zeile entfernt  }
  procedure gdk_display_close(display:PGdkDisplay);

  { Zeile entfernt  }
  function gdk_display_is_closed(display:PGdkDisplay):gboolean;

  { Zeile entfernt  }
  function gdk_display_is_composited(display:PGdkDisplay):gboolean;

  { Zeile entfernt  }
  function gdk_display_is_rgba(display:PGdkDisplay):gboolean;

  { Zeile entfernt  }
  function gdk_display_supports_input_shapes(display:PGdkDisplay):gboolean;

  { Zeile entfernt  }
  function gdk_display_prepare_gl(self:PGdkDisplay; error:PPGError):gboolean;

  { Zeile entfernt  }
  function gdk_display_create_gl_context(self:PGdkDisplay; error:PPGError):^GdkGLContext;

  { Zeile entfernt  }
  function gdk_display_get_default:^GdkDisplay;

  { Zeile entfernt  }
  function gdk_display_get_clipboard(display:PGdkDisplay):^GdkClipboard;

  { Zeile entfernt  }
  function gdk_display_get_primary_clipboard(display:PGdkDisplay):^GdkClipboard;

  { Zeile entfernt  }
(* Const before type ignored *)
  procedure gdk_display_notify_startup_complete(display:PGdkDisplay; startup_id:Pchar);

  { Zeile entfernt  }
(* Const before type ignored *)
  function gdk_display_get_startup_notification_id(display:PGdkDisplay):^char;

  { Zeile entfernt  }
  function gdk_display_get_app_launch_context(display:PGdkDisplay):^GdkAppLaunchContext;

  { Zeile entfernt  }
  function gdk_display_get_default_seat(display:PGdkDisplay):^GdkSeat;

  { Zeile entfernt  }
  function gdk_display_list_seats(display:PGdkDisplay):^GList;

  { Zeile entfernt  }
  function gdk_display_get_monitors(self:PGdkDisplay):^GListModel;

  { Zeile entfernt  }
  function gdk_display_get_monitor_at_surface(display:PGdkDisplay; surface:PGdkSurface):^GdkMonitor;

  { Zeile entfernt  }
  procedure gdk_display_put_event(display:PGdkDisplay; event:PGdkEvent);

  { Zeile entfernt  }
  function gdk_display_map_keyval(display:PGdkDisplay; keyval:guint; keys:PPGdkKeymapKey; n_keys:Plongint):gboolean;

  { Zeile entfernt  }
  function gdk_display_map_keycode(display:PGdkDisplay; keycode:guint; keys:PPGdkKeymapKey; keyvals:PPguint; n_entries:Plongint):gboolean;

  { Zeile entfernt  }
  function gdk_display_translate_key(display:PGdkDisplay; keycode:guint; state:GdkModifierType; group:longint; keyval:Pguint; 
             effective_group:Plongint; level:Plongint; consumed:PGdkModifierType):gboolean;

  { Zeile entfernt  }
(* Const before type ignored *)
  function gdk_display_get_setting(display:PGdkDisplay; name:Pchar; value:PGValue):gboolean;

  { Zeile entfernt  }
{$endif}
  { __GDK_DISPLAY_H__  }
  { was #define dname def_expr }
  function GDK_TYPE_DISPLAY : longint; { return type might be wrong }
    begin
      GDK_TYPE_DISPLAY:=gdk_display_get_type;
    end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GDK_DISPLAY(object : longint) : longint;
  begin
    GDK_DISPLAY:=G_TYPE_CHECK_INSTANCE_CAST(object,GDK_TYPE_DISPLAY,GdkDisplay);
  end;

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GDK_IS_DISPLAY(object : longint) : longint;
  begin
    GDK_IS_DISPLAY:=G_TYPE_CHECK_INSTANCE_TYPE(object,GDK_TYPE_DISPLAY);
  end;

  function gdk_display_get_type:GType;
  begin
    { You must implement this function }
  end;
  function gdk_display_open(display_name:Pchar):PGdkDisplay;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_name(display:PGdkDisplay):Pchar;
  begin
    { You must implement this function }
  end;
  function gdk_display_device_is_grabbed(display:PGdkDisplay; device:PGdkDevice):gboolean;
  begin
    { You must implement this function }
  end;
  procedure gdk_display_beep(display:PGdkDisplay);
  begin
    { You must implement this function }
  end;
  procedure gdk_display_sync(display:PGdkDisplay);
  begin
    { You must implement this function }
  end;
  procedure gdk_display_flush(display:PGdkDisplay);
  begin
    { You must implement this function }
  end;
  procedure gdk_display_close(display:PGdkDisplay);
  begin
    { You must implement this function }
  end;
  function gdk_display_is_closed(display:PGdkDisplay):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_is_composited(display:PGdkDisplay):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_is_rgba(display:PGdkDisplay):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_supports_input_shapes(display:PGdkDisplay):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_prepare_gl(self:PGdkDisplay; error:PPGError):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_create_gl_context(self:PGdkDisplay; error:PPGError):PGdkGLContext;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_default:PGdkDisplay;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_clipboard(display:PGdkDisplay):PGdkClipboard;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_primary_clipboard(display:PGdkDisplay):PGdkClipboard;
  begin
    { You must implement this function }
  end;
  procedure gdk_display_notify_startup_complete(display:PGdkDisplay; startup_id:Pchar);
  begin
    { You must implement this function }
  end;
  function gdk_display_get_startup_notification_id(display:PGdkDisplay):Pchar;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_app_launch_context(display:PGdkDisplay):PGdkAppLaunchContext;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_default_seat(display:PGdkDisplay):PGdkSeat;
  begin
    { You must implement this function }
  end;
  function gdk_display_list_seats(display:PGdkDisplay):PGList;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_monitors(self:PGdkDisplay):PGListModel;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_monitor_at_surface(display:PGdkDisplay; surface:PGdkSurface):PGdkMonitor;
  begin
    { You must implement this function }
  end;
  procedure gdk_display_put_event(display:PGdkDisplay; event:PGdkEvent);
  begin
    { You must implement this function }
  end;
  function gdk_display_map_keyval(display:PGdkDisplay; keyval:guint; keys:PPGdkKeymapKey; n_keys:Plongint):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_map_keycode(display:PGdkDisplay; keycode:guint; keys:PPGdkKeymapKey; keyvals:PPguint; n_entries:Plongint):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_translate_key(display:PGdkDisplay; keycode:guint; state:GdkModifierType; group:longint; keyval:Pguint; 
             effective_group:Plongint; level:Plongint; consumed:PGdkModifierType):gboolean;
  begin
    { You must implement this function }
  end;
  function gdk_display_get_setting(display:PGdkDisplay; name:Pchar; value:PGValue):gboolean;
  begin
    { You must implement this function }
  end;

