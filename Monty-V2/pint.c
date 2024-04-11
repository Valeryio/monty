#include "monty.h"

/**
 * pint - print an element
 * @stack: the stack
 * @n: the line number
 *
 * Description: This function prints the top
 * element of a stack
 * Return: Nothing
 */

void pint(stack_t **head, unsigned int i)
{
	stack_t *tmpnode = NULL;

	if (!(*head))
		fprintf(stderr, "L%d: can't pint, stack empty", i);

	tmpnode = (*head);
	while(tmpnode->next)
		tmpnode = tmpnode->next;

	printf("%d\n", tmpnode->n);
}
