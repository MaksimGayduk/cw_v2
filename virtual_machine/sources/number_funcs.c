/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:40:48 by maks              #+#    #+#             */
/*   Updated: 2018/05/23 10:27:14 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Converts array of bytes to a little-endian integer
**	and returns it.
*/

int get_number(void *arr)
{
	int res;
	unsigned char *s;

	res = 0;
	s = (unsigned char *)arr;
	res += s[3];
	res += s[2] << 8;
	res += s[1] << 16;
	res += s[0] << 24;

	return (res);
}

/*
**	Converts number to a normalized arena index and returns it;
**	For example: 	4106 => 10;
**					-1 	 => 4095;
*/

int	normalize_index(int index)
{
	index = index % MEM_SIZE;
	if (index < 0)
		index += MEM_SIZE;
	return (index);
}