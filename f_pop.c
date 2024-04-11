#include "monty.h"

/**
 * f_pop - pop a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function removes the top elements of a stack
 * Return: Nothing
 */

void f_pop(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(&(*head));
}
