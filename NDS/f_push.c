#include "monty.h"
#include <limits.h>
/**
 * f_push - push an element to the top of the stack
 * 
 * @stack: the stack to use
 * @n: the integer to push
 * Description: This function pushes an element to the
 * top of a stack
 * Return: Nothing
 */

void f_push(stack_t **head, unsigned int line_number)
{
	int stringChar = 0;

	stringChar = containString(montyline_args[1]);

	printf("Voici le result : %d\n", stringChar);

	printf("Arguments : %d\n", getNumberOfArgs());
	if ((getNumberOfArgs() < 2) || (stringChar == -1))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freeStack(&(*head));
		exit(EXIT_FAILURE);
	}

	printf("NOmbre d'arguments sur la ligne : %d\n", getNumberOfArgs());
	push(&(*head), atoi(montyline_args[1]));
}


int my_getnbr(char *str)
{
  int   res;

  if (*str == '-')
    return (-my_getnbr(str + 1));
  if (*str == '+')
    return (my_getnbr(str + 1));
  res = 0;
  while (*str)
    {
      res *= 10;
      res += *str - '0';
      str++;
    }
  return (res);
}
