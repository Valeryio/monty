#include "monty.h"

/**
 * mod - div two elements of a stack
 * @head: the stack
 *
 * Description: This function mod two elements at the top of a
 * stack
 * Return: Nothing
 */

void mod(stack_t **head)
{
	float result = 0;
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	(*head) = (*head)->next;

	result = (*head)->n % tmpnode->n;
	(*head)->n  = (int) result;

	free(tmpnode);
}
