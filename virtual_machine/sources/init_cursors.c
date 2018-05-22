/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cursors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 10:46:50 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 17:23:10 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Allocates mamory for cursors.
** Computes inital pc for cursors.
** Sets player`s signature to the first register.
*/

void	init_cursors(t_data *data)
{
	size_t		i;
	t_cursor	cursor;
	t_list		*new_node;

	data->curs_qty = data->players_qty;
	i = 0;
	while (i < data->curs_qty)
	{
		ft_bzero(&cursor, sizeof(t_cursor));
		cursor.pc = MEM_SIZE / data->players_qty * i;
		reverse_array(&GET_SIGNATURE(i), REG_SIZE);
		ft_memcpy(&cursor.reg[1], &GET_SIGNATURE(i), REG_SIZE);
		new_node = ft_lstnew(&cursor, sizeof(t_cursor));
		if (!data->cursors)
			data->cursors = new_node;
		else
			ft_lstadd(&data->cursors, new_node);
		i++;
	}
}