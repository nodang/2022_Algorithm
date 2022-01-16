#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* p_next;
	int data;
}st_node;

int n_init(st_node* front_node, int data)
{
	if (front_node == NULL)	return -1;

	st_node* node = malloc(sizeof(st_node));
	if (node == NULL)		return -1;

	node->data = data;
	node->p_next = NULL;
	front_node->p_next = node;

	return 0;
}

int n_exit(st_node* head_node)
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

int n_print(st_node* head_node)
{
	if (head_node == NULL)		return - 1;

	st_node* curr = head_node;
	while (curr != NULL)
	{
		printf("add_ress : %p	data : %10d		next : %p\n", curr, curr->data, curr->p_next);
		curr = curr->p_next;
	}

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
		n_init(p_curr, i);
		p_curr = p_curr->p_next;
	}

	n_print(p_head);
	for (int i = 1; i <= 10; i++)
	{
		n_exit(p_head);
	}

	n_print(p_head);

	free(p_head);

	return 0;
}