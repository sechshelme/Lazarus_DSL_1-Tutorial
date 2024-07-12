
unit gtkscrollbar;
interface

{
  Automatically converted by H2Pas 1.0.0 from gtkscrollbar.h
  The following command line parameters were used:
    -p
    -T
    -d
    -c
    -e
    gtkscrollbar.h
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
PGtkAdjustment  = ^GtkAdjustment;
PGtkScrollbar  = ^GtkScrollbar;
PGtkWidget  = ^GtkWidget;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


{ GTK - The GIMP Toolkit
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
  }
{
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
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
function GTK_TYPE_SCROLLBAR : longint; { return type might be wrong }

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCROLLBAR(obj : longint) : longint;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_IS_SCROLLBAR(obj : longint) : longint;

type

function gtk_scrollbar_get_type:TGType;cdecl;external;
function gtk_scrollbar_new(orientation:TGtkOrientation; adjustment:PGtkAdjustment):PGtkWidget;cdecl;external;
procedure gtk_scrollbar_set_adjustment(self:PGtkScrollbar; adjustment:PGtkAdjustment);cdecl;external;
function gtk_scrollbar_get_adjustment(self:PGtkScrollbar):PGtkAdjustment;cdecl;external;

implementation

{ was #define dname def_expr }
function GTK_TYPE_SCROLLBAR : longint; { return type might be wrong }
  begin
    GTK_TYPE_SCROLLBAR:=gtk_scrollbar_get_type;
  end;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_SCROLLBAR(obj : longint) : longint;
begin
  GTK_SCROLLBAR:=G_TYPE_CHECK_INSTANCE_CAST(obj,GTK_TYPE_SCROLLBAR,GtkScrollbar);
end;

{ was #define dname(params) para_def_expr }
{ argument types are unknown }
{ return type might be wrong }   
function GTK_IS_SCROLLBAR(obj : longint) : longint;
begin
  GTK_IS_SCROLLBAR:=G_TYPE_CHECK_INSTANCE_TYPE(obj,GTK_TYPE_SCROLLBAR);
end;


end.