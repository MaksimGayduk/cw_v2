/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:23:55 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 17:39:22 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Sets player`s execution code to arena.
*/

void	init_arena(t_data *data)
{
	t_list	*track;
	size_t	pc;
	size_t	i;
	char 	*exec_code;
	int		size;

	data->cycle_to_die = CYCLE_TO_DIE;
	data->live_checks = MAX_CHECKS;
	track = data->cursors;
	i = data->players_qty - 1;
	while (track)
	{
		pc = ((t_cursor *)track->content)->pc;
		exec_code = data->players[i].exec_code;
		size = GET_NUMBER(data->players[i].size);
		ft_memcpy(&(data->arena[pc]), exec_code, size);
		track = track->next;
		i--;
	}
}