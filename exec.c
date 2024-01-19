#include "monty.h"

/**
 * exec - function
 * @content: input
 * @stack: input
 * @counter: input
 * @file: input
 * Return: ntg
 */
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops_[] = {
		{"push", push_to_stack}, {"pall", print_stack}, {"pint", print_top},
		{"pop", pop_from_stack},
		{"swap", swap_top_two_elements},
		{"add", add_top_two_nodes},
		{"nop", no_operation},
		{"sub", subtract_top_two_elements},
		{NULL, NULL}
	};
	unsigned int i;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");

	for (i = 0; ops_[i].opcode && op; i++)
	{
		if (strcmp(op, ops_[i].opcode) == 0)
		{
			ops_[i].f(stack, counter);
			return (0);
		}
	}

	if (op && ops_[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
