NAME        = libpush_swap.a
PROGRAM     = push_swap
CHECKER     = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC =  h_functions.c \
       h_functions2.c \
       h_functions3.c \
       h_functions4.c \
       h_functions5.c \
       operations.c \
       stack_functions.c \
       sort.c \
       main_helper.c \
       main_helper2.c

SRC_BONUS = get_next_line_bonus.c \
            get_next_line_utils_bonus.c

MAIN_SRC        = main.c
MAIN_CHECKER_SRC = main_checker.c

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)
MAIN_OBJ    = $(MAIN_SRC:.c=.o)
CHECKER_OBJ = $(MAIN_CHECKER_SRC:.c=.o)

all: $(PROGRAM)

bonus: $(CHECKER)

$(PROGRAM): $(NAME) $(MAIN_OBJ)
	$(CC) $(MAIN_OBJ) $(NAME) -o $(PROGRAM)

$(CHECKER): $(NAME) $(CHECKER_OBJ)
	$(CC) $(CHECKER_OBJ) $(NAME) -o $(CHECKER)

$(NAME): $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $^

%.o: %.c push_swap.h push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS) $(MAIN_OBJ) $(CHECKER_OBJ)

fclean: clean
	rm -f $(NAME) $(PROGRAM) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re bonus
