/*
 * Copyright © 2010 Codethink Limited
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the licence, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Ryan Lortie <desrt@desrt.ca>
 */

#ifndef __GTK_APPLICATION_H__
#define __GTK_APPLICATION_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkwidget.h>
#include <gio/gio.h>

/* Zeile entfernt */

#define GTK_TYPE_APPLICATION            (gtk_application_get_type ())
#define GTK_APPLICATION(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_APPLICATION, GtkApplication))
#define GTK_APPLICATION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_APPLICATION, GtkApplicationClass))
#define GTK_IS_APPLICATION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_APPLICATION))
#define GTK_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_APPLICATION))
#define GTK_APPLICATION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_APPLICATION, GtkApplicationClass))

typedef struct _GtkApplication        GtkApplication;
typedef struct _GtkApplicationClass   GtkApplicationClass;

struct _GtkApplication
{
  GApplication parent_instance;
};

/**
 * GtkApplicationClass:
 * @parent_class: The parent class.
 * @window_added: Signal emitted when a `GtkWindow` is added to
 *    application through gtk_application_add_window().
 * @window_removed: Signal emitted when a `GtkWindow` is removed from
 *    application, either as a side-effect of being destroyed or
 *    explicitly through gtk_application_remove_window().
 */
struct _GtkApplicationClass
{
  GApplicationClass parent_class;

  /*< public >*/

  void (*window_added)   (GtkApplication *application,
                          GtkWindow      *window);
  void (*window_removed) (GtkApplication *application,
                          GtkWindow      *window);

  /*< private >*/
  gpointer padding[8];
};

/* Zeile entfernt */
GType            gtk_application_get_type      (void) ;

/* Zeile entfernt */
GtkApplication * gtk_application_new           (const char        *application_id,
                                                GApplicationFlags  flags);

/* Zeile entfernt */
void             gtk_application_add_window    (GtkApplication    *application,
                                                GtkWindow         *window);

/* Zeile entfernt */
void             gtk_application_remove_window (GtkApplication    *application,
                                                GtkWindow         *window);
/* Zeile entfernt */
GList *          gtk_application_get_windows   (GtkApplication    *application);

/* Zeile entfernt */
GMenuModel *     gtk_application_get_menubar   (GtkApplication    *application);
/* Zeile entfernt */
void             gtk_application_set_menubar   (GtkApplication    *application,
                                                GMenuModel        *menubar);

typedef enum
{
  GTK_APPLICATION_INHIBIT_LOGOUT  = (1 << 0),
  GTK_APPLICATION_INHIBIT_SWITCH  = (1 << 1),
  GTK_APPLICATION_INHIBIT_SUSPEND = (1 << 2),
  GTK_APPLICATION_INHIBIT_IDLE    = (1 << 3)
} GtkApplicationInhibitFlags;

/* Zeile entfernt */
guint            gtk_application_inhibit            (GtkApplication             *application,
                                                     GtkWindow                  *window,
                                                     GtkApplicationInhibitFlags  flags,
                                                     const char                 *reason);
/* Zeile entfernt */
void             gtk_application_uninhibit          (GtkApplication             *application,
                                                     guint                       cookie);

/* Zeile entfernt */
GtkWindow *      gtk_application_get_window_by_id   (GtkApplication             *application,
                                                     guint                       id);

/* Zeile entfernt */
GtkWindow *      gtk_application_get_active_window  (GtkApplication             *application);

/* Zeile entfernt */
char **         gtk_application_list_action_descriptions        (GtkApplication       *application);

/* Zeile entfernt */
char **         gtk_application_get_accels_for_action           (GtkApplication       *application,
                                                                  const char           *detailed_action_name);
/* Zeile entfernt */
char **         gtk_application_get_actions_for_accel           (GtkApplication       *application,
                                                                  const char           *accel);


/* Zeile entfernt */
void             gtk_application_set_accels_for_action           (GtkApplication       *application,
                                                                  const char           *detailed_action_name,
                                                                  const char * const  *accels);

/* Zeile entfernt */
GMenu *          gtk_application_get_menu_by_id                  (GtkApplication       *application,
                                                                  const char           *id);

/* Zeile entfernt */

/* Zeile entfernt */

#endif /* __GTK_APPLICATION_H__ */
