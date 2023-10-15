#include <gtk/gtk.h>

static void
huyak(GtkButton *button, GtkWindow * window)
{
	gtk_window_destroy(window);
}

static void 
app_activate(GApplication *app, gpointer *user_data)
{
    GtkWidget *window;
	GtkWidget *placeholder_history;
	GtkWidget *placeholder_terminal;
	GtkWidget *placeholder_button_pane;
    GtkWidget *vertical_box;


	window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "Carculator");
    // gtk_window_set_default_size (GTK_WINDOW(window), 360, 640);
    
	placeholder_history = gtk_label_new("HISTORY");
	placeholder_terminal = gtk_label_new("TERMINAL");
	placeholder_button_pane = gtk_button_new_with_label("DESTROY WINDOW, MUST BE BUTTONS");
	g_signal_connect(placeholder_button_pane, "clicked", G_CALLBACK(huyak), window);

    vertical_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(vertical_box), false);
    gtk_window_set_child(GTK_WINDOW(window), vertical_box);

    gtk_box_append(GTK_BOX(vertical_box), placeholder_history);
    gtk_box_append(GTK_BOX(vertical_box), placeholder_terminal);
    gtk_box_append(GTK_BOX(vertical_box), placeholder_button_pane);
	
	gtk_window_present(GTK_WINDOW(window));
}


int 
main (int argc, char * argv[])
{
    GtkApplication *app;
    int stat;
    app = gtk_application_new
                    ("lnp.calculator", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
    stat = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return stat;
}
