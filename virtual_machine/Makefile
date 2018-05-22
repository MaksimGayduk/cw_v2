# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/27 16:20:32 by mgayduk           #+#    #+#              #
#    Updated: 2018/05/22 21:43:28 by maks             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

# Directories
SRC_DIR := ./sources
OPER_DIR := $(SRC_DIR)/operations
OBJ_DIR := ./objects
INC_DIR := ./includes ./libft/includes
LFT_DIR := ./libft

# Source files
SRC :=	main.c					\
		helpers.c				\
		parse_input_params.c	\
		init_players.c			\
		init_processes.c		\
		init_arena.c			\
		number_funcs.c
		# play_corewar.c 			\
		# parse_arguments.c 		\
		# kill_cursors.c
		

# OPER := oper_tab.c		\
#  		oper_01_live.c	\
# 		oper_02_ld.c	\
# 		oper_03_st.c	\
# 		oper_04_add.c	\
# 		oper_05_sub.c	\
# 		oper_06_and.c	\
# 		oper_07_or.c	\
# 		oper_08_xor.c	\
# 		oper_09_zjmp.c	\
# 		oper_10_ldi.c	\
# 		oper_11_sti.c	\
# 		oper_12_fork.c	\
# 		oper_13_lld.c	\
# 		oper_14_lldi.c	\
# 		oper_15_lfork.c \
# 		oper_16_aff.c 

SRC := $(SRC) $(OPER)

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := libft.a

.PHONY = all clean fclean re


all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_DIR) all
	$(CC) $(FLAGS) $(OBJ) $(LFT_DIR)/$(LFT) $(INC) -o $(NAME)


VPATH := $(SRC_DIR) $(OPER_DIR)

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
