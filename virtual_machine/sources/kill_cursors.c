/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_cursors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:48:39 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 15:52:22 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Marks dead cursors.
**	Counts number of alive cursors and returns it. 
*/

static size_t	mark_dead_cursors(t_data *data)
{
	size_t i;
	size_t alive;
	t_cursor *test;

	i = 0;
	alive = 0;
	while (i < data->curs_qty)
	{
		test = &data->cursors[i];
		
		if (data->cursors[i].live == 0)
			data->cursors[i].dead = 1;
		else
			alive++;
		i++;
	}
	return (alive);
}


/*
**	Returns index of the next alive cursors.
*/

size_t	get_next_alive_cursor(t_data *data, size_t j)
{
	while (j < data->curs_qty)
	{
		if (!data->cursors[j].dead)
			return (j);
		j++;
	}
	return (-42);
}


/*
**	Copies alive cursors to a new array.
*/

void	refresh_cursor_array(t_data *data, size_t alive)
{
	t_cursor *temp;
	size_t i;
	size_t j;
	t_cursor *new_array;

	temp = data->cursors;
	new_array = (t_cursor *)ft_memalloc(sizeof(t_cursor) * alive);
	if (!new_array)
		error_msg(MEM_ERROR);
	i = 0;
	j = 0;
	while (i < alive)
	{
		j = get_next_alive_cursor(data, j);
		new_array[i] = data->cursors[j];
		i++;
		j++;
	}
	data->cursors = new_array;
	ft_bzero(temp, sizeof(t_cursor) * data->curs_qty);
	free(temp);
}

/*
**	While each check, the cursor, wich is not alive (live == 0)
**	should be deleted from array of cursors;
**	So I`m allocate memory to a new array and put there only alive cursors;
**	The old array being freed.
*/

void	kill_cursors(t_data *data)
{
	size_t alive;

	alive = mark_dead_cursors(data);
	if (alive == data->curs_qty)
		return ;
	refresh_cursor_array(data, alive);
	data->curs_qty = alive;
}