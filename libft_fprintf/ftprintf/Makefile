# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 17:27:06 by jfranco           #+#    #+#              #
#    Updated: 2025/04/04 13:18:51 by jfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftfprintf.a

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

SRCS = input.c out_digit.c out_char.c

OBJ_DIR = obj
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

# Create the object directory before compiling
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile the program (only generate the static library)
$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Static library created: $(NAME)"

# Rule to compile .c into .o
$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects
clean:
	rm -rf $(OBJ_DIR)
	@echo "Removed object files."

# Clean everything (objects and executable)
fclean: clean
	rm -f $(NAME)
	@echo "Static library removed."

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
