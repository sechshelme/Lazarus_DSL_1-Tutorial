
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


  { This file is generated by glib-mkenums, do not modify it. This code is licensed under the same license as the containing project. Note that it links to GLib, so must comply with the LGPL linking clauses.  }
{$ifndef __GTK_CSS_ENUM_TYPES_H__}
{$define __GTK_CSS_ENUM_TYPES_H__}  
{$if !defined (__GTK_CSS_H_INSIDE__) && !defined (GTK_COMPILATION)}
{$error "Only <gtk/css/gtkcss.h> can be included directly."}
{$endif}
{$include <glib-object.h>}
{$include <gdk/gdkversionmacros.h>}
  { Zeile entfernt  }
  { enumerations from "gtkcssenums.h"  }
  { Zeile entfernt  }

  { was #define dname def_expr }
  function GTK_TYPE_CSS_PARSER_ERROR : longint; { return type might be wrong }

  { Zeile entfernt  }
  { was #define dname def_expr }
  function GTK_TYPE_CSS_PARSER_WARNING : longint; { return type might be wrong }

  { Zeile entfernt  }
{$endif}
  { __GTK_CSS_ENUM_TYPES_H__  }
  { Generated data ends here  }
  { was #define dname def_expr }
  function GTK_TYPE_CSS_PARSER_ERROR : longint; { return type might be wrong }
    begin
      GTK_TYPE_CSS_PARSER_ERROR:=gtk_css_parser_error_get_type;
    end;

  { was #define dname def_expr }
  function GTK_TYPE_CSS_PARSER_WARNING : longint; { return type might be wrong }
    begin
      GTK_TYPE_CSS_PARSER_WARNING:=gtk_css_parser_warning_get_type;
    end;


