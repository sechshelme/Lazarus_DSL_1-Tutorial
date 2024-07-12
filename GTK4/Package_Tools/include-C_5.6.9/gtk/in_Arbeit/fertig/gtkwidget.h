/* GTK - The GIMP Toolkit
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
 */

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __GTK_WIDGET_H__
#define __GTK_WIDGET_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gdk/gdk.h>
#include <gsk/gsk.h>
#include <gtk/gtkaccelgroup.h>
#include <gtk/gtkborder.h>
#include <gtk/gtkshortcut.h>
#include <gtk/gtkshortcutaction.h>
#include <gtk/gtktypes.h>

// // // // 

/* Macro for casting a pointer to a GtkWidget or GtkWidgetClass pointer.
 * Macros for testing whether widget or klass are of type GTK_TYPE_WIDGET.
 */
#define GTK_TYPE_WIDGET                   (gtk_widget_get_type ())
#define GTK_WIDGET(widget)                (G_TYPE_CHECK_INSTANCE_CAST ((widget), GTK_TYPE_WIDGET, GtkWidget))
#define GTK_WIDGET_CLASS(klass)           (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_WIDGET, GtkWidgetClass))
#define GTK_IS_WIDGET(widget)             (G_TYPE_CHECK_INSTANCE_TYPE ((widget), GTK_TYPE_WIDGET))
#define GTK_IS_WIDGET_CLASS(klass)        (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_WIDGET))
#define GTK_WIDGET_GET_CLASS(obj)         (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_WIDGET, GtkWidgetClass))

#define GTK_TYPE_REQUISITION              (gtk_requisition_get_type ())

typedef struct _GtkWidgetPrivate       GtkWidgetPrivate;
typedef struct _GtkWidgetClass         GtkWidgetClass;
typedef struct _GtkWidgetClassPrivate  GtkWidgetClassPrivate;

/**
 * GtkAllocation:
 * @x: the X position of the widget’s area relative to its parents allocation.
 * @y: the Y position of the widget’s area relative to its parents allocation.
 * @width: the width of the widget’s allocated area.
 * @height: the height of the widget’s allocated area.
 *
 * The rectangle representing the area allocated for a widget by its parent.
 */
typedef         GdkRectangle       GtkAllocation;

/**
 * GtkTickCallback:
 * @widget: the widget
 * @frame_clock: the frame clock for the widget (same as calling gtk_widget_get_frame_clock())
 * @user_data: user data passed to gtk_widget_add_tick_callback().
 *
 * Callback type for adding a function to update animations. See gtk_widget_add_tick_callback().
 *
 * Returns: %G_SOURCE_CONTINUE if the tick callback should continue to be called,
 *  %G_SOURCE_REMOVE if the tick callback should be removed.
 */
typedef gboolean (*GtkTickCallback) (GtkWidget     *widget,
                                     GdkFrameClock *frame_clock,
                                     gpointer       user_data);

/**
 * GtkRequisition:
 * @width: the widget’s desired width
 * @height: the widget’s desired height
 *
 * A `GtkRequisition` represents the desired size of a widget. See
 * [GtkWidget’s geometry management section](class.Widget.html#height-for-width-geometry-management) for
 * more information.
 */
struct _GtkRequisition
{
  int width;
  int height;
};

/* The widget is the base of the tree for displayable objects.
 *  (A displayable object is one which takes up some amount
 *  of screen real estate). It provides a common base and interface
 *  which actual widgets must adhere to.
 */
struct _GtkWidget
{
  GInitiallyUnowned parent_instance;

  /*< private >*/

  GtkWidgetPrivate *priv;
};

/**
 * GtkWidgetClass:
 * @parent_class: The object class structure needs to be the first
 *   element in the widget class structure in order for the class mechanism
 *   to work correctly. This allows a GtkWidgetClass pointer to be cast to
 *   a GObjectClass pointer.
 * @show: Signal emitted when widget is shown
 * @hide: Signal emitted when widget is hidden.
 * @map: Signal emitted when widget is going to be mapped, that is
 *   when the widget is visible (which is controlled with
 *   gtk_widget_set_visible()) and all its parents up to the toplevel
 *   widget are also visible.
 * @unmap: Signal emitted when widget is going to be unmapped, which
 *   means that either it or any of its parents up to the toplevel
 *   widget have been set as hidden.
 * @realize: Signal emitted when widget is associated with a
 *   `GdkSurface`, which means that gtk_widget_realize() has been called or
 *   the widget has been mapped (that is, it is going to be drawn).
 * @unrealize: Signal emitted when the GdkSurface associated with
 *   widget is destroyed, which means that gtk_widget_unrealize() has
 *   been called or the widget has been unmapped (that is, it is going
 *   to be hidden).
 * @root: Called when the widget gets added to a `GtkRoot` widget. Must
 *   chain up
 * @unroot: Called when the widget is about to be removed from its
 *   `GtkRoot` widget. Must chain up
 * @size_allocate: Called to set the allocation, if the widget does
 *   not have a layout manager.
 * @state_flags_changed: Signal emitted when the widget state changes,
 *   see gtk_widget_get_state_flags().
 * @direction_changed: Signal emitted when the text direction of a
 *   widget changes.
 * @get_request_mode: Called to get the request mode, if the widget
 *   does not have a layout manager.
 *   This allows a widget to tell its parent container whether
 *   it prefers to be allocated in %GTK_SIZE_REQUEST_HEIGHT_FOR_WIDTH or
 *   %GTK_SIZE_REQUEST_WIDTH_FOR_HEIGHT mode.
 *   %GTK_SIZE_REQUEST_HEIGHT_FOR_WIDTH means the widget prefers to have
 *   `GtkWidgetClass.measure()` called first to get the default width (passing
 *   a for_size of -1), then again to get the height for said default width.
 *   %GTK_SIZE_REQUEST_CONSTANT_SIZE disables any height-for-width or
 *   width-for-height geometry management for said widget and is the
 *   default return.
 *   It’s important to note that any widget
 *   which trades height-for-width or width-for-height must respond properly
 *   to a for_size value >= -1 passed to `GtkWidgetClass.measure`, for both
 *   possible orientations.
 * @measure: Called to obtain the minimum and natural size of the widget,
 *   if the widget does not have a layout manager.
 *   Depending on the orientation parameter, the passed for_size can be
 *   interpreted as width or height. A widget will never be allocated less
 *   than its minimum size.
 * @mnemonic_activate: Activates the @widget if @group_cycling is
 *   %FALSE, and just grabs the focus if @group_cycling is %TRUE.
 * @grab_focus: Causes @widget to have the keyboard focus for the
 *   `GtkWindow` it’s inside.
 * @focus: Vfunc for gtk_widget_child_focus()
 * @set_focus_child: Sets the focused child of a widget. Must chain up
 * @move_focus: Signal emitted when a change of focus is requested
 * @keynav_failed: Signal emitted if keyboard navigation fails.
 * @query_tooltip: Signal emitted when “has-tooltip” is %TRUE and the
 *   hover timeout has expired with the cursor hovering “above”
 *   widget; or emitted when widget got focus in keyboard mode.
 * @compute_expand: Computes whether a container should give this
 *   widget extra space when possible.
 * @css_changed: Vfunc called when the CSS used by widget was changed. Widgets
 *   should then discard their caches that depend on CSS and queue resizes or
 *   redraws accordingly. The default implementation will take care of this for
 *   all the default CSS properties, so implementations must chain up.
 * @system_setting_changed: Emitted when a system setting was changed. Must chain up.
 * @snapshot: Vfunc called when a new snapshot of the widget has to be taken.
 * @contains: Vfunc for gtk_widget_contains().
 */
struct _GtkWidgetClass
{
  GInitiallyUnownedClass parent_class;

  /*< public >*/

  /* basics */
  void (* show)                (GtkWidget        *widget);
  void (* hide)                (GtkWidget        *widget);
  void (* map)                 (GtkWidget        *widget);
  void (* unmap)               (GtkWidget        *widget);
  void (* realize)             (GtkWidget        *widget);
  void (* unrealize)           (GtkWidget        *widget);
  void (* root)                (GtkWidget        *widget);
  void (* unroot)              (GtkWidget        *widget);
  void (* size_allocate)       (GtkWidget           *widget,
                                int                  width,
                                int                  height,
                                int                  baseline);
  void (* state_flags_changed) (GtkWidget        *widget,
                                GtkStateFlags     previous_state_flags);
  void (* direction_changed)   (GtkWidget        *widget,
                                GtkTextDirection  previous_direction);

  /* size requests */
  GtkSizeRequestMode (* get_request_mode)               (GtkWidget      *widget);
  void              (* measure) (GtkWidget      *widget,
                                 GtkOrientation  orientation,
                                 int             for_size,
                                 int            *minimum,
                                 int            *natural,
                                 int            *minimum_baseline,
                                 int            *natural_baseline);

  /* Mnemonics */
  gboolean (* mnemonic_activate)        (GtkWidget           *widget,
                                         gboolean             group_cycling);

  /* explicit focus */
  gboolean (* grab_focus)               (GtkWidget           *widget);
  gboolean (* focus)                    (GtkWidget           *widget,
                                         GtkDirectionType     direction);
  void     (* set_focus_child)          (GtkWidget           *widget,
                                         GtkWidget           *child);

  /* keyboard navigation */
  void     (* move_focus)               (GtkWidget           *widget,
                                         GtkDirectionType     direction);
  gboolean (* keynav_failed)            (GtkWidget           *widget,
                                         GtkDirectionType     direction);

  gboolean     (* query_tooltip)      (GtkWidget  *widget,
                                       int         x,
                                       int         y,
                                       gboolean    keyboard_tooltip,
                                       GtkTooltip *tooltip);

  void         (* compute_expand)     (GtkWidget  *widget,
                                       gboolean   *hexpand_p,
                                       gboolean   *vexpand_p);

  void         (* css_changed)                 (GtkWidget            *widget,
                                                GtkCssStyleChange    *change);

  void         (* system_setting_changed)      (GtkWidget            *widget,
                                                GtkSystemSetting      settings);

  void         (* snapshot)                    (GtkWidget            *widget,
                                                GtkSnapshot          *snapshot);

  gboolean     (* contains)                    (GtkWidget *widget,
                                                double     x,
                                                double     y);

  /*< private >*/

  GtkWidgetClassPrivate *priv;

  gpointer padding[8];
};



GType      gtk_widget_get_type            (void) ;

void       gtk_widget_unparent            (GtkWidget           *widget);

void       gtk_widget_show                (GtkWidget           *widget);

void       gtk_widget_hide                (GtkWidget           *widget);

void       gtk_widget_map                 (GtkWidget           *widget);

void       gtk_widget_unmap               (GtkWidget           *widget);

void       gtk_widget_realize             (GtkWidget           *widget);

void       gtk_widget_unrealize           (GtkWidget           *widget);

/* Queuing draws */

void       gtk_widget_queue_draw          (GtkWidget           *widget);

void       gtk_widget_queue_resize        (GtkWidget           *widget);

void       gtk_widget_queue_allocate      (GtkWidget           *widget);

GdkFrameClock* gtk_widget_get_frame_clock (GtkWidget           *widget);


void       gtk_widget_size_allocate       (GtkWidget           *widget,
                                           const GtkAllocation *allocation,
                                           int                  baseline);

void       gtk_widget_allocate            (GtkWidget               *widget,
                                           int                      width,
                                           int                      height,
                                           int                      baseline,
                                           GskTransform            *transform);


GtkSizeRequestMode  gtk_widget_get_request_mode               (GtkWidget      *widget);

void gtk_widget_measure (GtkWidget      *widget,
                         GtkOrientation  orientation,
                         int             for_size,
                         int            *minimum,
                         int            *natural,
                         int            *minimum_baseline,
                         int            *natural_baseline);

void                gtk_widget_get_preferred_size             (GtkWidget      *widget,
                                                               GtkRequisition *minimum_size,
                                                               GtkRequisition *natural_size);


void                    gtk_widget_set_layout_manager   (GtkWidget        *widget,
                                                         GtkLayoutManager *layout_manager);

GtkLayoutManager *      gtk_widget_get_layout_manager   (GtkWidget        *widget);


void                    gtk_widget_class_set_layout_manager_type        (GtkWidgetClass *widget_class,
                                                                         GType           type);

GType                   gtk_widget_class_get_layout_manager_type        (GtkWidgetClass *widget_class);


void       gtk_widget_class_add_binding   (GtkWidgetClass      *widget_class,
                                           guint                keyval,
                                           GdkModifierType      mods,
                                           GtkShortcutFunc      callback,
                                           const char          *format_string,
                                           ...);

void       gtk_widget_class_add_binding_signal
                                          (GtkWidgetClass      *widget_class,
                                           guint                keyval,
                                           GdkModifierType      mods,
                                           const char          *signal,
                                           const char          *format_string,
                                           ...);

void       gtk_widget_class_add_binding_action
                                          (GtkWidgetClass      *widget_class,
                                           guint                keyval,
                                           GdkModifierType      mods,
                                           const char          *action_name,
                                           const char          *format_string,
                                           ...);

void       gtk_widget_class_add_shortcut  (GtkWidgetClass      *widget_class,
                                           GtkShortcut         *shortcut);


void       gtk_widget_class_set_activate_signal                 (GtkWidgetClass *widget_class,
                                                                 guint           signal_id);

void       gtk_widget_class_set_activate_signal_from_name       (GtkWidgetClass *widget_class,
                                                                 const char     *signal_name);

guint      gtk_widget_class_get_activate_signal                 (GtkWidgetClass *widget_class);


gboolean   gtk_widget_mnemonic_activate   (GtkWidget           *widget,
                                           gboolean             group_cycling);

gboolean   gtk_widget_activate               (GtkWidget        *widget);


void       gtk_widget_set_can_focus       (GtkWidget           *widget,
                                           gboolean             can_focus);

gboolean   gtk_widget_get_can_focus       (GtkWidget           *widget);

void       gtk_widget_set_focusable       (GtkWidget           *widget,
                                           gboolean             focusable);

gboolean   gtk_widget_get_focusable       (GtkWidget           *widget);

gboolean   gtk_widget_has_focus           (GtkWidget           *widget);

gboolean   gtk_widget_is_focus            (GtkWidget           *widget);

gboolean   gtk_widget_has_visible_focus   (GtkWidget           *widget);

gboolean   gtk_widget_grab_focus          (GtkWidget           *widget);

void       gtk_widget_set_focus_on_click  (GtkWidget           *widget,
                                           gboolean             focus_on_click);

gboolean   gtk_widget_get_focus_on_click  (GtkWidget           *widget);


void       gtk_widget_set_can_target      (GtkWidget           *widget,
                                           gboolean             can_target);

gboolean   gtk_widget_get_can_target      (GtkWidget           *widget);


gboolean   gtk_widget_has_default         (GtkWidget           *widget);


void      gtk_widget_set_receives_default (GtkWidget           *widget,
                                           gboolean             receives_default);

gboolean  gtk_widget_get_receives_default (GtkWidget           *widget);



void                  gtk_widget_set_name               (GtkWidget    *widget,
                                                         const char   *name);

const char *         gtk_widget_get_name               (GtkWidget    *widget);



void                  gtk_widget_set_state_flags        (GtkWidget     *widget,
                                                         GtkStateFlags  flags,
                                                         gboolean       clear);

void                  gtk_widget_unset_state_flags      (GtkWidget     *widget,
                                                         GtkStateFlags  flags);

GtkStateFlags         gtk_widget_get_state_flags        (GtkWidget     *widget);


void                  gtk_widget_set_sensitive          (GtkWidget    *widget,
                                                         gboolean      sensitive);

gboolean              gtk_widget_get_sensitive          (GtkWidget    *widget);

gboolean              gtk_widget_is_sensitive           (GtkWidget    *widget);


void                  gtk_widget_set_visible            (GtkWidget    *widget,
                                                         gboolean      visible);

gboolean              gtk_widget_get_visible            (GtkWidget    *widget);

gboolean              gtk_widget_is_visible             (GtkWidget    *widget);


gboolean              gtk_widget_is_drawable            (GtkWidget    *widget);

gboolean              gtk_widget_get_realized           (GtkWidget    *widget);

gboolean              gtk_widget_get_mapped             (GtkWidget    *widget);


void                  gtk_widget_set_parent             (GtkWidget    *widget,
                                                         GtkWidget    *parent);

GtkWidget *           gtk_widget_get_parent             (GtkWidget    *widget);


GtkRoot *             gtk_widget_get_root               (GtkWidget    *widget);


GtkNative *           gtk_widget_get_native             (GtkWidget    *widget);


void                  gtk_widget_set_child_visible      (GtkWidget    *widget,
                                                         gboolean      child_visible);

gboolean              gtk_widget_get_child_visible      (GtkWidget    *widget);


int                   gtk_widget_get_allocated_width    (GtkWidget     *widget);

int                   gtk_widget_get_allocated_height   (GtkWidget     *widget);

int                   gtk_widget_get_allocated_baseline (GtkWidget     *widget);


void                  gtk_widget_get_allocation         (GtkWidget     *widget,
                                                         GtkAllocation *allocation);

gboolean                gtk_widget_compute_transform            (GtkWidget              *widget,
                                                                 GtkWidget              *target,
                                                                 graphene_matrix_t      *out_transform) ;

gboolean                gtk_widget_compute_bounds               (GtkWidget              *widget,
                                                                 GtkWidget              *target,
                                                                 graphene_rect_t        *out_bounds) ;

gboolean                gtk_widget_compute_point                (GtkWidget              *widget,
                                                                 GtkWidget              *target,
                                                                 const graphene_point_t *point,
                                                                 graphene_point_t       *out_point) ;


int                   gtk_widget_get_width              (GtkWidget     *widget);

int                   gtk_widget_get_height             (GtkWidget     *widget);

int                   gtk_widget_get_size               (GtkWidget     *widget,
                                                         GtkOrientation orientation);


gboolean   gtk_widget_child_focus         (GtkWidget           *widget,
                                           GtkDirectionType     direction);

gboolean   gtk_widget_keynav_failed       (GtkWidget           *widget,
                                           GtkDirectionType     direction);

void       gtk_widget_error_bell          (GtkWidget           *widget);


void       gtk_widget_set_size_request    (GtkWidget           *widget,
                                           int                  width,
                                           int                  height);

void       gtk_widget_get_size_request    (GtkWidget           *widget,
                                           int                 *width,
                                           int                 *height);

void       gtk_widget_set_opacity         (GtkWidget           *widget,
                                           double               opacity);

double     gtk_widget_get_opacity         (GtkWidget           *widget);

void         gtk_widget_set_overflow      (GtkWidget           *widget,
                                           GtkOverflow          overflow);

GtkOverflow  gtk_widget_get_overflow      (GtkWidget           *widget);


GtkWidget*   gtk_widget_get_ancestor    (GtkWidget      *widget,
                                         GType           widget_type);


int           gtk_widget_get_scale_factor (GtkWidget *widget);

GdkDisplay *  gtk_widget_get_display     (GtkWidget *widget);

GtkSettings*  gtk_widget_get_settings    (GtkWidget *widget);

GdkClipboard *gtk_widget_get_clipboard   (GtkWidget *widget);

GdkClipboard *gtk_widget_get_primary_clipboard (GtkWidget *widget);


/* Expand flags and related support */

gboolean gtk_widget_get_hexpand          (GtkWidget      *widget);

void     gtk_widget_set_hexpand          (GtkWidget      *widget,
                                          gboolean        expand);

gboolean gtk_widget_get_hexpand_set      (GtkWidget      *widget);

void     gtk_widget_set_hexpand_set      (GtkWidget      *widget,
                                          gboolean        set);

gboolean gtk_widget_get_vexpand          (GtkWidget      *widget);

void     gtk_widget_set_vexpand          (GtkWidget      *widget,
                                          gboolean        expand);

gboolean gtk_widget_get_vexpand_set      (GtkWidget      *widget);

void     gtk_widget_set_vexpand_set      (GtkWidget      *widget,
                                          gboolean        set);

gboolean gtk_widget_compute_expand       (GtkWidget      *widget,
                                          GtkOrientation  orientation);

/* Margin and alignment */

GtkAlign gtk_widget_get_halign        (GtkWidget *widget);

void     gtk_widget_set_halign        (GtkWidget *widget,
                                       GtkAlign   align);

GtkAlign gtk_widget_get_valign        (GtkWidget *widget);

void     gtk_widget_set_valign        (GtkWidget *widget,
                                       GtkAlign   align);

int      gtk_widget_get_margin_start  (GtkWidget *widget);

void     gtk_widget_set_margin_start  (GtkWidget *widget,
                                       int        margin);

int      gtk_widget_get_margin_end    (GtkWidget *widget);

void     gtk_widget_set_margin_end    (GtkWidget *widget,
                                       int        margin);

int      gtk_widget_get_margin_top    (GtkWidget *widget);

void     gtk_widget_set_margin_top    (GtkWidget *widget,
                                       int        margin);

int      gtk_widget_get_margin_bottom (GtkWidget *widget);

void     gtk_widget_set_margin_bottom (GtkWidget *widget,
                                       int        margin);


gboolean     gtk_widget_is_ancestor     (GtkWidget      *widget,
                                         GtkWidget      *ancestor);


gboolean     gtk_widget_translate_coordinates (GtkWidget  *src_widget,
                                               GtkWidget  *dest_widget,
                                               double      src_x,
                                               double      src_y,
                                               double     *dest_x,
                                               double     *dest_y);


gboolean     gtk_widget_contains              (GtkWidget  *widget,
                                               double      x,
                                               double      y);

GtkWidget *  gtk_widget_pick                  (GtkWidget   *widget,
                                               double       x,
                                               double       y,
                                               GtkPickFlags flags);


void         gtk_widget_add_controller        (GtkWidget          *widget,
                                               GtkEventController *controller);

void         gtk_widget_remove_controller     (GtkWidget          *widget,
                                               GtkEventController *controller);


PangoContext *gtk_widget_create_pango_context (GtkWidget   *widget);

PangoContext *gtk_widget_get_pango_context    (GtkWidget   *widget);

void gtk_widget_set_font_options (GtkWidget                  *widget,
                                  const cairo_font_options_t *options);

const cairo_font_options_t *gtk_widget_get_font_options (GtkWidget *widget);

PangoLayout  *gtk_widget_create_pango_layout  (GtkWidget   *widget,
                                               const char *text);

/* Functions for setting directionality for widgets */


void             gtk_widget_set_direction         (GtkWidget        *widget,
                                                   GtkTextDirection  dir);

GtkTextDirection gtk_widget_get_direction         (GtkWidget        *widget);


void             gtk_widget_set_default_direction (GtkTextDirection  dir);

GtkTextDirection gtk_widget_get_default_direction (void);


void                    gtk_widget_set_cursor                   (GtkWidget              *widget,
                                                                 GdkCursor              *cursor);

void                    gtk_widget_set_cursor_from_name         (GtkWidget              *widget,
                                                                 const char             *name);

GdkCursor *             gtk_widget_get_cursor                   (GtkWidget              *widget);


GList* gtk_widget_list_mnemonic_labels  (GtkWidget *widget);

void   gtk_widget_add_mnemonic_label    (GtkWidget *widget,
                                         GtkWidget *label);

void   gtk_widget_remove_mnemonic_label (GtkWidget *widget,
                                         GtkWidget *label);


void            gtk_widget_trigger_tooltip_query        (GtkWidget   *widget);

void            gtk_widget_set_tooltip_text             (GtkWidget   *widget,
                                                         const char  *text);

const char *    gtk_widget_get_tooltip_text             (GtkWidget   *widget);

void            gtk_widget_set_tooltip_markup           (GtkWidget   *widget,
                                                         const char  *markup);

const char *    gtk_widget_get_tooltip_markup           (GtkWidget   *widget);

void            gtk_widget_set_has_tooltip              (GtkWidget   *widget,
                                                         gboolean     has_tooltip);

gboolean        gtk_widget_get_has_tooltip              (GtkWidget   *widget);


GType           gtk_requisition_get_type (void) ;

GtkRequisition *gtk_requisition_new      (void) ;

GtkRequisition *gtk_requisition_copy     (const GtkRequisition *requisition);

void            gtk_requisition_free     (GtkRequisition       *requisition);


gboolean     gtk_widget_in_destruction (GtkWidget *widget);


GtkStyleContext * gtk_widget_get_style_context (GtkWidget *widget);


void              gtk_widget_class_set_css_name (GtkWidgetClass *widget_class,
                                                 const char     *name);

const char *      gtk_widget_class_get_css_name (GtkWidgetClass *widget_class);


guint gtk_widget_add_tick_callback (GtkWidget       *widget,
                                    GtkTickCallback  callback,
                                    gpointer         user_data,
                                    GDestroyNotify   notify);


void gtk_widget_remove_tick_callback (GtkWidget       *widget,
                                      guint            id);

/**
 * gtk_widget_class_bind_template_callback:
 * @widget_class: a `GtkWidgetClass`
 * @callback: the callback symbol
 *
 * Binds a callback function defined in a template to the @widget_class.
 *
 * This macro is a convenience wrapper around the
 * gtk_widget_class_bind_template_callback_full() function. It is not
 * supported after gtk_widget_class_set_template_scope() has been used
 * on @widget_class.
 */
//#define gtk_widget_class_bind_template_callback(widget_class, callback) \
//  gtk_widget_class_bind_template_callback_full (GTK_WIDGET_CLASS (widget_class), \
//                                                #callback, \
//                                                G_CALLBACK (callback))

/**
 * gtk_widget_class_bind_template_child:
 * @widget_class: a `GtkWidgetClass`
 * @TypeName: the type name of this widget
 * @member_name: name of the instance member in the instance struct for @data_type
 *
 * Binds a child widget defined in a template to the @widget_class.
 *
 * This macro is a convenience wrapper around the
 * gtk_widget_class_bind_template_child_full() function.
 *
 * This macro will use the offset of the @member_name inside the @TypeName
 * instance structure.
 */
//#define gtk_widget_class_bind_template_child(widget_class, TypeName, member_name) \
//  gtk_widget_class_bind_template_child_full (widget_class, \
//                                             #member_name, \
//                                             FALSE, \
//                                             G_STRUCT_OFFSET (TypeName, member_name))

/**
 * gtk_widget_class_bind_template_child_internal:
 * @widget_class: a `GtkWidgetClass`
 * @TypeName: the type name, in CamelCase
 * @member_name: name of the instance member in the instance struct for @data_type
 *
 * Binds a child widget defined in a template to the @widget_class, and
 * also makes it available as an internal child in GtkBuilder, under the
 * name @member_name.
 *
 * This macro is a convenience wrapper around the
 * gtk_widget_class_bind_template_child_full() function.
 *
 * This macro will use the offset of the @member_name inside the @TypeName
 * instance structure.
 */
//#define gtk_widget_class_bind_template_child_internal(widget_class, TypeName, member_name) \
//  gtk_widget_class_bind_template_child_full (widget_class, \
//                                             #member_name, \
//                                             TRUE, \
//                                             G_STRUCT_OFFSET (TypeName, member_name))

/**
 * gtk_widget_class_bind_template_child_private:
 * @widget_class: a `GtkWidgetClass`
 * @TypeName: the type name of this widget
 * @member_name: name of the instance private member in the private struct for @data_type
 *
 * Binds a child widget defined in a template to the @widget_class.
 *
 * This macro is a convenience wrapper around the
 * gtk_widget_class_bind_template_child_full() function.
 *
 * This macro will use the offset of the @member_name inside the @TypeName
 * private data structure (it uses G_PRIVATE_OFFSET(), so the private struct
 * must be added with G_ADD_PRIVATE()).
 */
//#define gtk_widget_class_bind_template_child_private(widget_class, TypeName, member_name) \
//  gtk_widget_class_bind_template_child_full (widget_class, \
//                                             #member_name, \
//                                             FALSE, \
//                                             G_PRIVATE_OFFSET (TypeName, member_name))

/**
 * gtk_widget_class_bind_template_child_internal_private:
 * @widget_class: a `GtkWidgetClass`
 * @TypeName: the type name, in CamelCase
 * @member_name: name of the instance private member on the private struct for @data_type
 *
 * Binds a child widget defined in a template to the @widget_class, and
 * also makes it available as an internal child in GtkBuilder, under the
 * name @member_name.
 *
 * This macro is a convenience wrapper around the
 * gtk_widget_class_bind_template_child_full() function.
 *
 * This macro will use the offset of the @member_name inside the @TypeName
 * private data structure.
 */
//#define gtk_widget_class_bind_template_child_internal_private(widget_class, TypeName, member_name) \
//  gtk_widget_class_bind_template_child_full (widget_class, \
//                                             #member_name, \
//                                             TRUE, \
//                                             G_PRIVATE_OFFSET (TypeName, member_name))


void    gtk_widget_init_template                        (GtkWidget             *widget);

GObject *gtk_widget_get_template_child                  (GtkWidget             *widget,
                                                         GType                  widget_type,
                                                         const char            *name);

void    gtk_widget_class_set_template                   (GtkWidgetClass        *widget_class,
                                                         GBytes                *template_bytes);

void    gtk_widget_class_set_template_from_resource     (GtkWidgetClass        *widget_class,
                                                         const char            *resource_name);

void    gtk_widget_class_bind_template_callback_full    (GtkWidgetClass        *widget_class,
                                                         const char            *callback_name,
                                                         GCallback              callback_symbol);

void    gtk_widget_class_set_template_scope             (GtkWidgetClass        *widget_class,
                                                         GtkBuilderScope       *scope);

void    gtk_widget_class_bind_template_child_full       (GtkWidgetClass        *widget_class,
                                                         const char            *name,
                                                         gboolean               internal_child,
                                                         gssize                 struct_offset);


void                    gtk_widget_insert_action_group  (GtkWidget    *widget,
                                                         const char   *name,
                                                         GActionGroup *group);


gboolean                gtk_widget_activate_action      (GtkWidget  *widget,
                                                         const char *name,
                                                         const char *format_string,
                                                         ...);

gboolean                gtk_widget_activate_action_variant (GtkWidget  *widget,
                                                            const char *name,
                                                            GVariant   *args);


void                    gtk_widget_activate_default     (GtkWidget *widget);


void                    gtk_widget_set_font_map         (GtkWidget             *widget,
                                                         PangoFontMap          *font_map);

PangoFontMap *          gtk_widget_get_font_map         (GtkWidget             *widget);


GtkWidget *             gtk_widget_get_first_child      (GtkWidget *widget);

GtkWidget *             gtk_widget_get_last_child       (GtkWidget *widget);

GtkWidget *             gtk_widget_get_next_sibling     (GtkWidget *widget);

GtkWidget *             gtk_widget_get_prev_sibling     (GtkWidget *widget);

GListModel *            gtk_widget_observe_children     (GtkWidget *widget);

GListModel *            gtk_widget_observe_controllers  (GtkWidget *widget);

void                    gtk_widget_insert_after         (GtkWidget *widget,
                                                         GtkWidget *parent,
                                                         GtkWidget *previous_sibling);

void                    gtk_widget_insert_before        (GtkWidget *widget,
                                                         GtkWidget *parent,
                                                         GtkWidget *next_sibling);

void                    gtk_widget_set_focus_child      (GtkWidget *widget,
                                                         GtkWidget *child);

GtkWidget *             gtk_widget_get_focus_child      (GtkWidget *widget);


void                    gtk_widget_snapshot_child       (GtkWidget   *widget,
                                                         GtkWidget   *child,
                                                         GtkSnapshot *snapshot);

gboolean                gtk_widget_should_layout        (GtkWidget   *widget);

const char *            gtk_widget_get_css_name         (GtkWidget   *self) ;

void                    gtk_widget_add_css_class        (GtkWidget   *widget,
                                                         const char  *css_class);

void                    gtk_widget_remove_css_class     (GtkWidget   *widget,
                                                         const char  *css_class);

gboolean                gtk_widget_has_css_class        (GtkWidget   *widget,
                                                         const char  *css_class);

char **                 gtk_widget_get_css_classes      (GtkWidget   *widget);

void                    gtk_widget_set_css_classes      (GtkWidget   *widget,
                                                         const char **classes);




/**
 * GtkWidgetActionActivateFunc:
 * @widget: the widget to which the action belongs
 * @action_name: the action name
 * @parameter: parameter for activation
 *
 * The type of the callback functions used for activating
 * actions installed with gtk_widget_class_install_action().
 *
 * The @parameter must match the @parameter_type of the action.
 */
typedef void (* GtkWidgetActionActivateFunc) (GtkWidget  *widget,
                                              const char *action_name,
                                              GVariant   *parameter);


void                    gtk_widget_class_install_action (GtkWidgetClass              *widget_class,
                                                         const char                  *action_name,
                                                         const char                  *parameter_type,
                                                         GtkWidgetActionActivateFunc  activate);


void                    gtk_widget_class_install_property_action (GtkWidgetClass *widget_class,
                                                                  const char     *action_name,
                                                                  const char     *property_name);


gboolean               gtk_widget_class_query_action  (GtkWidgetClass      *widget_class,
                                                       guint                index_,
                                                       GType               *owner,
                                                       const char         **action_name,
                                                       const GVariantType **parameter_type,
                                                       const char         **property_name);


void                    gtk_widget_action_set_enabled (GtkWidget  *widget,
                                                       const char *action_name,
                                                       gboolean    enabled);



void                    gtk_widget_class_set_accessible_role    (GtkWidgetClass    *widget_class,
                                                                 GtkAccessibleRole  accessible_role);

GtkAccessibleRole       gtk_widget_class_get_accessible_role    (GtkWidgetClass    *widget_class);




// // // // 

#endif /* __GTK_WIDGET_H__ */