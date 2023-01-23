#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL && (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
