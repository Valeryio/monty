#include "monty.h"

/**
 * pint - print an element
 * @head: the stack
 *
 * Description: This function prints the top
 * element of a stack
 * Return: Nothing
 */

void pint(stack_t **head)
{
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	printf("%d\n", tmpnode->n);
}
