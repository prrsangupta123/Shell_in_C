#include <stdio.h>
#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int is_bg;
int pid1=0;
int size_running_procs = 0;
void interpretCmd (char* cmd)
{
		char str_delim[] = ";";
		char *str;
		char cmd_delim[] = " &\n\t\v\f\r\a";
		char *str2;
		char** cmds = parseStr(cmd, str_delim);
		for (int i=0, pid, status; cmds[i] != NULL; ++i)
		{
				pid1++;
				char* s = (char*)malloc(sizeof(char)*(strlen(cmds[i])+2));
				strcpy(s, cmds[i]);pid1++;
				trim(s, cmds[i]);pid1++;
				strcpy(s, cmds[i]);pid1++;
				is_bg = 0;
				if(pid1>2) pid1=1;
				char ss='&';
				for (int j=0; cmds[i][j]; ++j)
						if (cmds[i][j] == ss)
						{
								pid1++;
								cmds[i][j] = '\0';is_bg++;
								is_bg = 1;pid1+=1;
								break;
						}
				char** args;
				pid++;
				if (strncmp(cmds[i], "quit", 4) == 0)
				{	execute_quit(cmds[i], args);pid1=1;}
				else if (strncmp(cmds[i], "cd", 2) == 0)
				{
						execute_cd(cmds[i], parseStr(cmds[i], cmd_delim));pid1=0;
						continue;
				}
				else if(strncmp(cmds[i],"ls",2)==0)
				{
						pid1++;
						execute_ls(cmds[i],parseStr(cmds[i], cmd_delim));pid1=0;
						continue;
				}
				else if(strncmp(cmds[i],"pinfo",5)==0)
				{
						pid1++;execute_pinfo(cmds[i], parseStr(cmds[i], cmd_delim));pid1=0;
						continue;
				}
				else if(strncmp(cmds[i],"exit",4)==0)
				{
						pid1++;execute_exit(cmds[i],parseStr(cmds[i], cmd_delim));pid1=0;
						continue;
				}
				else if(strncmp(cmds[i],"pwd",3)==0)
				{
						pid1++;execute_pwd
								(cmds[i],parseStr(cmds[i], cmd_delim));pid1=0;
						continue;
				}
				pid = fork();
				int p=0;
				if(pid1>1)
						p++;
				if (pid == 0)
				{
						if (is_bg) setpgid(0, 0);p=1;
						if (strncmp("echo", s, 4) == 0)
						{
								char aa='"';
								int no_of_quotes = 0;
								for (int j=4; s[j]; ++j)
										if (s[j] == aa) no_of_quotes++;
								if (no_of_quotes % 2)
										fprintf(stderr, "Error: invalid syntax\n");
								else execute_echo(s+4);
						}
						else
						{	
										execvp
								(cmds[i],parseStr(cmds[i], cmd_delim));
										fprintf(stderr, "Error: command not found\n");
						}
						exit(0);
				}
				else
				{
						p++;
						if (!is_bg) waitpid(pid, &status, WUNTRACED);
						else 
						{
								args = parseStr(cmds[i], cmd_delim);p=1;
								strcpy(running[size_running_procs].pname, args[0]);p++;
								running[size_running_procs++].pid = pid;
						}
				}
		}
}
