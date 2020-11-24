#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct stat stat_t;

extern char **environ;
void floop(char * envp[]);
char *read_line(void);
char **split_line(char *line);
void enviromentShell(char **sstr);
int execute(char *path, char **args, char * envp[]);
int cmp(char *line);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_getpath(void);
char *path(char *line);

#endif /* SHELL_H */
