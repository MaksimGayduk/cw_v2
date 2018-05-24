/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:43:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/24 08:50:17 by maks             ###   ########.fr       */
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
inline static void		compute_instructions(t_data *data)
{
	t_list *track;
	t_process *test;

	track = data->processes;
	if (data->cycle == 5982)
		ft_printf("%u\n", data->cycle);
	while (track)
	{
		test = track->content;
		if (OPCODE(track) && DELAY(track) == 0)
		{
			parse_arguments(data, track->content);
			test = data->processes->content;
			op_tab[OPCODE(track)].action(data, track->content);
			test = data->processes->content;				
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


void set_lives_to_zero(t_data *data)
{
	t_list	*track;
	size_t	i;

	data->total_lives = 0;
	i = 0;
	while (i < data->players_qty)
		data->players[i++].live = 0;
	track = data->processes;
	while (track)
	{
		LIVE(track) = 0;
		track = track->next;
	}			
}

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

void	play_corewar(t_data *data)
{
	while (1)
	{	
		// if (data->total_lives > 0)
		// 	ft_printf("%u\n", data->cycle);
		if (data->cycle_to_die <= 0)
			announce_the_winner(data);
		// if (DUMPED && data->cycle == DUMP_VALUE)
		// 	dump_arena(data);
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
