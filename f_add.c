#include "monty.h"

/**
 * f_add - add elements of a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function add the top elements of a stack
 * Return: Nothing
 */

void f_add(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (getStackLength(&(*head)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	add(&(*head));
}
