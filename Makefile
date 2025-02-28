NAME         = push_swap
BONUS_NAME   = checker

SRC_PUSH_SWAP = libft_0.c libft_bonus.c mysplit.c push_swap.c stack_tools.c \
                libft_1.c parsing.c stack_moves.c statistique.c stack_moves_1.c
		
SRC_BONUS     = checker_bonus.c stack_moves_bonus.c mysplit_bonus.c libft_0_bonus.c \
                libft_1_bonus.c libft_2bonus.c get_next_line.c get_next_line_utils.c \
                parsing_bonus.c bonus_tools.c stack_moves1_bonus.c

HEADER         = push_swap.h
HEADER_BONUS   = push_swap_bonus.h

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_BONUS     = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PUSH_SWAP): $(HEADER)
$(OBJ_BONUS): $(HEADER_BONUS)

clean:
	rm -f $(OBJ_PUSH_SWAP) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
