# picom-conf-gtk
A graphical configuration tool for picom.

## Building and installing

Building it is as simple as:
```
$ make
```

Once built, you can use the install target to install picom-conf-gtk onto your system:
```
# make install
```

You can also use the uninstall target to remove it:
```
#make uninstall
```

## Dependencies
This project depends on:
- [`GTK+ 3.0 (libgtk-3-dev)`](https://www.gtk.org/)
- [`libconfig (libconfig-dev)`](https://hyperrealm.github.io/libconfig)
- [`GNU gettext (gettext)`](https://www.gnu.org/software/gettext/)

## Localization
Localizations have been implemented through GNU gettext. This repository has a script that allows you to install localizations easily.

To compile and install the localization files for your current locale (if available) use this command:
```
# ./localeinstaller.sh
```
To compile and install the localization files for a specified locale (if available) use the -l flag, like this:
```
# ./localeinstaller.sh -l (INSERT LOCALE HERE)
```
You can also skip installing the localization files by using the -c flag, you can also use the script as a regular user when used.


