/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:57:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/06/01 13:45:27 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "corewar.h"

typedef struct	s_op
{
	int			op_code;
	char		*name;
	char		*description;
	int			codage;
	int			args_num;
	int			delay;
	int			carry;
	int			label_size;
	void		(*action)(t_data *, t_process *);
}				t_op;

extern			const t_op	g_op_tab[18];

void			live(t_data *data, t_process *process);
void			ld(t_data *data, t_process *process);
void			st(t_data *data, t_process *process);
void			add(t_data *data, t_process *process);
void			sub(t_data *data, t_process *process);
void			and(t_data *data, t_process *process);
void			or(t_data *data, t_process *process);
void			xor(t_data *data, t_process *process);
void			zjmp(t_data *data, t_process *process);
void			ldi(t_data *data, t_process *process);
void			sti(t_data *data, t_process *process);
void			fork_cor(t_data *data, t_process *process);
void			lld(t_data *data, t_process *process);
void			lldi(t_data *data, t_process *process);
void			lfork_cor(t_data *data, t_process *process);
void			aff(t_data *data, t_process *process);

void			let_new_process_play(t_data *data, t_process *process);

#endif