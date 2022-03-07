#include "push_swap.h"

void swap(int *arr, int x, int y)
{
  int temp;

  temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void sa(int *stack, int count)
{
  if (count > 1)
  {
    swap(stack, 0 , 1);
    ft_printf("sa\n"); 
  }
}

void sb(int *stack, int count)
{
  if (count > 1)
  {
  swap(stack, 0 , 1);
  ft_printf("sb\n"); 
  }
}

void ss(int *stack_a, int *stack_b, int count)
{
  sa(stack_a, count);
  sb(stack_b, count);
}

void pull(int *stack, int count)
{
  int i;

  i = 0;
  while(i < count)
  {
    stack[i] = stack[i+1];
    i++;
  }
  stack[i - 1] = 0;
}

void push(int *stack, int count)
{
  count--;
  while (count >= 0)
  {
    stack[count] = stack[count - 1];
    count--;
  }
  stack[0] = 0;
}

void pa(int *stack_a, int *stack_b, counter *stacker)
{
  if (stacker->b != 0)
  {
    stacker->a++;
    push(stack_a, stacker->a);
    stack_a[0] = stack_b[0];
    pull(stack_b, stacker->b);
    ft_printf("pa\n");
    stacker->b--;
  }
}

void pb(int *stack_a, int *stack_b, counter *stacker)
{ 
  if (stacker->a != 0)
  {
    stacker->b++;
    push(stack_b, stacker->b);
    stack_b[0] = stack_a[0];
    pull(stack_a, stacker->a);
    ft_printf("pb\n");
    stacker->a--;
  }
}

void rotate(int *stack, int count)
{
  int i;

  i = stack[0];
  pull(stack, count);
  stack[count-1] = i;
}

void ra(int *stack, int count)
{
  rotate(stack, count);
  ft_printf("ra\n");
}

void rb(int *stack, int count)
{
  rotate(stack, count);
  ft_printf("rb\n");
}

void rr(int *stack_a, int *stack_b, counter *stacker)
{
  rotate(stack_a, stacker->a);
  rotate(stack_b, stacker->b);
  ft_printf("rr\n");
}

void rev_rotate(int *stack, int count)
{
  int i;

  i = stack[count - 1];
  push(stack, count);
  stack[0] = i;
}

void rra(int *stack, int count)
{
  rev_rotate(stack, count);
  ft_printf("rra\n");
}

void rrb(int *stack, int count)
{
  rev_rotate(stack, count);
  ft_printf("rra\n");
}

void rrr(int *stack_a, int *stack_b, counter *stacker)
{
  rev_rotate(stack_a, stacker->a);
  rev_rotate(stack_b, stacker->b);
  ft_printf("rrr\n");
}
 