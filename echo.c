#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void execute_echo (char* args)
{
	for (int i=0; args[i];)
	{
		if (isspace(args[i]))
		{
			++i;
			continue;
		}
		if (args[i] == '"')
		{
			i=i+1;
			do
			{
				printf("%c", args[i]);
				++i;
			}while(args[i] && args[i] != '"');
			printf(" ");
			++i;
			continue;
		}
		do
		{
				printf("%c",args[i]);
				i++;
		}while(args[i] && !isspace(args[i]));
		printf(" ");
	}
	printf("\n");
}
