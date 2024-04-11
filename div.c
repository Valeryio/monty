#include "monty.h"

/**
 * div - div two elements of a stack
 * @head: the stack
 *
 * Description: This function div two elements at the top of a
 * stack
 * Return: Nothing
 */

void divs(stack_t **head)
{
	float result = 0;
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	(*head) = (*head)->next;

	result = (float)(*head)->n / (float)tmpnode->n;
	(*head)->n  = (int) result;

	free(tmpnode);
}
