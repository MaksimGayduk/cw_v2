/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:51:27 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/29 12:01:38 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "corewar.h"
# include <ncurses.h>

# define	BORDER_VER	42
# define	BORDER_HOR	42

# define	ARENA_RAW_SIZE 		64
# define 	ARENA_WIN_HEIGHT	70
# define	ARENA_WIN_WIDTH		210
# define	ARENA_Y_PADDING			4
# define 	ARENA_X_PADDING 			10

typedef	struct	s_ren
{
				WINDOW	*main_win;
				WINDOW	*arena_win;
				WINDOW	*side_win;
}				t_ren;

int		render_game(t_data *data);
WINDOW	*create_new_window(int height, int width, int start_y, int start_x);
void	render_arena(t_data *data, t_ren *ren_data);

#endif