#include "monty.h"
/**
 * arguments - handles monty command  arguments.
 * @full_command: Full line read from the file.
 * @line_number: line number read. 
 */
void arguments(char *full_command, int line_number)
{
	int i;
	char **argv;
	char *each;
	char *separator;

	separator = " ";
	argv = malloc(sizeof(each) * 2);
	each = strtok(full_command, separator);
	if (each == NULL)
		return;
	i = 0;
	while (each)
	{
		argv[i] = each;
		each = strtok(NULL, separator);
		i++;
	}
	if (argv[0] != NULL)
		opcode_interpreter(argv, line_number);
	free(argv);
}
