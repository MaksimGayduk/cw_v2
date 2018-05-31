/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:43:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/31 12:36:34 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	compute_pc(t_data *data, t_list *track, int steps)
{
	data->render.pc_map[PC(track)]--;
	PC(track) = normalize_index(PC(track) + steps);
	data->render.pc_map[PC(track)]++;
}


void	execute_instruction(t_data *data, t_list *track)
{
	parse_arguments(data, track->content);
	op_tab[OPCODE(track)].action(data, track->content);				
	if (OPCODE(track) != 9 || !CARRY(track))
		compute_pc(data, track, PADDING(track));
	ft_bzero(&GET_OPERATION(track), sizeof(t_oper));
}

/*
**	Goes through each process. 
**	Reads instructions and it`s arguments then execute them.
** 	Compute delay and pc.
*/
inline void		compute_instructions(t_data *data)
{
	t_list 		*track;

	track = data->processes;
	while (track)
	{
		if (OPCODE(track) && DELAY(track) == 0)
			execute_instruction(data, track);
		if (!OPCODE(track) && IS_OPCODE(PC_VAL(track)))
		{
			OPCODE(track) = PC_VAL(track);
			DELAY(track) = op_tab[OPCODE(track)].delay;
		}
		else if (!OPCODE(track) && !IS_OPCODE(PC_VAL(track)))
			compute_pc(data, track, 1);		
		if (DELAY(track))
			DELAY(track)--;
		track = track->next;
	}		
}

/*
**	Reduce cycle_to_die.
*/
inline void	handle_cycle(t_data *data)
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
inline int	play_corewar(t_data *data)
{
		if (data->cycle_to_die <= 0)
			return (0);
		if (DUMPED && data->cycle == DUMP_VALUE && !V_FLAG)
			dump_arena(data);
		compute_instructions(data);
		if (data->counter == data->cycle_to_die)
		{
			if (!data->total_lives)
				return (0);
			handle_cycle(data);
			kill_processes(data);
			set_lives_to_zero(data);
		}
		data->cycle++;
		data->counter++;
		return (1);
}
