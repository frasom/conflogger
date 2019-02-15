# Makefile for  conflogger
# 

CC=gcc
CFLAGS=-Wall -std=c99

SRCDIR = ./source
EXECDIR = ./DEB/bin
MANDIR = ./DEB/usr/share/man/man1
OBJ = *.o
BAK = *~

all:  deb exec man

deb: conflogger
	strip $(EXECDIR)/conflogger
	dpkg -b ./DEB conflogger.deb

exec: conflogger
	mkdir -p $(EXECDIR)

conflogger: $(SRCDIR)/conflog.c
	$(CC) -Wall -std=c99 $(SRCDIR)/conflog.c -o $(EXECDIR)/conflogger

man: conflogger.man
	mkdir -p $(MANDIR)

conflogger.man: $(SRCDIR)/man/conflogger.1
	gzip -c $(SRCDIR)/man/conflogger.1 > $(MANDIR)/conflogger.1.gz

clean:
	rm -rf $(OBJ) $(BAK)
