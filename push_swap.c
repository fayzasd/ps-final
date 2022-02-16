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

void print_stack(int *stack, int count)
{
  int i;

  i = 0;
  while(count > 0)
  {
    printf("%d",stack[i]);
    i++;
    count--;
  }
  printf("\n");
}

void swap(int *stack, int pri, int sec)
{
  int temp;

  temp = 0;
  temp = stack[pri];
  stack[pri] = stack[sec];
  stack[sec] = temp;
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
    wh
    ile(primary > stack_a[j])
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
  int count;

  count = count_input(argv);
  input_to_stack(argv, stack_a);
  sort_stack(stack_a, count);
  sort_stack(stack_a, count);
  print_stack(stack_a, count); 
}