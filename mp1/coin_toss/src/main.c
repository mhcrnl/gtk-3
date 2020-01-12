#include <gtk/gtk.h>

GtkWidget *g_lbl_coin;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/coin_toss.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    g_lbl_coin = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_coin"));

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_lbl_toss_clicked()
{
	gboolean result;
	result = g_random_boolean();
	if (result == TRUE) {
		gtk_label_set_text(GTK_LABEL(g_lbl_coin), "Heads");
		g_print("Heads\n");
	}
	else {
		gtk_label_set_text(GTK_LABEL(g_lbl_coin), "Tails");
		g_print("Tails\n");
	}
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
