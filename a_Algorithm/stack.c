#include <stdio.h>

#include "linked_list.h"

int pop(st_node** p_top_node)
{
	int err = delete_node(&p_top_node);
	if (err == -1)
		return -1;

	return 0;
}

int push(st_node* top_node, int data)
{
	int err = add_node(top_node, data);
	if (err == -1)
		return -1;

	return 0;
}

static int _print_stack(st_node* top_node)
{
	printf("|     top    |\n");

	st_node* curr = top_node->p_next;
	while (curr != NULL)
	{
		printf("|    %4d    |\n", curr->data);
		curr = curr->p_next;
	}

	printf("|_____bot____|\n");
	return 0;
}

int check_stack(void)
{
	st_node* top = init_node();
	int err = 0;

	for (int i = 0; i <= 10; i++)
	{
		err = push(top, i);
		if (err == -1)
			return 0;
	}

	err = _print_stack(top);
	if (err == -1)
		return 0;


	for (int i = 0; i <= 10; i++)
	{
		err = pop(&top);
		if (err == -1)
			return 0;
	}

	err = _print_stack(top);
	if (err == -1)
		return 0;

	err = exit_node(top);
	if (err == -1)
		return 0;

	return 0;
}