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
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap(&(*head));
}
