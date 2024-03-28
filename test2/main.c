#include "monty.h"
stack_t *stack = NULL;
/**
 * main - Entry point to the program.
 * @argc: Numeber of arguments during runtime.
 * @argv: array of string of arguments.
 * Return: End of the program.
 */
int main(int argc, char *argv[])
{
	int line_number = 1;
	char full_command[MAX_LINE];
	size_t size;
	FILE *file;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(full_command, MAX_LINE, file) != NULL)
	{
		size = strlen(full_command);
		if (size > 0 && full_command[size - 1] == '\n')
			full_command[size - 1] = '\0';
		arguments(full_command, line_number);
		line_number++;
	}
	fclose(file);
	return (0);
}
