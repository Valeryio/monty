#include "monty.h"

/**
 * freeStack - this function frees a stack
 *
 * @head: the head of the stack
 * Description: This function frees a stack
 * Return: Nothing
 */

void freeStack(stack_t **head)
{
	stack_t *tmpnode = NULL, *to_delete = NULL;

	tmpnode = (*head);
	while (tmpnode)
	{
		to_delete = tmpnode;
		tmpnode = tmpnode->next;
		free(to_delete);
	}
	*head = NULL;
}
