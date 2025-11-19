
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Directories
SRCS_DIR	= srcs
OBJS_DIR	= objs
INCLUDES	= -I includes -I libft -I libft/ft_printf
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Source files
SRCS		= $(SRCS_DIR)/main.c \
			  $(SRCS_DIR)/swap_operations.c \
			  $(SRCS_DIR)/push_operations.c \
			  $(SRCS_DIR)/rotate_operations.c \
			  $(SRCS_DIR)/reverse_rotate_operations.c \
			  $(SRCS_DIR)/stack_utils.c

# Object files
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Rules
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compilando push_swap..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Ejecutable creado: $(NAME)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@make clean -C $(LIBFT_DIR)
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@echo "Eliminando ejecutable..."
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "Ejecutable $(NAME) eliminado."

re: fclean all

.PHONY: all clean fclean re
