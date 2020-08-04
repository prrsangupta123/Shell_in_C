#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
void *buffer(char *buff)
{
		if(buff==NULL)
		{
				perror("Error in allocation");
				exit(EXIT_FAILURE);
		}
}
char* scanCmd ()
{
	char ch;
	int buff_sz = 128, it = 0;
	char* buff = (char*)malloc(buff_sz*sizeof(char));
	buffer(buff);
	while(1)
	{
		ch = getchar();
		if (ch == '\n')
		{
			buff[it] = '\0';
			break;
		}
		else if(ch==EOF)
		{ 
				buff[it]='\0';
				break;
		}
		buff[it] = ch;
		it++;
		if (it >= buff_sz)
		{
			buff_sz *= 2;
			buff = realloc(buff, buff_sz);
			buffer(buff);
		}
	}
	return buff;
}
