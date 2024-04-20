#include "monty.h"

/**
 * rotr - this function rotl a stack
 *
 * @head: (stack), the stack to use
 * Description: This function rotl the stack given
 * as argument
 * Return: Nothing
 */

void rotr(stack_t **head)
{
	stack_t *tmpnode = NULL;
	int tmp = 0, saved = 0;

	if ((*head) == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	tmpnode = (*head);
	tmp = tmpnode->n;
	tmpnode = tmpnode->next;

	while (tmpnode)
	{
		saved = tmpnode->n;
		tmpnode->n = tmp;

		tmp = saved;
		tmpnode = tmpnode->next;
	}
	(*head)->n = (unsigned int) tmp;
}
