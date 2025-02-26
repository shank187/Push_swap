NAME = push_swap
BONUS = checker

SRC = libft_0.c libft_bonus.c mysplit.c push_swap.c stack_tools.c libft_1.c parsing.c stack_moves.c statistique.c stack_moves_1.c 
SRC_BONUS = checker_bonus.c stack_moves.c mysplit.c libft_0.c libft_1.c libft_bonus.c get_next_line.c get_next_line_utils.c parsing.c stack_tools.c bonus_tools.c stack_moves_1.c

CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
RM = rm -f

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
