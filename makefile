NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Directories
LIBFT_DIR = Libft
PRINTF_DIR = ft_printf

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Include paths
INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Source files
SRCS = push_swap.c \
       checker.c \
       checker2.c \
       checke1.c \
       create_stack.c \
       operations.c \
	   Sorting.c

# Bonus source files (for checker program)
BONUS_SRCS = checker_bonus.c \
             checker_bonus2.c \
             create_stack_bonus.c \
             operations_bonus.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Colors for pretty output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
RESET = \033[0m

# Main rules
all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(PRINTF) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(PRINTF) -o $(BONUS_NAME)
	@echo "$(GREEN)✓ $(BONUS_NAME) compiled successfully!$(RESET)"

# Compile object files
%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)Compiled: $<$(RESET)"

# Compile libraries
$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "$(YELLOW)Compiling ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR)

# Clean rules
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@echo "$(RED)✓ Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "$(RED)✓ Executables removed$(RESET)"

re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re