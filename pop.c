#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop, an empty stack\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	temp = global_v.head->next;

	if (temp != NULL)
		temp->prev = NULL;

	free(global_v.head);
	global_v.head = temp;
}
