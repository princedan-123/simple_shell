#include "main.h"

/**
 * _setenv - sets an environment variable
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */

int _setenv(int argc, char *argv[])
{
	char *usage = "Command syntax: setenv VARIABLE VALUE";

	if (argc != 3)
	{
		write(STDOUT_FILENO, usage, strlen(usage));
		return (1);
	}
	
	setenv(argv[1], argv[2], 1) != 0;
	return (0);
}

/**
 * _unsetenv - unsets environment variable
 * @argc: number of arguments
