#include "monty.h"

/**
 * sub - subtracts the top element of the stack,
 *	from the second top element of the stack.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL && (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
