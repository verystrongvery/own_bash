NAME	= bash
LIB		= lib
SRC	= src
OBJ		= *.o
RM		= rm -rf
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all 	: $(NAME)

clean	:
		$(RM) $(OBJS) *.gch *.out
		make clean -C $(LIB)
		make clean -C $(SRC)

fclean	: clean
		$(RM) $(NAME)
		make fclean -C $(LIB)
		make fclean -C $(SRC)

re		: fclean all

$(NAME) :
		make -C $(LIB)
		make -C $(SRC)
		$(CC) -o bash $(CFLAGS) $(LIB)/$(OBJ) $(SRC)/$(OBJ)