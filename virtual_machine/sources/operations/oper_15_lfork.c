/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_15_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:08:36 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 11:55:26 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Creates new cursor.
**	Copies carry and registers of parent.
**	Puts new cursor on new pc, wich is input argument;
*/

void	lfork_cor(t_data *data, size_t c_num)
{
	t_cursor new;
	short	pc;

	new = data->cursors[c_num];
	ft_bzero(&(new.oper), sizeof(t_oper));
	pc = 	GET_PC(c_num) + GET_REV_NUMBER(GET_VALUE(c_num, 0),
			GET_SIZE(c_num, 0));
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
	data->curs_qty++;
}