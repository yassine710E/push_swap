NAME = libpush_swap.a
SRC = h_functions4.c h_functions.c h_functions2.c h_functions3.c operations.c stack_functions.c
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
MAIN = main.c
MAIN_OBJ = $(MAIN:.c=.o)
PROGRAM = push_swap

all : $(PROGRAM)

$(PROGRAM) : $(NAME) $(MAIN_OBJ)
	cc -g $(MAIN_OBJ) $(NAME) -o $@ 

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o : %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@ 

clean : 
	rm -f $(OBJ) $(MAIN_OBJ)
fclean : clean 
	rm -f $(NAME) $(PROGRAM)
re : fclean all

.PHONY : re fclean clean all