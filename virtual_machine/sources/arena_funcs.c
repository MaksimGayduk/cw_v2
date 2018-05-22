/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:56:31 by maks              #+#    #+#             */
/*   Updated: 2018/05/22 23:57:10 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


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
		index = start % MEM_SIZE;
		if (index < 0)
			index += MEM_SIZE;
		data->arena[index] = src[i];
		start++;
		i++;
	}
}

/*
**	Reads some peace of arena memory
**	Implements the idea of cycled memory
**	For exmaple: arena[-2] => arena[4094]
**	arena[4098] => arena[2]
*/

t_byte	*read_arena_chunk(t_data *data, t_byte *dest, int start, size_t n)
{
	size_t i;
	int index;

	i = 0;

	while (i < n)
	{
		index = start % MEM_SIZE;
		if (index < 0)
			index += MEM_SIZE;
		dest[i] = data->arena[index];
		start++;
		i++;
	}
	return (dest);
}