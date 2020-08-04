#include <ctype.h>
#include "shell.h"
#include<string.h>
void trim (char* s, char* cmd)
{
		int it=0, i=0, j=strlen(s)-1;
		while(i<strlen(s))
		{
				if (!isspace(s[i]))
						break;
				i++;
		}
		while(j>=0)
		{
				if (!isspace(s[j]))
						break;
				j--;
		}
		while(i<=j)
		{
				cmd[it++]=s[i];
				i++;
		}
		cmd[it] = '\0';
}
