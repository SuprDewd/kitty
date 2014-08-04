#include "../config.h"

#include <stdlib.h>
#include <stdio.h>
#include <webkit2/webkit2.h>

void usage(void) {
    puts("Usage: kitty URL");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    if (argc != 2) {
        usage();
        return 1;
    }

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), PACKAGE_NAME);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *web_view = webkit_web_view_new();
    WebKitSettings *settings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(web_view));
    g_object_set(G_OBJECT(settings), "enable-developer-extras", TRUE, NULL);

    gtk_container_add(GTK_CONTAINER(window), web_view);

    gtk_widget_show(web_view);
    gtk_widget_show(window);

    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web_view), argv[1]);

    /* WebKitWebInspector *inspector = webkit_web_view_get_inspector(WEBKIT_WEB_VIEW(web_view)); */
    /* webkit_web_inspector_show(WEBKIT_WEB_INSPECTOR(inspector)); */

    gtk_main();

    return EXIT_SUCCESS;
}

