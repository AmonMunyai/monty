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
	stack_t *node;

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

	add_dnodeint(stack, atoi(global_variable.n));
}

/**
 * pall - prints all the values on the stack,
 *	starting from the top of the stack.
 * @stack: stack_t doubly linked list.
 * @line_number: line number in the file.
 * Return: nothing.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
