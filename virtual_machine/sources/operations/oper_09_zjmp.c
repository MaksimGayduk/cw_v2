/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_09_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:21:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/21 14:53:34 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_data *data, size_t c_num)
{
	short offset;
	short dest;

	if (!GET_CARRY(c_num))
		return ;
	offset = GET_REV_NUMBER(GET_VALUE(c_num, 0), GET_SIZE(c_num, 0));
	dest = GET_PC(c_num) + (offset % IDX_MOD);
	dest %= MEM_SIZE;
	if (dest < 0)
		dest += MEM_SIZE;
	GET_PC(c_num) = dest;
}