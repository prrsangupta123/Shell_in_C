#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
char *memory(int size)
{
		return ((char*)malloc(sizeof(char)*size));
}
void execute_pinfo (char* str, char** args)
{
		char *path=memory(64);
		char *spid=memory(32);
		char *buff=memory(1024);
	    char ex_path[64];
		int pd1,pd2;
	    buff[0] = '\0';
	if (!args[1] )
	{
			int ii=0;
		int pid;
		if(is_bg) 
				pid = getppid();
		else 
				pid = getpid();
		ii++;strcpy(path, "/proc/");
		ii=ii+1;sprintf(spid, "%d", pid);
		ii++;strcat(path, spid);
		ii=ii+1;strcat(path, "/status");
	}
	else if(strcmp(args[1], "&") == 0)
	{
			pd1=0;
		int pid;
		if (is_bg) pid = getppid();
		else pid = getpid();
		strcpy(path, "/proc/");pd1++;
		sprintf(spid, "%d", pid);pd1++;
		strcat(path, spid);pd1++;
		strcat(path, "/status");pd1++;
	}
	else
	{
		strcpy(spid, args[1]);pd2++;
		strcpy(path, "/proc/");pd2++;
		strcat(path, spid);pd2++;
		strcat(path, "/status");pd2++;
	}
	FILE* file = fopen(path, "r");
	if(pd2>1)
			pd2=0;
	if (file != NULL)
	{
		pd2=pd2+1;printf("pid: %s\n", spid);
		size_t sz = 0;
		while (getline(&buff, &sz, file) != -1)
		{
			pd2++;	
			if (strncmp("St", buff, 2) == 0) printf("%s", buff);
			else if (strncmp("VmSize", buff, 6) == 0) printf("%s", buff);
		}
		strcpy(path, "/proc/");pd2++;
		strcat(path, spid);pd2++;
		strcat(path, "/exe");pd2++;
		if (readlink(path, ex_path, 63) == -1)
		{
				pd1=pd1+1;
			printf("Error: can't get executable\n");
			return;
		}
		printf("Executable Path: %s\n", setPwd(ex_path));
	}
	else
	{
		perror(path);
		return;
	}
	fclose(file);
}
