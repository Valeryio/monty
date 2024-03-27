#include "monty.h"

/**
 * get_name - this function get the names of a file
 * 
 * @str: the first string
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
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy(*filename, tmpname);
	printf("That's the name of the file : %s\n", (*filename));
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
			return montyfunc[i].f;
		i++;
	}

	return (NULL);
}
