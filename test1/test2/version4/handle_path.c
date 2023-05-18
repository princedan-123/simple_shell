#include "main.h"

/**
 * handle_path - makes a path for an executable command
 * @tokens: the array of string parameters from tokenization
 * @line: the input string read by getline from stdin
 * Return: a string which is a path
 */

char *handle_path(char *tokens[])
{
	char *check = NULL, *command = NULL;

	check = strchr(tokens[0], '/');
	if (check != NULL)
	{
		command = path1(tokens);
	//	free(tokens);
	}
	else
		command = path2(tokens);
	return (command);
}
