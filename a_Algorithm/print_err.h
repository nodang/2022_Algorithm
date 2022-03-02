#ifndef PRINT_ERR_H
#define PRINT_ERR_H

#define PRINT_ERR_ADDRESS(FUNC, NAME)	printf("Err[%s] : %s's address is NULL\n", FUNC, NAME)
#define PRINT_ERR_EMPTY(FUNC)			printf("Err[%s] : stack is empty or memory error\n", FUNC);
#define PRINT_ERR_MEMORY(NAME)			printf("Err[%s] : Memory isn't enough\n", NAME)

#endif