/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_10_ldi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:45:25 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 13:09:20 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi(t_data *data, size_t c_num)
{
	t_cursor	*test;
	t_byte		val1[REG_SIZE];
	t_byte		val2[REG_SIZE];
	short		reg_num;
	int			dest;

	test = &data->cursors[c_num];
	ft_bzero(&val1, REG_SIZE);
	ft_bzero(&val2, REG_SIZE);
	reg_num = GET_REG_NUM(c_num, 2);
	if (INCORRECT_REG_NUM(reg_num))
		return ;
	if (GET_TYPE(c_num, 0) == IND_CODE)
		ft_memcpy(&val1, &GET_VALUE_IDX(c_num, 0), REG_SIZE);
	else
		ft_memcpy(&val1, &GET_VALUE(c_num, 0), REG_SIZE);
	ft_memcpy(&val2, &GET_VALUE(c_num, 1), REG_SIZE);
	dest = 	GET_REV_NUMBER(&val1, GET_SIZE(c_num, 0)) +
			GET_REV_NUMBER(&val2, GET_SIZE(c_num, 1));
	dest %= IDX_MOD;
	dest = GET_PC(c_num) + dest;
	read_arena_chunk(data, GET_REGISTER(c_num, reg_num), dest, REG_SIZE);
}