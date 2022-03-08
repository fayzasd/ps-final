#include "push_swap.h"

void find_least(int *stack, counter *stacker, first *least)
{
  int i;
  int j;

  i = 0;
  j = 1;
  least->pos = 0;
  while (i < stacker->a)
  {
    least->val = stack[i];
    j = 0;
    while (j < stacker->a)
    {
      if (stack[j] < least->val)
      {
        least->val = stack[j];
        least->pos = j;
      }
      j++;
    }
    i++;
  }
}

void sort_stack_1(int *stack_a, int *stack_b, counter *stacker, first *least)
{
  int i;
  int j;

  j = 0;
  i = 0;
  find_least(stack_a, stacker, least);
  if (least->pos == 0)
    pb(stack_a, stack_b, stacker);
  else if (least->pos == (stacker->total - 1))
    rra(stack_a, stacker->a, stacker);
  else
  {
    if ((least->pos) > ((stacker->a)/2))
      rra(stack_a, stacker->a, stacker);
    else
      ra(stack_a, stacker->a, stacker);
  }
  if (stacker->a > 0)
    sort_stack_1(stack_a, stack_b, stacker, least);
  else
    {
      while(i < stacker->total)
      {
        pa(stack_a, stack_b, stacker);
        i++;
      }
    }
}

int sort_check(int *stack, int count)
{
  int i;
  int j;

  j = 0;
  i = 0;
  while (i < count)
  {
    j = i + 1;
    while (j < count)
    {
      if (stack[i] > stack[j])
        return 1;
      j++;
    }
    i++;
  }
  return 0;
}

void sort_stack(int *stack, counter *stacker)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (i < stacker->b)
  {
    j = i + 1;
    while (j < stacker->b)
    {
      while (stack[i] > stack[j])
      {
        
      }
    }
  }

}

void sort_stack_2(int *stack_a, int *stack_b, counter *stacker)
{
  int i;
  int j;
  first least;

  i = 0;
  while (i < stacker->total)
  {
    j = i + 1;
    if (stack_a[i] > stack_a[j])
      sa(stack_a, stacker->a, stacker);
    if (sort_check(stack_a, stacker->a) == 1)
    {
      pb(stack_a, stack_b, stacker);
      pb(stack_a, stack_b, stacker);
    }
    i++;
  }
}

int main(int argc, char **argv)
{
  int stack_a[count_input(argv)];
  int stack_b[count_input(argv)];
  counter stacker;
  first least;
 
  stacker.total = count_input(argv);
  stacker.a = stacker.total;
  stacker.icount = 0;
  if (check_input(argv, stack_a, &stacker) == 1)
    write(2,"Error\n",6);
  else
  {
    input_to_stack(join_input(argv), stack_a);
    init_stack(stack_b, stacker.a);
    stacker.b = 0; 
    sort_stack_1(stack_a, stack_b, &stacker, &least);
    ft_printf("\nstack_a:\n");
    print_stack(stack_a, stacker.a);
    ft_printf("stack_b:\n");
    print_stack(stack_b, stacker.b); 
    ft_printf("instrctions:%d\n",stacker.icount);
  }
} 