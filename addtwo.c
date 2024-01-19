#include "monty.h"

/**
 * add_top_two_nodes - function
 * @stack: input
 * @lineNumber: inpuy
 * Return: void
 */
void add_top_two_nodes(stack_t **stack, unsigned int lineNumber)
{
	stack_t *current;
	int length = 0, result;

	current = *stack;
	for (; current; current = current->next, length++)
		;

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	result = current->n + current->next->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
