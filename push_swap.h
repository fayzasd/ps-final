

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include"ft_printf/ft_printf.h"

typedef struct count_ab {
  int a;
  int b;
  int total;
}counter;

typedef struct lesser {
  int val;
  int pos;
} first;

void swap(int *arr, int x, int y);
void sa(int *stack, int count);
void sb(int *stack, int count);
void ss(int *stack_a, int *stack_b, int count);
void pull(int *stack, int count);
void push(int *stack, int count);
void pa(int *stack_a, int *stack_b, counter *stacker);
void pb(int *stack_a, int *stack_b, counter *stacker);
void rotate(int *stack, int count);
void ra(int *stack, int count);
void rb(int *stack, int count);
void rr(int *stack_a, int *stack_b, counter *stacker);
void rra(int *stack, int count);
void rrb(int *stack, int count);
void rrr(int *stack_a, int *stack_b, counter *stacker);

#endif