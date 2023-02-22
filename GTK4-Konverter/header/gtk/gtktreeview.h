/* gtktreeview.h
 * Copyright (C) 2000  Red Hat, Inc.,  Jonathan Blandford <jrb@redhat.com>
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
 */

#ifndef __GTK_TREE_VIEW_H__
#define __GTK_TREE_VIEW_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkwidget.h>
#include <gtk/gtktreemodel.h>
#include <gtk/gtktreeviewcolumn.h>
#include <gtk/gtkentry.h>

/* Zeile entfernt */

/**
 * GtkTreeViewDropPosition:
 * @GTK_TREE_VIEW_DROP_BEFORE: dropped row is inserted before
 * @GTK_TREE_VIEW_DROP_AFTER: dropped row is inserted after
 * @GTK_TREE_VIEW_DROP_INTO_OR_BEFORE: dropped row becomes a child or is inserted before
 * @GTK_TREE_VIEW_DROP_INTO_OR_AFTER: dropped row becomes a child or is inserted after
 *
 * An enum for determining where a dropped row goes.
 */
typedef enum
{
  /* drop before/after this row */
  GTK_TREE_VIEW_DROP_BEFORE,
  GTK_TREE_VIEW_DROP_AFTER,
  /* drop as a child of this row (with fallback to before or after
   * if into is not possible)
   */
  GTK_TREE_VIEW_DROP_INTO_OR_BEFORE,
  GTK_TREE_VIEW_DROP_INTO_OR_AFTER
} GtkTreeViewDropPosition;

#define GTK_TYPE_TREE_VIEW            (gtk_tree_view_get_type ())
#define GTK_TREE_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_TREE_VIEW, GtkTreeView))
#define GTK_IS_TREE_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_TREE_VIEW))
#define GTK_TREE_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_TREE_VIEW, GtkTreeViewClass))
#define GTK_IS_TREE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_TREE_VIEW))
#define GTK_TREE_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_TREE_VIEW, GtkTreeViewClass))

typedef struct _GtkTreeView           GtkTreeView;
typedef struct _GtkTreeViewClass      GtkTreeViewClass;
typedef struct _GtkTreeSelection      GtkTreeSelection;

/**
 * GtkTreeViewColumnDropFunc:
 * @tree_view: A `GtkTreeView`
 * @column: The `GtkTreeViewColumn` being dragged
 * @prev_column: A `GtkTreeViewColumn` on one side of @column
 * @next_column: A `GtkTreeViewColumn` on the other side of @column
 * @data: (closure): user data
 *
 * Function type for determining whether @column can be dropped in a
 * particular spot (as determined by @prev_column and @next_column).  In
 * left to right locales, @prev_column is on the left of the potential drop
 * spot, and @next_column is on the right.  In right to left mode, this is
 * reversed.  This function should return %TRUE if the spot is a valid drop
 * spot.  Please note that returning %TRUE does not actually indicate that
 * the column drop was made, but is meant only to indicate a possible drop
 * spot to the user.
 *
 * Returns: %TRUE, if @column can be dropped in this spot
 */
typedef gboolean (* GtkTreeViewColumnDropFunc) (GtkTreeView             *tree_view,
						GtkTreeViewColumn       *column,
						GtkTreeViewColumn       *prev_column,
						GtkTreeViewColumn       *next_column,
						gpointer                 data);

/**
 * GtkTreeViewMappingFunc:
 * @tree_view: A `GtkTreeView`
 * @path: The path that’s expanded
 * @user_data: user data
 *
 * Function used for gtk_tree_view_map_expanded_rows().
 */
typedef void     (* GtkTreeViewMappingFunc)    (GtkTreeView             *tree_view,
						GtkTreePath             *path,
						gpointer                 user_data);

/**
 * GtkTreeViewSearchEqualFunc:
 * @model: the `GtkTreeModel` being searched
 * @column: the search column set by gtk_tree_view_set_search_column()
 * @key: the key string to compare with
 * @iter: a `GtkTreeIter` pointing the row of @model that should be compared
 *  with @key.
 * @search_data: (closure): user data from gtk_tree_view_set_search_equal_func()
 *
 * A function used for checking whether a row in @model matches
 * a search key string entered by the user. Note the return value
 * is reversed from what you would normally expect, though it
 * has some similarity to strcmp() returning 0 for equal strings.
 *
 * Returns: %FALSE if the row matches, %TRUE otherwise.
 */
typedef gboolean (*GtkTreeViewSearchEqualFunc) (GtkTreeModel            *model,
						int                      column,
						const char              *key,
						GtkTreeIter             *iter,
						gpointer                 search_data);

/**
 * GtkTreeViewRowSeparatorFunc:
 * @model: the `GtkTreeModel`
 * @iter: a `GtkTreeIter` pointing at a row in @model
 * @data: (closure): user data
 *
 * Function type for determining whether the row pointed to by @iter should
 * be rendered as a separator. A common way to implement this is to have a
 * boolean column in the model, whose values the `GtkTreeViewRowSeparatorFunc`
 * returns.
 *
 * Returns: %TRUE if the row is a separator
 */
typedef gboolean (*GtkTreeViewRowSeparatorFunc) (GtkTreeModel      *model,
						 GtkTreeIter       *iter,
						 gpointer           data);

struct _GtkTreeView
{
  GtkWidget parent_instance;
};

struct _GtkTreeViewClass
{
  GtkWidgetClass parent_class;

  void     (* row_activated)              (GtkTreeView       *tree_view,
                                           GtkTreePath       *path,
                                           GtkTreeViewColumn *column);
  gboolean (* test_expand_row)            (GtkTreeView       *tree_view,
                                           GtkTreeIter       *iter,
                                           GtkTreePath       *path);
  gboolean (* test_collapse_row)          (GtkTreeView       *tree_view,
                                           GtkTreeIter       *iter,
                                           GtkTreePath       *path);
  void     (* row_expanded)               (GtkTreeView       *tree_view,
                                           GtkTreeIter       *iter,
                                           GtkTreePath       *path);
  void     (* row_collapsed)              (GtkTreeView       *tree_view,
                                           GtkTreeIter       *iter,
                                           GtkTreePath       *path);
  void     (* columns_changed)            (GtkTreeView       *tree_view);
  void     (* cursor_changed)             (GtkTreeView       *tree_view);

  /* Key Binding signals */
  gboolean (* move_cursor)                (GtkTreeView       *tree_view,
                                           GtkMovementStep    step,
                                           int                count,
                                           gboolean           extend,
                                           gboolean           modify);
  gboolean (* select_all)                 (GtkTreeView       *tree_view);
  gboolean (* unselect_all)               (GtkTreeView       *tree_view);
  gboolean (* select_cursor_row)          (GtkTreeView       *tree_view,
                                           gboolean           start_editing);
  gboolean (* toggle_cursor_row)          (GtkTreeView       *tree_view);
  gboolean (* expand_collapse_cursor_row) (GtkTreeView       *tree_view,
                                           gboolean           logical,
                                           gboolean           expand,
                                           gboolean           open_all);
  gboolean (* select_cursor_parent)       (GtkTreeView       *tree_view);
  gboolean (* start_interactive_search)   (GtkTreeView       *tree_view);

  /*< private >*/
  gpointer _reserved[16];
};

/* Zeile entfernt */
GType                  gtk_tree_view_get_type                      (void) ;

/* Creators */
/* Zeile entfernt */
GtkWidget             *gtk_tree_view_new                           (void);
/* Zeile entfernt */
GtkWidget             *gtk_tree_view_new_with_model                (GtkTreeModel              *model);

/* Accessors */
/* Zeile entfernt */
GtkTreeModel          *gtk_tree_view_get_model                     (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_set_model                     (GtkTreeView               *tree_view,
								    GtkTreeModel              *model);
/* Zeile entfernt */
GtkTreeSelection      *gtk_tree_view_get_selection                 (GtkTreeView               *tree_view);

/* Zeile entfernt */
gboolean               gtk_tree_view_get_headers_visible           (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_set_headers_visible           (GtkTreeView               *tree_view,
								    gboolean                   headers_visible);
/* Zeile entfernt */
void                   gtk_tree_view_columns_autosize              (GtkTreeView               *tree_view);
/* Zeile entfernt */
gboolean               gtk_tree_view_get_headers_clickable         (GtkTreeView *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_set_headers_clickable         (GtkTreeView               *tree_view,
								    gboolean                   setting);
/* Zeile entfernt */
gboolean               gtk_tree_view_get_activate_on_single_click  (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_set_activate_on_single_click  (GtkTreeView               *tree_view,
								    gboolean                   single);

/* Column functions */
/* Zeile entfernt */
int                    gtk_tree_view_append_column                 (GtkTreeView               *tree_view,
								    GtkTreeViewColumn         *column);
/* Zeile entfernt */
int                    gtk_tree_view_remove_column                 (GtkTreeView               *tree_view,
								    GtkTreeViewColumn         *column);
/* Zeile entfernt */
int                    gtk_tree_view_insert_column                 (GtkTreeView               *tree_view,
								    GtkTreeViewColumn         *column,
								    int                        position);
/* Zeile entfernt */
int                    gtk_tree_view_insert_column_with_attributes (GtkTreeView               *tree_view,
								    int                        position,
								    const char                *title,
								    GtkCellRenderer           *cell,
								    ...) ;
/* Zeile entfernt */
int                    gtk_tree_view_insert_column_with_data_func  (GtkTreeView               *tree_view,
								    int                        position,
								    const char                *title,
								    GtkCellRenderer           *cell,
                                                                    GtkTreeCellDataFunc        func,
                                                                    gpointer                   data,
                                                                    GDestroyNotify             dnotify);

/* Zeile entfernt */
guint                  gtk_tree_view_get_n_columns                 (GtkTreeView               *tree_view);
/* Zeile entfernt */
GtkTreeViewColumn     *gtk_tree_view_get_column                    (GtkTreeView               *tree_view,
								    int                        n);
/* Zeile entfernt */
GList                 *gtk_tree_view_get_columns                   (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_move_column_after             (GtkTreeView               *tree_view,
								    GtkTreeViewColumn         *column,
								    GtkTreeViewColumn         *base_column);
/* Zeile entfernt */
void                   gtk_tree_view_set_expander_column           (GtkTreeView               *tree_view,
								    GtkTreeViewColumn         *column);
/* Zeile entfernt */
GtkTreeViewColumn     *gtk_tree_view_get_expander_column           (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_set_column_drag_function      (GtkTreeView               *tree_view,
								    GtkTreeViewColumnDropFunc  func,
								    gpointer                   user_data,
								    GDestroyNotify             destroy);

/* Actions */
/* Zeile entfernt */
void                   gtk_tree_view_scroll_to_point               (GtkTreeView               *tree_view,
								    int                        tree_x,
								    int                        tree_y);
/* Zeile entfernt */
void                   gtk_tree_view_scroll_to_cell                (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    GtkTreeViewColumn         *column,
								    gboolean                   use_align,
								    float                      row_align,
								    float                      col_align);
/* Zeile entfernt */
void                   gtk_tree_view_row_activated                 (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    GtkTreeViewColumn         *column);
/* Zeile entfernt */
void                   gtk_tree_view_expand_all                    (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_collapse_all                  (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_expand_to_path                (GtkTreeView               *tree_view,
								    GtkTreePath               *path);
/* Zeile entfernt */
gboolean               gtk_tree_view_expand_row                    (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    gboolean                   open_all);
/* Zeile entfernt */
gboolean               gtk_tree_view_collapse_row                  (GtkTreeView               *tree_view,
								    GtkTreePath               *path);
/* Zeile entfernt */
void                   gtk_tree_view_map_expanded_rows             (GtkTreeView               *tree_view,
								    GtkTreeViewMappingFunc     func,
								    gpointer                   data);
/* Zeile entfernt */
gboolean               gtk_tree_view_row_expanded                  (GtkTreeView               *tree_view,
								    GtkTreePath               *path);
/* Zeile entfernt */
void                   gtk_tree_view_set_reorderable               (GtkTreeView               *tree_view,
								    gboolean                   reorderable);
/* Zeile entfernt */
gboolean               gtk_tree_view_get_reorderable               (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_set_cursor                    (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    GtkTreeViewColumn         *focus_column,
								    gboolean                   start_editing);
/* Zeile entfernt */
void                   gtk_tree_view_set_cursor_on_cell            (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    GtkTreeViewColumn         *focus_column,
								    GtkCellRenderer           *focus_cell,
								    gboolean                   start_editing);
/* Zeile entfernt */
void                   gtk_tree_view_get_cursor                    (GtkTreeView               *tree_view,
								    GtkTreePath              **path,
								    GtkTreeViewColumn        **focus_column);


/* Layout information */
/* Zeile entfernt */
gboolean               gtk_tree_view_get_path_at_pos               (GtkTreeView               *tree_view,
								    int                        x,
								    int                        y,
								    GtkTreePath              **path,
								    GtkTreeViewColumn        **column,
								    int                       *cell_x,
								    int                       *cell_y);
/* Zeile entfernt */
void                   gtk_tree_view_get_cell_area                 (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    GtkTreeViewColumn         *column,
								    GdkRectangle              *rect);
/* Zeile entfernt */
void                   gtk_tree_view_get_background_area           (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    GtkTreeViewColumn         *column,
								    GdkRectangle              *rect);
/* Zeile entfernt */
void                   gtk_tree_view_get_visible_rect              (GtkTreeView               *tree_view,
								    GdkRectangle              *visible_rect);
/* Zeile entfernt */
gboolean               gtk_tree_view_get_visible_range             (GtkTreeView               *tree_view,
								    GtkTreePath              **start_path,
								    GtkTreePath              **end_path);
/* Zeile entfernt */
gboolean               gtk_tree_view_is_blank_at_pos               (GtkTreeView               *tree_view,
                                                                    int                        x,
                                                                    int                        y,
                                                                    GtkTreePath              **path,
                                                                    GtkTreeViewColumn        **column,
                                                                    int                       *cell_x,
                                                                    int                       *cell_y);

/* Drag-and-Drop support */
/* Zeile entfernt */
void                   gtk_tree_view_enable_model_drag_source      (GtkTreeView               *tree_view,
								    GdkModifierType            start_button_mask,
								    GdkContentFormats         *formats,
								    GdkDragAction              actions);
/* Zeile entfernt */
void                   gtk_tree_view_enable_model_drag_dest        (GtkTreeView               *tree_view,
								    GdkContentFormats         *formats,
								    GdkDragAction              actions);
/* Zeile entfernt */
void                   gtk_tree_view_unset_rows_drag_source        (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                   gtk_tree_view_unset_rows_drag_dest          (GtkTreeView               *tree_view);


/* These are useful to implement your own custom stuff. */
/* Zeile entfernt */
void                   gtk_tree_view_set_drag_dest_row             (GtkTreeView               *tree_view,
								    GtkTreePath               *path,
								    GtkTreeViewDropPosition    pos);
/* Zeile entfernt */
void                   gtk_tree_view_get_drag_dest_row             (GtkTreeView               *tree_view,
								    GtkTreePath              **path,
								    GtkTreeViewDropPosition   *pos);
/* Zeile entfernt */
gboolean               gtk_tree_view_get_dest_row_at_pos           (GtkTreeView               *tree_view,
								    int                        drag_x,
								    int                        drag_y,
								    GtkTreePath              **path,
								    GtkTreeViewDropPosition   *pos);
/* Zeile entfernt */
GdkPaintable          *gtk_tree_view_create_row_drag_icon          (GtkTreeView               *tree_view,
								    GtkTreePath               *path);

/* Interactive search */
/* Zeile entfernt */
void                       gtk_tree_view_set_enable_search     (GtkTreeView                *tree_view,
								gboolean                    enable_search);
/* Zeile entfernt */
gboolean                   gtk_tree_view_get_enable_search     (GtkTreeView                *tree_view);
/* Zeile entfernt */
int                        gtk_tree_view_get_search_column     (GtkTreeView                *tree_view);
/* Zeile entfernt */
void                       gtk_tree_view_set_search_column     (GtkTreeView                *tree_view,
								int                         column);
/* Zeile entfernt */
GtkTreeViewSearchEqualFunc gtk_tree_view_get_search_equal_func (GtkTreeView                *tree_view);
/* Zeile entfernt */
void                       gtk_tree_view_set_search_equal_func (GtkTreeView                *tree_view,
								GtkTreeViewSearchEqualFunc  search_equal_func,
								gpointer                    search_user_data,
								GDestroyNotify              search_destroy);

/* Zeile entfernt */
GtkEditable                  *gtk_tree_view_get_search_entry         (GtkTreeView                   *tree_view);
/* Zeile entfernt */
void                          gtk_tree_view_set_search_entry         (GtkTreeView                   *tree_view,
								      GtkEditable                   *entry);

/* Convert between the different coordinate systems */
/* Zeile entfernt */
void gtk_tree_view_convert_widget_to_tree_coords       (GtkTreeView *tree_view,
							int          wx,
							int          wy,
							int         *tx,
							int         *ty);
/* Zeile entfernt */
void gtk_tree_view_convert_tree_to_widget_coords       (GtkTreeView *tree_view,
							int          tx,
							int          ty,
							int         *wx,
							int         *wy);
/* Zeile entfernt */
void gtk_tree_view_convert_widget_to_bin_window_coords (GtkTreeView *tree_view,
							int          wx,
							int          wy,
							int         *bx,
							int         *by);
/* Zeile entfernt */
void gtk_tree_view_convert_bin_window_to_widget_coords (GtkTreeView *tree_view,
							int          bx,
							int          by,
							int         *wx,
							int         *wy);
/* Zeile entfernt */
void gtk_tree_view_convert_tree_to_bin_window_coords   (GtkTreeView *tree_view,
							int          tx,
							int          ty,
							int         *bx,
							int         *by);
/* Zeile entfernt */
void gtk_tree_view_convert_bin_window_to_tree_coords   (GtkTreeView *tree_view,
							int          bx,
							int          by,
							int         *tx,
							int         *ty);

/* Zeile entfernt */
void     gtk_tree_view_set_fixed_height_mode (GtkTreeView          *tree_view,
					      gboolean              enable);
/* Zeile entfernt */
gboolean gtk_tree_view_get_fixed_height_mode (GtkTreeView          *tree_view);
/* Zeile entfernt */
void     gtk_tree_view_set_hover_selection   (GtkTreeView          *tree_view,
					      gboolean              hover);
/* Zeile entfernt */
gboolean gtk_tree_view_get_hover_selection   (GtkTreeView          *tree_view);
/* Zeile entfernt */
void     gtk_tree_view_set_hover_expand      (GtkTreeView          *tree_view,
					      gboolean              expand);
/* Zeile entfernt */
gboolean gtk_tree_view_get_hover_expand      (GtkTreeView          *tree_view);
/* Zeile entfernt */
void     gtk_tree_view_set_rubber_banding    (GtkTreeView          *tree_view,
					      gboolean              enable);
/* Zeile entfernt */
gboolean gtk_tree_view_get_rubber_banding    (GtkTreeView          *tree_view);

/* Zeile entfernt */
gboolean gtk_tree_view_is_rubber_banding_active (GtkTreeView       *tree_view);

/* Zeile entfernt */
GtkTreeViewRowSeparatorFunc gtk_tree_view_get_row_separator_func (GtkTreeView               *tree_view);
/* Zeile entfernt */
void                        gtk_tree_view_set_row_separator_func (GtkTreeView                *tree_view,
								  GtkTreeViewRowSeparatorFunc func,
								  gpointer                    data,
								  GDestroyNotify              destroy);

/* Zeile entfernt */
GtkTreeViewGridLines        gtk_tree_view_get_grid_lines         (GtkTreeView                *tree_view);
/* Zeile entfernt */
void                        gtk_tree_view_set_grid_lines         (GtkTreeView                *tree_view,
								  GtkTreeViewGridLines        grid_lines);
/* Zeile entfernt */
gboolean                    gtk_tree_view_get_enable_tree_lines  (GtkTreeView                *tree_view);
/* Zeile entfernt */
void                        gtk_tree_view_set_enable_tree_lines  (GtkTreeView                *tree_view,
								  gboolean                    enabled);
/* Zeile entfernt */
void                        gtk_tree_view_set_show_expanders     (GtkTreeView                *tree_view,
								  gboolean                    enabled);
/* Zeile entfernt */
gboolean                    gtk_tree_view_get_show_expanders     (GtkTreeView                *tree_view);
/* Zeile entfernt */
void                        gtk_tree_view_set_level_indentation  (GtkTreeView                *tree_view,
								  int                         indentation);
/* Zeile entfernt */
int                         gtk_tree_view_get_level_indentation  (GtkTreeView                *tree_view);

/* Convenience functions for setting tooltips */
/* Zeile entfernt */
void          gtk_tree_view_set_tooltip_row    (GtkTreeView       *tree_view,
						GtkTooltip        *tooltip,
						GtkTreePath       *path);
/* Zeile entfernt */
void          gtk_tree_view_set_tooltip_cell   (GtkTreeView       *tree_view,
						GtkTooltip        *tooltip,
						GtkTreePath       *path,
						GtkTreeViewColumn *column,
						GtkCellRenderer   *cell);
/* Zeile entfernt */
gboolean      gtk_tree_view_get_tooltip_context(GtkTreeView       *tree_view,
						int                x,
						int                y,
						gboolean           keyboard_tip,
						GtkTreeModel     **model,
						GtkTreePath      **path,
						GtkTreeIter       *iter);
/* Zeile entfernt */
void          gtk_tree_view_set_tooltip_column (GtkTreeView       *tree_view,
					        int                column);
/* Zeile entfernt */
int           gtk_tree_view_get_tooltip_column (GtkTreeView       *tree_view);

/* Zeile entfernt */


#endif /* __GTK_TREE_VIEW_H__ */
