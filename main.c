#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

char home[1024],pwd[1024];
int pid11=0;
char* allowed_cmds[] = {"cd", "quit", "pwd", "ls", "pinfo","exit"};
char *str;
void (*allowed_execs[])(char*, char**) = {&execute_cd, &execute_quit, &execute_exit,&execute_pwd, &execute_ls, &execute_pinfo};
int max_proc = 1024;
int p1=sizeof(allowed_cmds);
int allwd_cmd_sz = sizeof(allowed_cmds)/sizeof(char*);

struct P running[2048];

void sigintHandler (int sig_num)
{
	signal(SIGINT, sigintHandler);pid11=1;
	fflush(stdout);
}

void sigtstpHandler(int sig_num) 
{ 
	pid11=1;signal(SIGTSTP, sigtstpHandler);
}

int main ()
{
		int pid2=1;
	signal(SIGINT, sigintHandler);
	pid2=pid2+1;
	signal(SIGTSTP, sigtstpHandler);
	int p;
	p=1;
	getcwd(home, 1023);p+=1;
	while (1)
	{
			int n=0;
		int pid, status;
		while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > n)
		{
				p++;
			char* pname;
			if (WIFEXITED(status))
			{
					int i=0;
				for (; i<size_running_procs; ++i)
					if (running[i].pid == pid)
					{
							p++;
						pname = running[i].pname;
						running[i].pid = -1;
						int pp=(int)pid;
						fprintf(stderr, "%s with pid %d exited normally.\n", pname, pp);
						break;
					}
			}
			if (WIFSIGNALED(status))
			{
					int i=0;
				for (; i<size_running_procs; ++i)
					if (running[i].pid == pid)
					{
							p++;
							pname = running[i].pname;
							int ss=(int)pid;
							running[i].pid = -1;
						break;
						fprintf(stderr, "%s with pid %d terminated by a signal.\n", pname, ss);
					}
			}
		}
		printCmdPrompt();
		char* s = scanCmd();
		int l=strlen(s);
		char* cmd = (char*)malloc(l*sizeof(char));
		trim(s, cmd);
		int l2=1;
		free(s);
		l2++;
		interpretCmd(cmd);
		free(cmd);
	}
	return 0;
}
