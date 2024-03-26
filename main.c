#include "monty.h"

int main(int argc, char* argv[])
{
	FILE *myfile = NULL;
//	char filename = strlen(argv[1]);
	char *filename = NULL;
	if (argc <= 1 || argc > 2)
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	if (!filename)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy(filename, argv[1]);
	filename[strlen(argv[1])] = '\0';

	printf("Voici le nom du fichier : %s\n", filename);

//	myfile = fopen("")

	return (0);
}
