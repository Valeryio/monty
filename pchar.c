#include "monty.h"

/**
 * pchar - print an element
 * @head: the stack
 *
 * Description: This function prints the char at the top
 * element of a stack
 * Return: Nothing
 */

void pchar(stack_t **head)
{
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	printf("%c\n", tmpnode->n);
}
