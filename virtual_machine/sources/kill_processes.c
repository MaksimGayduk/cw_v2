/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:48:39 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/30 16:44:40 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Counts alive processes and returns it. 
*/

static size_t	count_live_processes(t_data *data)
{
	t_process *test;

	size_t alive;
	t_list *track;

	alive = 0;
	track = data->processes;
	while (track)
	{
		test = track->content;
		if (LIVE(track))
			alive++;
		track = track->next;
	}
	return (alive);
}


static void		delete_from_beginnig(t_list **head, t_list **track)
{
	*head = (*head)->next;
	free(*track);
	*track = *head;
}

static void		delete_process(t_list **track, t_list **overtake)
{
	(*overtake)->next = (*track)->next;
	free(*track);
	*track = (*overtake)->next;
}

void	delete_dead_processes(t_data *data)
{
	t_list	*track;
	t_list	*overtake;

	track = data->processes;
	while (track)
	{
		overtake = track;
		if (!LIVE(track) && track == data->processes)
		{
			delete_from_beginnig(&data->processes, &track);
			continue ;
		}
		track = track->next;
		if (track && !LIVE(track))
			delete_process(&track, &overtake);			
	}
}

/*
**	While each check, the process, wich is not alive (live == 0)
**	should be deleted from list of processes;
*/

void	kill_processes(t_data *data)
{
	size_t alive;

	alive = count_live_processes(data);
	if (alive == data->process_qty)
		return ;
	delete_dead_processes(data);
	data->process_qty = ft_lstlen(data->processes);
}