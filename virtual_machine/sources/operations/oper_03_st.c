/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_03_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:38:56 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/21 11:37:47 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_data *data, size_t c_num)
{
	t_byte *val;
	int dest;
	short reg;

	reg = GET_REG_NUM(c_num, 0);
	if (INCORRECT_REG_NUM(reg))
		return ;
	val = GET_REGISTER(c_num, reg);
	if (GET_TYPE(c_num, 1) == IND_CODE)
	{
		dest = GET_PC(c_num) + (GET_OFFSET(c_num, 1) % IDX_MOD);
		write_arena_chunk(data, val, dest, REG_SIZE);
	}
	else if (GET_TYPE(c_num, 1) == REG_CODE)
	{
		dest = GET_REG_NUM(c_num, 1);
		if (INCORRECT_REG_NUM(dest))
			return ;
		ft_memcpy(GET_REGISTER(c_num, dest), val, REG_SIZE);
	}
}