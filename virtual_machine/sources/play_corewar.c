/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:43:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/24 18:53:54 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	test_process(t_list *head)
{
	t_process *process;

	while (head)
	{
		process = head->content;
		head = head->next;
	}
}

	// if (data->cycle == 5982)
	// 	ft_printf("%u\n", data->cycle);

/*
**	Goes through each process. 
**	Reads instructions and it`s arguments then execute them.
** 	Compute delay and pc.
*/

inline static void		compute_instructions(t_data *data)
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
		}
		if (!OPCODE(track) && IS_OPCODE(PC_VAL(track)))
		{
			OPCODE(track) = PC_VAL(track);
			DELAY(track) = op_tab[OPCODE(track)].delay;
		}
		else if (!OPCODE(track) && !IS_OPCODE(PC_VAL(track)))
			PC(track) = normalize_index(++PC(track));
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
	while (1)
	{	
		// if (data->total_lives > 0)
		// 	ft_printf("%u\n", data->cycle);
		if (data->cycle_to_die <= 0)
			announce_the_winner(data);
		if (DUMPED && data->cycle == DUMP_VALUE)
			dump_arena(data);
		compute_instructions(data);
		if (data->counter == data->cycle_to_die)
		{
			if (!data->total_lives)
				announce_the_winner(data);
			handle_cycle(data);
			kill_processes(data);
			set_lives_to_zero(data);
		}
		ft_printf("%u\n", data->cycle);
		data->cycle++;
		data->counter++;
	}
}
