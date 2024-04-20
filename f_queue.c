#include "monty.h"

/**
 * f_queue - Implement the queue version of the opcode
 *
 * @head: the stack to use to do nothing
 * @line_number: verifications to do on the line
 * Description: This function implement the queue version
 * of the monty's stack
 * Return: Nothing
 */

void f_queue(stack_t **head, unsigned int line_number)
{
	line_number++;
	if ((*head) == NULL)
	{
		line_number++;
		return;
	}

	queue(&(*head));
}
