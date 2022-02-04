#ifndef STACK_H
#define STACK_H


int empty(const st_node* p_ceiling_node);
int pop(st_node** pp_ceiling_node);
int push(st_node* p_ceiling_node, const int data);
int size(const st_node* p_ceiling_node);
int top(const st_node* p_ceiling_node);
int check_stack(void);

#endif