#include "monty.h"
#include <limits.h>
/**
 * f_push - push an element to the top of the stack
 *
 * @head: the stack to use
 * @line_number: the numberr of the line
 * Description: This function pushes an element to the
 * top of a stack
 * Return: Nothing
 */

void f_push(stack_t **head, unsigned int line_number)
{
	int stringChar = 0;
/*Verify if the argument to use is a string or an integer*/
	stringChar = containString(montyline_args[1]);

	if ((getNumberOfArgs() < 2) || (stringChar == -1))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freeStack(&(*head));
		exit(EXIT_FAILURE);
	}
/*Execute the right function if everything is alright*/
	push(&(*head), atoi(montyline_args[1]));
}
