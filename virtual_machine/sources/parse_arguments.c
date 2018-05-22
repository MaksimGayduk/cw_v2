/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:48:33 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/21 19:39:55 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_register(t_data *data, int *padding, size_t c_num)
{
	int i;
	int reg;

	(*padding)++;
	i = 0;
	while (GET_USED(c_num, i))
		i++;
	reg = data->arena[(GET_PC(c_num) + *padding) % MEM_SIZE];
	GET_REG_NUM(c_num, i) = reg;
	GET_SIZE(c_num, i) = REG_SIZE;
	GET_TYPE(c_num, i) = REG_CODE;
	GET_USED(c_num, i) = 1;
	if (INCORRECT_REG_NUM(reg))
		return ;
	ft_memcpy(GET_VALUE(c_num, i), GET_REGISTER(c_num, reg), REG_SIZE);

}

void	read_direct_value(t_data *data, int *padding, size_t c_num)
{
	int		i;
	int		size;
	t_byte	temp[DIR_SIZE];

	(*padding)++;
	i = 0;
	while (GET_USED(c_num, i))
		i++;
	size = op_tab[GET_OPCODE(c_num)].label_size;
	ft_bzero(temp, sizeof(temp));
	read_arena_chunk(data, temp, GET_PC(c_num) + *padding, size);
	if (temp[0] & 0b10000000)
		ft_memset(&GET_VALUE(c_num, i), -1, DIR_SIZE);
	ft_memcpy(GET_VALUE(c_num, i), temp, size);
	GET_SIZE(c_num, i) = size;
	GET_TYPE(c_num, i) = DIR_CODE;
	GET_USED(c_num, i) = 1;
	(*padding) += size - 1;
}

void	read_indirect_value(t_data *data, int *padding, size_t c_num)
{
	int		i;
	short	offset;
	t_byte	temp[T_IND];

	(*padding)++;
	i = 0;
	while (GET_USED(c_num, i))
		i++;

	ft_bzero(temp, sizeof(temp));
	read_arena_chunk(data, temp, GET_PC(c_num) + *padding, IND_SIZE);
	offset = GET_REV_NUMBER(temp, IND_SIZE);
	GET_OFFSET(c_num, i) = offset;
	read_arena_chunk(data, temp, GET_PC(c_num) + offset, T_IND);
	ft_memcpy(GET_VALUE(c_num, i), temp, T_IND);
	read_arena_chunk(data, temp, GET_PC(c_num) + (offset % IDX_MOD), T_IND);
	ft_memcpy(GET_VALUE_IDX(c_num, i), temp, T_IND);
	GET_SIZE(c_num, i) = REG_SIZE;
	GET_TYPE(c_num, i) = IND_CODE;
	GET_USED(c_num, i) = 1;
	(*padding) += IND_SIZE - 1;
}

/*
**  Parses arguments of instruction.
**  Determinates argument`s type (T_REG, T_DIR, T_IND) using codage.
**	Takes data and number of player;
**  Sets PC to the next instruction.
**	
**	c_num - number of cursor;
*/

void	parse_arguments(t_data *data, size_t c_num)
{
	int		k;
	int		padding;
	t_byte	codage;

	padding = 0;
	if (!op_tab[GET_OPCODE(c_num)].codage)
		read_direct_value(data, &padding, c_num);
	else
	{
		padding = 1;
		codage = data->arena[GET_PC(c_num) + padding];
		while (codage)
		{
			k = (codage & 0b11000000) >> 6;
			if (k == REG_CODE)
				read_register(data, &padding, c_num);
			else if (k == DIR_CODE)
				read_direct_value(data, &padding, c_num);
			else if (k == IND_CODE)
				read_indirect_value(data, &padding, c_num);
			codage = codage << 2;
		}
	}
	GET_PADDING(c_num) = padding + 1;
}
