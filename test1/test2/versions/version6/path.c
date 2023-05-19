#include "main.h"

/**
 * path1 - finds a command using the path variable
 * @tokens: an array of tokenized string
 * Return: returns the command if found
 */

char *path1(char *tokens[])
{
	char *check = NULL;
	int i;
	check = strchr(tokens[0], '/');
	i = access(tokens[0], X_OK);
	if ((check != NULL) && (i == 0))
		return (tokens[0]);
	else
	{
		perror("command not found");
		free(tokens);
	}
	
	return (NULL);
}
/**
 * path2 - makes path for none-path command
 * @tokens: array of strings from tokenization
 * Return: a string is returned
 */

char *path2(char *tokens[])
{
	char *parse = NULL, *parsed = NULL, *tmp = NULL, *slash = "/";
	char *tmp1 = NULL, *tmp2 = NULL, *path = NULL, *command = NULL;
	char *get_path = NULL;

	get_path = getenv("PATH");
	path = strdup(get_path);
	parse = strtok(path, ":");
	while (parse != NULL)
	{
		parsed = strdup(parse);
		tmp = malloc(sizeof(char) * strlen(parsed) + strlen(slash) + 20);
		if (tmp == NULL)
			return (NULL);
		tmp1 = strcpy(tmp, parsed);
		tmp2 = strcat(tmp1, slash);
		command = strcat(tmp2, tokens[0]);
		if (access(command, X_OK) == 0)
			break;
		else if (access(command, X_OK) != 0)
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
		//free(parsed);
		free(tokens);
		return (NULL);
	}
	free(path);
	free(parsed);
	return (command);
}
