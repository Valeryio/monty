#include "monty.h"

/**
 * f_div - div elements of a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function div the second element of the stack
 * by the top
 * Return: Nothing
 */

void f_div(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (getStackLength(&(*head)) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (montyline_args[1] == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divs(&(*head));
}
