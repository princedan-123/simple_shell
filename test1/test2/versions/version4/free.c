#include "main.h"

/**
 * memory_free - frees memory allocated dynamically
 * @line: inputs read by getline function
 * @command: string from path function
 * @tokens: array from strtok function
 * Return: nothing is returned
 */

void memory_free(char *line, char *command, char *tokens[])
{
	free(line);
	if (tokens[0] != command)/* prevents double free of commands in path form*/
		free(command);
	free(tokens);
}
