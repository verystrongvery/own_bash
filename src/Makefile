SRC 	= $(wildcard *.c)
OBJS	= $(SRC:.c=.o)

NAME	= bash
RM		= rm -rf
LIB		= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all 	: $(NAME)

clean	:
		$(RM) $(OBJS) *.gch *.out

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

$(NAME) : $(OBJS)