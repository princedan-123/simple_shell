#include "main.h"

/**
 * exit_child - exits the child process
 * @tokens: an array of tokenized strings
 * Return: nothing is returned
 */

void exit_child(char *tokens[])
{
	int check = strcmp(tokens[0], "exit");
	if (check == 0 )
		exit(EXIT_SUCCESS);
}

/**
 * _exit_status - checks the exit status
 * @status: exit status
 *
 * Return: 0
 */

int _exit_status(int status)
{
	int e_status;

	if (WIFEXITED(status))
		return (0);
	else if (!(WIFEXITED(status)))
	{
		e_status = WEXITSTATUS(status);
		return (e_status);
	}
	return (0);
}
