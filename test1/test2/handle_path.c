#include "main.h"

/**
 * handle_path - makes a path for an executable command
 * @tokens: the array of string parameters from tokenization
 * @line: the input string read by getline from stdin
 * Return: a string which is a path
 */

char *handle_path(char *tokens[], char *line)
{
	char *check = NULL, *command = NULL;

	check = strchr(tokens[0], '/');
	if (check != NULL)
		command = path1(tokens, line);
	else
		command = path2(tokens, line);
	return (command);
}
