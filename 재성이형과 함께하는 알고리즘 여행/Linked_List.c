#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* p_next;
	int data;
}st_node;

st_node* init_node(st_node* front_node)
{
	if (front_node == NULL)
	{
		printf("Err[front node] : Front node's address is NULL");
		return NULL;
	}
	st_node* node = malloc(sizeof(st_node));
	if (node == NULL)
	{
		printf("Err[malloc] : Memory isn't enough");
		return NULL;
	}
	return node;
}

int change_data(st_node* node, int data)
{
	if (node == NULL)
	{
		printf("Err[node] : Node's address is NULL");
		return -1;
	}

	node->data = data;

	return 0;
}

int add_node(st_node* front_node, int data)
{
	st_node* node = init_node(front_node);
	if (node == NULL)		return -1;

	if (change_data(node, data) == -1)	return -1;
	node->p_next = NULL;
	front_node->p_next = node;

	return 0;
}

int exit_node(st_node* head_node)
{
	if (head_node == NULL)		return -1;

	st_node* curr = head_node;
	while (curr->p_next->p_next != NULL)		curr = curr->p_next;
	
	st_node* rm_node = curr->p_next;

	curr->p_next = rm_node->p_next;
	rm_node->p_next = NULL;

	free(rm_node);

	return 0;
}

int print_node(st_node* head_node)
{
	if (head_node == NULL)
	{
		printf("Err[head node] : Head node's address is NULL");
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

int main(void)
{
	st_node* p_head = NULL;
	p_head = malloc(sizeof(st_node));
	if (p_head == NULL)	return -1;

	st_node *p_curr = p_head;
	for (int i = 1; i <= 10; i++)
	{
		if (add_node(p_curr, i) == -1)		return 0;
		p_curr = p_curr->p_next;
	}

	if (print_node(p_head) == -1)			return 0;
	for (int i = 1; i <= 10; i++)
		if (exit_node(p_head) == -1)		return 0;

	if (print_node(p_head) == -1)			return 0;

	free(p_head);

	return 0;
}