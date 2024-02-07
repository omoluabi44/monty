#include "monty.h"
#define _GNU_SOURCE
/**
 * main - the monty bytecode
 *@argc: lenth of the arguement
 *@argv: arguement
 *Return: NULL
 */
int main(int argc, char *argv[])
{

	int ret;
	size_t len = 0;

	valid_argument(argc);
	ini_all_func();
	fileOpen = file((argv[1]));

	ret = getline(&line, &len, fileOpen);
	while (ret != -1)
	{
		line_number += 1;
		tokenize_opcodes();
		function_ptr();
		run_instr();
		ret = getline(&line, &len, fileOpen);
	}
	free_arguments();
	return (0);
}
/**
 * file - the file function
 *@filename: file that will be open
 *Return: the address of the file
 */
FILE *file(char *filename)
{
	FILE *ptr;

	ptr = fopen(filename, "r");
	if (!ptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(line);
		free_arguments();
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
/**
 * ini_all_func - iniatialize malloc
 */
void ini_all_func(void)
{
	all_func = malloc(sizeof(instruction_t));
	if (all_func == NULL)
		malloc_fail();
	head = malloc(sizeof(stack_t));
	if (head == NULL)
		malloc_fail();
}
/**
 * malloc_fail - handle malloc fail
 */
void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}
/**
 * close_stream - handle close-stream;
 */
void close_stream(void)
{
	if (fileOpen == NULL)
		return;
	fclose(fileOpen);
	fileOpen = NULL;
}
