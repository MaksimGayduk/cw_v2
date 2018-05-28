/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:50:38 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/28 18:15:47 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

WINDOW	*create_new_window(int height, int width, int start_y, int start_x)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, start_y, start_x);
	refresh();
	box(local_win, BORDER_VER , BORDER_HOR);
	wrefresh(local_win);
	return (local_win);
}

int render_game(t_data *data)
{
	static t_ren	ren_data;

	ren_data.main_win = initscr();

	//init_screen()
	
	curs_set(0);

	start_color();                 
    init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_RED);

	render_arena(data, &ren_data);
	
	getch();
	delwin(ren_data.arena_win);
	endwin();
	return (0);
}