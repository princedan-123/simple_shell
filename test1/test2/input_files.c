#include "main.h"

/**
 * get_env - prints the environmental variables to stdout
 * @env: array of environment variables
 * @str: command input
 *
 * Return: void
 */

void get_env(char **env)
{
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
/**
 * _getline - reads the command from the user
 *
 * Return: command read from user
 */
char *_getline(void)
{
	ssize_t get;
	size_t n = 0;
	char *str = NULL;

	get = getline(&str, &n, stdin);
	str[strcspn(str, "\n")] = '\0';
	if (get == -1)
		return (NULL);

	return (str);
}

/**
 * main - getss user input and executes the shell
 *
 * Return: 0 on success
 */


int main(void)
{
	char **tokens = NULL;
	char *line = NULL, *command = NULL;
	int status;
	pid_t pid;

	while (1)
	{
		display();
		line = _getline();
		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		tokens = _tokenize(line);
		exit_child(tokens, line);
		command = path(tokens);
		if (command == NULL)
			continue;
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			break;
		}
		else if (pid == 0)
		{
			if (strcmp(line, "env") == 0)
			{
				get_env(environ);
				break;
			}
			executor(command, tokens);
		}
		else
		{
			wait(&status);
			_exit_status(status);
		}
		free(line);
		if (tokens[0] != command)/*preventing double frees*/
			free(command);
		free(tokens);/*this must come after if */
	}
	return (0);
}

/**
 * _tokenize - tokenizes a string
 * @str: string to be tokenized
 * Return: array of tokenized strings
 */

/*char **_tokenize(char *str)
{
	char **parsed = NULL;
	int i = 0, j;
	char *token;

	parsed = malloc(sizeof(char) * (strlen(str) + 1));
	token = strtok(str, " ");
	while (token != NULL)
	{
		parsed[i] = malloc(sizeof(char) * (strlen(str) * 1));
		if (!parsed[i])
		{
			perror("Error");
			for (j = 0; j < i; j++)
				free(parsed[j]);
			free(parsed);
			exit(EXIT_FAILURE);
		}
		strcpy(parsed[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	parsed[i] = NULL;
	return (parsed);
}*/
char **_tokenize(char *str)
{
        char **parsed = NULL;

        int i = 0;

        char *token = NULL;

        parsed = malloc(sizeof(char *) * strlen(str) + 1);
	if (parsed == NULL)
		return (NULL);
        token = strtok(str, " ");
	while (token != NULL)
	{
		parsed[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	parsed[i] = NULL;
	return (parsed);
}

/**
 * executor - executes shell commands
 * @command: array of command and arguments
 * @tokens: command line arguments
 *
 * Return: 0
 */

int executor(char *command, char **tokens)
{
	if ((access(command, X_OK) == 0))
	{
		if ((execve(command, tokens, environ)) != 0)
		{
			//exit(EXIT_FAILURE);
		}
	
	}
	return (0);
}
