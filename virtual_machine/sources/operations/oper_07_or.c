/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_07_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 16:22:03 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/11 18:31:23 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	or(t_data *data, size_t c_num)
{
	intmax_t res;
	t_byte *v1;
	t_byte *v2;
	short reg_num;

	if ((GET_TYPE(c_num, 0) == REG_CODE &&
		INCORRECT_REG_NUM(GET_REG_NUM(c_num, 0))) ||
		(GET_TYPE(c_num, 1) == REG_CODE &&
		INCORRECT_REG_NUM(GET_REG_NUM(c_num, 1))) ||
		INCORRECT_REG_NUM(GET_REG_NUM(c_num, 2)))
		return ;
	
	v1 = GET_VALUE(c_num, 0);
	v2 = GET_VALUE(c_num, 1);
	reg_num = GET_REG_NUM(c_num, 2);
	res = GET_REV_NUMBER(v1, REG_SIZE) | GET_REV_NUMBER(v2, REG_SIZE);
	reverse_array(&res, REG_SIZE);
	ft_memcpy(GET_REGISTER(c_num, reg_num), &res, REG_SIZE);
	SET_CARRY(c_num, reg_num);
}