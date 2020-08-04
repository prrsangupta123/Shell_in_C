shell: \
			main.o \
			cd.o \
			echo.o \
			quit.o \
			exit.o \
			ls.o \
			pinfo.o \
			pwd.o \
			interpretCmd.o \
			parseStr.o \
			printCmdPrompt.o \
			scanCmd.o \
			setPwd.o \
			trim.o
	$(CC) -g -o shell $^

clean:
	@rm -f *.o shell

main.o: shell.h main.c
	$(CC) -g -c main.c

cd.o: shell.h cd.c
	$(CC) -g -c cd.c

echo.o: shell.h echo.c
	$(CC) -g -c echo.c

quit.o: shell.h quit.c
	$(CC) -g -c quit.c

exit.o: shell.h exit.c
	$(CC) -g -c exit.c

ls.o: shell.h ls.c
	$(CC) -g -c ls.c

fg.o: shell.h fg.c
	$(CC) -g -c fg.c

bg.o: shell.h bg.c
	$(CC) -g -c bg.c

pinfo.o: shell.h pinfo.c
	$(CC) -g -c pinfo.c

pwd.o: shell.h pwd.c
	$(CC) -g -c pwd.c

interpretCmd.o: shell.h interpretCmd.c
	$(CC) -g -c interpretCmd.c

parseStr.o: shell.h parseStr.c
	$(CC) -g -c parseStr.c

printCmdPrompt.o: shell.h printCmdPrompt.c
	$(CC) -g -c printCmdPrompt.c

scanCmd.o: shell.h scanCmd.c
	$(CC) -g -c scanCmd.c

setPwd.o: shell.h setPwd.c
	$(CC) -g -c setPwd.c

trim.o: shell.h trim.c
	$(CC) -g -c trim.c
