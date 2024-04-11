#include "monty.h"

/**
 * swap - swap two element
 * @head: the stack
 *
 * Description: This function swap two element at the top
 * of a stack
 * Return: Nothing
 */

void swap(stack_t **head)
{
	stack_t *tmpnode = NULL;
	int tmp = 0;

	tmpnode = (*head);
	tmpnode = tmpnode->next;

	tmp = (*head)->n;
	(*head)->n = tmpnode->n;
	tmpnode->n = tmp;

	printf("%d\n", tmpnode->n);
}
