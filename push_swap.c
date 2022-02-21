#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct count_ab {
  int a;
  int b;
  int total;
}counter;

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

int input_to_stack(char **input, int *stack_a)
{
  int i;
  int j;
  int stack_no;

  stack_no = 0;
  i = 0;
  j = 1;
  while (input[j])
  {
    stack_a[i] = ft_atoi(input[j]);
    j++;
    i++;
    stack_no++;
  }
  return stack_no;
}

void init_stack(int *stack, int count)
{
  while (count > 0)
  {
    *stack = 0;
    *stack++;
    count--;
  }
}

void print_stack(int *stack, int count)
{
  int i;

  i = 0;
  while( i < count)
  {
    printf("%d\n",stack[i]);
    i++;
  }
  printf("\n");
}

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
    printf("sa\n"); 
  }
}

void sb(int *stack, int count)
{
  if (count > 1)
  {
  swap(stack, 0 , 1);
  printf("sb\n"); 
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
  int i;
  
  i = 0;
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
    printf("pb\n");
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
    printf("pb\n");
    stacker->a--;
  }
}

void ra_rb(int *stack, int count, char flag)
{
  int i;

  i = stack[0];
  pull(stack, count);
  stack[count-1] = i;
  if (flag == 'a')
    printf("ra\n");
  else if (flag == 'b')
    printf("rb\n");
}

void rr(int *stack_a, int *stack_b, counter *stacker)
{
  ra_rb(stack_a, stacker->a, 0);
  ra_rb(stack_b, stacker->b, 0);
  printf("rr\n");
}

void rra_rrb(int *stack, int count, char flag)
{
  int i;

  i = stack[count - 1];
  push(stack, count);
  stack[0] = i;
  if (flag == 'a')
    printf("rra\n");
  else if (flag == 'b')
    printf("rrb\n");  
}

void rrr(int *stack_a, int *stack_b, counter *stacker)
{
  rra_rrb(stack_a, stacker->a, 0);
  rra_rrb(stack_b, stacker->b, 0);
  printf("rrr\n");
}

void sort_stack(int *stack_a, int count)
{
  int i;
  int j;
  int primary;
  int secondary_count;

  i = 0;
  j = 0;
  primary = 0;
  secondary_count = 0;
  while(count > 0)
  {
    primary = stack_a[i];
    j = i + 1;
    secondary_count = count - 1;
    while(primary > stack_a[j])
    {
      swap(stack_a, i ,j);
      j++;
      secondary_count--;
    }
    count--;
    i++;
  }
}

void main(int argc, char **argv)
{
  int stack_a[count_input(argv)];
  int stack_b[count_input(argv)];
  counter stacker;

  stacker.total = count_input(argv);
  stacker.a = input_to_stack(argv, stack_a);
  init_stack(stack_b, stacker.a);
  stacker.b = 0;
  // sort_stack(stack_a, count);
  ra_rb(stack_a, stacker.a, 'a');
  // rra(stack_a, stacker.a);
  pb(stack_a, stack_b, &stacker);
  pb(stack_a, stack_b, &stacker);
  pb(stack_a, stack_b, &stacker);
  // rrb(stack_b, stacker.b);
  ra_rb(stack_b, stacker.b, 'b');
  // rr(stack_a, stack_b, &stacker);
  // pa(stack_a, stack_b, &stacker);
  printf("\nstack_a:\n");
  print_stack(stack_a, stacker.total);
  printf("stack_b:\n");
  print_stack(stack_b, stacker.total); 
} 