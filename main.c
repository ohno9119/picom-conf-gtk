#include <dirent.h>
#include <gtk/gtk.h>
#include <libconfig.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"
#include "ui.h"
#include "localization.h"

int main(int argc, char *argv[])
{
	loadlc();
    gtk_init(&argc, &argv);
    init_config();
    open_config_file(); 
    create_window();
    destroy_config();
    gtk_main();
    return 0;
}
