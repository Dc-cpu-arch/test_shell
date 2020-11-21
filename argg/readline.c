#include "shell.h"

char *read_line(void)
{
        char *line = NULL;
        ssize_t bufsz = 0;
        if (getline(&line, &bufsz, stdin) == -1)
        {
                if (feof(stdin))
                {
                        exit(EXIT_SUCCESS);
                }
                else
		{
                        perror("readline");
                        exit(EXIT_FAILURE);
                }
        }
        return (line);
}
