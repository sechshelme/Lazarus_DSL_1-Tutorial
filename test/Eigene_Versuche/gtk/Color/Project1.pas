program Project1;

uses
  GLib2,
  Gdk2,
  Gtk2;

  procedure press(widget: PGtkWidget; event: PGdkEventButton; user_data: gpointer); cdecl;
  begin
    WriteLn('Press Button ', PtrUInt(user_data));
  end;

  procedure main;
  var
    Window, fixed, btn1, btn2, btn3, frame1: PGtkWidget;
    col: TGdkColor = (pixel: 0; red: 27000; green: 30000; blue: 35000);

  begin
    GTK_Init(@argc, @argv);

    Window := gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Window), 'Hallo');
    gtk_window_set_default_size(GTK_WINDOW(Window), 500, 500);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed := gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);


    frame1 := gtk_frame_new('Hello World');
    gtk_frame_set_shadow_type(GTK_FRAME(frame1), GTK_SHADOW_IN);
    gtk_fixed_put(GTK_FIXED(fixed), frame1, 150, 150);
    gtk_widget_modify_bg(fixed, GTK_STATE_NORMAL, @col);
    gtk_widget_modify_fg(fixed, GTK_STATE_NORMAL, @col);

    btn1 := gtk_button_new_with_label('Button1');
    gtk_fixed_put(GTK_FIXED(fixed), btn1, 150, 50);
    gtk_widget_set_size_request(btn1, 75, 25);
    gtk_widget_modify_bg(btn1, GTK_STATE_NORMAL, @col);
    gtk_widget_modify_fg(btn1, GTK_STATE_NORMAL, @col);
    gtk_signal_connect(PGtkObject(btn1), 'clicked', G_CALLBACK(@press), Pointer(1));

    btn2 := gtk_button_new_with_label('Button2');
    gtk_fixed_put(GTK_FIXED(fixed), btn2, 15, 15);
    gtk_widget_set_size_request(btn2, 75, 25);
    gtk_signal_connect(PGtkObject(btn2), 'clicked', G_CALLBACK(@press), Pointer(2));

    btn3 := gtk_button_new_with_label('Button3');
    gtk_fixed_put(GTK_FIXED(fixed), btn3, 100, 100);
    gtk_widget_set_size_request(btn3, 75, 25);
    gtk_signal_connect(PGtkObject(btn3), 'clicked', G_CALLBACK(@press), Pointer(3));

    gtk_widget_show_all(window);

    g_signal_connect(G_OBJECT(window), 'destroy', G_CALLBACK(@gtk_main_quit), nil);

    GTK_Main;

  end;

begin
  main;
end.
