#include "linked_list.h"

st_node* init_node(void)
{
	st_node* node = calloc(1, sizeof(st_node));
	if (node == NULL)		
	{
		PRINT_ERR_MEMORY("init_node");
		return NULL;
	}
	return node;
}

int exit_node(st_node** pp_rm_node)
{
	if (pp_rm_node == NULL || *pp_rm_node == NULL)
	{
		PRINT_ERR_ADDRESS("exit_node", "rm_node");
		return -1;
	}

	free(*pp_rm_node);
	*pp_rm_node = NULL;

	return 0;
}

int add_node(st_node* p_front_node, const int data)
{
	if (p_front_node == NULL)
	{
		PRINT_ERR_ADDRESS("add_node", "front_node");
		return -1;
	}
	st_node* p_node = init_node();
	if (p_node == NULL)
		return -1;

	p_node->data = data;

	if (p_front_node->p_next == NULL)
	{
		p_node->p_next = NULL;
		p_front_node->p_next = p_node;
	}
	else
	{
		p_node->p_next = p_front_node->p_next;
		p_front_node->p_next = p_node;
	}

	return 0;
}

int delete_node(st_node** pp_front_node)
{
	if (*pp_front_node == NULL || (*pp_front_node)->p_next == NULL)
	{
		PRINT_ERR_ADDRESS("exit_node", "front_node");
		return -1;
	}

	st_node* p_rm_node = (*pp_front_node)->p_next;

	(*pp_front_node)->p_next = p_rm_node->p_next;
	p_rm_node->p_next = NULL;

	int err = exit_node(&p_rm_node);
	if (err == -1)
		return -1;

	return 0;
}

static int _print_node(const st_node* p_head_node)
{
	if (p_head_node == NULL)
	{
		PRINT_ERR_ADDRESS("printf_node", "head node");
		return -1;
	}

	st_node* p_curr = p_head_node;
	while (p_curr != NULL)
	{
		printf("add_ress : %p	data : %10d		next : %p\n", p_curr, p_curr->data, p_curr->p_next);
		p_curr = p_curr->p_next;
	}
	printf("\n");

	return 0;
}

int check_linked_list(void)
{
	int err = 0;

	st_node* p_head = init_node();
	if(p_head == NULL)
		return 0;

	st_node *p_curr = p_head;
	for (int i = 1; i <= 10; i++)
	{
		err = add_node(p_curr, i);
		if (err == -1)
			return 0;

		p_curr = p_curr->p_next;
	}

	err = _print_node(p_head);
	if (err == -1)
		return 0;

	for (int i = 1; i <= 5; i++)
	{
		err = delete_node(&p_head);
		if (err == -1)
			return 0;
	}

	err = _print_node(p_head);
	if (err == -1)
		return 0;

	err = exit_node(&p_head);
	if (err == -1)
		return -1;

	return 0;
}