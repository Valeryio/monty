#include "monty.h"

/**
 * get_name - this function get the names of a file
 *
 * @tmpname: the first string
 * @filename: the string that will save the name
 * Description: this function swap the value of
 * the name of a file in a more readable variable
 * Return: Nothing
 */

void get_name(char *tmpname, char **filename)
{
	/*Getting the name of the file to write a clean code!*/
	*filename = malloc(sizeof(char) * (strlen(tmpname) + 1));
	if (!(*filename))
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy(*filename, tmpname);
}


/**
 * get_instruction_func - get an instruction by a function
 *
 * @str: a string
 * Description: This function returns a function and chose
 * between different parts of a datastructure
 * Return: A function
 */

void (*get_instruction_func(char *str))(stack_t**, unsigned int)
{
	int i = 0;
	instruction_t montyfunc[] = {
					{"push", push},
					{"pall", pall},
					{NULL, NULL}
				};

	if (!str)
		printf("La chaine envoyee est erronnee !");

	while (i < 2)
	{
		if (!strcmp(montyfunc[i].opcode, str))
			return (montyfunc[i].f);
		i++;
	}

	return (NULL);
}


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
        separator = " \t";
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

void line_checker(char *line, unsigned int line_number)
{
	int i = 0;
	char **line_arguments, opcodes[8];
/*	instruction_t montyfunc[] = {
					{"push", push},
					{"pall", pall},
					{NULL, NULL}
				};
*/
	line_arguments = get_arguments(line);
	strcpy(opcodes,line_arguments[0]);

	printf("Line number : %d and Heyo ! %s\n",line_number, opcodes);
	while (line_arguments[i])
	{
		printf("HEy l'argument : %s\n", line_arguments[i]);
		i++;
	}
}

