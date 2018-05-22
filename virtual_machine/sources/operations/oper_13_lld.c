/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_13_lld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:01:03 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/16 17:21:04 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes a random argument and a registry. 
**	Load the value of the first argument in the registry
*/

void	lld(t_data *data, size_t c_num)
{
	t_byte *val;
	short reg_num;

	reg_num = GET_REG_NUM(c_num, 1);
	if (INCORRECT_REG_NUM(reg_num))
		return ;
	val = GET_VALUE(c_num, 0);	
	ft_memcpy(GET_REGISTER(c_num, reg_num), val, REG_SIZE);
	SET_CARRY(c_num, reg_num);
}