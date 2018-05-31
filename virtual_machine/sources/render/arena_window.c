/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:21:09 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/31 10:38:44 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
**	Draws horisontal and vertical coordinate bars.
*/
void		render_cordinates(WINDOW *a_win)
{
	size_t	i;

	wmove(a_win, ARENA_Y_PADDING - 2, ARENA_X_PADDING);

	wattron(a_win, COLOR_PAIR(43));
	i = 0;
	while (i < ARENA_RAW_SIZE)
		wprintw(a_win, "%02hhi ", i++);
	i = 0;
	wmove(a_win, ARENA_Y_PADDING - 1, ARENA_X_PADDING - 2);
	while (i++ < ARENA_RAW_SIZE * 3 + 1)
		wprintw(a_win, "-");
	i = ARENA_Y_PADDING;
	while (i < ARENA_RAW_SIZE + 4)
	{
		mvwprintw(a_win, i, ARENA_X_PADDING - 6, "%02hhi |", i - 4);
		i++;
	}
	wrefresh(a_win);
	wattroff(a_win, COLOR_PAIR(10));
}

/*
**	Draws arena data with necessary colors of players.
**	Color map array used to define color.
*/
void		render_arena(t_data *data)
{
	WINDOW	*a_win;
	size_t	i;
	int		y;
	int		x;
	int		c;

	a_win = data->render.arena_win;
	wmove(a_win, ARENA_Y_PADDING, ARENA_X_PADDING);
	i = 0;
	while (i < MEM_SIZE)
	{
		if (data->render.pc_map[i])
			c = data->render.color_map[i] + 4;
		else
			c = data->render.color_map[i];
		wattron(a_win, COLOR_PAIR(c));
		wprintw(a_win, "%02hhx", data->arena[i]);
		wattroff(a_win, COLOR_PAIR(c));
		wprintw(a_win, " ");
		i++;
		if (i % ARENA_RAW_SIZE == 0)
		{
			getyx(a_win, y, x);
			wmove(a_win, y + 1, ARENA_X_PADDING);
		}
	}
	wrefresh(a_win);
}


/*
**	Renders arena data.
*/
void	render_arena_win(t_data *data)
{
	if (!data->render.arena_win)
		data->render.arena_win = create_new_window(ARENA_WIN_HEIGHT, ARENA_WIN_WIDTH,
													ARENA_Y_OFFSET, ARENA_X_OFFSET);
	render_cordinates(data->render.arena_win);
	render_arena(data);
}