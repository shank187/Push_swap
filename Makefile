NAME = push_swap
SRC = libft_0.c libft_bonus.c mysplit.c push_swap.c stack_tools.c testing.c libft_1.c parsing.c stack_moves.c statistique.c 
FLAGS = -Wall -Wextra -Werror
CC = cc
OBJ = $(SRC:%.c=%.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean