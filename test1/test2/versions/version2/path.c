#include "main.h"

/**
 * path - finds a command using the path variable
 * @tokens: an array of tokenized string
 * Return: returns the command if found
 */

char *path1(char *tokens[])
{
	char *check = NULL;

	check = strchr(tokens[0], '/');
	if (check != NULL)
	{
		if (access(tokens[0], F_OK) != 0)
			perror("command not found");
		else
			return (tokens[0]);
	}
}
/*
char *_get_path_environ(void)
{
	char *get_path = NULL, *path = NULL;
	get_path = getenv("PATH");
	if (get_path == NULL)
	{
		perror("unable to get path");
		return (NULL);
	}
	path = strdup(get_path);
	return (path);
}*/
char *path2(char *tokens[])
{
	char *parse = NULL, *parsed = NULL, *tmp = NULL, *slash = "/", *get_path = NULL;

	char *tmp1 = NULL, *tmp2 = NULL, *path = NULL, *command = NULL;

	get_path = getenv("PATH");
	path = strdup(get_path);
	parse = strtok(path, ":");
	while (parse != NULL)
	{
		parsed = strdup(parse);
		tmp = malloc(sizeof(char) * strlen(parsed) + strlen(slash) + 5);
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
	{
		perror("command not found");
		free(path);
		free(parsed);
		return (NULL);
	}
	free(path);
	free(parsed);
	return (command);
}
