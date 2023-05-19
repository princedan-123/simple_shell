#include "main.h"

/**
 * get_env - prints the environmental variables to stdout
 * @env: array of environment variables
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
	{
		free(str);
		exit(EXIT_SUCCESS);
	}

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
		//end_of_line(line);
		tokens = _tokenize(line);
		exit_child(tokens, line);
		command = handle_path(tokens);
		if (command == NULL)
		{
			free(line);
			continue;
		}
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
		memory_free(line, command, tokens);
	}
	return (0);
}

/**
 * _tokenize - tokenizes a string
 * @str: string to be tokenized
 * Return: array of tokenized strings
 */

char **_tokenize(char *str)
{
	char **parsed = NULL;

	int i = 0;

	char *token = NULL;

	parsed = malloc(sizeof(char *) * (strlen(str) + 1));
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
		execve(command, tokens, environ);
	return (0);
}
