#include "main.h"

/**
 * path - finds a command using the path variable
 * @tokens: an array of tokenized string
 * Return: returns the command if found
 */

char *path(char *tokens[])
{
	char *check = NULL, *get_path = NULL, *path = NULL, *tmp = NULL, *slash = "/";
	char *parse = NULL, *command = NULL, *tmp1 = NULL, *parsed = NULL;
	char *tmp2 = NULL;

	check = strchr(tokens[0], '/');
	if (check != NULL)
		return (tokens[0]);
	get_path = getenv("PATH");
	if (get_path == NULL)
	{
		perror("unable to get path");
		return (NULL);
	}
	path = strdup(get_path);
	parse = strtok(path, ":");
	while (parse != NULL)
	{
		parsed = strdup(parse);
		tmp = malloc(sizeof(char) * strlen(parsed) + strlen(slash) + 3);
		if (tmp == NULL)
			return (NULL);
		tmp1 = strcpy(tmp, parsed);
		tmp2 = strcat(tmp1, slash);
		command = strcat(tmp2, tokens[0]);
		if (access(command, F_OK) == 0)
			break;
		else if (access(command, F_OK) != 0)
		{
			free(parsed);
			free(command);
		}
		parse = strtok(NULL, ":");
	}
	if (parse == NULL)
		perror("command not found");
	free(path);
	free(parsed);
	return (command);
}
