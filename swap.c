#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL && (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
