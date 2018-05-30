/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:50:38 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/30 15:50:42 by mgayduk          ###   ########.fr       */
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
	
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);

	init_pair(42, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(43, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(47, COLOR_BLACK, COLOR_MAGENTA);
}

void	set_speed(t_data *data)
{
	int c;

	while ((c = getch()) != ' ')
	{
		data->render.paused = 1;;
		render_speed_data(data);
		if (c == 's') data->render.speed -= 100;
		if (c == 'q') data->render.speed -= 10;
		if (c == 'w') data->render.speed -= 1;
		if (c == 'e') data->render.speed += 1;
		if (c == 'r') data->render.speed += 10;
		if (c == 'd') data->render.speed += 100;
		if (data->render.speed < 1) data->render.speed = 1;
		if (data->render.speed > 1000) data->render.speed = 1000;
	}
	data->render.paused = !data->render.paused;
	render_speed_data(data);
}

void	init_start_window(t_data *data)
{
	data->render.main_win = initscr();
	curs_set(0);
	init_colors();
	noecho();
	data->render.speed = 50;
	data->render.paused = 1;
	render_side_bar(data);
	render_arena(data);
	set_speed(data);
}

int render_game(t_data *data)
{
	int c;
	while (1)
	{
		usleep(1000000 / data->render.speed);
		timeout(10);
		if ((c = getch()) == ' ')
			set_speed(data);
		render_arena(data);
		play_corewar(data);
		render_cycle_data(data);
	}
	delwin(data->render.arena_win);
	delwin(data->render.side_win);
	endwin();
	return (0);
}