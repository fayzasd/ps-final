#include "push_swap.h"

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
    ft_printf("%d\n",no);
  return 0;
}

int check_input (char **input, int *stack, counter *stacker)
{
  int i;
  int j;

  i = 1;
  j = 0;
  while (input[i])
  {
    j = 0;
    while (input[i][j])
    {
      if (!ft_isdigit(input[i][j]) && input[i][j] != ' ')
        return 1;
      j++;
    }
    i++;
  }
  if (check_dup(stack, stacker->a) == 1)
    return 1;
  return 0;
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
