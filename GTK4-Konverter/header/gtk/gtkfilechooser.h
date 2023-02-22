/* GTK - The GIMP Toolkit
 * gtkfilechooser.h: Abstract interface for file selector GUIs
 * Copyright (C) 2003, Red Hat, Inc.
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

#ifndef __GTK_FILE_CHOOSER_H__
#define __GTK_FILE_CHOOSER_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkfilefilter.h>
#include <gtk/gtkwidget.h>

/* Zeile entfernt */

#define GTK_TYPE_FILE_CHOOSER             (gtk_file_chooser_get_type ())
#define GTK_FILE_CHOOSER(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_FILE_CHOOSER, GtkFileChooser))
#define GTK_IS_FILE_CHOOSER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_FILE_CHOOSER))

typedef struct _GtkFileChooser      GtkFileChooser;

/**
 * GtkFileChooserAction:
 * @GTK_FILE_CHOOSER_ACTION_OPEN: Indicates open mode.  The file chooser
 *  will only let the user pick an existing file.
 * @GTK_FILE_CHOOSER_ACTION_SAVE: Indicates save mode.  The file chooser
 *  will let the user pick an existing file, or type in a new
 *  filename.
 * @GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER: Indicates an Open mode for
 *  selecting folders.  The file chooser will let the user pick an
 *  existing folder.
 *
 * Describes whether a `GtkFileChooser` is being used to open existing files
 * or to save to a possibly new file.
 */
typedef enum
{
  GTK_FILE_CHOOSER_ACTION_OPEN,
  GTK_FILE_CHOOSER_ACTION_SAVE,
  GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER
} GtkFileChooserAction;

/* Zeile entfernt */
GType gtk_file_chooser_get_type (void) ;

/* GError enumeration for GtkFileChooser */
/**
 * GTK_FILE_CHOOSER_ERROR:
 *
 * Used to get the `GError` quark for `GtkFileChooser` errors.
 */
#define GTK_FILE_CHOOSER_ERROR (gtk_file_chooser_error_quark ())

/**
 * GtkFileChooserError:
 * @GTK_FILE_CHOOSER_ERROR_NONEXISTENT: Indicates that a file does not exist.
 * @GTK_FILE_CHOOSER_ERROR_BAD_FILENAME: Indicates a malformed filename.
 * @GTK_FILE_CHOOSER_ERROR_ALREADY_EXISTS: Indicates a duplicate path (e.g. when
 *  adding a bookmark).
 * @GTK_FILE_CHOOSER_ERROR_INCOMPLETE_HOSTNAME: Indicates an incomplete hostname
 *  (e.g. "http://foo" without a slash after that).
 *
 * These identify the various errors that can occur while calling
 * `GtkFileChooser` functions.
 */
typedef enum {
  GTK_FILE_CHOOSER_ERROR_NONEXISTENT,
  GTK_FILE_CHOOSER_ERROR_BAD_FILENAME,
  GTK_FILE_CHOOSER_ERROR_ALREADY_EXISTS,
  GTK_FILE_CHOOSER_ERROR_INCOMPLETE_HOSTNAME
} GtkFileChooserError;

/* Zeile entfernt */
GQuark gtk_file_chooser_error_quark (void);

/* Configuration */

/* Zeile entfernt */
void                 gtk_file_chooser_set_action          (GtkFileChooser       *chooser,
                                                           GtkFileChooserAction  action);
/* Zeile entfernt */
GtkFileChooserAction gtk_file_chooser_get_action          (GtkFileChooser       *chooser);
/* Zeile entfernt */
void                 gtk_file_chooser_set_select_multiple (GtkFileChooser       *chooser,
                                                           gboolean              select_multiple);
/* Zeile entfernt */
gboolean             gtk_file_chooser_get_select_multiple (GtkFileChooser       *chooser);
/* Zeile entfernt */
void                 gtk_file_chooser_set_create_folders  (GtkFileChooser       *chooser,
                                                           gboolean              create_folders);
/* Zeile entfernt */
gboolean             gtk_file_chooser_get_create_folders  (GtkFileChooser       *chooser);

/* Suggested name for the Save-type actions */

/* Zeile entfernt */
void                 gtk_file_chooser_set_current_name    (GtkFileChooser       *chooser,
                                                           const char           *name);
/* Zeile entfernt */
char *               gtk_file_chooser_get_current_name    (GtkFileChooser       *chooser);

/* GFile manipulation */

/* Zeile entfernt */
GFile *              gtk_file_chooser_get_file            (GtkFileChooser       *chooser);
/* Zeile entfernt */
gboolean             gtk_file_chooser_set_file            (GtkFileChooser       *chooser,
                                                           GFile                *file,
                                                           GError              **error);
/* Zeile entfernt */
GListModel *         gtk_file_chooser_get_files           (GtkFileChooser       *chooser);
/* Zeile entfernt */
gboolean             gtk_file_chooser_set_current_folder  (GtkFileChooser       *chooser,
                                                           GFile                *file,
                                                           GError              **error);
/* Zeile entfernt */
GFile *              gtk_file_chooser_get_current_folder  (GtkFileChooser       *chooser);

/* List of user selectable filters */

/* Zeile entfernt */
void                 gtk_file_chooser_add_filter          (GtkFileChooser       *chooser,
                                                           GtkFileFilter        *filter);
/* Zeile entfernt */
void                 gtk_file_chooser_remove_filter       (GtkFileChooser       *chooser,
                                                           GtkFileFilter        *filter);
/* Zeile entfernt */
GListModel *         gtk_file_chooser_get_filters         (GtkFileChooser       *chooser);

/* Current filter */

/* Zeile entfernt */
void                 gtk_file_chooser_set_filter          (GtkFileChooser       *chooser,
                                                           GtkFileFilter        *filter);
/* Zeile entfernt */
GtkFileFilter *      gtk_file_chooser_get_filter          (GtkFileChooser       *chooser);

/* Per-application shortcut folders */

/* Zeile entfernt */
gboolean             gtk_file_chooser_add_shortcut_folder (GtkFileChooser       *chooser,
                                                           GFile                *folder,
                                                           GError              **error);
/* Zeile entfernt */
gboolean             gtk_file_chooser_remove_shortcut_folder
                                                          (GtkFileChooser       *chooser,
                                                           GFile                *folder,
                                                           GError              **error);
/* Zeile entfernt */
GListModel *         gtk_file_chooser_get_shortcut_folders (GtkFileChooser      *chooser);

/* Custom widgets */

/* Zeile entfernt */
void                 gtk_file_chooser_add_choice           (GtkFileChooser      *chooser,
                                                            const char          *id,
                                                            const char          *label,
                                                            const char         **options,
                                                            const char         **option_labels);
/* Zeile entfernt */
void                 gtk_file_chooser_remove_choice        (GtkFileChooser      *chooser,
                                                            const char          *id);
/* Zeile entfernt */
void                 gtk_file_chooser_set_choice           (GtkFileChooser      *chooser,
                                                            const char          *id,
                                                            const char          *option);
/* Zeile entfernt */
const char *         gtk_file_chooser_get_choice           (GtkFileChooser      *chooser,
                                                            const char          *id);

/* Zeile entfernt */

#endif /* __GTK_FILE_CHOOSER_H__ */
