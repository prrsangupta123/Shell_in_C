#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void execute_cd (char* str, char** args)
{
		int flag=0;
		char *args1;
		if(args[1] && strcmp(args[1],"&") == 0);
		else if(args[2] && strcmp(args[2],"&") == 0);
		else if (!args[1])
				chdir(home);
		else if((strcmp(args[1],"~") == 0)) 
		{
				flag++;
				chdir(home);
		}
		else 
		{
				int s=strncmp("~",args[1],1);
				if(s==0)
				{
						char* path = home;
						char* args1 =home;
						strcat(path, &args[1][1]);
						args[1] = path;
				}
				int v=chdir(args[1]);
				if (v == -1)
				{
						flag=1;
						printf("Error: could not change directory\n");
				}

		}
}
