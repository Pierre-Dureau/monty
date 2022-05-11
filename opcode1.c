#include "monty.h"

/**
 * push - Push a number in the Stack
 *
 * @stack: The list
 * @line_number: Number of the line
 * @token: Line
 * Return: Value to push
 */

int push(stack_t **stack, unsigned int line_number, char *token, FILE *file)
{
	stack_t *head = *stack;
	char *temp, *number;
	int i, j, value, check = 0, neg = 0;

	token = strtok(NULL, "\n");
	for (; *token == ' '; token++)
		;
	temp = token;
	if (*token == '-')
	{
		neg = 1;
		temp++;
	}
	for (i = 0; *temp >= '0' && *temp <= '9'; temp++, i++)
		check = 1;
	if (*temp != ' ' && *temp != '\n' && *temp != '\0')
		check = 0;
	if (check == 1)
	{
		if (neg == 1)
			i += 1;
		number = malloc(sizeof(char) * (i + 1));
		if (neg == 1)
			number[0] = '-';
		for (j = 0; j < i; j++, token++)
			number[j] = *token;
		number[j] = '\0';
		value = atoi(number);
		free(number);
		return (value);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		handle_exit(head);
	}
	return (-1);
}

/**
 * pall - Print the list
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;

	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
	(void)line_number;
}

/**
 * pint - Print the first value
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		handle_exit(head);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Delete the first value
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		handle_exit(head);
	}

	head = head->next;
	free(*stack);
	*stack = head;
	if (head != NULL)
		head->prev = NULL;
}

/**
 * swap - Swaps the top two elements of the stack
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		handle_exit(head);
	}

	tmp = head->next;
	head->next = head->next->next;
	if (head->next)
		head->next->prev = head;
	head->prev = tmp;
	tmp->next = head;
	tmp->prev = NULL;
	*stack = tmp;
}
