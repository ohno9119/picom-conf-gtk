#include <dirent.h>
#include <gtk/gtk.h>
#include <libconfig.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libintl.h>
#include <locale.h>
#include "config.h"
#include "ui.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    bindtextdomain("picom-conf-gtk", "/usr/share/locale");
    bind_textdomain_codeset("picom-conf-gtk", "UTF-8");
    textdomain("picom-conf-gtk");
    gtk_init(&argc, &argv);
    init_config();
    open_config_file(); 
    create_window();
    destroy_config();
    gtk_main();
    return 0;
}
