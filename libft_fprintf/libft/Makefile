# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:58:20 by jfranco           #+#    #+#              #
#    Updated: 2025/03/26 15:44:46 by jfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atol.c ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
       ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
       ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
       ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c 

OBJ_DIR = obj
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)
	@echo "\033[38;5;213m(っ◔◡◔)っ ♥ Ecole 19 | philo | Julie ♥\033[0m"

# Create the object directory before compiling
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile the program (only generate the static library)
$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Libreria statica creata: $(NAME)"

# Rule to compile .c into .o
$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects
clean:
	rm -rf $(OBJ_DIR)
	@echo "File oggetto rimossi."

# Clean everything (objects and executable)
fclean: clean
	rm -f $(NAME)
	@echo "Libreria statica rimosso."

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
