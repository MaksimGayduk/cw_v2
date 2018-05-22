/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_02_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:01:03 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 13:23:59 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes a random argument and a registry. 
**	Load the value of the first argument in the registry
*/

void	ld(t_data *data, size_t c_num)
{
	t_cursor *test;
	t_byte val[REG_SIZE];
	short reg_num;

	test = &data->cursors[c_num];
	ft_bzero(&val, REG_SIZE);
	reg_num = GET_REG_NUM(c_num, 1);
	if (INCORRECT_REG_NUM(reg_num))
		return ;
	if (GET_TYPE(c_num, 0) == DIR_CODE)
		ft_memcpy(&val, &GET_VALUE(c_num, 0), REG_SIZE);	
	else if (GET_TYPE(c_num, 0) == IND_CODE)
		ft_memcpy(&val, &GET_VALUE_IDX(c_num, 0), REG_SIZE);
	else
		return ;
	ft_memcpy(&GET_REGISTER(c_num, reg_num), &val, REG_SIZE);
	SET_CARRY(c_num, reg_num);
}