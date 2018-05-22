/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:40:48 by maks              #+#    #+#             */
/*   Updated: 2018/05/22 21:53:56 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Converts array of bytes to the little-endian integer
**	and returns it;
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