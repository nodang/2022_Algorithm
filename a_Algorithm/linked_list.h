#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define PRINT_ERR_ADDRESS(FUNC, NAME)		printf("Err[%s] : %s's address is NULL\n", FUNC, NAME)
#define PRINT_ERR_MEMORY(NAME)				printf("Err[%s] : Memory isn't enough\n", NAME)

typedef struct Node
{
	struct Node* p_next;
	int data;
}st_node;

st_node* init_node(void);
int exit_node(st_node** pp_rm_node);
int add_node(st_node* p_front_node, const int data);
int delete_node(st_node** pp_front_node);
int check_linked_list(void);

#endif