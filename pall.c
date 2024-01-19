#include "monty.h"

/**
 * print_stack - function
 * @stack: input
 * @counter: input
 * Return: ntg
 */
void print_stack(stack_t **stack, unsigned int counter)
{
	stack_t *current_node;
	(void)counter;

	for (current_node = *stack; current_node; current_node = current_node->next)
	{
		printf("%d\n", current_node->n);
	}
}
