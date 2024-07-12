
unit gtkscalebutton;
interface

{
  Automatically converted by H2Pas 1.0.0 from gtkscalebutton.h
  The following command line parameters were used:
    -p
    -T
    -d
    -c
    -e
    gtkscalebutton.h
}

{ Pointers to basic pascal types, inserted by h2pas conversion program.}
Type
  PLongint  = ^Longint;
  PSmallInt = ^SmallInt;
  PByte     = ^Byte;
  PWord     = ^Word;
  PDWord    = ^DWord;
  PDouble   = ^Double;

Type
Pchar  = ^char;
PGtkAdjustment  = ^GtkAdjustment;
PGtkScaleButton  = ^GtkScaleButton;
PGtkScaleButtonClass  = ^GtkScaleButtonClass;
PGtkWidget  = ^GtkWidget;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


{ GTK - The GIMP Toolkit
 * Copyright (C) 2005 Ronald S. Bultje
 * Copyright (C) 2006, 2007 Christian Persch
 * Copyright (C) 2006 Jan Arne Petersen
 * Copyright (C) 2007 Red Hat, Inc.
 *
 * Authors:
 * - Ronald S. Bultje <rbultje@ronald.bitfreak.net>
 * - Bastien Nocera <bnocera@redhat.com>
 * - Jan Arne Petersen <jpetersen@jpetersen.org>
 * - Christian Persch <chpe@svn.gnome.org>
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
{
 * Modified by the GTK+ Team and others 2007.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
  }
(** unsupported pragma#pragma once*)
{$if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)}
{$error "Only <gtk/gtk.h> can be included directly."}
{$endif}
{$include <gtk/gtkwidget.h>}

{ was #define dname def_expr }
function GTK_TYPE_SCALE_BUTTON : longint; { return type might be wrong }

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCALE_BUTTON(obj : longint) : longint;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCALE_BUTTON_CLASS(klass : longint) : longint;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_IS_SCALE_BUTTON(obj : longint) : longint;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_IS_SCALE_BUTTON_CLASS(klass : longint) : longint;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCALE_BUTTON_GET_CLASS(obj : longint) : longint;

type
  PGtkScaleButton = ^TGtkScaleButton;
  TGtkScaleButton = record
      parent_instance : TGtkWidget;
    end;

{ signals  }
{< private > }
  PGtkScaleButtonClass = ^TGtkScaleButtonClass;
  TGtkScaleButtonClass = record
      parent_class : TGtkWidgetClass;
      value_changed : procedure (button:PGtkScaleButton; value:Tdouble);cdecl;
      padding : array[0..7] of Tgpointer;
    end;


function gtk_scale_button_get_type:TGType;cdecl;external;
(* Const before type ignored *)
function gtk_scale_button_new(min:Tdouble; max:Tdouble; step:Tdouble; icons:PPchar):PGtkWidget;cdecl;external;
(* Const before type ignored *)
procedure gtk_scale_button_set_icons(button:PGtkScaleButton; icons:PPchar);cdecl;external;
function gtk_scale_button_get_value(button:PGtkScaleButton):Tdouble;cdecl;external;
procedure gtk_scale_button_set_value(button:PGtkScaleButton; value:Tdouble);cdecl;external;
function gtk_scale_button_get_adjustment(button:PGtkScaleButton):PGtkAdjustment;cdecl;external;
procedure gtk_scale_button_set_adjustment(button:PGtkScaleButton; adjustment:PGtkAdjustment);cdecl;external;
function gtk_scale_button_get_plus_button(button:PGtkScaleButton):PGtkWidget;cdecl;external;
function gtk_scale_button_get_minus_button(button:PGtkScaleButton):PGtkWidget;cdecl;external;
function gtk_scale_button_get_popup(button:PGtkScaleButton):PGtkWidget;cdecl;external;
function gtk_scale_button_get_active(button:PGtkScaleButton):Tgboolean;cdecl;external;
function gtk_scale_button_get_has_frame(button:PGtkScaleButton):Tgboolean;cdecl;external;
procedure gtk_scale_button_set_has_frame(button:PGtkScaleButton; has_frame:Tgboolean);cdecl;external;

implementation

{ was #define dname def_expr }
function GTK_TYPE_SCALE_BUTTON : longint; { return type might be wrong }
  begin
    GTK_TYPE_SCALE_BUTTON:=gtk_scale_button_get_type;
  end;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCALE_BUTTON(obj : longint) : longint;
begin
  GTK_SCALE_BUTTON:=G_TYPE_CHECK_INSTANCE_CAST(obj,GTK_TYPE_SCALE_BUTTON,GtkScaleButton);
end;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCALE_BUTTON_CLASS(klass : longint) : longint;
begin
  GTK_SCALE_BUTTON_CLASS:=G_TYPE_CHECK_CLASS_CAST(klass,GTK_TYPE_SCALE_BUTTON,GtkScaleButtonClass);
end;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_IS_SCALE_BUTTON(obj : longint) : longint;
begin
  GTK_IS_SCALE_BUTTON:=G_TYPE_CHECK_INSTANCE_TYPE(obj,GTK_TYPE_SCALE_BUTTON);
end;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_IS_SCALE_BUTTON_CLASS(klass : longint) : longint;
begin
  GTK_IS_SCALE_BUTTON_CLASS:=G_TYPE_CHECK_CLASS_TYPE(klass,GTK_TYPE_SCALE_BUTTON);
end;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCALE_BUTTON_GET_CLASS(obj : longint) : longint;
begin
  GTK_SCALE_BUTTON_GET_CLASS:=G_TYPE_INSTANCE_GET_CLASS(obj,GTK_TYPE_SCALE_BUTTON,GtkScaleButtonClass);
end;


end.