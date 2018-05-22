/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:43:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 16:13:26 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


inline static void		compute_instructions(t_data *data)
{
	int i;
	t_cursor *test;

	i = data->curs_qty - 1;
	if (data->cycle == 2055)
		ft_printf("stop\n");
	while (i > -1)
	{
		test = &data->cursors[i];
		if (GET_OPCODE(i) && GET_OPERATION(i).delay == 0)
		{
			parse_arguments(data, i);
			op_tab[GET_OPCODE(i)].action(data, i);					
			if (GET_OPCODE(i) != 9 || !GET_CARRY(i))
				GET_PC(i) += GET_PADDING(i);
			ft_bzero(&GET_OPERATION(i), sizeof(t_oper));
		}
		if (!GET_OPCODE(i) && IS_OPCODE(GET_PC_VAL(i)))
		{
			GET_OPCODE(i) = GET_PC_VAL(i);
			GET_OPERATION(i).delay = op_tab[GET_OPCODE(i)].delay;
		}
		else if (!GET_OPERATION(i).op_code && !IS_OPCODE(GET_PC_VAL(i)))
			GET_PC(i)++;
		GET_OPERATION(i).delay--;
		i--;
	}		
}


static void set_lives_zero(t_data *data)
{
	size_t i;

	data->total_lives = 0;
	i = 0;
	while (i < data->players_qty)
		data->players[i++].live = 0;
	i = 0;
	while (i < data->curs_qty)
		data->cursors[i++].live = 0;			
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
	kill_cursors(data);
	set_lives_zero(data);
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
	ft_printf("Contestant %d, %s, has won !\n",
				data->players[p_num].signature,
				data->players[p_num].name);
	ft_printf("The game end on %d cycle\n", data->cycle);
	exit(1);
}

void	play_corewar(t_data *data)
{
	while (1)
	{	
		// if (data->cycle == 976)
		// 	ft_printf("asd");
		
		// if (data->cur_temp != data->cursors)
		// 	ft_printf("asd");
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
		}
		ft_printf("%u\n", data->cycle);
		data->cycle++;
		data->counter++;
	}
}
