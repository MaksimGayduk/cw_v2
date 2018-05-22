/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:57:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 11:56:25 by mgayduk          ###   ########.fr       */
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
	int			argc;
	int			delay;
	int			carry;
	int			label_size;
	void		(*action)(t_data *, size_t);
}				t_op;

extern			const t_op	op_tab[18];

void			live(t_data *data, size_t c_num);
void			ld(t_data *data, size_t c_num);
void			st(t_data *data, size_t c_num);
void			add(t_data *data, size_t c_num);
void			sub(t_data *data, size_t c_num);
void			and(t_data *data, size_t c_num);
void			or(t_data *data, size_t c_num);
void			xor(t_data *data, size_t c_num);
void			zjmp(t_data *data, size_t c_num);
void			ldi(t_data *data, size_t c_num);
void			sti(t_data *data, size_t c_num);
void			fork_cor(t_data *data, size_t c_num);
void			lld(t_data *data, size_t c_num);
void			lldi(t_data *data, size_t c_num);
void			lfork_cor(t_data *data, size_t c_num);
void			aff(t_data *data, size_t c_num);

void			let_new_cursor_play(t_data *data, size_t c_num);

#endif