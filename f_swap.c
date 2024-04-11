#include "monty.h"

/**
 * f_swap - swap two element of a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function swap two elements of the top of
 * a stack
 * Return: Nothing
 */

void f_swap(stack_t **head, unsigned int line_number)
{
	int i  = 0;
	printf("ON est la\n");
	if ((*head) == NULL)
	{
		printf("NULL\n");
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeStack(&(*head));
		for (i = 0; i < getNumberOfArgs(); i++)
			free(montyline_args[i]);
		free(montyline_args);
		exit(EXIT_FAILURE);
	}
	printf("Longueur de la stack : %d\n", getStackLength(&(*head)));
	printf("Verification de la taille\n");
	if (getStackLength(&(*head)) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeStack(&(*head));
		for (i = 0; i < getNumberOfArgs(); i++)
			free(montyline_args[i]);
		free(montyline_args);
		exit(EXIT_FAILURE);
	}

	swap(&(*head));
}
