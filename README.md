# Configfile changes Logger

----

conflogger writes information about changes of [config]-file to a logfile

Usage: conflogger FILE

----

Conflogger is a console tool that calls an editor.

After closing the editor, conflogger asks for information about the change and writes it to a log-file.
The log-file and editor is freely selectable, the settings are save at the configuration file.

conflogger will look for a configuration file in the users home directory located at ~/. conflogger.conf. At the first start conflogger create a configuration file.

## Example config file “.conflogger.conf”

    LOGFILE=configInfo
    EDITOR=gedit



## Example program sequence:

$ conflogger /etc/example/config.com

    start conflogger

          -> read config "~/.conflogger.conf"

          -> call EDITOR to open </etc/example/config.com>

          <- close EDITOR

     conflogger ask ChangeInfo:

          -> write ChangeInfo to log-file

     end conflogger

## show info

$ cat configInfo |grep FILE

    Sat Jan  7 17:42:24 2017 - FILE - Change Information ...........................
    Thu Jan 12 18:57:31 2017 - FILE - Change Information ...........................
    Thu Jan 12 19:58:52 2017 - FILE - Change Information ...........................
    .
    .

<a class="github-button" href="https://github.com/frasom/conflogger/archive/master.zip" data-style="mega" aria-label="Download frasom/conflogger on GitHub">Download</a>


