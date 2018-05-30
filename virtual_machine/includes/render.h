/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:51:27 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/30 15:46:35 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "corewar.h"

# define	BORDER_VER	42
# define	BORDER_HOR	42

/*
**	Definition of terms:
**	HEIGHT / WIDTH - dimensions of window
**	OFFSET - distance between zero coordinates of terminal and window
**	PADDING - distance between of border of window and its content
*/

# define	ARENA_RAW_SIZE 		64
# define 	ARENA_WIN_HEIGHT	70
# define	ARENA_WIN_WIDTH		205
# define	ARENA_Y_OFFSET		0
# define 	ARENA_X_OFFSET		0
# define	ARENA_Y_PADDING		4
# define 	ARENA_X_PADDING 	10

# define	SIDE_WIN_HEIGHT		ARENA_WIN_HEIGHT
# define	SIDE_WIN_WIDTH		50
# define	SIDE_Y_OFFSET		ARENA_Y_OFFSET
# define	SIDE_X_OFFSET		ARENA_WIN_WIDTH - 1
# define	SIDE_Y_PADDING		2
# define 	SIDE_X_PADDING 		5

# define	SPEED_WIN_HEIGHT	4
# define	SPEED_WIN_WIDTH		SIDE_WIN_WIDTH - SIDE_X_PADDING * 2
# define	SPEED_Y_OFFSET		SIDE_Y_OFFSET + SIDE_Y_PADDING
# define	SPEED_X_OFFSET		SIDE_X_OFFSET + SIDE_X_PADDING

# define	CYCLE_WIN_HEIGHT	4
# define	CYCLE_WIN_WIDTH		SIDE_WIN_WIDTH - SIDE_X_PADDING
# define	CYCLE_Y_OFFSET		SPEED_Y_OFFSET + SPEED_WIN_HEIGHT
# define	CYCLE_X_OFFSET		SIDE_X_OFFSET + SIDE_X_PADDING

# define	PLAYER_WIN_HEIGHT	4 * MAX_PLAYERS
# define	PLAYER_WIN_WIDTH	SIDE_WIN_WIDTH - SIDE_X_PADDING * 2
# define	PLAYER_Y_OFFSET		CYCLE_Y_OFFSET + CYCLE_WIN_HEIGHT
# define	PLAYER_X_OFFSET		SIDE_X_OFFSET + SIDE_X_PADDING

# define	PARAM_WIN_HEIGHT	8
# define	PARAM_WIN_WIDTH		SIDE_WIN_WIDTH - SIDE_X_PADDING * 2
# define	PARAM_Y_OFFSET		PLAYER_Y_OFFSET + PLAYER_WIN_HEIGHT + 4
# define	PARAM_X_OFFSET		SIDE_X_OFFSET + SIDE_X_PADDING

int				render_game(t_data *data);
WINDOW			*create_new_window(int height, int width,
				int start_y, int start_x);
void			render_arena(t_data *data);
void			render_side_bar(t_data *data);
void			render_speed_data(t_data *data);
void			render_cycle_data(t_data *data);

#endif