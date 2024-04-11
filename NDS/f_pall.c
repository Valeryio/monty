#include "monty.h"

/**
 * f_pall - print a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function prints the elements of a stack
 * Return: Nothing
 */

void f_pall(stack_t **head, unsigned int line_number)
{
	line_number++;

	/*NO VERIFICATIONS to do in a line with the pall instruction*/
	pall(&(*head));
}
