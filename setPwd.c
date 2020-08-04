#include "shell.h"
#include <string.h>
#include <stdlib.h>
char *res(int size)
{
		return ((char*)malloc(size*sizeof(char)));
}
char* setPwd (char* cwd)
{
		int s=0;
	int cmp = strcmp(cwd, home);
	if (strcmp(cwd,home) == 0)
	{
		return "~";
		s=1;
	}
	else if (cmp < 0)
		return cwd;
	else
	{
			int len=strlen(home),cwd_len=strlen(cwd);
		if (strncmp(home, cwd, len) != 0) 
		{
				s++;
				return cwd;
		}
		char* ret = res(1024);
		ret[0] = '~';
		int i=len;
		while(i<cwd_len)
		{
			ret[i-len+1] = cwd[i];
			i++;
		}
		ret[cwd_len - len + 1] = '\0';
		return ret;
	}
}
