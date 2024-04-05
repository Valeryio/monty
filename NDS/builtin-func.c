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
char **getArguments(char *line)
{
	int i;
	char **arguments, *field, *separator;

	i = 0;
	separator = " \t\n";
	arguments = malloc(sizeof(field) * 2);
	field = strtok(line, separator);

	printf("BOn, voici le premier argument : %s\n", field);

/* When we get an empty line send a null*/
	if (!field)
		return (NULL);

	while (field)
	{
		arguments[i] = field;
		field = strtok(NULL, separator);
		i++;
	}
	return (arguments);
}

/**
 * arg_detector - this function check if an argument exist
 * @str: the argument
 *
 * Description: 
 * Return: An integer
 */

int isValidArgument()
{
	int i = 0;
	char *montyinstructions[] = {"push", "pall", "pint", "NULL"};

	while (montyinstructions[i])
	{
		if (strcmp(montyinstructions[i], montyline_args[0]) == 0)
			return (1);
		i++;
	}
	printf("La chaine %s est inconnue\n", montyline_args[0]);
	return (0);
}

/**
 * numberofargs - count the number of args
 *
 * Description: This function counts the number of args in
 * a monty line datastructure (array of strings)
 * Return: An integer
 */

int getNumberOfArgs()
{
	unsigned int i = 0;
	if (montyline_args == NULL)
		return (0);
	while (montyline_args[i] != NULL)
		i++;
	return (i);
}

/**
 * args_checker - check each arguments of a monty's line
 * @args: a array of args
 * @length: the length of the arrray
 *
 * Description: This function check each args of a line
 * and send its result
 * Return: 1 on success, 0 otherwise
 */

int args_checker(char *args[], int length)
{

/*	length = length - 1;
*/
	printf("JE suis la et ma taille est : %d\n", length);

/*Check for bad entry for push*/
	if (!strcmp(args[0], "push") && (length == 1))
		return (0);
	if (!strcmp(args[0], "push") && (atoi(args[1]) == 0))
		return (0);

/*Check for pall function*/
	if (!strcmp(args[0], "pall") && (args[1] != 0))
		return (0);

	return (1);
}
