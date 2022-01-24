#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

#define PRINT_ERR_ADDRESS(FUNC, NAME)		printf("Err[%s] : %s's address is NULL\n", FUNC, NAME)
#define PRINT_ERR_MEMORY(NAME)				printf("Err[%s] : Memory isn't enough\n", NAME)

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

int exit_node(st_node** rm_node)
{
	if(rm_node == NULL || *rm_node == NULL)
		return -1;

	free(*rm_node);
	*rm_node = NULL;

	return 0;
}

int add_node(st_node* front_node, const int data)
{
	if (front_node == NULL)
	{
		PRINT_ERR_ADDRESS("add_node", "front node");
		return -1;
	}
	st_node* node = init_node();
	if (node == NULL)
		return -1;

	node->data = data;

	if (front_node->p_next == NULL)
	{
		node->p_next = NULL;
		front_node->p_next = node;
	}
	else
	{
		node->p_next = front_node->p_next;
		front_node->p_next = node;
	}

	return 0;
}

int delete_node(st_node** front_node)
{
	if (*front_node == NULL || (*front_node)->p_next == NULL)
	{
		PRINT_ERR_ADDRESS("exit_node", "front_node");
		return -1;
	}

	st_node* rm_node = (*front_node)->p_next;

	(*front_node)->p_next = rm_node->p_next;
	rm_node->p_next = NULL;

	int err = exit_node(&rm_node);
	if (err == -1)
		return -1;

	return 0;
}

static int _print_node(st_node* head_node)
{
	if (head_node == NULL)
	{
		PRINT_ERR_ADDRESS("printf_node", "head node");
		return -1;
	}

	st_node* curr = head_node;
	while (curr != NULL)
	{
		printf("add_ress : %p	data : %10d		next : %p\n", curr, curr->data, curr->p_next);
		curr = curr->p_next;
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

	for (int i = 1; i <= 10; i++)
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