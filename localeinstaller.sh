#!/usr/bin/env bash

JUST_COMPILE='false'
LOCALE="$LANG"

while getopts ':cl:' 'OPTKEY'; do
    case ${OPTKEY} in
        'c')
            JUST_COMPILE='true'
            ;;
        'l')
		    LOCALE="$OPTARG"
            ;;
    esac
done

CPATH="$PWD/locales/$LOCALE"
POPATH="$CPATH/picom-conf-gtk.po"
MOPATHL="$CPATH/LC_MESSAGES"
MOPATH="$MOPATHL/picom-conf-gtk.mo"

cd "$PWD/locales/"

if ${JUST_COMPILE}; then
	echo "Not installing"
else	
	if [ "$EUID" -ne 0 ]
		then echo "Please run as root"
		exit
	fi
fi

if [ -d "$CPATH" ]; then
	echo "Locale found"
else
	echo "Locale not found"
	exit 1
fi

if [ -d "$MOPATHL" ]; then
	echo "LC_MESSAGES found"
else
	echo "LC_MESSAGES not found"
	mkdir "$MOPATHL"
fi

msgfmt "$POPATH" --output-file="$MOPATH"

if ${JUST_COMPILE}; then
	echo "Done"
else
	install -Dm0644 "$MOPATH" "/usr/share/locale/$LOCALE/LC_MESSAGES/picom-conf-gtk.mo"
	echo "Done"
fi
