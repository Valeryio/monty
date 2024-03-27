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
	(*filename) = malloc(sizeof(char) * (strlen(tmpname) + 1));
	if (!(*filename))
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy((*filename), tmpname);
	(*filename[strlen(tmpname)]) = '\0';
	printf("That's the name of the file : %s\n", (*filename));
}
