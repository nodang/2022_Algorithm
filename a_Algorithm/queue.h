#ifndef QUEUE_H
#define QUEUE_H

#include "configure.h"
#include "linked_list.h"

typedef struct Queue {
	st_node* qp;
}st_qp;

st_qp* init_queue(void);
int exit_queue(st_qp** pp_rm_qp);
int empty_q(const st_qp* p_qp);
int enqueue_q(st_qp* p_qp, const int data);
int dequeue_q(st_qp** pp_qp);
int size_q(const st_qp* p_qp);
int front_q(const st_qp* p_qp);
int check_queue(void);

#endif