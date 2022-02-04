#include <stdio.h>

#include "linked_list.h"

#define PRINT_ERR_EMPTY(FUNC)		printf("Err[%s] : stack is empty or memory error\n", FUNC);

static int _print_err_stack(const st_node* p_ceiling_node, const char* func_name)
{
	if (p_ceiling_node == NULL)
	{
		PRINT_ERR_ADDRESS(func_name, "node");
		return -1;
	}
	int empty_return = empty(p_ceiling_node);
	if (empty_return != 0)
	{
		PRINT_ERR_EMPTY(func_name);
		return -1;
	}

	return 0;
}

int empty(const st_node* p_ceiling_node)
{
	if (p_ceiling_node == NULL)
	{
		PRINT_ERR_ADDRESS("empty in the stack", "node");
		return -1;
	}

	return (p_ceiling_node->p_next == NULL);
}

int pop(st_node** pp_ceiling_node)
{
	if (pp_ceiling_node == NULL || *pp_ceiling_node == NULL)
	{
		PRINT_ERR_ADDRESS("pop in the stack", "node");
		return -1;
	}

	int pop_return = (*pp_ceiling_node)->p_next->data;
	int err = delete_node(&pp_ceiling_node);
	if (err == -1)
		return -1;

	return 0;
}

int push(st_node* p_ceiling_node, const int data)
{
	int err = add_node(p_ceiling_node, data);
	if (err == -1)
		return -1;
	else
		return 0;
}

int size(const st_node* p_ceiling_node)
{
	int len = 0;
	int err = _print_err_stack(p_ceiling_node, "size in stack");
	if (err == -1)
		return -1;

	st_node* p_curr = p_ceiling_node;
	while (p_curr->p_next != NULL)
	{
		len++;
		p_curr = p_curr->p_next;
	}
	printf("stack size is %d\n", len);

	return 0;
}

int top(const st_node* p_ceiling_node)
{
	int err = _print_err_stack(p_ceiling_node, "top in stack");
	if (err == -1)
		return -1;

	printf("The top integer : %d\n", p_ceiling_node->p_next->data);

	return 0;
}

static int _print_stack(const st_node* p_ceiling_node)
{
	printf("|   ceiling  |\n");
	st_node* p_curr = p_ceiling_node->p_next;
	while (p_curr != NULL)
	{
		printf("|    %-4d    |\n", p_curr->data);
		p_curr = p_curr->p_next;
	}
	printf("|___bottom___|\n");
	return 0;
}

static int _print_empty(const st_node* p_ceiling_node)
{
	int bool_empty = empty(p_ceiling_node);
	if (bool_empty == -1)
		return -1;
	else if (bool_empty == 1)
		printf("stack is empty\n");
	else
		printf("stack is not empty\n");

	return 0;
}

int check_stack(void)
{
	st_node* p_ceiling = init_node();
	int err = 0;

	for (int i = 1; i <= 10; i++)
	{
		err = push(p_ceiling, i);
		if (err == -1)
			return 0;
	}

	err = _print_stack(p_ceiling);
	err |= _print_empty(p_ceiling);
	err |= size(p_ceiling);
	if (err == -1)
		return 0;
	
	for (int i = 1; i <= 10; i++)
	{
		err = top(p_ceiling);
		err |= pop(&p_ceiling);
		if (err == -1)
			return 0;
	}

	err = _print_stack(p_ceiling);
	err |= _print_empty(p_ceiling);
	err |= size(p_ceiling);
	if (err == -1)
		return 0;

	err = exit_node(&p_ceiling);
	if (err == -1)
		return 0;

	return 0;
}