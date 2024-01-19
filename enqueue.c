#include "monty.h"
/**
 * enqueue - function
 * @head: input
 * @value: input
 * Return: Void
 */
void enqueue(stack_t **head, int value)
{
	stack_t *newNode, *current;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->next = NULL;

	current = *head;
	if (current)
	{
		while (current->next)
			current = current->next;
	}

	if (!current)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		current->next = newNode;
		newNode->prev = current;
	}
}
