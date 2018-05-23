/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:48:33 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/23 10:38:12 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_register(t_data *data, int *padding, t_process *process)
{
	int i;
	int reg_num;

	(*padding)++;
	i = 0;
	while (GET_USED(process, i))
		i++;
	reg_num = data->arena[(process->pc + *padding) % MEM_SIZE];
	GET_REG_NUM(process, i) = reg_num;
	GET_SIZE(process, i) = REG_SIZE;
	GET_TYPE(process, i) = REG_CODE;
	GET_USED(process, i) = 1;
	if (INCORRECT_REG_NUM(reg_num))
		return ;
	ft_memcpy(GET_VALUE(process, i), process->reg[reg_num], REG_SIZE);

}

void	read_direct_value(t_data *data, int *padding, t_process *process)
{
	int		i;
	int		size;
	t_byte	temp[DIR_SIZE];

	(*padding)++;
	i = 0;
	while (GET_USED(process, i))
		i++;
	size = op_tab[process->oper.op_code].label_size;
	ft_bzero(temp, sizeof(temp));
	read_arena_chunk(data, temp, process->pc + *padding, size);
	if (temp[0] & 0b10000000)
		ft_memset(&GET_VALUE(process, i), -1, DIR_SIZE);
	ft_memcpy(GET_VALUE(process, i), temp, size);
	GET_SIZE(process, i) = size;
	GET_TYPE(process, i) = DIR_CODE;
	GET_USED(process, i) = 1;
	(*padding) += size - 1;
}

void	read_indirect_value(t_data *data, int *padding, t_process *process)
{
	int		i;
	short	offset;
	t_byte	temp[T_IND];

	(*padding)++;
	i = 0;
	while (GET_USED(process, i))
		i++;

	ft_bzero(temp, sizeof(temp));
	read_arena_chunk(data, temp, process->pc + *padding, IND_SIZE);
	offset = get_number(temp);
	GET_OFFSET(process, i) = offset;

	ft_bzero(temp, sizeof(temp));
	read_arena_chunk(data, temp, process->pc + offset, T_IND);
	ft_memcpy(GET_VALUE(process, i), temp, T_IND);
	
	ft_bzero(temp, sizeof(temp));
	read_arena_chunk(data, temp, process->pc + (offset % IDX_MOD), T_IND);
	ft_memcpy(GET_VALUE_IDX(process, i), temp, T_IND);
	GET_SIZE(process, i) = REG_SIZE;
	GET_TYPE(process, i) = IND_CODE;
	GET_USED(process, i) = 1;
	(*padding) += IND_SIZE - 1;
}

/*
**  Parses arguments of instruction.
**  Determinates argument`s type (T_REG, T_DIR, T_IND) using codage.
**	Takes data and number of player;
**  Sets PC to the next instruction.
*/

void	parse_arguments(t_data *data, t_process *process)
{
	int		k;
	int		padding;
	t_byte	codage;

	padding = 0;
	if (!op_tab[process->oper.op_code].codage)
		read_direct_value(data, &padding, process);
	else
	{
		padding = 1;
		codage = data->arena[process->pc + padding];
		while (codage)
		{
			k = (codage & 0b11000000) >> 6;
			if (k == REG_CODE)
				read_register(data, &padding, process);
			else if (k == DIR_CODE)
				read_direct_value(data, &padding, process);
			else if (k == IND_CODE)
				read_indirect_value(data, &padding, process);
			codage = codage << 2;
		}
	}
	process->padding = padding + 1;
}
