#include "queue.h"

st_qp* init_queue(void)
{
	st_qp* p_qp = calloc(1, sizeof(st_qp));
	if (p_qp == NULL)
	{
		PRINT_ERR_MEMORY("init_stack");
		return NULL;
	}

	p_qp->qp = init_node();
	if (p_qp->qp == NULL)
		return NULL;

	return p_qp;
}

int exit_queue(st_qp** pp_rm_qp)
{
	if (pp_rm_qp == NULL || *pp_rm_qp == NULL)
	{
		PRINT_ERR_ADDRESS("exit_queue", "rm_queue");
		return -1;
	}
	int err = 0;
	st_node* p_curr = (*pp_rm_qp)->qp;
	while (p_curr->p_next != NULL)
	{
		p_curr = p_curr->p_next;
		err |= delete_node(&p_curr);
		if (err == -1)
			return -1;
	}
	err |= exit_node(&((*pp_rm_qp)->qp));
	if (err == -1)
		return -1;

	free(*pp_rm_qp);
	*pp_rm_qp = NULL;

	return 0;
}

int empty_q(const st_qp* p_qp)
{
	if(p_qp == NULL || p_qp->qp == NULL)
	{
		PRINT_ERR_ADDRESS("empty in stack", "sp");
		return -1;
	}

	return (p_qp->qp->p_next == NULL);
}

int enqueue_q(st_qp* p_qp, const int data)
{
	if (p_qp == NULL || p_qp->qp == NULL)
	{
		PRINT_ERR_ADDRESS("enqueue in queue", "p_qp");
		return -1;
	}
	st_node* p_curr = p_qp->qp;
	while (p_curr->p_next != NULL)
		p_curr = p_curr->p_next;

	int err = add_node(p_curr, data);
	if (err == -1)
		return -1;
	else
		return 0;
}

int dequeue_q(st_qp** pp_qp)
{
	if (pp_qp == NULL || *pp_qp == NULL || (*pp_qp)->qp == NULL)
	{
		PRINT_ERR_ADDRESS("dequeue in queue", "pp_qp");
		return -1;
	}
	if ((*pp_qp)->qp->p_next == NULL)
	{
		PRINT_ERR_ADDRESS("dequeue in queue", "p_next");
		return -1;
	}
	int dequeue_return = ((*pp_qp)->qp->p_next->data);
	int err = delete_node(&(*pp_qp)->qp);
	if (err == -1)
		return -1;

	return dequeue_return;
}

int size_q(const st_qp* p_qp)
{
	if (p_qp == NULL || p_qp->qp == NULL)
	{
		PRINT_ERR_ADDRESS("size in queue", "p_qp");
		return -1;
	}
	int len = 0;
	st_node* p_curr = p_qp->qp;
	while (p_curr->p_next != NULL)
	{
		len++;
		p_curr = p_curr->p_next;
	}
	printf("queue size is %d\n", len);

	return 0;
}

int front_q(const st_qp* p_qp)
{
	if (p_qp == NULL || p_qp->qp == NULL)
	{
		PRINT_ERR_ADDRESS("front in queue", "p_qp");
		return -1;
	}
	if (p_qp->qp->p_next == NULL)
	{
		PRINT_ERR_ADDRESS("front in queue", "p_next");
		return -1;
	}

	printf("The front integer : %d\n", p_qp->qp->p_next->data);

	return 0;
}

static int _print_queue(const st_qp* p_qp)
{
	printf("|    front   |\n");
	st_node* p_curr = p_qp->qp->p_next;
	while (p_curr != NULL)
	{
		printf("|    %-4d    |\n", p_curr->data);
		p_curr = p_curr->p_next;
	}
	printf("|    rear    |\n");
	return 0;
}

static int _print_empty(const st_qp* p_qp)
{
	int bool_empty = empty_q(p_qp);
	if (bool_empty == -1)
		return -1;
	else if (bool_empty == 1)
		printf("queue is empty\n");
	else
		printf("queue is not empty\n");

	return 0;
}

int check_queue(void)
{
	st_qp* p_qp = init_queue();
	int err = 0;

	for (int i = 1; i <= 10; i++)
	{
		err = enqueue_q(p_qp, i);
		if (err == -1)
			return 0;
	}

	err = _print_queue(p_qp);
	err |= _print_empty(p_qp);
	err |= size_q(p_qp);
	if (err == -1)
		return 0;

	for (int i = 1; i <= 10; i++)
	{
		err = front_q(p_qp);
		int rtn = dequeue_q(&p_qp);
		printf("dequeue retrun : %d\n", rtn);
		if (err == -1)
			return 0;
	}

	err = _print_queue(p_qp);
	err |= _print_empty(p_qp);
	err |= size_q(p_qp);
	if (err == -1)
		return 0;

	err = exit_queue(&p_qp);
	if (err == -1)
		return 0;

	return 0;
}