# picom-conf-gtk
A graphical configuration tool for picom.

## Building and installing

Building it is as simple as:
```
make
```

Once built, you can use the install target to install picom-conf-gtk onto your system:
```
make install
```

You can also use the uninstall target to remove it:
```
make uninstall
```

## Dependencies
This project depends on:
- [`GTK+ 3.0 (libgtk-3-dev)`](https://www.gtk.org/)
- [`libconfig (libconfig-dev)`](https://hyperrealm.github.io/libconfig)

## Localization
The localization system is very basic. It loads in localized text strings from: /usr/share/picomconfgtk/locales/(LOCALE NAME).locale. An example localization has been provided as "example.locale". Ideally a proper gettext based system should be implemented but I currently do not have the time to figure out gettext.
