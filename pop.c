#include "monty.h"

/**
 * pop - pop an element
 * @head: the stack
 *
 * Description: This function pop the top the top
 * element of the stack
 * Return: Nothing
 */

void pop(stack_t **head)
{
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	*head = tmpnode->next;
	free(tmpnode);
}
