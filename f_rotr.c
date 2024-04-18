#include "monty.h"

/**
 * f_rotr - rotate a stack
 *
 * @head: the stack to use to rotate the stack
 * @line_number: verifications to do on the line
 * Description: This function call the function that rotate
 * the stack
 * Return: Nothing
 */

void f_rotr(stack_t **head, unsigned int line_number)
{
	line_number++;
	rotr(&(*head));
}
