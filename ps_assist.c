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
  if (no > count)
    return 1;
  return 0;
}