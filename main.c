#include "monty.h"

global_t global_v = {0, NULL, NULL, NULL, NULL, NULL, NULL};

/**
 * main - driver code
 * @argc: no. of arguments
 * @argv: array of arguments
 * Return: always 0 (on success)
 */

int  main(int argc, char *argv[])
{
	char *n;
	size_t size = 0, line_number = 1;
	ssize_t readline;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global_v.file = fopen(argv[1], "r"); /* open file */
	if (global_v.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((readline = getline(&global_v.buffer, &size, global_v.file)) > 0)
	{
		global_v.opcode = strtok(global_v.buffer, " \n\t\v\b\r\f\a");

		global_v.f = get_op(global_v.opcode);
		if (global_v.f == NULL)
		{
			fprintf(stderr, "L%ld: unknown instruction %s\n",
					line_number, global_v.opcode);
			exit(EXIT_FAILURE);
		}

		n = strtok(NULL, " \n\t\v\b\r\f\a");
		if (n != NULL)
			global_v.n = n;

		global_v.f(&global_v.head, line_number); /* execute */
		line_number++;
	}
	free(global_v.buffer);
	fclose(global_v.file);

	return (EXIT_SUCCESS);
}
