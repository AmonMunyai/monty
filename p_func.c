#include "monty.h"

/**
 * push
 * @stack:
 * @line_number
 * Return:
 */

void push(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (global_variable.n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	while (global_variable.n[i] != '\0')
	{
		if (global_variable.n[i] < '0' || global_variable.n[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	printf("-------- PUSH EXIT_SUCCESS --------\n");
}

/**
 * push
 * @stack:
 * @line_number
 * Return:
 */

void pall(stack_t **stack, unsigned int line_number)
{
	printf("-------- PALL EXIT_SUCCESS --------\n");
}
