#include "stack.h"

st_sp* init_stack(void)
{
	st_sp* p_sp = calloc(1, sizeof(st_sp));
	if (p_sp == NULL)
	{
		PRINT_ERR_MEMORY("init_stack");
		return NULL;
	}

	p_sp->sp = init_node();
	if (p_sp->sp == NULL)
		return NULL;

	return p_sp;
}

int exit_stack(st_sp** pp_rm_sp)
{
	if (pp_rm_sp == NULL || *pp_rm_sp == NULL)
	{
		PRINT_ERR_ADDRESS("exit_stack", "rm_stack");
		return -1;
	}
	int err = 0;
	st_node* curr = (*pp_rm_sp)->sp;
	while (curr->p_next != NULL)
	{
		curr = curr->p_next;
		err |= delete_node(&curr);
		if (err == -1)
			return -1;
	}
	err |= exit_node(&((*pp_rm_sp)->sp));
	if (err == -1)
		return -1;

	free(*pp_rm_sp);
	*pp_rm_sp = NULL;

	return 0;
}

int empty_s(const st_sp* p_sp)
{
	if (p_sp == NULL || p_sp->sp == NULL)
	{
		PRINT_ERR_ADDRESS("empty in stack", "sp");
		return -1;
	}

	return (p_sp->sp->p_next == NULL);
}

int pop_s(st_sp** pp_sp)
{
	if (pp_sp == NULL || *pp_sp == NULL || (*pp_sp)->sp == NULL)
	{
		PRINT_ERR_ADDRESS("pop in stack", "pp_sp");
		return -1;
	}
	if ((*pp_sp)->sp->p_next == NULL)
	{
		PRINT_ERR_ADDRESS("pop in stack", "p_next");
		return -1;
	}

	int pop_return = (*pp_sp)->sp->p_next->data;
	int err = delete_node(&(*pp_sp)->sp);
	if (err == -1)
		return -1;

	return pop_return;
}

int push_s(st_sp* p_sp, const int data)
{
	if (p_sp == NULL || p_sp->sp == NULL)
	{
		PRINT_ERR_ADDRESS("pop in the stack", "p_sp");
		return -1;
	}

	int err = add_node(p_sp->sp, data);
	if (err == -1)
		return -1;
	else
		return 0;
}

int size_s(const st_sp* p_sp)
{
	if (p_sp == NULL || p_sp->sp == NULL)
	{
		PRINT_ERR_ADDRESS("size in stack", "p_sp");
		return -1;
	}
	int len = 0;
	st_node* p_curr = p_sp->sp;
	while (p_curr->p_next != NULL)
	{
		len++;
		p_curr = p_curr->p_next;
	}
	printf("stack size is %d\n", len);

	return 0;
}

int top_s(const st_sp* p_sp)
{
	if (p_sp == NULL || p_sp->sp == NULL)
	{
		PRINT_ERR_ADDRESS("top in stack", "p_sp");
		return -1;
	}
	if (p_sp->sp->p_next == NULL)
	{
		PRINT_ERR_ADDRESS("top in stack", "p_next");
		return -1;
	}

	printf("The top integer : %d\n", p_sp->sp->p_next->data);

	return 0;
}

static int _print_stack(const st_sp* p_sp)
{
	printf("|   ceiling  |\n");
	st_node* p_curr = p_sp->sp->p_next;
	while (p_curr != NULL)
	{
		printf("|    %-4d    |\n", p_curr->data);
		p_curr = p_curr->p_next;
	}
	printf("|___bottom___|\n");
	return 0;
}

static int _print_empty(const st_sp* p_sp)
{
	int bool_empty = empty_s(p_sp);
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
	st_sp* p_sp = init_stack();
	int err = 0;

	for (int i = 1; i <= 10; i++)
	{
		err = push_s(p_sp, i);
		if (err == -1)
			return 0;
	}

	err = _print_stack(p_sp);
	err |= _print_empty(p_sp);
	err |= size_s(p_sp);
	if (err == -1)
		return 0;
	
	for (int i = 1; i <= 10; i++)
	{
		err = top_s(p_sp);
		int rtn = pop_s(&p_sp);
		printf("pop return : %d\n", rtn);
		if (err == -1)
			return 0;
	}

	err = _print_stack(p_sp);
	err |= _print_empty(p_sp);
	err |= size_s(p_sp);
	if (err == -1)
		return 0;

	err = exit_stack(&p_sp);
	if (err == -1)
		return 0;

	return 0;
}