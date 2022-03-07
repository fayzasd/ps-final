#include "push_swap.h"

int	ft_isdigit(int val)
{
	if ('0' <= val && val <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	n;
	int				flag;

	n = 0;
	flag = 1;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			flag += 1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
	{
		n += (*str - 48);
		if (ft_isdigit(*++str) != 0)
			n *= 10;
	}
	if (flag > 1)
		return ((int)-n);
	return ((int)n);
}

int check_dup(int *stack, int count)
{
  int i;
  int j;
  int no;

  i = 0;
  j = 0;
  no = 0;
  while (i < count)
  {
    j = 0;
    while(j < count)
    {
      if (stack[i] == stack[j])
        no++;
      j++;
    }
    i++;
  }
  ft_printf("no:%d\ncount:%d\n",no,count);
  if (no > count)
    return 1;
  return 0;
}

int count_multiple(char **input)
{
  int i;
  int j;
  int count;

  i = 0;
  j = 1;
  count = 0;
  while (input[i])
  {
    j = 1;
    while (input[i][j])
    {
      if (input[i][j] == ' ' && ft_isdigit(input[i][j+1]))
       count++;
      j++;      
    }
    i++;
  }
  return (count);
}

int count_input(char **input)
{
  int count;
  int i;

  count = 0;
  i = 1;
  while (input[i])
  {
    count++;
    i++;
  }
  return (count);
}

void input_to_stack(char **input, int *stack_a)
{
  int i;
  int j;

  i = 0;
  j = 1;
  while (input[j])
  {
    stack_a[i] = ft_atoi(input[j]);
    j++;
    i++;
  }
}

void input_multi(char **input, int *stack, int total)
{
  int i;
  int j;
  int k;

  i = 1;
  j = 0;
  k = 0;
  while (input[i] && i < (total - 1))
  {
    j = 0;
    while (input[i][j])
    {
      if (ft_isdigit(input[i][j]))
        {
          stack[k] = (input[i][j] - '0');
          if (ft_isdigit(input[i][j+1]))
            stack[k] *= 10;
          j++;
          while(ft_isdigit(input[i][j]) && input[i][j])
          {
            stack[k] += (input[i][j] - '0');
            if (ft_isdigit(input[i][j+1]) && input[i][j+1])
              stack[k] *= 10;
            j++;
          }
        }
      k++;
      j++;        
    }
    i++;
  }
}

void input_2(char **input, int *stack, int total)
{
  
}

void init_stack(int *stack, int count)
{
  while (count > 0)
  {
    *stack = 0;
    stack++;
    count--;
  }
}

void print_stack(int *stack, int count)
{
  int i;

  i = 0;
  while( i < count)
  {
    ft_printf("%d\n",stack[i]);
    i++;
  }
  ft_printf("\n");
}

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

void sort_stack(int *stack_a, int *stack_b, counter *stacker, first *least)
{
  int j;

  j = 0;
  find_least(stack_a, stacker, least);
  if (least->pos == 0)
    pb(stack_a, stack_b, stacker);
  else if (least->pos == (stacker->total - 1))
    rra(stack_a, stacker->a);
  else
  {
    if ((least->pos) > ((stacker->total)/2))
      rra(stack_a, stacker->a);
    else
      ra(stack_a, stacker->a);
  }
  if (stacker->a > 0)
    sort_stack(stack_a, stack_b, stacker, least);
}

int main(int argc, char **argv)
{
  int stack_a[count_input(argv)+count_multiple(argv)];
  int stack_b[count_input(argv)+count_multiple(argv)];
  counter stacker;
  first least;
  int i = 0;
 
  stacker.total = count_multiple(argv) + count_input(argv);
  stacker.a = stacker.total;
  ft_printf("total:%d multi:%d + input:%d\n",stacker.total,count_multiple(argv), count_input(argv));
  // input_to_stack(argv, stack_a);
  input_multi(argv, stack_a, stacker.total);
  ft_printf("total:%d multi:%d + input:%d\n",stacker.total,count_multiple(argv), count_input(argv));
  if (check_dup(stack_a, stacker.total) == 1)
    write(2,"Error\n",6);
  else
  {
    init_stack(stack_b, stacker.a);
    stacker.b = 0; 
    sort_stack(stack_a, stack_b, &stacker, &least);
    while(i < stacker.total)
    {
      pa(stack_a, stack_b, &stacker);
      i++;
    }
    ft_printf("\nstack_a:\n");
    print_stack(stack_a, stacker.total);
    ft_printf("stack_b:\n");
    print_stack(stack_b, stacker.total); 
  }
} 