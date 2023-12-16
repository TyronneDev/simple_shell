#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *get_input();
void execute_command(char *command, char **envp);
void resolve_command_path(char **command_with_args);

#endif /* SHELL_H */
