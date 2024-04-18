#include "monty.h"

/**
 * f_rotl - rotate a stack
 *
 * @head: the stack to use to rotate the stack
 * @line_number: verifications to do on the line
 * Description: This function call the function that rotate
 * the stack
 * Return: Nothing
 */

void f_rotl(stack_t **head, unsigned int line_number)
{
	line_number++;
	rotl(&(*head));
}
