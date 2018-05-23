/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:55:18 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/23 15:55:42 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
**	global array, that contains instructions of Corewar  
**	{op_code, name, description, codage, argc, cycles, carry, label size}
*/

const t_op	op_tab[OPER_QTY] = 
{
	{0, NULL, NULL, 0, 0, 0, 0, 0, NULL},
	{0x01, "live", "alive", 0, 1, 10, 0, 4, &live},
	{0x02, "ld", "load", 1, 2, 5, 1, 4, &ld},
	{0x03, "st", "store", 1, 2, 5, 0, 4, &st},
	{0x04, "add", "addition", 1, 3, 10, 1, 4, &add},
	{0x05, "sub", "substruction", 1, 3, 10, 1, 4, &sub},
	{0x06, "and", "r1 & r2 -> r3", 1, 3, 6, 1, 4, &and},
	{0x07, "or", "r1 | r2 -> r3", 1, 3, 6, 1, 4, &or},
	{0x08, "xor", "r1 ^ r2 -> r3", 1, 3, 6, 1, 4, &xor},
	{0x09, "zjmp", "jump if zero", 0, 1, 20, 0, 2, &zjmp},
	{0x0A, "ldi", "load index", 1, 3, 25, 0, 2, &ldi},
	{0x0B, "sti", "store index", 1, 3, 25, 0, 2, &sti},
	{0x0C, "fork", "fork procces", 0, 1, 800, 0, 2, fork_cor},
	{0x0D, "lld", "long load", 1, 2, 10, 1, 4, NULL},
	{0x0E, "lldi", "long load index", 1, 3, 50, 1, 2, NULL},
	{0x0F, "lfork", "long fork", 0, 1, 1000, 0, 2, NULL},
	{0x10, "aff", "aff", 1, 1, 2, 0, 4, NULL},
	{0, NULL, NULL, 0, 0, 0, 0, 0, NULL}
};
