# Configfile Logger
conflogger ermöglicht eine automatische Dokumentation der Änderungen von Konfigurationsdateien. conflogger übernimmt den Aufruf des Editors und fragt nach beenden des Editors eine Beschreibung der Änderung ab.
Der zu verwendende Editor und die Logdatei werden in einer Konfigurationsdatei “.conflogger.conf” im Homeverzeichnis des Benutzers abgelegt.  
Die conflogger Konfigurationsdatei wird beim ersten Programmstart automatisch angelegt.

## Beispiel Konfigurationsdatei: “.conflogger.conf”

    LOGFILE=configInfo
    EDITOR=gedit

## Beispielprogrammablauf:

    $ conflogger /etc/example/config.com

              -> einlesen Konfiguration "~/.conflogger.conf"

              -> aufrufen EDITOR </etc/example/config.com>

              <- beenden EDITOR

         conflogger erfragt die Änderungen:

              -> speichern der Änderungsinformation im log-file

## Anzeigen der Änderungshistorie
     $ cat configInfo
     - conflogger LogDatei
     Sat Jan  7 17:42:24 2017 - /etc/hosts - Änderung der Drucker Adresse Zeile 6
     Thu Jan 12 18:57:31 2017 - /etc/fstab - neues NFS Verzeichnis 'test' auf Server
     Thu Jan 12 18:58:52 2017 - /etc/mysql/my.cnf - änderung Datenbank Verzeichnis
     Sat Jan 14 17:20:49 2017 - /etc/fstab - löschen NFS Verzeichnis 'test'

Die Änderungshistorie einer einzelnen Konfigurationsdatei kann mit 'grep' ausgegeben werden.

    $ cat configInfo | grep fstab
    - conflogger LogDatei
    Thu Jan 12 18:57:31 2017 - /etc/fstab - neues NFS Verzeichnis 'test' auf Server
    Sat Jan 14 17:20:49 2017 - /etc/fstab - keine Änderung

## Info
Pro Änderung kann nur eine Zeile mit max. 1024 Zeichen eingegeben werden.
Die conflogger Logdatei wird beim ersten Programmlauf automatisch angelegt.

### Systemanforderungen
conflogger wurde auf einem ubuntu 16.04 System entwickelt, sollte aber auf jedem Unixoiden System (Unix, Linux, macOS) laufen.

### Installation

## Debian-Paketsystem

Download des Instalationspakets von Github: [conflogger.deb](https://github.com/frasom/conflogger)

## Andere Linux-Distributionen
 
Das Installationsscript installiert conflogger im Verzeichnis /bin und benötigt sudo rechte.  
Alternativ kann die Programmdatei 'conflogger' auch manuell im Homeverzeichnis abgespeichert werden.

    $ cp QUELLZEICHNIS/bin_xx/conflogger ~/ZIELVERZEICHNIS
* QUELLVERZEICHNIS und ZIELVERZEICHNIS müssen individuell angepasst werden.
* bin_xx muss je nach  Prozessorarchitektur 32/64 Bit angepasst werden.

#### Programme kompiliert und installiert
 Sollte das Programm auf dem Zielsystem nicht laufen kann es mit make und gcc kompiliert werden. Eventuell muss des Makefile angepasst oder conflogger manuell kompiliert werden.


### Dateiliste
| Datei Verzeichnis  | Info |
|--------|------:|
| bin_32/ | conflogger 32 Bit _Linux_ |
| bin_64/ | conflogger 64 Bit _Linux_ |
| install.sh |Installationsscript _Linux_ |
| Makefile | Makefile |
| man/ | Hilfedatei _Linux_ |
| source/ | source-Dateien |
