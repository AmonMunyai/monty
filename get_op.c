#include "monty.h"

/**
 * get_op - returns a function, to corresponding to opcode.
 * @op: opcode.
 * Return: corresponding function to opcode.
 */

void (*get_op(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0;

	while (strcmp(ops[i].opcode, op) != 0 && ops != NULL)
		i++;

	return (ops[i].f);
}
