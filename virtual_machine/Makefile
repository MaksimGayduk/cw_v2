# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/27 16:20:32 by mgayduk           #+#    #+#              #
#    Updated: 2018/05/29 13:22:37 by mgayduk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

# Compiler
CC		= gcc
FLAGS	= -g -Wall -Wextra -Werror 

# Directories
SRC_DIR := ./sources
OPER_DIR := $(SRC_DIR)/operations
RENDER_DIR := $(SRC_DIR)/render
OBJ_DIR := ./objects
INC_DIR := ./includes ./libft/includes
LFT_DIR := ./libft

# Libs
LFT := $(LFT_DIR)/libft.a -lncurses

#includes
INC := $(addprefix -I, $(INC_DIR))

# Source files
SRC :=	main.c					\
		helpers.c				\
		parse_input_params.c	\
		init_players.c			\
		init_processes.c		\
		init_arena.c			\
		number_funcs.c			\
		arena_funcs.c 			\
		play_corewar.c 			\
		parse_arguments.c 		\
		kill_processes.c		\
		game_funcs.c
		

OPER := oper_tab.c		\
 		oper_01_live.c	\
		oper_02_ld.c	\
		oper_03_st.c	\
		oper_04_add.c	\
		oper_05_sub.c	\
		oper_06_and.c	\
		oper_07_or.c	\
		oper_08_xor.c	\
		oper_09_zjmp.c	\
		oper_10_ldi.c	\
		oper_11_sti.c	\
		oper_12_fork.c	\
		oper_13_lld.c	\
		oper_14_lldi.c	\
		oper_15_lfork.c \
		oper_16_aff.c 

VIS	:=	render_main.c		\
		arena_window.c		\
		side_bar_window.c 

SRC := $(SRC) $(OPER) $(VIS)

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

.PHONY = all clean fclean re


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_DIR) all
	$(CC) $(FLAGS) $(OBJ) $(LFT) $(INC) -o $(NAME)


VPATH := $(SRC_DIR) $(OPER_DIR) $(RENDER_DIR)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
	
clean:
	make -C $(LFT_DIR) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LFT_DIR)/$(LFT)
	rm -rf $(NAME)

re: fclean all
