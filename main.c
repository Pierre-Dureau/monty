#include "monty.h"

size_t print_dlistint(stack_t *h)
{
	size_t count = 0;
	stack_t *t = h;

	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
		count++;
	}

	return (count);
}

/**
 * start - Get the lines of the file and do the instruction
 *
 * @file: Monty file with instructions
 */

void start(FILE *file)
{
	stack_t *head = NULL;
	char line[100];
	char *token, *word, *number, *temp;
	int value, ln = 0, i, j, check = 0;
	void (*fnc)(stack_t **stack, unsigned int line_number);

	while (fgets(line, 100, file) != NULL)
	{
		ln++;
		token = strtok(line, " \n");
		word = strdup(token);
		if (strcmp(word, "push") == 0)
		{
			token = strtok(NULL, "\n");
			for (; *token == ' '; token++);
			temp = token;
			for (i = 0; *temp >= '0' && *temp <= '9'; temp++, i++)
				check = 1;

			if (check == 1)
			{
				check = 0;
				number = malloc(sizeof(char) * i);
				for (j = 0; j < i; j++, token++)
					number[j] = *token;

				value = atoi(number);
				free(number);
				add_dnodeint(&head, value);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
			}
			free(word);
			continue;
		}
		fnc = get_instruction(word);
		if (fnc)
			fnc(&head, ln);
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
