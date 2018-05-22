/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_16_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:19:56 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/16 17:26:20 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_data *data, size_t c_num)
{
	t_byte *val;

	if (INCORRECT_REG_NUM(GET_REG_NUM(c_num, 0)))
		return ;

	val = GET_VALUE(c_num, 0);
	ft_printf("Aff: %c\n", GET_REV_NUMBER(val, GET_SIZE(c_num, 0) % 256));
}