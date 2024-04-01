#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file (unused)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    UNUSED(line_number);

    stack_t *temp = *stack;

    while (temp && temp->n != 0 && isascii(temp->n))
    {
        printf("%c", temp->n);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}
/*
 * free_stack - frees a stack
 * @stack: double pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
 i   stack_t *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}
/**
 * stack - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the Monty bytecode file
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    (void)stack;
    /* Do nothing, stack format is default */
}

/**
 * queue - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the Monty bytecode file
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    (void)stack;
    /* Reverse the linked list to switch to queue mode */
    stack_t *current = *stack;
    stack_t *prev = NULL;
    stack_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    *stack = prev;
}
