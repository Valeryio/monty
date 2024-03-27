#include "monty.h"

/**
 * pall - show all the elements of a stack
 * 
 * @head: the head of the stack
 * @i: an integer
 * Description: This function shows all the
 * node inside a stack
 * Return: nothing
 */

void pall(stack_t **head, unsigned int i)
{
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	while (tmpnode != NULL)
	{
		printf("%d\n", tmpnode->n);
		tmpnode = tmpnode->next;
	}
}

/**
 * custom-pall - show all the elements of a stack
 * 
 * @head: the head of the stack
 * @i: an integer
 * Description: This function shows all the
 * node inside a stack
 * Return: nothing
 */

void custom_pall(stack_t **head, unsigned int i)
{
	stack_t *tmpnode = NULL;

	tmpnode = (*head);
	while (tmpnode != NULL)
	{
		printf("[%d]-", tmpnode->n);
		tmpnode = tmpnode->next;
	}

	printf("||*\n\n");
}
