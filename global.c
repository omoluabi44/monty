#include "monty.h"
instruction_t *all_func;
stack_t *head = NULL;
unsigned int line_number = 0;
int N_token = 0;
FILE *fileOpen = NULL;
char *line = NULL;
