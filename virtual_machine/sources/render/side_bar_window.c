/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_bar_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:20:20 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/31 11:54:53 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"


void	render_speed_data(t_data *data)
{
	WINDOW			*speed_win;

	if (!data->render.speed_win)
	{
		data->render.speed_win = subwin(data->render.side_win,
								SPEED_WIN_HEIGHT, SPEED_WIN_WIDTH,
								SPEED_Y_OFFSET, SPEED_X_OFFSET);
		wrefresh(data->render.side_win);
	}
	speed_win = data->render.speed_win;
	if (data->render.paused) mvwprintw(speed_win, 0, 0, "** PAUSED ** ");
	if (!data->render.paused) mvwprintw(speed_win, 0, 0, "** RUNNING **");

	mvwprintw(speed_win, 2, 0, "Max Speed: %4i cycle/second",
				data->render.speed);

	touchwin(speed_win);
	wrefresh(speed_win);
}

void	render_cycle_data(t_data *data)
{
	WINDOW			*cycle_win;

	if (!data->render.cycle_win)
	{
		data->render.cycle_win = subwin(data->render.side_win,
										CYCLE_WIN_HEIGHT, CYCLE_WIN_WIDTH,
										CYCLE_Y_OFFSET, CYCLE_X_OFFSET);
		wrefresh(data->render.side_win);
	}
	cycle_win = data->render.cycle_win;
	mvwprintw(cycle_win, 0, 0, "Cycle:\t\t%zu", data->cycle);
	mvwprintw(cycle_win, 2, 0, "Processes:\t%zu", data->process_qty);
	touchwin(cycle_win);
	wrefresh(cycle_win);
}

void render_players_data(t_data *data)
{
	size_t	i;
	WINDOW	*player_win;

	if (!data->render.player_win)
	{
		data->render.player_win = subwin(data->render.side_win,
										PLAYER_WIN_HEIGHT, PLAYER_WIN_WIDTH,
										PLAYER_Y_OFFSET, PLAYER_X_OFFSET);
		wrefresh(data->render.side_win);
	}
	player_win = data->render.player_win;

	i = 0;
	while (i < data->players_qty)
	{
		mvwprintw(player_win, i * 4, 0, "Player %i: ", data->players[i].signature);
		wattron(player_win, COLOR_PAIR(i + 1));
		wprintw(player_win, "%s", data->players[i].name);
		wattroff(player_win, COLOR_PAIR(i + 1));
		mvwprintw(player_win, i * 4 + 1, 4, "Last live:\t\t\t%i", data->players[i].last_live);
		mvwprintw(player_win, i * 4 + 2, 4, "Lives in current period:\t%i",
				data->players[i].live);
		i++;
	}
	touchwin(player_win);
	wrefresh(player_win);
}

void	render_parameters(t_data *data)
{
	WINDOW	*param_win;

	if (!data->render.param_win)
	{
		data->render.param_win = subwin(data->render.side_win,
										PARAM_WIN_HEIGHT, PARAM_WIN_WIDTH,
										PARAM_Y_OFFSET, PARAM_X_OFFSET);
		wrefresh(data->render.side_win);
	}
	param_win = data->render.param_win;
	mvwprintw(param_win, 0, 0, "CYCLE_TO_DIE:\t%4i", data->cycle_to_die);
	mvwprintw(param_win, 2, 0, "CYCLE_DELTA:\t%i", CYCLE_DELTA);
	mvwprintw(param_win, 4, 0, "NBR_LIVE:\t%i", NBR_LIVE);
	mvwprintw(param_win, 6, 0, "MAX_CHECKS:\t%i", MAX_CHECKS);
	
	touchwin(param_win);
	wrefresh(param_win);
}

void		render_side_bar(t_data *data)
{

	if (!data->render.side_win)
		data->render.side_win = create_new_window(SIDE_WIN_HEIGHT, SIDE_WIN_WIDTH,
													SIDE_Y_OFFSET, SIDE_X_OFFSET);
	wattron(data->render.side_win, A_BOLD);
	render_speed_data(data);
	render_cycle_data(data);
	render_players_data(data);  
	render_parameters(data);
	wattroff(data->render.side_win, A_BOLD);
	wrefresh(data->render.side_win);
}