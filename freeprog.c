#include "monty.h"

/**
 * freeprog - free all the necessary values
 *
 * @stack: the stack of monty
 * Description: This function frees all the necessary
 * values like the monty's stack and the arguments
 * array
 * Return: A number
 */

int freeprog(stack_t **head)
{
	int i = 0;

	if ((*head) == NULL)
		return (0);

	freeStack(&(*head));
	printf("Je crois que tout va bien jusqu'ici\n");

	printf("Nombre d'arguements : %d\n", getNumberOfArgs());
	
	for (; i < getNumberOfArgs(); i++)
		free(montyline_args[i]);

	printf("Je crois que tout va bien jusqu'ici aussi\n");

	free(montyline_args);
	return (0);
}
