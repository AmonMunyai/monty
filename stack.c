#include "monty.h"

/**
 * add_dnodeint - adds a new node at the end of a stack_t list.
 * @head: head of stack_t list.
 * @n: integer.
 * Return: the address of a new node.
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node, *temp;

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
		temp = *head;
		temp->prev = node;
		node->next = temp;
	}

	node->prev = NULL;
	*head = node;

	return (node);
}

/**
 * print_dnodeint - prints all the elements of a stack_t list.
 * @head: head of stack_t list.
 * @n: integer.
 * Return: the number of elements in a stack_t list.
 */

size_t print_dnodeint(stack_t **head, const int n __attribute__((unused)))
{
	size_t count = 0;
	stack_t *temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		count++;
	}

	return (count);
}
