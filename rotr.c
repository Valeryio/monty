#include "monty.h"

/**
 * rotl - this function rotl a stack
 *
 * @head: (stack), the stack to use
 * Description: This function rotl the stack given
 * as argument
 * Return: Nothing
 */

void rotr(stack_t **head)
{
	stack_t *tmpnode = NULL;
	int tmp = 0;

	if ((*head) == NULL)
		return;

	tmpnode = (*head);

	while (tmpnode->next)
	{
		if (tmpnode->next->next == NULL)
			tmp = tmpnode->next->n;
		tmpnode->next->n = tmpnode->n;
		tmpnode = tmpnode->next;
	}
	
	(*head)->n = (unsigned int) tmp;
}
