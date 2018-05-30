/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:22:40 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/30 15:53:13 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <inttypes.h>
# include <ncurses.h>

# include "libft.h"
# include "constants.h"

typedef char	t_byte;

# define BUFF_SIZE 16
# define DUMP_SIZE 32

# define IS_OPCODE(x) (x > 0 && x <= OPER_QTY - 2) ? 1 : 0

/*
**	Defines for data access simplification
*/

// process block
# define GET_PROCESS(x)		((t_process *)x->content)
# define PC(x)				GET_PROCESS(x)->pc
# define PC_VAL(x)			data->arena[PC(x)]
# define CARRY(x)			GET_PROCESS(x)->carry
# define SET_CARRY(x, v)	x->carry = !REGISTER_VALUE(process, reg_num)
# define PADDING(x)			GET_PROCESS(x)->padding
# define LIVE(x)			GET_PROCESS(x)->live

// Operation block
# define GET_OPERATION(x)	GET_PROCESS(x)->oper
# define DELAY(x)			GET_OPERATION(x).delay
# define OPCODE(x)			GET_OPERATION(x).op_code


// Arguments block
# define GET_ARGUMENT(x, v)		x->oper.args[v]
# define VALUE(x, v)			GET_ARGUMENT(x, v).val
# define VALUE_IDX(x, v)		GET_ARGUMENT(x, v).val_idx
# define REG_NUM(x, v)			GET_ARGUMENT(x, v).reg_num
# define OFFSET(x, v)			GET_ARGUMENT(x, v).offset
# define SIZE(x, v)				GET_ARGUMENT(x, v).size
# define TYPE(x, v)				GET_ARGUMENT(x, v).type
# define USED(x, v)				GET_ARGUMENT(x, v).used



//# define REGISTER(x, v)			x->registers[v].reg[v]
# define REGISTER_VALUE(x, v)	get_int_number(x->registers[v])
# define INCORRECT_REG_NUM(x)	x < 1 || x > REG_NUMBER ? 1 : 0

# define GET_PLAYER_INFO(x)	data->input_params.players_info[x]
# define GET_FILE_PATH(x)	data->input_params.players_info[x].file_path
# define GET_SIGNATURE(x)	data->input_params.players_info[x].signature

# define DUMPED				data->input_params.dump
# define DUMP_VALUE 		data->input_params.dump_value

# define MEM_ERROR "memory allocation failed" 


/*
**	The structure that represents a player.
**	Such as register in byte code have numbers from 1 to REG_NUMBER,
**	reg[0] is empty and won`t be used.
**	It`s simplifies the access to registers
*/

typedef struct	s_player
{
	t_byte		magic[MAGIC_LENGTH];
	t_byte 		name[PROG_NAME_LENGTH + 1];
	t_byte		size[SIZE_LENGTH];
	t_byte		comment[COMMENT_LENGTH + 1];
	t_byte		*exec_code;
	size_t		exec_code_size;
	size_t		file_size;
	int			signature;
	int			number;
	size_t		live;
	size_t		last_live;
}				t_player;

typedef struct	s_arg
{
	t_byte		val[REG_SIZE];
	t_byte		val_idx[REG_SIZE];
	t_byte		type;
	short		reg_num;
	int			offset;
	int			size;
	t_byte		used;
}				t_arg;

typedef	struct	s_oper
{
	int			op_code;
	size_t		delay;
	t_arg		args[3];
}				t_oper;

typedef struct	s_process
{
	size_t		pc;
	size_t		padding;
	size_t		live;
	t_byte		dead;
	t_byte		carry;
	t_oper		oper;
	t_byte		registers[REG_NUMBER + 1][REG_SIZE];
}				t_process;

typedef	struct	s_info
{
	char		*file_path;
	int			signature;
	t_byte		used;
}				t_info;

typedef	struct	s_params
{
	t_byte		v;
	t_byte		dump;
	int			dump_value;
	t_info		players_info[MAX_PLAYERS];
}				t_params;

typedef	struct	s_ren
{
				t_byte	color_map[MEM_SIZE];
				WINDOW	*main_win;
				WINDOW	*arena_win;
				WINDOW	*side_win;
				WINDOW	*speed_win;
				int		speed;
				t_byte	paused;
				WINDOW	*cycle_win;
				WINDOW	*player_win;
				WINDOW	*param_win;
}				t_ren;

typedef struct	s_data
{
	t_byte		arena[MEM_SIZE];
	size_t		players_qty;
	t_player	players[MAX_PLAYERS];
	size_t		process_qty;
	t_list		*processes;
	int			cycle;
	int			counter;
	size_t		live_checks;
	size_t		total_lives;
	int			cycle_to_die;
	t_params	input_params;
	t_ren		render;
}				t_data;

# include		"render.h"
# include 		"operations.h"


void			parse_input_params(t_data *data, char **argv);
void			init_players(t_data *data);
void			init_processes(t_data *data);
void			init_arena(t_data *data);
void			parse_arguments(t_data *data, t_process *process);

void    		play_corewar(t_data *data);
void			handle_cycle(t_data *data);
void			compute_instructions(t_data *data);
void			kill_processes(t_data *data);

/*
** 	arena_funcs.c
*/
t_byte			*read_arena_chunk(t_data *data, t_byte *dest, int start, size_t n);
void			write_arena_chunk(t_data *data, t_byte *src, int start, size_t n);
void 			set_lives_to_zero(t_data *data);


/*
**	game_funcs.c
*/
void			announce_the_winner(t_data *data);
void			introduce_players(t_data *data);

/*
** helpers.c
*/
void			error_msg(char *msg, char *arg);
void			*reverse_array(void *arr, size_t arr_size);
void			dump_arena(t_data *data);

/*
**	number_funcs.c
*/
int				get_number(void *arr, int size);
int				get_int_number(void *arr);
short 			get_short_number(void *arr);
int				normalize_index(int index);

#endif