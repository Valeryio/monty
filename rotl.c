#include "monty.h"

/**
 * rotl - this function rotl a stack
 *
 * @head: (stack), the stack to use
 * Description: This function rotl the stack given
 * as argument
 * Return: Nothing
 */

void rotl(stack_t **head)
{
	stack_t *tmpnode = NULL;
	int tmp = 0;

	if ((*head) == NULL)
		return;

	tmp = (*head)->n;
	tmpnode = (*head);

	while (tmpnode->next)
	{
		tmpnode->n = tmpnode->next->n;
	}
	
	tmpnode->n = (unsigned int) tmp;
}
