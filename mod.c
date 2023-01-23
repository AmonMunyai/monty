#include "monty.h"

/**
 * mod - computes the rest of the division,
 *	of the second top element of the stack,
 *	by the top element of the stack.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n %= (*stack)->next->n;
	pop(stack, line_number);
}
