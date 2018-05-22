/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_01_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:22:48 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 12:53:19 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
**	The instruction that allows a process to stay alive.
**	It can also record that the player whose number is the argument
**	is indeed alive.
*/

int	is_player_num(t_data *data, size_t c_num)
{
	int	i;
	int	arg;

	arg = GET_REV_NUMBER(GET_VALUE(c_num, 0), REG_SIZE);
	i = 0;
	while (i < (int)data->players_qty)
	{
		if (data->players[i].signature == arg)
			return (i);
		i++;
	}
	return (-42);
}

void	live(t_data *data, size_t c_num)
{
	t_cursor	*test;
	int			p_num;

	test = &data->cursors[c_num];
	if ((p_num = is_player_num(data, c_num)) != -42)
	{
		data->players[p_num].live++;
		data->players[p_num].last_live = data->cycle;
	}	
	data->cursors[c_num].live++;
	data->total_lives++;
}