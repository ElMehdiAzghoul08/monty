#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - functiom
 * @argc: input
 * @argv: input
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *lineContent;
	FILE *file;
	size_t size = 0;
	ssize_t readLine = 1;
	stack_t *stack = NULL;
	unsigned int lineCounter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; readLine > 0; lineCounter++)
	{
		lineContent = NULL;
		readLine = getline(&lineContent, &size, file);
		bus.content = lineContent;
		if (readLine > 0)
		{
			exec(lineContent, &stack, lineCounter, file);
		}
		free(lineContent);
	}
	freeStack(stack);
	fclose(file);
	return (0);
}
