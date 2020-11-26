#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct stat stat_t;

extern char **environ;
int floop(char *envp[]);
char **_strtok(char *s, char *delm);
char *read_line(void);
char *_getenv(const char *name, char **env);
char **split_line(char *line);
void enviromentShell(char **sstr);
int execute(char *path, char **args, char *envp[]);
int cmp(char *line);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_getpath(void);
int path(char *line, char **args);

#endif /* SHELL_H */
