#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* p_next;
	int data;
}st_node;

static int _print_err_address(const char* function, const char* name)
{
	printf("Err[%s] : %s's address is NULL\n", function, name);
	return -1;
}
// read only : const
static inline void _print_err_memory(const char* name)
{
	printf("Err[%s] : Memory isn't enough\n", name);
}

st_node* init_node(void)	//c : (void) | c++ : ()
{
	st_node* node = calloc(1, sizeof(st_node));	// (st_node*)malloc
	if (node == NULL)		
	{
		_print_err_memory("init_node");
		return NULL;
	}

	//memset(node, 0, sizeof(st_node));			// 확장성을 고려하여 코드를 설계할 것
	//malloc + memset = calloc		속도 차이가 있음

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

int change_data(st_node* node,const int data)
{
	if (node == NULL)		
		return _print_err_address("change_node", "node");

	node->data = data;

	return 0;
}

//inline으로 선언할 시 헤더에 함수를 통째로 선언할 것

int add_node(st_node* front_node, const int data)
{
	if (front_node == NULL)				
		return _print_err_address("add_node", "front node");

	st_node* node = init_node();
	if (node == NULL)
		return -1;

	if (change_data(node, data) == -1)	
		return -1;

// 함수를 직접 호출하는 것은 지양할 것 | 한정된 메모리 시스템가 아니면 지양할 것
// 코드의 규칙성을 지킬 것

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
		return _print_err_address("exit_node", "front_node");

	st_node* rm_node = (*front_node)->p_next;

	(*front_node)->p_next = rm_node->p_next;
	rm_node->p_next = NULL;

	exit_node(&rm_node);

	return 0;
}

static int print_node(st_node* head_node)
{
	if (head_node == NULL)		
		return _print_err_address("printf_node", "head node");

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
	st_node* p_head = init_node();
	if(p_head == NULL)
		return 0;

	st_node *p_curr = p_head;
	for (int i = 1; i <= 10; i++)
	{
		if (add_node(p_curr, i) == -1)		return 0;
		p_curr = p_curr->p_next;
	}

	if (print_node(p_head) == -1)			return 0;

	for (int i = 1; i <= 10; i++)
	{
		if (delete_node(&p_head) == -1)		return 0;
	}

	if (print_node(p_head) == -1)			return 0;

	exit_node(&p_head);		// 함수로 처리 또는 malloc으로 직접 선언해서 헷갈리는 현상을 방지할 것

	return 0;
}