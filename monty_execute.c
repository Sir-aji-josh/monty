#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
*
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", fun_push}, {"pall", fun_pall}, {"pint", fun_pint},
				{"pop", fun_pop},
				{"swap", fun_swap},
				{"add", fun_add},
				{"nop", fun_nop},
				{"sub", fun_sub},
				{"div", fun_div},
				{"mul", fun_mul},
				{"mod", fun_mod},
				{"pchar", fun_pchar},
				{"pstr", fun_pstr},
				{"rotl", fun_rotl},
				{"rotr", fun_rotr},
				{"queue", fun_queue},
				{"stack", fun_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \\");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \\");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
