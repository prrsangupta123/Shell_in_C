#include "shell.h"
#include <unistd.h>
#include <stdio.h>

void execute_pwd (char* str, char** args)
{
		int s=0;
	getcwd(pwd, 1023);
	s++;
	printf("%s\n", pwd);
}
