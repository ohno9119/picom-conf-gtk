SOURCES = main.c localization.c config.c  ui.c
CC ?= cc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = -g -w $(shell $(PKGCONFIG) --cflags gtk+-3.0 libconfig)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0 libconfig) -lm
OBJS  = ${SOURCES:.c=.o}
PACKAGE = picom-conf-gtk

all: picom-conf-gtk

%.o: %.c
	${CC} ${CFLAGS} ${LIBS} -c $<
	
picom-conf-gtk: $(OBJS)
	${CC} -o ${PACKAGE} ${OBJS} ${CFLAGS} ${LIBS}
	
.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f picom-conf-gtk
	
uninstall:
	rm -f /usr/local/bin/picom-conf-gtk
	rm -f /usr/share/icons/hicolor/64x64/apps/picom-conf.png
	
cinstall: clean picom-conf-gtk install

install:
	install -Dm0755 picom-conf-gtk /usr/local/bin/picom-conf-gtk
	install -Dm0644 picom-conf.png /usr/share/icons/hicolor/64x64/apps/picom-conf.png
	
