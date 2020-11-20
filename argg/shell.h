#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void floop(void);
char *read_line(void);
char **split_line(char *line);

#endif /* SHELL_H */
