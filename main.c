#include "shell.h"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[], char *envp[])
{
	char *input;

	while (1)
	{
		input = get_input();

		if (input == NULL)
		{
			break; /* Exit shell */
		}

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		execute_command(input, envp);

		free(input);
	}

	return EXIT_SUCCESS;
}

