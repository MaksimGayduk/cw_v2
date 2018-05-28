/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:26:35 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/28 12:36:57 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	introduce_players(t_data *data)
{
	size_t i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < data->players_qty)
	{
		ft_printf("* Player %i, weighing %u bytes, \"%s\" (\"%s\") !\n",
					data->players[i].signature,
					data->players[i].exec_code_size,
					data->players[i].name,
					data->players[i].comment);
		i++;
	}
}


/*
**	Determinates which player sad live last.
**	Writes message who is winner.
*/

void	announce_the_winner(t_data *data)
{
	size_t	i;
	size_t	p_num;

	i = 1;
	p_num = 0;
	while (i < data->players_qty)
	{
		if (data->players[i].last_live > data->players[p_num].last_live)
			p_num = i;
		i++;
	}
	ft_printf("Contestant %d, \" %s \", has won !\n",
				data->players[p_num].signature,
				data->players[p_num].name);
	ft_printf("The game end on %d cycle\n", data->cycle);
	exit(1);
}