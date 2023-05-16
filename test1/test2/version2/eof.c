#include "main.h"

/**
 * end_of_line - handles eof condition in getline function
 * @line: the string read from stdin by getline function
 * Return: nothing is returned by this function
 */

void end_of_line(char *line)
{
	if (line == NULL)
	{
		write(STDOUT_FILENO, "\n", sizeof(char) * 1);
		exit(EXIT_SUCCESS);
	}
}
