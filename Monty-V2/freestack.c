#include "monty.h"

/**
 * freestack - this function frees a stack
 *
 * @head: the head of the stack
 * Description: This function frees a stack
 * Return: Nothing
 */

void freestack(stack_t **head)
{
	stack_t *tmpnode = NULL;
	
	while (*head)
	{
		tmpnode = (*head);
		(*head) = (*head)->next;
		free(tmpnode);
	}
}
