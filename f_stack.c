#include "monty.h"

/**
 * f_stack - Implement the stack version of the opcode
 *
 * @head: the stack to use to do nothing
 * @line_number: verifications to do on the line
 * Description: This function do nothing cause the normal
 * format of the data structure in a monty interpreter is
 * a stack
 * Return: Nothing
 */

void f_stack(stack_t **head, unsigned int line_number)
{
	line_number++;
	if ((*head) == NULL)
	{
		line_number++;
	}
	nop();
}
