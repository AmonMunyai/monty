#include "monty.h"

/**
 * _div - prints the value at the top of the stack,
 *	followed by a new line.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next->n)
	{
		fprintf(stderr, "L%d: dividion by zero\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n /= (*stack)->next->n;
	pop(stack, line_number);
}
