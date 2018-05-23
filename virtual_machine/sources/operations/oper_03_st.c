/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_03_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:38:56 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/23 13:03:19 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_data *data, t_process *process)
{
	t_byte	*val;
	int		dest;
	short	reg_num;

	reg_num = REG_NUM(process, 0);
	if (INCORRECT_REG_NUM(reg_num))
		return ;
	val = process->registers[reg_num];
	if (TYPE(process, 1) == IND_CODE)
	{
		dest = process->pc + (OFFSET(process, 1) % IDX_MOD);
		write_arena_chunk(data, val, dest, REG_SIZE);
	}
	else if (TYPE(process, 1) == REG_CODE)
	{
		reg_num = REG_NUM(process, 1);
		if (INCORRECT_REG_NUM(reg_num))
			return ;
		ft_memcpy(process->registers[reg_num], val, REG_SIZE);
	}
}