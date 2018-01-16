#!/bin/bash
set -e

EXECDIR=/bin/
MANDIR='/usr/share/man/man1/'

cpu=`uname -m`

mkdir -p $EXECDIR


if [ $cpu = 'x86_64' ]; then
    sudo cp ./bin_64/conflogger $EXECDIR
else
    sudo cp ./bin_32/conflogger $EXECDIR
fi

#copy man-page
read -p"Manpage install (y/n)? " response
if [ "$response" == "y" ]; then
    sudo cp ./man/*.gz $MANDIR
fi

 




