#include "monty.h"
/**
 *free_arguments - free memory for lines and all_fun
 */
void free_arguments()
{
	free_head();
	close_stream();
	free(all_func);
	free(line);
	free_tokes();

}
/**
 * free_head - free all node
 */
void free_head(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	tmp = head->next;

	while (head != NULL)
	{
		free(head);
		head = tmp;
		if (tmp != NULL)
			tmp = tmp->next;
	}

}
/**
 *is_number - check if is number
 *@str: the string
 *Return: 1
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 *free_tokes - free all token in array
 */
void free_tokes(void)
{
	int i = 0;

	if (tokens == NULL)
		return;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	tokens = NULL;
}

