#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (global_v.n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	if (global_v.n[0] == '-')
		i++;

	while (global_v.n[i] != '\0')
	{
		if (global_v.n[i] < '0' || global_v.n[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	add_dnodeint(stack, atoi(global_v.n));
}
