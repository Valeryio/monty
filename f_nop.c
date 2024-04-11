#include "monty.h"

/**
 * f_nop - do nothing
 *
 * @head: the stack to use to do nothing
 * @line_number: verifications to do on the line
 * Description: This function do nothing
 * Return: Nothing
 */

void f_nop(stack_t **head, unsigned int line_number)
{
	line_number++;
	if ((*head) == NULL)
	{
		line_number++;
	}
	nop();
}
