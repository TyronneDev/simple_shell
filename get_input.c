#include "shell.h"

char *get_input()
{
	char *input = NULL;
	size_t input_size = 0;

	printf("($) ");

	while (1)
	{
		ssize_t read_size = getline(&input, &input_size, stdin);

		if (read_size == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(input);
				return NULL;
			}
			else
			{
				perror("Error reading input");
				exit(EXIT_FAILURE);
			}
		}

		/* Remove trailing newline */
		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0)
		{
			break; /* Break the loop when valid input is received */
		}
		else
		{
			printf("($) ");
		}
	}

	return input;
}
