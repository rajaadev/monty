#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
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
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;

    if (temp != NULL && temp->next != NULL)
    {
        *stack = temp->next;
        temp->next->prev = NULL;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = *stack;
        (*stack)->prev = temp;
        (*stack)->next->prev = NULL;
        (*stack)->prev = NULL;
    }
}
/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;

    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        temp->prev = NULL;
        temp->next = *stack;
        (*stack)->prev = temp;
        *stack = temp;
    }
}

