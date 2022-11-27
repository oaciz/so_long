NAME		= so_long
SRCS		= $(wildcard support/*.c) $(wildcard ./*.c)
OBJS		= $(SRCS:.c=.o)
LBFT		= libft/libft.a
PF			= ft_printf/libftprintf.a
CFLAGS		= -Wall -Wextra -Werror -g
LFLAGS		= -framework OpenGL -framework AppKit -L./mlx -lmlx -L./ft_printf -lftprintf -L./libft -lft

all: $(NAME)

$(NAME): $(OBJS) $(LBFT) $(PF)
	make -C ./mlx 2> /dev/null
	gcc $(LFLAGS) $(OBJS) -o $(NAME)

$(LBFT):
	make -C ./libft

$(PF):
	make -C ./ft_printf

clean:
	make -C ./mlx clean
	make -C ./ft_printf clean
	make -C ./libft clean
	rm -rf $(OBJS)

fclean:
	make -C ./ft_printf fclean
	make -C ./libft fclean
	make -C ./mlx clean
	rm -rf $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
