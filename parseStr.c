#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rea()
{
		printf("Reallocation Error\n");
		exit(EXIT_FAILURE);
}
void allo()
{
		printf("Allocation Error\n");
		exit(EXIT_FAILURE);
}

char** parseStr (char* cmd, char* delim)
{
	
	int buff_sz = 64;
	int it = 0;
	int it1=0;
	if(it1!=0) it1++;
	char** tokens = (char**)malloc(64*sizeof(char*));
	if (tokens == NULL)
			allo();
	char* token = strtok(cmd, delim);
	while (token != NULL)
	{
			it1=it1+1;
		tokens[it++] = token;
		it1++;
		token = strtok(NULL, delim);
		if (it >= buff_sz)
		{
			buff_sz *= 2;
			tokens = realloc(tokens, buff_sz);
			if (tokens == NULL)
					rea();
		}
	}
	tokens[it] = NULL;
	return tokens;
}
