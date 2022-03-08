#include "push_swap.h"

int	ft_isdigit(int val)
{
	if ('0' <= val && val <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
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

int check_input(int *stack, int count)
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
  // ft_printf("no:%d\ncount:%d\n",no,count);
  if (no > count)
    return 1;
  return 0;
}

int count_input(char **input)
{
  int count;
  int i;
  int j;

  count = 0;
  i = 1;
  j = 0;
  while (input[i])
  {
    j = 0;
    while (input[i][j])
    {
      if (input[i][j] != ' ' && !(ft_isdigit(input[i][j+1])))  
        count++;
      j++;
    }
    i++;
  }
  return (count);
}

int count_arg(char **input)
{
  int count;
  int i;
  int j;

  count = 0;
  i = 1;
  j = 0;
  while (input[i])
  {
    j = 0;
    while (input[i][j])
    {
      count++;
      j++;
    }
    i++;
  }
  return count;
}

char *join_input(char **input)
{
  int i;
  int j;
  int k;
  char *output;

  i = 1;
  k = 0;
  output = (char *)malloc(count_arg(input)*sizeof(char));
  while (input[i])
  {
    j = 0;
    while (input[i][j])
    {
      if(input[i][j] != ' ')
        output[k++] = input[i][j];
      else
        output[k++] = ' ';
      j++;
    }
    output[k++] = ' ';
    i++; 
  }
  output[k] = '\0';
  return (output);
}

void input_to_stack(char *input, int *stack_a)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (input[j])
  {
    if (ft_isdigit(input[j]))
    {
      stack_a[i] = input[j] - '0';
      if (ft_isdigit(input[j+1]))
            stack_a[i] *= 10;
      j++;
      while(ft_isdigit(input[j]) && input[j])
      {
        stack_a[i] += (input[j] - '0');
        if (ft_isdigit(input[j+1]) && input[j+1])
          stack_a[i] *= 10;
        j++;
      }
    i++;
    }
    j++;
  }
  free(input);
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


void sort_stack_2(int *stack_a, int *stack_b, counter *stacker)
{
  int i;
  int j;

  i = 0;
  j = 0;
  if (stack_a[0] > stack_a[1])
    sa(stack_a, stacker->a, stacker);
  else if (sort_check(stack_a, stacker->a) == 1)
  {
    pb(stack_a, stack_b, stacker);
    pb(stack_a, stack_b, stacker);
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
  // ft_printf("total:%d + count_input:%d + count_arg:%d\n",stacker.total, count_input(argv), count_arg(argv));
  input_to_stack(join_input(argv), stack_a);
  // ft_printf("string is%s\n",join_input(argv));
  if (check_input(stack_a, stacker.total) == 1)
    write(2,"Error\n",6);
  else
  {
    init_stack(stack_b, stacker.a);
    stacker.b = 0; 
    sort_stack_1(stack_a, stack_b, &stacker, &least);
    ft_printf("\nstack_a:\n");
    print_stack(stack_a, stacker.a);
    ft_printf("instrctions:%d\n",stacker.icount);
  
    // ft_printf("stack_b:\n");
    // print_stack(stack_b, stacker.b); 
  }
} 