.PHONY: all re clean fclean

NAME = libftprintf.a
CC = cc 
FLAGS = -Wall -Werror -Wextra
SRC =	ft_printf.c \
		ft_fonctions_supp.c
OBJ = $(SRC:.c=.o)

all : $(NAME) 

%.o : %.c ft_printf.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : clean all