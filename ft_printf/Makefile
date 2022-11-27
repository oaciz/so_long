SRCS		=	ft_printf.c ft_printf_utils.c\

OBJS		=	${SRCS:.c=.o}

CC			= gcc

RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

NAME = 		libftprintf.a

all:		${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY :	all fclean re
