#include "monty.h"

/**
 * get_arguments - get the two arguments of monty code
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
	int i = 0, result = 0;
	char opcode[8], arg[8];
	/*Freeing the previous line arguments before adding new ones*/
	while (i < getNumberOfArgs())
	{
		free(montyline_args[i]);
		i++;
	}
	free(montyline_args);
	montyline_args = NULL;
	/*Getting a new line*/
	result = sscanf(line, "%s %s", opcode, arg);
	if (result == 1)
	{
		montyline_args = (char **)malloc(1 * sizeof(char *));
		mallocError(&(montyline_args));
		montyline_args[0] = malloc(sizeof(char) * (strlen(opcode) + 1));

		strcpy(montyline_args[0], opcode);
		montyline_args[1] = NULL;
	}

	if (result == 2)
	{
		montyline_args = (char **)malloc(2 * sizeof(char *));
		mallocError(&(*montyline_args));

		montyline_args[0] = NULL;
		montyline_args[1] = NULL;
		montyline_args[0] = malloc(sizeof(char) * (strlen(opcode) + 1));
		mallocError(montyline_args[0]);
		montyline_args[1] = malloc(sizeof(char) * (strlen(arg) + 1));
		mallocError(montyline_args[1]);

		strcpy(montyline_args[0], opcode);
		strcpy(montyline_args[1], arg);
	}
}

/**
 * arg_detector - this function check if an argument exist
 * @head: (stack), the stack to use
 * @line_number: (int), the line number of the monty file
 *
 * Description: This function verifies if the instruction
 * on the line, is known, and if it's valid
 * Return: An integer
 */

int isValidArgument(stack_t **head)
{
	int i = 0, known_arg = 0, result = 0;
	char *montyinstructions[] = {"push", "pall", "pint", "NULL"};

	/*Verify if the instruction is known*/
	while (i < 3)
	{
		result = strcmp(montyinstructions[i], montyline_args[0]);
		if (result == 0)
		{
	/*Break if the instruction is known*/
			known_arg = 1;
			break;
		}
		i++;
	}

	if (!known_arg)
	{
		freeStack(&(*head));
		exit(EXIT_FAILURE);
	}
	printf("----------------VALIDATION- OUT -------------------\n");

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
	while (montyline_args[i] != NULL)
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
 * in a string
 * Return: A number
 */

int containString(char *str)
{
	int i = 0, result = 1;

	if (!str)
	{
		printf("NULL string, cannot check of characters!\n");
		return (-1);
	}

	while (str[i] != '\0')
	{
/*If the first char is - or + continue */
		if ((str[i] == 43) || (str[i] == 45))
		{	i++;
			printf("C'est un operateur\n\n");
			continue;
		}

		printf("-------STR[%c] : %d\n\n", str[i], str[i]);

		if (((str[i] < 48) || (str[i] > 57)))
		{
			result = -1;
			printf("Ce truc n'est pas un entier");
			return (result);
		}
		i++;
	}
	return (result);
}
