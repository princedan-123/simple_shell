#include "main.h"

/**
 * get_env - prints the environmental variables to stdout
 *
 * Return: void
 */

void get_env(char **env)
{
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * main - getss user input and executes the shell
 * @user_input: comand entered by user
 *
 * Return: 0 on success
 */


int main(void)
{
	char *user_input = NULL;
	ssize_t get;
	size_t n = 0;
	char **tokens = NULL;
	int status;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		get = getline(&user_input, &n, stdin);
		user_input[strcspn(user_input, "\n")] = '\0';
		if (get == -1)
			break;

		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			break;
		}
		else if (pid == 0)
		{
			if ((strcmp(user_input, "env")) == 0)
			{
				get_env(environ);
				break;
			}
			tokens = _tokenize(user_input);
			executor(tokens);
			free(tokens);
		}
		else
			wait(&status);
	}
	free(user_input);
	return (0);
}

/**
 * _tokenize - tokenizes a string
 * @str: string to be tokenized
 * Return: array of tokenized strings
 

char **_tokenize(char *str)
{
	const char *delim = " ";
	char *token;
	char **tokens = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (i + 1));
		if (!tokens)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}*/

char **_tokenize(char *str)
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
	return(parsed);
}

/**
 * executor - executes shell commands
 * @command: array of command and arguments
 *
 * Return: 0
 */

int executor(char **command)
{
	if ((access(command[0], X_OK) == 0))
	{
		if ((execve(command[0], command, NULL)) != 0)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (0);
}
