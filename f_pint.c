#include "monty.h"

/**
 * f_pint - pint a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function prints the elements of a stack
 * Return: Nothing
 */

void f_pint(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	pint(&(*head));
}
