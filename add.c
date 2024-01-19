#include "monty.h"
/**
 * addnode - function
 * @stack: input
 * @value: input
 * Return: void
 */
void addnode(stack_t **stack, int value)
{
	stack_t *new_node, *current_node;

	current_node = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (current_node)
		current_node->prev = new_node;

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
