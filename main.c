#include "monty.h"

int main(int argc, char* argv[])
{
	FILE *myfile = NULL;
//	char filename = strlen(argv[1]);
	char *filename = NULL;

/*Verifing if the program have been well used like the prototype 
 * said : monty <file> 
 **/
	if (argc <= 1 || argc > 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
/*
 * Getting the name of the file tohave a better code readibility than just
 * write with an incomprehensible name of variable! @filename is better than
 * argv[1]!
 **/
	filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	if (!filename)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy(filename, argv[1]);
	filename[strlen(argv[1])] = '\0';

	printf("Voici le nom du fichier : %s\n", filename);

/*
 * Try to open the file
 */
	myfile = fopen(filename, "r");

	if (!myfile)
	{
		printf("Error, Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
//	myfile = fopen("")




	fclose(myfile);

	return (0);
}
