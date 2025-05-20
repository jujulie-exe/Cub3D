# Nome dell'eseguibile
NAME = cube3D

# Compiler e flag
CC = cc
CFLAGS = -g3 -O1 -Wall -Wextra  -Iminilibx -Isrc #-Werror

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
		$(SRCDIR)/debug_and_test/testmoves.c \
		$(SRCDIR)/debug_and_test/testcalculs.c \
		$(SRCDIR)/rendering/player.c \
		$(SRCDIR)/rendering/raycasting.c \
		$(SRCDIR)/debug_and_test/testrender.c \
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

# File render alternativi per i test
RENDER_TEST_SRC = 	$(SRCDIR)/debug_and_test/testrender.c \
					$(SRCDIR)/debug_and_test/testrender.c \
					$(SRCDIR)/debug_and_test/testmoves.c

# Escludi i render originali per il test
SRC_NO_RENDER = $(filter-out $(EXCLUDE), $(SRC))


EXCLUDE = 	$(SRCDIR)/rendering/calculs.c \
            $(SRCDIR)/rendering/moves.c \
			$(SRCDIR)/rendering/render.c 

# File usati nel test: tutti tranne i render originali, più i nuovi render
TEST_SRC = $(SRC_NO_RENDER) $(RENDER_TEST_SRC)

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
	@echo "$(PINK)Cube 3D compiled successfully!$(RESET)"

# Regola per compilare il programma
$(NAME): $(LIBFT) $(FPRINTF) $(MINILIBX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

# Regola per compilare il programma test

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
	@echo "$(GREEN)Objects removed.$(RESET)"

# Pulizia totale
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@$(MAKE) -C $(FPRINTF_DIR) fclean --silent
	@echo "$(GREEN)Executable and libraries removed.$(RESET)"

# Ricompilazione completa
re: fclean all

# Esecuzione del programma
run: re
	./$(NAME) cubmap/VALID_FILE_MAP/ALL_VALID2.cub

test: re
	@echo "Compilazione in modalità test con TEST_SRC:"
	@echo "$(TEST_SRC)"
	$(MAKE) all SRC="$(TEST_SRC)" OBJ="$(TEST_SRC:.c=.o)" OUTNAME="test_program"


	

.PHONY: all clean fclean re run
