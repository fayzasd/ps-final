#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

void pa(int *stack_a, int *stack_b, int count)
{
  if (count != 0)
  {
    push(stack_a, count);
    stack_a[0] = stack_b[0];
    pull(stack_b, count);
    printf("pb\n");;
  }
}

void pb(int *stack_a, int *stack_b, int count)
{ 
  if (count != 0)
  {
    push(stack_b, count);
    stack_b[0] = stack_a[0];
    pull(stack_a, count);
    printf("pb\n");
  }
}

void ra_rb(int *stack, int count)
{
  int first;
  int last;
  int i;
  int j;

  i = 0;
  j = 1;
  last = count - 1;
  first = stack[0];
  while (count > 0)
  {
    stack[i] = stack[j];
    i++;
    j++;
    count--;
  }
  stack[last] = first;
}

void rotate()
{

}

void ra(int *stack)
{
  int first;
  

}

void rra_rrb(int *stack, int count)
{
  int i;
  int j;
  int last;
  int count_1;

  i = 0;
  j = count - 2;
  last = stack[count - 1];
  count_1 = count - 1;
  while(count > 0)
  {
    stack[count_1] = stack[j];
    j--;
    count_1--;
    count--;
  }
  stack[0] = last;
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
  int count;

  count = count_input(argv);
  input_to_stack(argv, stack_a);
  init_stack(stack_b, count);
  // sort_stack(stack_a, count);
  sa(stack_a, count);
  pb(stack_a,stack_b, count);
  pa(stack_a, stack_b, count);
  printf("\nstack_a:\n");
  print_stack(stack_a, count);
  printf("stack_b:\n");
  print_stack(stack_b, count); 
} 