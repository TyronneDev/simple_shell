#include "shell.h"

void execute_command(char *command, char **envp)
{
	pid_t = pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		/* Fork failed */
		perror("Fork failed");
		return;
	}

	if (pid == 0)
	{
		/* Child process */
		char *args[] = {command, NULL}; /* Command with arguments */

		char *env_path = getenv("PATH");
		if (env_path != NULL)
		{
			resolve_command_path(args); /*  Resolve command path based on PATH */
		}

		if (execve(args[0], args, envp) == -1)
		{
			/*Command not found in current directory or PATH*/
			fprintf(stderr, "Command not found: %s\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		{
			printf("($) "); /* Display prompt after successful command execution */
		}
		else
		{
			printf("\n($) "); /* Display prompt on the next line for command failure */
		}
	}
}
