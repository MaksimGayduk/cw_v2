/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:21:09 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/28 18:24:00 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void draw_cordinates(WINDOW *a_win)
{
	size_t	i;

	wmove(a_win, 2, X_PADDING);

	wattron(a_win, COLOR_PAIR(1));
	i = 0;
	while (i < NC_RAW_SIZE)
		wprintw(a_win, "%02hhi ", i++);
	i = 0;
	wmove(a_win, 3, X_PADDING);
	while (i++ < NC_RAW_SIZE * 3 - 1)
		wprintw(a_win, "-");
	i = 4;
	while (i < NC_RAW_SIZE + 4)
	{
		mvwprintw(a_win, i, 2, "%02hhi |", i - 4);
		i++;
	}
	wrefresh(a_win);
	wattroff(a_win, COLOR_PAIR(1));
}

int		cursor_on_pc(t_data *data, size_t cursor)
{
	t_list *track;

	track = data->processes;
	while (track)
	{
		if (PC(track) == cursor)
			return (1);
		track = track->next;
	}
	return (0);
}


void 	draw_arena(t_data *data, WINDOW *a_win)
{
	size_t	i;
	int		y;
	int		x;

	wmove(a_win, 4, X_PADDING);
	i = 0;
	while (i < MEM_SIZE)
	{
		if (cursor_on_pc(data, i))
			wattron(a_win, COLOR_PAIR(2));
		wprintw(a_win, "%02hhx", data->arena[i]);
		wattroff(a_win, COLOR_PAIR(2));
		wprintw(a_win, " ");
		i++;
		if (i % NC_RAW_SIZE == 0)
		{
			getyx(a_win, y, x);
			wmove(a_win, y + 1, X_PADDING);
		}
	}
	wrefresh(a_win);
}

void	render_arena(t_data *data, t_ren *ren_data)
{
	WINDOW *a_win;

	a_win = ren_data->arena_win;
	if (!a_win)
		a_win = create_new_window(ARENA_WIN_HEIGHT, ARENA_WIN_WIDTH, 0, 0);
	
	draw_cordinates(a_win);
	draw_arena(data, a_win);
}