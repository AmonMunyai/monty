#include "monty.h"

/**
 * add_dnodeint - adds a new node at the end of a stack_t list.
 * @head: head of stack_t list.
 * @n: integer.
 * Return: the address of a new node.
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = n;

	if (*head == NULL)
		node->next = NULL;
	else
	{
		(*head)->prev = node;
		node->next = *head;
	}

	node->prev = NULL;
	*head = node;

	return (node);
}
