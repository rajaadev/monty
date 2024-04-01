#include "monty.h"

void err(int error_code, ...)
{
	va_list args;
	char *file_name;
	int line_number;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			file_name = va_arg(args, char *);
			fprintf(stderr, "Error: Can't open file %s\n", file_name);
			break;
		case 3:
			line_number = va_arg(args, int);
			char *instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			line_number = va_arg(args, int);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void more_err(int error_code, ...)
{
	va_list args;
	int line_number;
	char *instruction;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			line_number = va_arg(args, int);
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			break;
		case 7:
			line_number = va_arg(args, int);
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			break;
		case 8:
			line_number = va_arg(args, int);
			instruction = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, instruction);
			break;
		case 9:
			line_number = va_arg(args, int);
			fprintf(stderr, "L%d: division by zero\n", line_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void string_err(int error_code, ...)
{
	va_list args;
	int line_number;

	va_start(args, error_code);
	line_number = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
