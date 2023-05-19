#include "main.h"

/**
 * display - displays prompt to the user
 * Return: nothing is returned
 */

void display(void)
{
	int active = isatty(STDIN_FILENO);

	char *prompt = "$ ";

	if (active == 1)
		write(STDOUT_FILENO, prompt, strlen(prompt));
}
