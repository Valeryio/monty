#include "monty.h"

/**
 * f_mod - div elements of a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function mod the second element of the stack
 * by the top
 * Return: Nothing
 */

void f_mod(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (getStackLength(&(*head)) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod(&(*head));
}
