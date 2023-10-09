#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "CALCULATOR_GTK_4");
	gtk_widget_show(window);

}

int main(int argc, char *argv[])
{
	int status = 0;
	GtkApplication *app;
	app = gtk_application_new("org.gtk.Calculator_GTK_4", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return status;
}

