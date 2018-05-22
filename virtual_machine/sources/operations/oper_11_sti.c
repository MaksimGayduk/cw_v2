/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_11_sti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:22:16 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 13:06:46 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_data *data, size_t c_num)
{
	t_cursor	*test;
	t_byte		val1[REG_SIZE];
	t_byte		val2[REG_SIZE];
	t_byte		val3[REG_SIZE];
	int			dest;

	test = &data->cursors[c_num];
	ft_bzero(&val1, REG_SIZE);
	ft_bzero(&val2, REG_SIZE);
	ft_bzero(&val3, REG_SIZE);
	if (INCORRECT_REG_NUM(GET_REG_NUM(c_num, 0)))
		return ;
	ft_memcpy(&val1, &GET_VALUE(c_num, 0), REG_SIZE);
	if (GET_TYPE(c_num, 1) == IND_CODE)
		ft_memcpy(&val2, &GET_VALUE_IDX(c_num, 1), REG_SIZE);
	else 
		ft_memcpy(&val2, &GET_VALUE(c_num, 1), REG_SIZE);
	ft_memcpy(&val3, &GET_VALUE(c_num, 2), REG_SIZE);

	dest = 	GET_REV_NUMBER(&val2, GET_SIZE(c_num, 1)) +
			GET_REV_NUMBER(&val3, GET_SIZE(c_num, 2));
	dest %= IDX_MOD;
	dest = GET_PC(c_num) + dest;
	write_arena_chunk(data, val1, dest, REG_SIZE);
}		
