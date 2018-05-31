/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:50:36 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/31 10:58:26 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_colors(void)
{
	if (!has_colors()) 
	{
    	endwin();
    	error_msg("Your terminal does not support color", NULL);	
	}
	start_color();
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);

	init_pair(42, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(43, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(47, COLOR_BLACK, COLOR_MAGENTA);
}

void	update_color_map(t_data *data, size_t src, int start, size_t n)
{
	size_t	i;
	int		index;
	int		parent_color;

	parent_color = data->render.color_map[src];
	i = 0;
	while (i < n)
	{
		index = normalize_index(start);
		data->render.color_map[index] = parent_color;
		start++;
		i++;
	}
}