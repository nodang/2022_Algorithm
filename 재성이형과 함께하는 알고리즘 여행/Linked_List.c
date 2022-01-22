#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* p_next;
	int data;
}st_node;

int print_err_address(char function[], char name[])
{
	printf("Err[%s] : %s's address is NULL\n", function, name);
	return -1;
}

int print_err_memory(char name[])
{
	printf("Err[%s] : Memory isn't enough\n", name);
	return NULL;
}

st_node* init_node()
{
	st_node* node = malloc(sizeof(st_node));
	if (node == NULL)		
		return print_err_memory("init_node", "node_malloc");

	node->p_next = NULL;

	return node;
}

int change_data(st_node* node, int data)
{
	if (node == NULL)		
		return print_err_address("change_node", "node");

	node->data = data;

	return 0;
}

int add_node(st_node* front_node, int data)
{
	if (front_node == NULL)				
		return print_err_address("add_node", "front node");

	st_node* node = init_node();
	if (node == NULL)	return -1;

	if (-change_data(node, data))	return -1;

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

int exit_node(st_node* front_node)
{
	if (front_node == NULL)
		return print_err_address("exit_node", "front_node");
	
	st_node* rm_node = front_node->p_next;
	if (rm_node == NULL)
		return print_err_address("exit_node", "rm_node");

	front_node->p_next = rm_node->p_next;
	rm_node->p_next = NULL;

	free(rm_node);

	return 0;
}

static int print_node(st_node* head_node)
{
	if (head_node == NULL)		
		return print_err_address("printf_node", "head node");

	st_node* curr = head_node;
	while (curr != NULL)
	{
		printf("add_ress : %p	data : %10d		next : %p\n", curr, curr->data, curr->p_next);
		curr = curr->p_next;
	}
	printf("\n");

	return 0;
}

int main(void)
{
	st_node* p_head = NULL;
	p_head = init_node();

	st_node *p_curr = p_head;
	for (int i = 1; i <= 10; i++)
	{
		if (-add_node(p_curr, i))		return 0;
		p_curr = p_curr->p_next;
	}

	if (-print_node(p_head))			return 0;

	for (int i = 1; i <= 10; i++)
	{
		if (-exit_node(p_head))			return 0;
	}

	if (-print_node(p_head))			return 0;

	free(p_head);

	return 0;
}