#include "monty.h"

/**
 * f_pstr - print a string from a stack
 *
 * @head: the stack to use
 * @line_number: verifications to do on the line
 * Description: This function prints a string from a stack
 * Return: Nothing
 */

void f_pstr(stack_t **head, unsigned int line_number)
{
	line_number++;
	pstr(&(*head));
}
