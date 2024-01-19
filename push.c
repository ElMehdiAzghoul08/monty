#include "monty.h"

/**
 * push_to_stack - function
 * @stack: input
 * @counter: input
 * Return: void
 */
void push_to_stack(stack_t **stack, unsigned int counter)
{
	int value, index = 0, invalid_input = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			invalid_input = 1;

		while (bus.arg[index] != '\0')
		{
			if (bus.arg[index] < '0' || bus.arg[index] > '9')
				invalid_input = 1;

			index++;
		}

		if (invalid_input)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			freeStack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(stack, value);
	else
		enqueue(stack, value);
}
