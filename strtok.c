#include "monty.h"
char **tokens = NULL;
/**
 *tokenize_opcodes - split the command and int
 */
void tokenize_opcodes(void)
{
	char *d = " \n";
	char *value_cp = NULL;
	char *token_N = NULL;
	int i = 0;

	value_cp = malloc(sizeof(char) * (strlen(line) + 1));
	strcpy(value_cp, line);
	N_token = 0;
	token_N = strtok(value_cp, d);
	while (token_N)
	{
		N_token += 1;
		token_N = strtok(NULL, d);
	}
	tokens = malloc(sizeof(char *) * (N_token + 1));
	strcpy(value_cp, line);
	token_N = strtok(value_cp, d);
	while (token_N)
	{
		tokens[i] = malloc(sizeof(char) * (strlen(token_N) + 1));
		if (tokens[i] == NULL)
			malloc_fail();
		strcpy(tokens[i], token_N);
		token_N = strtok(NULL, d);
		i++;
	}
	tokens[i] = NULL;
	free(value_cp);



}
