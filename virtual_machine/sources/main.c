/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:12:55 by mgayduk           #+#    #+#             */
/*   Updated: 2018/06/17 12:37:25 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		print_usage();
	ft_bzero(&data, sizeof(t_data));
	parse_input_params(&data, ++argv);
	init_players(&data);
	if (!data.players_qty)
		error_msg("No players were specified", NULL);
	init_processes(&data);
	init_arena(&data);
	if (data.input_params.v)
		render_game(&data);
	else
	{
		introduce_players(&data);
		while (play_corewar(&data))
			;
		announce_the_winner(&data);
	}
	return (0);
}