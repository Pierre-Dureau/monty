#include "monty.h"

/**
 * add - Add the 2 first values
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		handle_exit(head);
	}

	temp = head->next;
	temp->n += head->n;
	temp->prev = NULL;
	pop(&head, line_number);
	*stack = temp;
}

/**
 * sub - Substract the 2 first values
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		handle_exit(head);
	}

	temp = head->next;
	temp->n -= head->n;
	temp->prev = NULL;
	pop(&head, line_number);
	*stack = temp;
}

/**
 * _div - Divide the 2 first values
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		handle_exit(head);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		handle_exit(head);
	}

	temp = head->next;
	temp->n /= head->n;
	temp->prev = NULL;
	pop(&head, line_number);
	*stack = temp;
}

/**
 * mul - Multiply the 2 first values
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		handle_exit(head);
	}

	temp = head->next;
	temp->n *= head->n;
	temp->prev = NULL;
	pop(&head, line_number);
	*stack = temp;
}

/**
 * mod - Module the 2 first values
 *
 * @stack: A pointer to the adress of the doubly linked list
 * @line_number: The line number of the monty file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		handle_exit(head);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		handle_exit(head);
	}

	temp = head->next;
	temp->n %= head->n;
	temp->prev = NULL;
	pop(&head, line_number);
	*stack = temp;
}
