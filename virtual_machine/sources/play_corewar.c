/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:43:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/29 18:32:04 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Goes through each process. 
**	Reads instructions and it`s arguments then execute them.
** 	Compute delay and pc.
*/

void		compute_instructions(t_data *data)
{
	t_list *track;
	t_process *test;

	track = data->processes;
	while (track)
	{
		test = track->content;
		if (OPCODE(track) && DELAY(track) == 0)
		{
			parse_arguments(data, track->content);
			op_tab[OPCODE(track)].action(data, track->content);				
			if (OPCODE(track) != 9 || !CARRY(track))
				PC(track) = normalize_index(PC(track) + PADDING(track));
			ft_bzero(&GET_OPERATION(track), sizeof(t_oper));
			render_arena(data);
		}
		if (!OPCODE(track) && IS_OPCODE(PC_VAL(track)))
		{
			OPCODE(track) = PC_VAL(track);
			DELAY(track) = op_tab[OPCODE(track)].delay;
		}
		else if (!OPCODE(track) && !IS_OPCODE(PC_VAL(track)))
		{
			PC(track) = normalize_index(++PC(track));
			render_arena(data);
		}
			
		if (DELAY(track))
			DELAY(track)--;
		track = track->next;
	}		
}

/*
**	Reduce cycle_to_die.
*/

void	handle_cycle(t_data *data)
{
	data->counter = 0;
	if (data->total_lives >= NBR_LIVE)
	{
		data->cycle_to_die -= CYCLE_DELTA;
		data->live_checks = MAX_CHECKS;
	}
	else
		data->live_checks--;
	if (!data->live_checks)
	{
		data->cycle_to_die -= CYCLE_DELTA;
		data->live_checks = MAX_CHECKS;
	}
}

/*
**	Main cycle of corewar game.
*/
void	play_corewar(t_data *data)
{
		render_side_bar(data);
		if (data->cycle_to_die <= 0)
			announce_the_winner(data);
			//return (0);
		if (DUMPED && data->cycle == DUMP_VALUE)
			dump_arena(data);
		compute_instructions(data);
		if (data->counter == data->cycle_to_die)
		{
			if (!data->total_lives)
				announce_the_winner(data);
				//return (0);
			handle_cycle(data);
			kill_processes(data);
			set_lives_to_zero(data);
		}
		data->cycle++;
		data->counter++;
		//return (1);
}
