#ifndef STACK_H
#define STACK_H

#include "configure.h"
#include "linked_list.h"

typedef struct Stack {
	st_node* sp;
}st_sp;

st_sp* init_stack(void);
int exit_stack(st_sp** pp_rm_sp);
int empty_s(const st_sp* p_sp);
int pop_s(st_sp** pp_sp);
int push_s(st_sp* p_sp, const int data);
int size_s(const st_sp* p_sp);
int top_s(const st_sp* p_sp);
int check_stack(void);

#endif