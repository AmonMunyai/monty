#include "monty.h"

/**
 * pint - prints the value at the top of the stack,
 *	followed by a new line.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", global_v.head->n);
}
