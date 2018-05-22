/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:07:58 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 21:52:49 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

int main(void)
{
	int n = 0;
	int s = 0;
	short v = 0;

	t_byte v1[REG_SIZE] = {0xff, 0xff, 0xff, 0xfd};

	n = get_number(v1);

	s = *(int *)v1;

	
	// t_byte v2[REG_SIZE] = {0x00, 0x00, 0x0a, 0xf1};

	
	ft_printf("n: %d\ns: %d\nv %d\n", n, s, v);
	return (0);
}