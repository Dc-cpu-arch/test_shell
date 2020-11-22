#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
void floop(char * envp[]);
char *read_line(char * envp[]);
char **split_line(char *line);
void enviromentShell(char **sstr);
int execute(char *path, char **args, char * envp[]);
int cmp(char *line, char * envp[]);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);


#endif /* SHELL_H */
