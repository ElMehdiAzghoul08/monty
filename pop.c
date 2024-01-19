#include "monty.h"

/**
 * pop_from_stack - a function
 * @stack: input
 * @line_number: input
 * Return: void
 */
void pop_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	current_node = *stack;
	*stack = current_node->next;
	free(current_node);
}
