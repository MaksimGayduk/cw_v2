/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:50:38 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/31 13:43:11 by mgayduk          ###   ########.fr       */
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
	render_arena_win(data);
	set_speed(data);
}

int render_game(t_data *data)
{
	int i;
	int c;

	init_start_window(data);
	i = 0;
	while (1)
	{
		i++;
		timeout(1000 / (data->render.speed));
		if ((c = getch()) == ' ')
			set_speed(data);
		if (!play_corewar(data))
			break ;
		if ((data->render.speed > 900 && i % 16) ||
			(data->render.speed > 750 && i % 8) ||
			(data->render.speed > 500 && i % 4) ||
			(data->render.speed > 100 && i % 2))
			continue;	
		render_side_bar(data);
		render_arena(data);
	}
	delwin(data->render.arena_win);
	delwin(data->render.side_win);
	endwin();
	return (0);
}