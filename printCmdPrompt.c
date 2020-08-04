#include "shell.h"
#include <stdio.h>
#include <pwd.h>
#include<stdlib.h>
#include <unistd.h>

void printCmdPrompt ()
{
	char hostname[512] = {'\0'};
	gethostname(hostname,511);
	char *username=getenv("USER");
	char pwd[1024] = {'\0'};
	getcwd(pwd, 1023);
	char* cwd = setPwd(pwd);
	printf("\033[1;32m<%s@%s:\033[0m\033[1;34m%s\033[0m> ", username, hostname, cwd);
}
