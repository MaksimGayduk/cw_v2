/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:12:55 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 20:48:06 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		error_msg("no input parameters");
	ft_bzero(&data, sizeof(t_data));
	parse_input_params(&data, ++argv);
	init_players(&data);
	init_processes(&data);
	init_arena(&data);
	// play_corewar(&data);
	return (0);
}