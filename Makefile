# Nome dell'eseguibile
NAME = cube3D

# Compiler e flag
CC = cc
CFLAGS = -g3 -Ofast  -Wall -Wextra #-Werror -Iminilibx -Isrc

# Colori
GREEN = \033[38;5;82m
PINK = \033[38;5;213m
RESET = \033[0m

# Directory sorgenti e oggetti
SRCDIR = src
OBJ_DIR = obj

# File sorgente
SRCS =  $(SRCDIR)/GNL/get_next_line.c \
        $(SRCDIR)/parsing/proccess_parsing.c \
        $(SRCDIR)/parsing/parsing_utilis.c \
		$(SRCDIR)/parsing/flood_fill_algo.c \
        $(SRCDIR)/parsing/intern_process.c \
        $(SRCDIR)/parsing/add_color.c \
		$(SRCDIR)/parsing/parsing_control_map.c \
		$(SRCDIR)/parsing/controll_fill.c \
        $(SRCDIR)/clean_up_and_error/clean_err.c \
		$(SRCDIR)/clean_up_and_error/ft_db_array.c \
		$(SRCDIR)/init_mlx_and_hook/mlx_init_ptr.c \
		$(SRCDIR)/rendering/calculs.c \
		$(SRCDIR)/rendering/moves.c \
		$(SRCDIR)/rendering/player.c \
		$(SRCDIR)/rendering/raycasting.c \
		$(SRCDIR)/rendering/render.c \
		$(SRCDIR)/rendering/textures.c \
		$(SRCDIR)/rendering/texture_utils.c \
        $(SRCDIR)/main.c

# Creazione degli oggetti (o) a partire dai sorgenti
OBJ = $(SRCS:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)

# MiniLibX paths
MINILIBX_DIR = ./minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
MINILIBX_LIB = -L$(MINILIBX_DIR) -lmlx
MINILIBX_INCLUDE = -I$(MINILIBX_DIR)

# Libft path
LIBFT_DIR = libft_fprintf/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Fprintf path
FPRINTF_DIR = libft_fprintf/ftprintf
FPRINTF = $(FPRINTF_DIR)/libftfprintf.a

# Librerie da linkare
LIBS = $(MINILIBX_LIB) -lmlx_Linux \
       $(LIBFT) $(FPRINTF) \
       -L/usr/lib -lXext -lX11 -lm -lz

# Header ASCII art (opzionale)
define HEADER
	\033[38;5;213m

    .::           .::                         .:::::
 .::   .::        .::                .:: .::  .::   .::
.::       .::  .::.::         .::        .::  .::    .::
.::       .::  .::.:: .::   .:   .::  .::     .::    .::
.::       .::  .::.::   .::.::::: .::    ::.  .::    .::
 .::   .::.::  .::.::   .::.:             :::..::   .::
   .::::    .::.::.:: .::    .::::   .::::::  .:::::

    
	\033[0m
endef
export HEADER

# Compilation principale
all: $(NAME)
	@echo "$$HEADER"
	@echo "$(PINK)Cube 3D compilato con successo! $(RESET)"

# Regola per compilare il programma
$(NAME): $(LIBFT) $(FPRINTF) $(MINILIBX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

# Creazione della directory obj e compilazione degli oggetti
$(OBJ_DIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Regola per compilare libft
$(LIBFT):
	@echo -n "Compiling Libft... ["
	@for i in 1 2 3 4 5 6 7 8 9 10; do \
		echo -n "$(GREEN)♥$(RESET)"; \
		sleep 0.1; \
		done
	@echo "] Done."
	@$(MAKE) -C $(LIBFT_DIR) --silent

# Regola per compilare fprintf
$(FPRINTF):
	@echo -n "Compiling Printf... ["
	@for i in 1 2 3 4 5 6 7 8 9 10; do \
		echo -n "$(GREEN)♥$(RESET)"; \
		sleep 0.1; \
		done
	@echo "] Done."
	@$(MAKE) -C $(FPRINTF_DIR) --silent

# Regola per compilare minilibx
$(MINILIBX):
	@echo -n "Compiling MiniLibX... ["
	@for i in 1 2 3 4 5 6 7 8 9 10; do \
		echo -n "$(GREEN)♥$(RESET)"; \
		sleep 0.1; \
		done
	@echo "] Done."
	@$(MAKE) -C $(MINILIBX_DIR) --silent

# Pulizia oggetti
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(FPRINTF_DIR) clean --silent
	@$(MAKE) -C $(MINILIBX_DIR) clean --silent
	@echo "$(GREEN)Oggetti rimossi.$(RESET)"

# Pulizia totale
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@$(MAKE) -C $(FPRINTF_DIR) fclean --silent
	@echo "$(GREEN)Eseguibile e librerie rimosse.$(RESET)"

# Ricompilazione completa
re: fclean all

# Esecuzione del programma
run:
ifeq ($(wildcard $(NAME)),)
	$(MAKE) re
else
	$(MAKE) all
endif
	./$(NAME) cubmap/VALID_FILE_MAP/ALL_VALID2.cub

.PHONY: all clean fclean re run
