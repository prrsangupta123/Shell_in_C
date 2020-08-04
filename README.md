              CREATING AN INTERACTIVE USER DEFINED SHELL:-

FUNCTIONS IT IS IMPLEMENTING:-

1) ls
2) cd 
3) echo
4) quit
5) pinfo
6) pwd

FOR RUNNING A SHELL:-

1) Type make;./shell in terminal

FILES:-

- main.c : This is the main function which is handling signals and calling the scanCmd function for input, interpretCmd function for implementing a command.

- executeCmd.c : contains execution loop, calls every function based on user command

- input.c : parses user input from command line into commands and tokens

- parseStr.c : This function is used to remove extra spaces from the given string.

- printCmdPrompt : This is printing the command prompt.

- quit.c : Used for exiting from the terminal.

- exit.c : Used for exiting from the shell.

- interpretCmd.c : This is calling all other functions based on the given command.

- scanCmd : Scaning the command.

- setPwd : for setting the present working directory.

- shell.h : contains all the header files and declaration of the functions and variables.

- trim.c :  removing the extra spaces from the input command.

- makefile : compiling all the files.

- cd.c - To change the directory.further commands- cd . , cd .. , cd dirname,etc.

- ls.c - displays list of all files and directories.further commands- ls -l, ls -la, ls -al,etc.

- echo.c - echoes whatever the user typed

- pwd.c - displays present working directory (Absolute path).

- pinfo.c - prints the process related info of your shell program or given process ID

FOR EXITING FROM THE SHELL:-

Type exit or quit in terminal.











