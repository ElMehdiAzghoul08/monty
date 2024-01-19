#include "monty.h"

/**
 * subtract_top_two_elements - function
 * @stack: input
 * @line_number: input
 * Return: void
 */
void subtract_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	int result, node_count;

	current_node = *stack;
	while (current_node != NULL)
	{
		node_count++;
		current_node = current_node->next;
	}

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	current_node = *stack;
	result = current_node->next->n - current_node->n;
	current_node->next->n = result;
	*stack = current_node->next;
	free(current_node);
}
