/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_14_lldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:45:25 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/16 17:14:40 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	The same as ldi, but without offset %= IDX_MOD;
**	Modifies carry;
*/

void	lldi(t_data *data, size_t c_num)
{
	t_byte		*val1;
	t_byte		*val2;
	int			offset;
	short		reg_num;

	reg_num = GET_REG_NUM(c_num, 2);
	if (INCORRECT_REG_NUM(reg_num))
		return ;
	if (GET_TYPE(c_num, 0) == IND_CODE)
		val1 = GET_VALUE_IDX(c_num, 0);
	else
		val1 = GET_VALUE(c_num, 0);
	val2 = GET_VALUE(c_num, 1);
	offset = 	GET_REV_NUMBER(val1, GET_SIZE(c_num, 0)) +
				GET_REV_NUMBER(val2, GET_SIZE(c_num, 1));

	read_arena_chunk(data, GET_REGISTER(c_num, reg_num),
				GET_PC(c_num) + offset, REG_SIZE);
	
	SET_CARRY(c_num, reg_num);
}