#include "monty.h"

/**
 * get_arguments - this functions get the two arguments of
 * monty code
 *
 * @line: a string
 * Description: This function takes a string and save the
 * monty's code instruction from it
 * Return: An array of strings
 */
char** get_arguments(char *line)
{
        int i;
        char **arguments, *field, *separator;

        i = 0;
        separator = " \t\n";
        arguments = malloc(sizeof(field) * 2);
        field = strtok(line, separator);

        while (field)
        {
                arguments[i] = field;
                field = strtok(NULL, separator);
                i++;
        }
	return (arguments);
}


/**
 * line_checker - checks if an instruction's line is valid
 *
 * @line: that's the line
 * @line_number: that is the line number
 *
 * Description: This function checks if each line it gets
 * is a functional monty code instruction
 * Return: A function
 */

int line_checker(char *line, unsigned int line_number)
{
	int i = 0, j = 0, n = 0, check = 0;
	char **line_arguments, line_opcode[16];
	instruction_t montyfunc[] = {
					{"push", push},
					{"pall", pall},
					{NULL, NULL}
				};

	line_arguments = get_arguments(line);

	while (line_arguments[j] != NULL)
		j++;
	printf("Nombre d'arguments recuperes : %d, ligne [%d]\n", j, line_number);

	check = args_checker(line_arguments, j);
	printf("Le check : %d\n", check);

	if (!check)
	{
		fprintf(stderr, "L%d: usage: push integer\n", (int)line_number);
		return (0);
	}

/*Saving these variables into arguments*/
	strcpy(line_opcode,line_arguments[0]);

/*Getting the second ones*/
	if (j == 2)
		n = atoi(line_arguments[1]);

	i = 0;
	while (i < 2)
	{
		printf("Resultat de la comparaison : %d\n", strcmp(line_opcode, montyfunc[i].opcode));
		if (strcmp(line_opcode, montyfunc[i].opcode) == 0)
		{
			montyfunc[i].f((&montystack), n);
			break;
		}
		i++;
	}

	printf("Taille de la variable : \"%s\" = [%ld]\n\n", line_opcode, strlen(line_opcode));
	
	return (1);
}


/**
 * args_checker - check each arguments of a monty's line
 * @args: a array of args
 * @length: the length of the arrray
 *
 * Description: This function check each args of a line
 * and send its result
 * Return: 1 on SUCCESS, 0 if not
 */

int args_checker(char* args[], int length)
{
	length = length - 1;

	if (!strcmp(args[0], "push") && (atoi(args[1]) == 0))
		return (0);

/*Check for pall function*/
	if (!strcmp(args[0], "pall") && (args[1] != 0))
		return (0);

	return (1);
}
