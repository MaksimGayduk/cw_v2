/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:50:38 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/29 17:10:14 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

WINDOW	*create_new_window(int height, int width, int start_y, int start_x)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, start_y, start_x);
	refresh();
	wattron(local_win, COLOR_PAIR(42) | A_DIM);
	box(local_win, BORDER_VER , BORDER_HOR);
	wattroff(local_win, COLOR_PAIR(42) | A_DIM);
	wrefresh(local_win);
	return (local_win);
}

void	init_colors(void)
{
	if (has_colors() == FALSE) 
	{
    	endwin();
    	ft_printf("Your terminal does not support color\n");
    	exit(1);
	}
	start_color();
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(41, COLOR_RED, COLOR_BLACK);
	init_pair(42, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(43, COLOR_MAGENTA, COLOR_BLACK);
}

int render_game(t_data *data)
{

	data->render.main_win = initscr();
	curs_set(0);
	init_colors();
	
	//render_arena(data);
	//render_side_bar(data);
	
	//getch();
	delwin(data->render.arena_win);
	delwin(data->render.side_win);
	endwin();
	return (0);
}