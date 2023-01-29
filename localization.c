#include <dirent.h>
#include <libconfig.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "localization.h"

config_t localcfg;
int file_loaded = 0;

void show_localization_error()
{
    char message[256];
    snprintf(message, sizeof message, "Locale load failed: %s (%s:%d)\n", config_error_text(&localcfg), config_error_file(&localcfg), config_error_line(&localcfg));
    printf("%s", message);
}

void loadlc()
{
    char *locales_file;
    char *lang;
    lang = getenv("LANG");
    locales_file = malloc(strlen("/usr/share/picomconfgtk/locales/") + strlen(lang) + strlen(".locale") + 1);
    strcpy(locales_file, "/usr/share/picomconfgtk/locales/");
    strcat(locales_file, lang);
    strcat(locales_file, ".locale");
    config_init(&localcfg);
    if (access(locales_file, F_OK) != 0)
    {
        printf("Unable to load %s. Does not exist.\n", locales_file);
    }
    if (config_read_file(&localcfg, locales_file) == CONFIG_FALSE)
    {
        printf("Unable to load %s\n", locales_file);
        show_localization_error();
        return;
    }
    file_loaded = 1;
    printf("Loaded %s\n", locales_file);
}

void replace_spaces(char *str)
{
    int ix = 0;
    while (*str)
    {
        if (*str == ' ')
            *str = '_';
        str++;
        ix++;
    }
    str - ix;
}

char *lcgettext(const char *value)
{
    const char *retval;
    char *retvalact;
    char *Cvalue = malloc(strlen(value) + 1);
    strcpy(Cvalue, value);
    replace_spaces(Cvalue);

    if (file_loaded == 1)
    {
        if (config_lookup_string(&localcfg, Cvalue, &retval) != CONFIG_FALSE)
        {
            retvalact = malloc(strlen(retval) + 1);
            strcpy(retvalact, retval);
            printf("%s found. Returning %s\n", Cvalue, retvalact);
        }
        else
        {
            retvalact = malloc(strlen(value) + 1);
            strcpy(retvalact, value);
            printf("%s not found. Returning %s\n", Cvalue, retvalact);
        }
    }
    else
    {
        retvalact = malloc(strlen(value) + 1);
        strcpy(retvalact, value);
        printf("(Key value:%s) Locale file not loaded. Returning %s\n", Cvalue, retvalact);
    }
    return strdup(retvalact);
}
