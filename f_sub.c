#include "monty.h"

/**
 * f_sub - sub elements of a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function substract the top elements of a stack
 * Return: Nothing
 */

void f_sub(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (getStackLength(&(*head)) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub(&(*head));
}
