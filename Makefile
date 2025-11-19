# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by student           #+#    #+#              #
#    Updated: 2024/01/01 00:00:00 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Directories
SRCS_DIR	= srcs
OBJS_DIR	= objs
INCLUDES	= -I includes -I libft
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

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
