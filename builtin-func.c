#include "monty.h"
#define MAX_LENGTH 256

/**
 * getArguments - get the two arguments of monty code
 *
 * @line: a string
 *
 * Description: This function takes a string and save
 * the monty's code instruction from it. It stores each
 * arguments, the opcode and the number (or not) in an
 * array of character that is sent
 *
 * Return: An array of strings
 * -------------- -------------
 * | arguments[0] | *opcode   |
 * -------------- -------------
 * | arguments[1] | str(int)) |
 * -------------- -------------
 */
/*UPDATED VERSION OF THE FUNCTION getArguments*/
void getArguments(char *line)
{
	int i = 0, result = 0, nullptr = 1;
	char opcode[MAX_LENGTH], arg[MAX_LENGTH];
	/*Freeing the previous line arguments before adding new ones*/
	while (i < getNumberOfArgs())
	{
		free(montyline_args[i]);
		i++;
	}
	free(montyline_args);
	montyline_args = NULL;
	/*Getting a new line*/
	result = sscanf(line, " %s %s", opcode, arg);
	if (result == 1)
	{
		montyline_args = (char **)malloc((1 + nullptr) * sizeof(char *));
		mallocError(&(montyline_args));
		montyline_args[0] = malloc(sizeof(char) * (strlen(opcode) + 1));

		strcpy(montyline_args[0], opcode);
		montyline_args[1] = NULL;
	}

	if (result == 2)
	{
		montyline_args = (char **)malloc((2 + nullptr) * sizeof(char *));
		mallocError(&(montyline_args));

		montyline_args[0] = NULL;
		montyline_args[1] = NULL;
		montyline_args[2] = NULL;
		montyline_args[0] = malloc(sizeof(char) * (strlen(opcode) + 1));
		mallocError(&montyline_args[0]);
		montyline_args[1] = malloc(sizeof(char) * (strlen(arg) + 1));
		mallocError(&montyline_args[1]);

		strcpy(montyline_args[0], opcode);
		strcpy(montyline_args[1], arg);
	}
}

/**
 * isValidArgument - this function check if an argument exist
 * @head: (stack), the stack to use
 * @line_number: (int), the line number of the monty file
 *
 * Description: This function verifies if the instruction
 * on the line, is known, and if it's valid
 * Return: An integer
 */
int isValidArgument(stack_t **head, unsigned int line_number)
{
	int i = 0, known_arg = 0, result = 0;
	char *montyinstructions[] = {"push", "pall", "pint", "pop", "swap", "nop", "add", 
				"sub", "div", "NULL"};

	/*Verifying if the given argument is known*/
	while (i < 9)
	{
		result = strcmp(montyinstructions[i], montyline_args[0]);
		if (result == 0)
		{
			known_arg = 1;
			break;
		}
		i++;
	}
	/*Line_num... is a long word, let's reuse result to have a line lenght <= 80*/
	result = line_number;
	if (!known_arg)
	{
	/*Free the stack and exit the program if the arguments is not known*/
		fprintf(stderr, "L%d: unknown instruction %s\n", result, montyline_args[0]);
		freeStack(&(*head));
		exit(EXIT_FAILURE);
	}

	return (0);
}


/**
 * getNumberOfArgs - count the number of args
 *
 * Description: This function counts the number of args in
 * a monty line datastructure (array of strings)
 * Return: An integer
 */

int getNumberOfArgs(void)
{
	int i = 0;

	if (montyline_args == NULL)
		return (0);
	while (montyline_args[i])
	{
		i++;
	}
	return (i);
}


/**
 * containString - verify non number char in string
 *
 * @str: non number char
 * Description: Verifiy if there is a non number character
 * in a string, or if there's no an argument where it should
 * be one.
 * Return: A number
 */

int containString(char *str)
{
	int i = 0, result = 1;

/*There is no second argument for an instruction that need one*/
	if (!str)
		return (-1);

	while (str[i] != '\0')
	{
/*If the first char is - or + continue */
		if ((str[i] == 43) || (str[i] == 45))
		{	i++;
			continue;
		}
/*If the character is not an integer, get out and return -1*/
		if (((str[i] < 48) || (str[i] > 57)))
		{
			result = -1;
			return (result);
		}
		i++;
	}
	return (result);
}


/**
 * getStackLength - get the length of the stack
 *
 * @head: the stack
 * Description: This function gets the length of the stack
 * Return: An integer
 */

int getStackLength(stack_t **head)
{
	int length = 0;
	stack_t *tmpnode = NULL;

	if ((*head) == NULL)
		return (0);

	tmpnode = (*head);
	while(tmpnode)
	{
		length++;
		tmpnode = tmpnode->next;
	}

	return (length);
}
