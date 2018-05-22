/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 10:46:50 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 17:23:10 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Allocates mamory for processes.
** Computes inital pc for processes.
** Sets player`s signature to the first register.
*/

void	init_processes(t_data *data)
{
	size_t		i;
	t_process	process;
	t_list		*new_node;

	data->curs_qty = data->players_qty;
	i = 0;
	while (i < data->curs_qty)
	{
		ft_bzero(&process, sizeof(t_process));
		process.pc = MEM_SIZE / data->players_qty * i;
		reverse_array(&GET_SIGNATURE(i), REG_SIZE);
		ft_memcpy(&process.reg[1], &GET_SIGNATURE(i), REG_SIZE);
		new_node = ft_lstnew(&process, sizeof(t_process));
		if (!data->processes)
			data->processes = new_node;
		else
			ft_lstadd(&data->processes, new_node);
		i++;
	}
}