/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_12_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:08:36 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 16:20:30 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	let_new_cursor_play(t_data *data, size_t c_num)
{
	if (IS_OPCODE(GET_PC_VAL(c_num)))
	{
		GET_OPCODE(c_num) = GET_PC_VAL(c_num);
		GET_OPERATION(c_num).delay = op_tab[GET_OPCODE(c_num)].delay - 1;
		parse_arguments(data, c_num);
	}
}

/*
**	Creates new cursor.
**	Copies carry and registers of parent.
**	Puts new cursor on new pc, wich is input argument;
*/

void	fork_cor(t_data *data, size_t c_num)
{
	t_cursor *test;
	t_cursor new;
	short	pc;

	new = data->cursors[c_num];
	ft_bzero(&(new.oper), sizeof(t_oper));
	pc = 	GET_PC(c_num) + GET_REV_NUMBER(GET_VALUE(c_num, 0),
			GET_SIZE(c_num, 0));
	pc %= IDX_MOD;
	pc %= MEM_SIZE;
	if (pc < 0)
		pc += MEM_SIZE;
	new.pc = pc;
	data->cursors = (t_cursor *)realloc(data->cursors,
								sizeof(t_cursor) * (data->curs_qty + 1));
	if (!data->cursors)
		error_msg(MEM_ERROR);
	data->cursors[data->curs_qty] = new;
	let_new_cursor_play(data, data->curs_qty);
	test = &data->cursors[data->curs_qty];
	data->curs_qty++;
}