#ifndef STACK_H
#define STACK_H

typedef struct Stack {
	st_node* sp;
}st_sp;

st_sp* init_stack(void);
int exit_stack(st_sp** pp_rm_sp);
int empty(const st_sp* p_sp);
int pop(st_sp** pp_sp);
int push(st_sp* p_sp, const int data);
int size(const st_sp* p_sp);
int top(const st_sp* p_sp);
int check_stack(void);

#endif