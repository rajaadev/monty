#include "monty.h"
/**
* push - Pushes an element onto the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number being executed from the Monty file.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	if (!data)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(data);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	if (*stack)
	{
	new_node->next = *stack;
	(*stack)->prev = new_node;
	}
	else
	{
	new_node->next = NULL;
	}
	*stack = new_node;
	}

/**
* pall - Prints all the values on the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number being executed from the Monty file.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
* pint - Prints the value at the top of the stack.
* @stack: Double pointer to the stack.
* @line_number: Line number in the Monty file.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
* pop - Removes the top element of the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number being executed from the Monty file.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
/**
* swap - Swaps the top two elements of the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: The line number in the file where the opcode appears.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (is_empty(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
