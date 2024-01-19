#include "monty.h"

/**
 * freeStack - function
 * @stack: input
 */
void freeStack(stack_t *stack)
{
	stack_t *temp;

	for (; stack; stack = temp)
	{
		temp = stack->next;
		free(stack);
	}
}

