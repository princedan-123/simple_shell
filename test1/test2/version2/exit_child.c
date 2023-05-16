#include "main.h"

/**
 * exit_child - exits the child process
 * @tokens: an array of tokenized strings
 * @line: inputs read from stdin using getline function
 * Return: nothing is returned
 */

void exit_child(char *tokens[], char *line)
{
	char *str = "exit";

	int check = strcmp(tokens[0], str);

	if (check == 0)
	{
		free(line);
		free(tokens);
		exit(EXIT_SUCCESS);
	}
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
