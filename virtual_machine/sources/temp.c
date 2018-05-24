/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:07:58 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/24 20:33:41 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc temp.c ../libft/libft.a -I ../includes/ -I ../libft/includes

#include "corewar.h"

void	error_msg2(char *msg, char *arg)
{
	char *buff;

	if (arg == NULL)
		ft_printf(RED "Error: %s\n" RESET, msg);
	else
	{
		buff = ft_strnew(ft_strlen(msg) + 8);
		buff = ft_strcat(buff, "Error: ");
		buff = ft_strcat(buff, msg);
		buff = ft_strcat(buff, "\n");
		ft_printf(msg, arg);
		ft_strdel(&buff);
	}
	system("leaks a.out");
	exit(1);
}


int main(void)
{
	char *msg = "File %s is too small to be a champion";
	char *filename = "zork.cor";

	error_msg2(msg, filename);

	system("leaks a.out");
	return (0);
}