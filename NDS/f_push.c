#include "monty.h"

/**
 * f_push - push an element to the top of the stack
 * 
 * @stack: the stack to use
 * @n: the integer to push
 * Description: This function pushes an element to the
 * top of a stack
 * Return: Nothing
 */

void f_push(stack_t **head, unsigned int line_number)
{
	if ((getNumberOfArgs() < 2) || (atoi(montyline_args[1]) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freeStack(&(*head));
		exit(EXIT_FAILURE);
	}

	printf("NOmbre d'arguments sur la ligne : %d\n", getNumberOfArgs());
	push(&(*head), atoi(montyline_args[1]));
}
