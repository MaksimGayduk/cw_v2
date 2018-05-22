/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:30:59 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 22:09:44 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Reads champion`s data: magic, name, size, comment
**	and executable code from file to structure player
**	and returns it. 
*/

static void		read_champ(t_player *player, char *file_path)
{
	int			fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit(ft_printf("Can't read source file %s\n", file_path));
	player->file_size += read(fd, player->magic, MAGIC_LENGTH);
	player->file_size += read(fd, player->name, PROG_NAME_LENGTH);
	lseek(fd, PADDING, 1);
	player->file_size += read(fd, player->size, SIZE_LENGTH);
	player->file_size += read(fd, player->comment, COMMENT_LENGTH);
	lseek(fd, PADDING, 1);
	player->file_size += PADDING * 2;
	player->file_size += get_number(player->size);
	player->exec_code = (char *)malloc(get_number(player->size));
	if (!player->exec_code)
		error_msg(MEM_ERROR);
	read(fd, player->exec_code, GET_NUMBER(player->size));
	close(fd);
}

void	check_champ(t_player *player, char *file_path)
{
	int magic;

	if (player->file_size < MIN_PROGSIZE)
		exit(ft_printf("Error: File %s is too small to be a champion\n",
			file_path));
			
	magic = GET_REV_NUMBER(player->magic, MAGIC_LENGTH);	
	if (magic != COREWAR_EXEC_MAGIC)
		exit(ft_printf("File %s has an invalid header\n",
			file_path));
}


/*
**	Create an array of players and reads data for each of them.
*/

void			init_players(t_data *data)
{
	size_t	i;
	
	i = 0;
	while (i < data->players_qty)
	{
		read_champ(&(data->players[i]), GET_FILE_PATH(i));
		check_champ(&(data->players[i]), GET_FILE_PATH(i));
		data->players[i].signature = GET_SIGNATURE(i);
		i++;
	}
}