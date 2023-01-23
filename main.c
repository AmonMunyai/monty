#include "monty.h"

global_t global_variable = {0};

/**
 * read_file - opens a file.
 * @filename: name of file to open.
 * Return: a FILE pointer.
 */

FILE read_file(char * const filename)
{
	FILE *file;

	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - driver code
 * @argc: no. of arguments
 * @argv: array of arguments
 * Return: always 0 (on success)
 */

int  main(int argc, char *argv[])
{
	FILE *file;
	size_t size = 0, line_number = 1;
	ssize_t readline;
	stack_t *stack = NULL;
	char *buffer, *opcode, *n;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(filename);

	while ((readline = getline(&buffer, &size, file)) > 0)
	{
		opcode = strtok(buffer, " \n\t\v\b\r\f\a"); /* get opcode */
		f = get_op(opcode);

		if (f == NULL)
		{
			fprintf(stderr, "L%ld: unknown instruction %s",
					line_number, opcode);
			exit(EXIT_FAILURE);
		}

		n = strtok(NULL, " \n\t\v\b\r\f\a"); /* get <int> argument */

		if (n != NULL)
			global_variable.n = n;

		f(&stack, line_number); /* execute instruction */
		line_number++;
	}
	free(buffer);
	fclose(file);

	return (EXIT_SUCCESS);
}
