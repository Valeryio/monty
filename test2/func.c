#include "monty.h"
/**
  * _strdup - reallocates the string and copy its value.
  * @str: string to be reallocated and copies.
  * Return: end of the program.
  */
char *_strdup(char *str)
{
	char *cpy;
	int i;

	cpy = malloc(sizeof(*str));
	while (str != NULL)
	{
		if (cpy == NULL)
			return (NULL);
		for (i = 0; str[i] != '\0'; i++)
			cpy[i] = str[i];
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
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
void pus(stack_t **head, unsigned int n)
{
	stack_t* newnode = NULL;

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


void pal(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void pin(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	printf("Function: pin, Line number: %d\n", line_number);
}

void po(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	        printf("Function: po, Line number: %d\n", line_number);
}

void swa(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	        printf("Function: swa, Line number: %d\n", line_number);
}

void add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	        printf("Function: add, Line number: %d\n", line_number);
}

void no(stack_t **stack, unsigned int line_number)
{
	        printf("Function: no, Line number: %d\n", line_number);
	(void) stack;
}
