/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:52:05 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/21 12:30:59 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_msg(char *msg)
{
	ft_printf(RED "Error: %s\n" RESET, msg);
	exit(1);
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


/*
**	Reverses array.
**	Such as readed memory dump from .cor file is big endian,
**	to correct casting, array should be reversed.
**	for example: 
**	0017  --> {0x00, 0x17} in little endian will be 5888
**	after reverse - {0x17, 0x00} will be 23 as needed.
*/

void	*reverse_array(void *arr, size_t arr_size)
{
	int		i;
	int		j;
	char	temp;
	char	*s;

	s = (char *)arr;
	i = 0;
	j = arr_size - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

void	dump_arena(t_data *data)
{
	size_t	i;

	ft_printf("\n\t\t\t\t\t\t~~~ ARENA DUMP ~~~\n\n");
	i = 0;
	ft_printf("\t");
	while (i < DUMP_SIZE)
		ft_printf("%2i ", i++);
	ft_printf("\n\t-----------------------------------------------");
	ft_printf("------------------------------------------------\n");
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % DUMP_SIZE == 0)
			ft_printf("%i\t", i / DUMP_SIZE);
		ft_printf("%02hhx", data->arena[i]);
		i++;
		ft_printf(" ");
		if (i % DUMP_SIZE == 0)
			ft_printf("\n");
	}
	exit(1);
}