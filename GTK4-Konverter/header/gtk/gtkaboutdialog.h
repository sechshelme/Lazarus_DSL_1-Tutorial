/* GTK - The GIMP Toolkit

   Copyright (C) 2001 CodeFactory AB
   Copyright (C) 2001 Anders Carlsson <andersca@codefactory.se>
   Copyright (C) 2003, 2004 Matthias Clasen <mclasen@redhat.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library. If not, see <http://www.gnu.org/licenses/>.

   Author: Anders Carlsson <andersca@codefactory.se>
*/

#ifndef __GTK_ABOUT_DIALOG_H__
#define __GTK_ABOUT_DIALOG_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkwindow.h>

/* Zeile entfernt */

#define GTK_TYPE_ABOUT_DIALOG            (gtk_about_dialog_get_type ())
#define GTK_ABOUT_DIALOG(object)         (G_TYPE_CHECK_INSTANCE_CAST ((object), GTK_TYPE_ABOUT_DIALOG, GtkAboutDialog))
#define GTK_IS_ABOUT_DIALOG(object)      (G_TYPE_CHECK_INSTANCE_TYPE ((object), GTK_TYPE_ABOUT_DIALOG))

typedef struct _GtkAboutDialog        GtkAboutDialog;

/**
 * GtkLicense:
 * @GTK_LICENSE_UNKNOWN: No license specified
 * @GTK_LICENSE_CUSTOM: A license text is going to be specified by the
 *   developer
 * @GTK_LICENSE_GPL_2_0: The GNU General Public License, version 2.0 or later
 * @GTK_LICENSE_GPL_3_0: The GNU General Public License, version 3.0 or later
 * @GTK_LICENSE_LGPL_2_1: The GNU Lesser General Public License, version 2.1 or later
 * @GTK_LICENSE_LGPL_3_0: The GNU Lesser General Public License, version 3.0 or later
 * @GTK_LICENSE_BSD: The BSD standard license
 * @GTK_LICENSE_MIT_X11: The MIT/X11 standard license
 * @GTK_LICENSE_ARTISTIC: The Artistic License, version 2.0
 * @GTK_LICENSE_GPL_2_0_ONLY: The GNU General Public License, version 2.0 only
 * @GTK_LICENSE_GPL_3_0_ONLY: The GNU General Public License, version 3.0 only
 * @GTK_LICENSE_LGPL_2_1_ONLY: The GNU Lesser General Public License, version 2.1 only
 * @GTK_LICENSE_LGPL_3_0_ONLY: The GNU Lesser General Public License, version 3.0 only
 * @GTK_LICENSE_AGPL_3_0: The GNU Affero General Public License, version 3.0 or later
 * @GTK_LICENSE_AGPL_3_0_ONLY: The GNU Affero General Public License, version 3.0 only
 * @GTK_LICENSE_BSD_3: The 3-clause BSD licence
 * @GTK_LICENSE_APACHE_2_0: The Apache License, version 2.0
 * @GTK_LICENSE_MPL_2_0: The Mozilla Public License, version 2.0
 *
 * The type of license for an application.
 *
 * This enumeration can be expanded at later date.
 */
typedef enum {
  GTK_LICENSE_UNKNOWN,
  GTK_LICENSE_CUSTOM,

  GTK_LICENSE_GPL_2_0,
  GTK_LICENSE_GPL_3_0,

  GTK_LICENSE_LGPL_2_1,
  GTK_LICENSE_LGPL_3_0,

  GTK_LICENSE_BSD,
  GTK_LICENSE_MIT_X11,

  GTK_LICENSE_ARTISTIC,

  GTK_LICENSE_GPL_2_0_ONLY,
  GTK_LICENSE_GPL_3_0_ONLY,
  GTK_LICENSE_LGPL_2_1_ONLY,
  GTK_LICENSE_LGPL_3_0_ONLY,

  GTK_LICENSE_AGPL_3_0,
  GTK_LICENSE_AGPL_3_0_ONLY,

  GTK_LICENSE_BSD_3,
  GTK_LICENSE_APACHE_2_0,
  GTK_LICENSE_MPL_2_0
} GtkLicense;


/* Zeile entfernt */
GType                  gtk_about_dialog_get_type               (void) ;
/* Zeile entfernt */
GtkWidget             *gtk_about_dialog_new                    (void);
/* Zeile entfernt */
void                   gtk_show_about_dialog                   (GtkWindow       *parent,
                                                                const char      *first_property_name,
                                                                ...) ;
/* Zeile entfernt */
const char *          gtk_about_dialog_get_program_name       (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_program_name       (GtkAboutDialog  *about,
                                                                const char      *name);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_version            (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_version            (GtkAboutDialog  *about,
                                                                const char      *version);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_copyright          (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_copyright          (GtkAboutDialog  *about,
                                                                const char      *copyright);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_comments           (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_comments           (GtkAboutDialog  *about,
                                                                const char      *comments);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_license            (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_license            (GtkAboutDialog  *about,
                                                                const char      *license);
/* Zeile entfernt */
void                   gtk_about_dialog_set_license_type       (GtkAboutDialog  *about,
                                                                GtkLicense       license_type);
/* Zeile entfernt */
GtkLicense             gtk_about_dialog_get_license_type       (GtkAboutDialog  *about);

/* Zeile entfernt */
gboolean               gtk_about_dialog_get_wrap_license       (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_wrap_license       (GtkAboutDialog  *about,
                                                                gboolean         wrap_license);

/* Zeile entfernt */
const char *          gtk_about_dialog_get_system_information (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_system_information (GtkAboutDialog  *about,
                                                                const char      *system_information);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_website            (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_website            (GtkAboutDialog  *about,
                                                                const char      *website);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_website_label      (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_website_label      (GtkAboutDialog  *about,
                                                                const char      *website_label);
/* Zeile entfernt */
const char * const *   gtk_about_dialog_get_authors            (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_authors            (GtkAboutDialog  *about,
                                                                const char     **authors);
/* Zeile entfernt */
const char * const *   gtk_about_dialog_get_documenters        (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_documenters        (GtkAboutDialog  *about,
                                                                const char     **documenters);
/* Zeile entfernt */
const char * const *   gtk_about_dialog_get_artists            (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_artists            (GtkAboutDialog  *about,
                                                                const char     **artists);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_translator_credits (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_translator_credits (GtkAboutDialog  *about,
                                                                const char      *translator_credits);
/* Zeile entfernt */
GdkPaintable          *gtk_about_dialog_get_logo               (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_logo               (GtkAboutDialog  *about,
                                                                GdkPaintable    *logo);
/* Zeile entfernt */
const char *          gtk_about_dialog_get_logo_icon_name     (GtkAboutDialog  *about);
/* Zeile entfernt */
void                   gtk_about_dialog_set_logo_icon_name     (GtkAboutDialog  *about,
                                                                const char      *icon_name);
/* Zeile entfernt */
void                  gtk_about_dialog_add_credit_section      (GtkAboutDialog  *about,
                                                                const char      *section_name,
                                                                const char     **people);

/* Zeile entfernt */

/* Zeile entfernt */

#endif /* __GTK_ABOUT_DIALOG_H__ */


