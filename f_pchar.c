#include "monty.h"

/**
 * f_pchar - pint a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function prints the char of the top elements of a stack
 * Return: Nothing
 */

void f_pchar(stack_t **head, unsigned int line_number)
{
	int c[1];

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c[0] = (*head)->n;
	if (c[0] > 127 || c[0] < 0)
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	pchar(&(*head));
}
