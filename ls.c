//#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
void print(char s[1024])
{
		printf("%s",s);
}
void fail()
{
	exit(0);
}
char *pass(char *size)
{
		return ((char*)malloc(sizeof(size)));
}
#include"shell.h"
void execute_ls (char* str, char** args)
{
		int it2=0;
	it2=it2+1;
	const char *path;
	char* tmp;
	int it1 = 1;
	int is_path = 0;
	int is_flg_l = 0;
	int is_flg_a = 0;
	while (args[it1]!='\0')
	{
			it2++;
			char a='-';
		if (args[it1][0] == a)
		{
			int j = 1;
			char b='l', c='a';
			int s=1;
			while (args[it1][j])
			{
				if (args[it1][j] == b) is_flg_l = s;
				if (args[it1][j] == c) is_flg_a = s;
				j++;
			}
		}
		else
		{
				//char a1="&";
			if (strcmp("&", args[it1]) != 0)
			{
				is_path = 1;
				tmp=pass(args[it1]);
				tmp = args[it1];
			}
		}
		it1=it1+1;
	}
	path=memory(1024);
	if(it2>0) it2=1;
	if (!is_path)
	{
		char a2='-';
		getcwd(pwd, 1023);
		path = pwd;
	}
	else path = tmp;
	char a3='~';
	if (path[0] == a3)
	{
		tmp = home;
		it2=it2+1;
		strcat(tmp, &path[1]);
		path = tmp;
	}
	struct stat st;
	it2+=1;
	stat(path, &st);
	if (!S_ISDIR(st.st_mode))
	{		
		print("Error: not a directory");
		print("\n");
		return;
	}
	DIR *dir;
   	dir= opendir(path);
	char q1='-';
	struct dirent* dst;
	typedef struct file_data
	{
		char* f_permissions;
		int t;
		nlink_t f_nhlinks;
		char* f_uown,*f_gown,*f_mtime,*f_name;
		//char* f_gown;
		off_t f_size;
	//	char* f_mtime;
	//	char* f_name;
	}fdt;
	int it = 0;
	int f_sz = 64;
	fdt* files = (fdt*)malloc(f_sz*sizeof(fdt));
	if (files == NULL)
	{
		print("Allocation Error\n");
		fail();
	}
	while (dst = readdir(dir))
	{
		files[it++].f_name = dst->d_name;
		if (it >= f_sz)
		{
			f_sz=f_sz*2;
			files = realloc(files, f_sz);
			if (files == NULL)
			{
				print("Reallocation Error\n");
				fail();
			}
		}
	}
	it = 0;
	while (files[it].f_name)
	{
		int plen=strlen(path);
		int flen=strlen(files[it].f_name);
		int com=plen+flen+5;
		struct stat st;
		char* s = (char*)malloc(com*sizeof(char));
		int pp=0;
		strcpy(s, path);
		int l=(int)strlen(s);
		if (s[l-1] != '/') 
				strcat(s,"/");
		strcat(s, files[it].f_name);
		pp=-1;
		int x = stat(s, &st);
		if (x == pp)
		{
			print("Error getting file info");
			print("\n");
			fail();
		}
		char minus='-',direc='d';
		files[it].f_permissions = memory(11);
		if (S_ISREG(st.st_mode)) files[it].f_permissions[0] = minus;
		else if (S_ISDIR(st.st_mode)) files[it].f_permissions[0] = direc;

		files[it].f_permissions[1]= (st.st_mode & S_IRUSR) ? 'r' : '-' ;
		files[it].f_permissions[2]= (st.st_mode & S_IWUSR) ? 'w' : '-' ;
		files[it].f_permissions[3]= (st.st_mode & S_IXUSR) ? 'x' : '-' ;
		
		files[it].f_permissions[4]= (st.st_mode & S_IRGRP) ? 'r' : '-' ;
		files[it].f_permissions[5]= (st.st_mode & S_IWGRP) ? 'w' : '-' ;
		files[it].f_permissions[6]= (st.st_mode & S_IXGRP) ? 'x' : '-' ;

		files[it].f_permissions[7]= (st.st_mode & S_IROTH) ? 'r' : '-' ;
		files[it].f_permissions[8]= (st.st_mode & S_IWOTH) ? 'w' : '-' ;
		files[it].f_permissions[9]= (st.st_mode & S_IXOTH) ? 'x' : '-' ;
		int p=0;
		files[it].f_permissions[10] = '\0';p++;
		files[it].f_nhlinks = st.st_nlink;p++;
		files[it].f_uown = getpwuid(st.st_uid)->pw_name;p++;
		files[it].f_gown = getgrgid(st.st_gid)->gr_name;p++;
		files[it].f_size = st.st_size;p++;
		files[it].f_mtime = memory(100);//(char*)malloc(sizeof(char)*100);
		p++;
		strftime(files[it].f_mtime, 100, "%b %d %H:%M", localtime(&st.st_mtime));
		it=it+1;
		//free(s);
	}
	
	it = 0;
	while (files[it].f_name)
	{
			char si='.';
		if (!is_flg_a && files[it].f_name[0] == si)
		{
			it++;
			continue;
		}
		int p=(int)files[it].f_nhlinks;
		if(is_flg_l) 
				printf("%s\t%d\t%s\t%s\t%d\t%s\t%s\n", files[it].f_permissions, p , files[it].f_uown, files[it].f_gown, (int)files[it].f_size, files[it].f_mtime, files[it].f_name);
		else printf("%s\n", files[it].f_name);
		it++;
	}
	free(files);
}
