NAME		= push_swap

SRCS		= push_swap.c \
					ps_instrucs.c \
					ft_printf/ft_printf.c \
					ft_printf/ft_printf_assist.c \
					ft_printf/ft_printf_utils.c \

OBJS		= $(SRCS:%.c=%.o)
# FLAGS		= -Wall -Werror -Wextra


$(NAME): $(FTPRINTF)
		make -C ft_printf
		gcc $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS)
		make -C ft_printf/ clean

fclean:	clean
		rm -f $(NAME)
		make -C ft_printf/ fclean

re: fclean all
