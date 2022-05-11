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
	int sum = 0;
	stack_t *top1, *top2;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = head;
	top2 = head->next;
	sum = top1->n + top2->n;
	(*stack)->n = sum;
	pop(stack, line_number);
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
	int sub = 0;
	stack_t *top1, *top2;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = head;
	top2 = head->next;
	sub = top1->n - top2->n;
	(*stack)->n = sub;
	pop(stack, line_number);
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
	int div = 0;
	stack_t *top1, *top2;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = head;
	top2 = head->next;
	div = top1->n / top2->n;
	(*stack)->n = div;
	pop(stack, line_number);
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
	int mul = 0;
	stack_t *top1, *top2;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = head;
	top2 = head->next;
	mul = top1->n * top2->n;
	(*stack)->n = mul;
	pop(stack, line_number);
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
	int mod = 0;
	stack_t *top1, *top2;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = head;
	top2 = head->next;
	mod = top1->n % top2->n;
	(*stack)->n = mod;
	pop(stack, line_number);
}
