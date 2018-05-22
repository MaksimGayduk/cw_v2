/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:07:58 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/14 18:10:31 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int n;
	int s;
	short v;

	// t_byte v1[REG_SIZE] = {0x00, 0x00, 0x0a, 0xf1};
	// t_byte v2[REG_SIZE] = {0x00, 0x00, 0x0a, 0xf1};

	s = -3 % 10;
	n = 4098 % 4096;

	v = 0;

	//s = GET_REV_NUMBER(v2, REG_SIZE);

	//v = n + s;
	//reverse_array(&v, sizeof(int));

	printf("n: %d\ns: %d\nv %d\n", n, s, v);
	return (0);
}