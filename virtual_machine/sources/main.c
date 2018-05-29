/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:12:55 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/29 17:09:47 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		error_msg("no input parameters", NULL);
	ft_bzero(&data, sizeof(t_data));
	parse_input_params(&data, ++argv);
	init_players(&data);
	init_processes(&data);
	init_arena(&data);
	introduce_players(&data);
	
	render_game(&data);
	render_arena(&data);
	render_side_bar(&data);

	play_corewar(&data);


	delwin(data.render.arena_win);
	delwin(data.render.side_win);
	return (0);
}