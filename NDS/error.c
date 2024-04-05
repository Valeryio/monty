#include "monty.h"

/**
 * OpenFileError - error generated with bad open file
 *
 * Description: This function is in reality an implementation
 * of an Error that end the program when the program encounter
 * an error when opening the given monty's program file
 */

void OpenFileError(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}

/**
 * UsageFileError - error generated with bad file given as argument
 *
 * Description: This function is in reality an implementation of an
 * Error that end the program when a bad file is given as argument
 * to the monty's interpretor.
 */

void UsageFileError()
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
