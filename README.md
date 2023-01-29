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

## Localizations 
The localization system is currently complete aside from some minor bugs.
This program loads in localized text strings from: /usr/share/picomconfgtk/locales/(LOCALE NAME).locale.
An example localization has been provided as "example.locale".
