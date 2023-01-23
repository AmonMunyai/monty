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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"NULL", NULL}
	};

	int i = 0;

	while (strcmp(ops[i].opcode, op) != 0 && i < 11)
		i++;

	return (ops[i].f);
}
