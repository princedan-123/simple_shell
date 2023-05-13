#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

char **_tokenize(char *str);
void get_env(char **env);
int executor(char *command, char **tokens);
void exit_child(char *tokens[]);
void display(void);
char *path(char *tokens[]);
int _exit_status(int status);

#endif
