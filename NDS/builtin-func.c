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
char **getArguments____isold(char *line)
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
/*UPDATED VERSION OF THE FUNCTION getArguments*/
void getArguments(char *line)
{
	int i = 0, result = 0;
	char opcode[8], arg[8];

	while (i < getNumberOfArgs())
	{
		free(montyline_args[i]);
		i++;
	}
	free(montyline_args);
	montyline_args = NULL;

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
		
		if (montyline_args == NULL)
		{
			printf("Error: malloc failed for double P");
			exit(EXIT_FAILURE);
		}
		/*mallocError(&(*montyline_args));
		*/

		montyline_args[0] = NULL;
		montyline_args[1] = NULL;
		montyline_args[0] = malloc(sizeof(char) * (strlen(opcode) + 1));
		/*mallocError(montyline_args[0]);
		*/if (montyline_args[0] == NULL)
		{
			printf("Error: malloc failed for double P");
			exit(EXIT_FAILURE);
		}
		montyline_args[1] = malloc(sizeof(char) * (strlen(arg) + 1));
	/*	mallocError(montyline_args[1]);
		*/
		if (montyline_args[1] == NULL)
		{
			printf("Error: malloc failed for double P");
			exit(EXIT_FAILURE);
		}

		strcpy(montyline_args[0], opcode);
		strcpy(montyline_args[1], arg);
		printf("YEs arg1 : %s, et arg2 : %s\n", montyline_args[0], montyline_args[1]);
	}

}

/**
 * arg_detector - this function check if an argument exist
 * @str: the argument
 *
 * Description: 
 * Return: An integer
 */

int isValidArgument(stack_t **head, unsigned int line_number)
{
	int i = 0, known_arg = 0, result = 0;
	char *montyinstructions[] = {"push", "pall", "pint", "NULL"};

	printf("----------------VALIDATION-------------------\n");
	while (i < 3)
	{
		result = strcmp(montyinstructions[i], montyline_args[0]);
		printf("Le resultat : %d\n", result);
		if (result == 0)
		{
			known_arg = 1;
			break;
		}
		i++;
	}
	printf("Known result : %d\n", known_arg);

	if (!known_arg)
	{
		printf("L%d: unkown instruction <%s>\n", line_number, montyline_args[0]);
		freeStack(&(*head));
		if ((*head))
			printf("La stack est non nulle !\n");
		exit(EXIT_FAILURE);
	}
	printf("----------------VALIDATION- OUT -------------------\n");

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
