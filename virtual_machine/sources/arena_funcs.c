/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:56:31 by maks              #+#    #+#             */
/*   Updated: 2018/05/23 10:35:40 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Reads some peace of arena memory.
**	start - index of arena, where reading should begin.
**	n - size of data, that should be written.
**	Implements the idea of cycled memory
**	For exmaple: 	arena[-2] => arena[4094]
**					arena[4098] => arena[2]
*/

t_byte	*read_arena_chunk(t_data *data, t_byte *dest, int start, size_t n)
{
	size_t i;
	int index;

	i = 0;
	while (i < n)
	{
		index = normalize_index(start);
		dest[i] = data->arena[index];
		start++;
		i++;
	}
	return (dest);
}

/*
**	Writes some data to arena
**	start - index of arena, where writing should begin.
**	n - size of data, that should be written.
*/

void	write_arena_chunk(t_data *data, t_byte *src, int start, size_t n)
{
	size_t i;
	int index;

	i = 0;
	while (i < n)
	{
		index = normalize_index(start);
		data->arena[index] = src[i];
		start++;
		i++;
	}
}

