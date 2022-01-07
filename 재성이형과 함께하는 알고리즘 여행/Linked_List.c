#include <stdio.h>
#include <stdlib.h>

struct Node	
{
	struct Node *Next;
	int Data;
};

struct Node *init(struct Node *front, int data)
{
	struct Node *node = malloc(sizeof(struct Node));
	node->Data = data;

	if (front->Next != NULL)
	{
		struct Node *Rear = front->Next;
		front->Next = node;
		node->Next = Rear;
	}
	else
	{
		front->Next = node;
		node->Next = NULL;
	}

	return node;
}

void node_exit(struct Node *front)
{
	struct Node *curr = front->Next;

	front->Next = curr->Next;
	curr->Next = NULL;
}

int main(void)
{
	struct Node *head = malloc(sizeof(struct Node));
	head->Next = NULL;

	struct Node *node1 = init(head, 10);
	struct Node *node2 = init(node1, 20);
	struct Node *node3 = init(node2, 30);
	struct Node *node4 = init(node3, 40);
	struct Node *node5 = init(node4, 50);

	struct Node *node6 = init(node2, 60);
	struct Node *node7 = init(node5, 70);

	node_exit(head);

	struct Node *curr = head->Next;
	while (curr != NULL)
	{
		printf("%d\n", curr->Data);
		curr = curr->Next;
	}

	free(node7);
	free(node6);
	free(node5);
	free(node4);
	free(node3);
	free(node2);
	free(node1);
	free(head);

	return 0;
}