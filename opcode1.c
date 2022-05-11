#include "monty.h"

/**
 * @brief
 *
 * @param stack
 * @param line_number
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
 * @brief
 *
 * @param stack
 * @param line_number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *start = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	start = start->next;
	free(*stack);
	*stack = start;
	if (start != NULL)
		start->prev = NULL;
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
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = head->next;

	head->next = head->next->next;
	if (head->next->prev)
		head->next->prev = head;
	head->prev = tmp;
	tmp->next = head;
	tmp->prev = NULL;
	*stack = tmp;
}
