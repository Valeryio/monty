#include "monty.h"


/**
 * push - this function push an node
 * to a stack
 *
 * @head: the head of the link
 * @n: the data of the node
 * Description: This function adds node
 * to an existing stack.
 * Return: Nothing
 */
void push(stack_t **head, int n)
{
	stack_t *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = n;

/*In this case where the stack is empty!*/
	if (!(*head))
	{
		printf("La stack est nulle !");
		newnode->next = NULL;
		newnode->prev = NULL;
		(*head) = newnode;
		return;
	}

/*What is the stack is not empty?*/
	newnode->prev = NULL;
	newnode->next = (*head);
	(*head) = newnode;
}


/**
 * pall - show all the elements of a stack
 *
 * @head: the head of the stack
 * @n: an integer
 * @line_number: the line number
 * Description: This function shows all the
 * node inside a stack
 * Return: nothing
 */
void pall(stack_t **head)
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
 * custom_pall - show all the elements of a stack
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

	i = i - 1;
	tmpnode = (*head);
	while (tmpnode != NULL)
	{
		printf("[%d]-", tmpnode->n);
		tmpnode = tmpnode->next;
	}

	printf("||*\n\n");
}
