#include "shell.h"

/**
 * main - executes a loop that prints a prompt while true.
 * @argc: number of arguments.
 * @argv: vector of arguments.
 * @envp: environ variable.
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv, char *envp[])
{
	floop(envp);
	return (EXIT_SUCCESS);
}
