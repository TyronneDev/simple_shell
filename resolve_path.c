#include "shell.h"

void resolve_command_path(char **command_with_args) 
{
	char *env_path = NULL, *dir = NULL, *full_path = NULL, *path_copy = NULL;
	char *command = command_with_args[0]; /* Extract the command part */
	int i = 0;

	if (command == NULL || command_with_args == NULL)
		return;

	env_path = getenv("PATH");
	if (env_path == NULL)
		return;

	path_copy = strdup(env_path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		full_path = malloc(strlen(command) + strlen(dir) + 2);
		if (full_path == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			return;
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(command_with_args[0]);
			command_with_args[0] = strdup(full_path);
			free(full_path);

			/* Adjust pointers for arguments after resolving command path*/
			for (i = 1; command_with_args[i] != NULL; ++i) 
				break;
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
}
