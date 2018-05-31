/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_09_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:21:30 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/31 10:15:47 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_data *data, t_process *process)
{
	short offset;
	short dest;

	if (!process->carry)
		return ;
	offset = get_short_number(VALUE(process, 0));
	dest = process->pc + (offset % IDX_MOD);
	dest = normalize_index(dest);
	data->render.pc_map[process->pc]--;
	process->pc = dest;
	data->render.pc_map[process->pc]++;
}