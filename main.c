#include "monty.h"

/**
 * start - Get the lines of the file and do the instruction
 *
 * @file: Monty file with instructions
 */

void start(FILE *file)
{
	stack_t *head = NULL;
	char line[100];
	char *t, *word, *number;
	int value, ln = 0, i, j;
	void (*fnc)(stack_t **stack, unsigned int line_number);

	while (fgets(line, 100, file) != NULL)
	{
		ln++;
		t = strtok(line, " \n");
		word = strdup(t);
		if (strcmp(word, "push") == 0)
		{
			for (i = 5; t[i] >= '0' && t[i] <= '9'; i++);
			if (i > 5)
			{
				number = malloc(sizeof(char) * (i - 5));
				for (j = 5; j < i; j++)
					number[j - 5] = t[j];
				value = atoi(number);
				free(number);
				add_dnodeint(&head, value);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer", ln);
			}
			free(word);
			continue;
		}
		fnc = get_instruction(word);
		if (fnc)
		{
			fnc(&head, ln);
		}
		free(word);
	}
}

/**
 * main - Read Monty byte code files
 *
 * @ac: Number of arguments
 * @av: Arguements
 * Return: 0
 */

int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(av[1], "r");
		if (!file)
		{
			fprintf(stderr, "Error: Can't open file <file>");
			exit(EXIT_FAILURE);
		}
		else
			start(file);
	}

	return (0);
}
