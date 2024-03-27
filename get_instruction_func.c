#include "monty.h"

/**
 * get_instruction_func - get an instruction by a function
 *
 * @str: a string
 * Description: This function returns a function and chose
 * between different parts of a datastructure
 * Return: A function
 */

void (*get_instruction_func(char *str))(stack_t**, unsigned int)
{
	int i = 0;
	instruction_t montyfunc[] = {
					{"push", push},
					{"pall", pall},
					{NULL, NULL}
				};

	if (!str)
		printf("La chaine envoyee est erronnee !");

	while (i < 2)
	{
		if (!strcmp(montyfunc[i].opcode, str))
			return montyfunc[i].f;
		i++;
	}

	return (NULL);
}
