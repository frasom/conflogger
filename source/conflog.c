/* conflogger
   Log change at configuration

   Copyright (C) 2017  Frank Sommer

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   <http://www.gnu.org/licenses/>
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define VERSION	"0.4"
#define CONFIGFILE ".conflogger.conf"
#define MAXBUF 1024
#define DELIM "="
#define SET_LOGFILE "configInfo"
#define SET_EDITOR "vi"


struct config
{
   char LOGFILE[MAXBUF];
   char EDITOR[MAXBUF];
};

struct config get_config(char *configfile)
{
		struct config configstruct;

        FILE *file = fopen (configfile, "r");                                                         /* open configuration file */

        if (file != NULL)
        {
                char line[MAXBUF];
                int i = 0;

                while(fgets(line, sizeof(line), file) != NULL)                                        /* read configuration file */
                {
                        char *cfline;
                        cfline = strstr((char *)line,DELIM);
                        cfline = cfline + strlen(DELIM);

                        if (i == 0){
                                memcpy(configstruct.LOGFILE,cfline,strlen(cfline-1));
                        } else if (i == 1){
                                memcpy(configstruct.EDITOR,cfline,strlen(cfline-1));
                        }
                        i++;
                }
                fclose(file);
        }
        else {
			FILE *datei = fopen (configfile, "w");                                        /* create configuration file */
				if (datei == NULL)
				{
					printf("Error create configuration file: %s\n",configfile);
				}
				fprintf (datei, "LOGFILE=%s\n", SET_LOGFILE);
                fprintf (datei, "EDITOR=%s\n", SET_EDITOR);
				fclose (datei);
				memcpy(configstruct.LOGFILE,SET_LOGFILE,strlen(SET_LOGFILE));
				memcpy(configstruct.EDITOR,SET_EDITOR,strlen(SET_EDITOR));
			}
        return configstruct;

}


int ChangeInfo ();


int main(int argc, char *argv[])
{
	int id;
	char command[255];
	char conffile[255];
	char logfile[255];
	char *env_home = getenv("HOME");


	sprintf(conffile, "%s/%s",env_home,CONFIGFILE);                                               /* set path + configuration_file name  */

	struct config configstruct;
    configstruct = get_config(conffile);                                                              /* load configuration */


	if (argc < 2) {                                                                               /*  missing parameter */
		printf(" \n");
		printf("Usage: %s FILE\n", argv[0]);
		printf(" \n");
		printf("Logfile ==  %s",configstruct.LOGFILE);
		printf("Editor  ==  %s",configstruct.EDITOR);
		printf("conflogger Version %s\n", VERSION);
		printf("Copyright (C) 2017  Frank Sommer\n");
		printf("This program comes with ABSOLUTELY NO WARRANTY.\n");
	}
	else {
		strcpy(command, configstruct.EDITOR);                                                 /*  command part1    */
		command[ strlen( command ) - 1 ] = 0x0;                                               /*  drop Linefeed */
		strcat(command, " ");                                                                 /*  add space to command  */
		strcat(command, argv[1]);                                                             /*  add filename to command  */

		strcpy(logfile, configstruct.LOGFILE);                                                /*  logfile name   */
		logfile[ strlen( logfile ) - 1 ] = 0x0;                                               /*  drop Linefeed */

		id = system (command);                                                                /*  call system to edit file */
		if(id == 0) {
			id = ChangeInfo (argv[1], logfile);                                           /*  config info schreiben   */
		}
		else {
		printf ("CommandError: %d.\n",id);
		return 1;
		}
	}
	return 0;
}

int ChangeInfo (char *dat, char *file)
{
	FILE *datei;
	char string[1024];
	char log_file[255];
	char *temp;
	char *env_home = getenv("HOME");                                                              /* get HOME for log file  */

	sprintf(log_file, "%s/%s",env_home,file);                                                     /* set path + ChangeInfo-file name  */

	datei = fopen (log_file, "a");                                                                /* open log-filen   */

	if (datei == NULL)
	{
		printf("Error open Logfile %s\n",log_file);
		return 1;
	}
	printf("Change Info: ");
	fgets(string, 1020, stdin);

	time_t rawtime;                                                                               /*  get Time */
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	temp = ( asctime( timeinfo ) );
	temp[ strlen( temp ) - 1 ] = 0x0;                                                             /* drop Linefeed */

	fprintf (datei, "%s", temp );
	fprintf (datei, " - %s - %s", dat, string);
	fclose (datei);
	return 0;
}
