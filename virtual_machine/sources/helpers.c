/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:52:05 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/24 20:38:36 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_msg(char *msg, char *arg)
{
	if (arg == NULL)
		ft_printf("Error: %s\n", msg);
	else
	{
		ft_printf("Error: ");
		ft_printf(msg, arg);
		ft_printf("\n");
	}
	exit(1);
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