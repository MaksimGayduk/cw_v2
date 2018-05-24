/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:07:58 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/24 07:59:44 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc temp.c ../libft/libft.a -I ../includes/ -I ../libft/includes

#include "corewar.h"

int main(void)
{
	int n = 0;
	int s = 0;
	short v = 0;

	//t_byte v1[REG_SIZE] = {0xff, 0xff, 0xff, 0xfd};

	n = 0x80000000;

	s = 20;

	v = n * -1;
	// t_byte v2[REG_SIZE] = {0x00, 0x00, 0x0a, 0xf1};

	
	ft_printf("n: %d\ns: %d\nv %d\n", n, s, v);
	return (0);
}