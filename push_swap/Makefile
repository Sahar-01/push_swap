NAME = push_swap

# Directories
SRC_DIR = srcs
LIBFT_DIR = libft
INCLUDE_DIR = inc

# Libft build
LIBFT_A = $(LIBFT_DIR)/libft.a

# Source files
SRC_FILES = \
	$(SRC_DIR)/operations/push.c \
	$(SRC_DIR)/operations/rotate.c \
	$(SRC_DIR)/operations/rrotate.c\
	$(SRC_DIR)/operations/sort_three.c \
	$(SRC_DIR)/operations/sort_five.c \
	$(SRC_DIR)/operations/sort_main.c \
	$(SRC_DIR)/operations/stack_utils.c \
	$(SRC_DIR)/operations/sort_utils.c \
    $(SRC_DIR)/operations/sorted.c \
	$(SRC_DIR)/operations/swap.c \
	$(SRC_DIR)/push_swap/main.c \
    $(SRC_DIR)/push_swap/init_stack.c \
    $(SRC_DIR)/push_swap/append.c 

OBJ_FILES = $(SRC_FILES:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/inc

# Rules
.PHONY: all clean fclean re

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(LIBFT_A) -o $(NAME)
	@echo "✅ push_swap compiled successfully"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
