/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:30:59 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/24 19:25:30 by mgayduk          ###   ########.fr       */
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
	int			size;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error_msg("Can't read source file %s", file_path);
	player->file_size += read(fd, player->magic, MAGIC_LENGTH);
	player->file_size += read(fd, player->name, PROG_NAME_LENGTH);
	lseek(fd, PADDING_LENGTH, 1);
	player->file_size += read(fd, player->size, SIZE_LENGTH);
	player->file_size += read(fd, player->comment, COMMENT_LENGTH);
	lseek(fd, PADDING_LENGTH, 1);
	player->file_size += PADDING_LENGTH * 2;
	size = get_int_number(player->size);
	player->file_size += size;
	player->exec_code = (char *)malloc(size);
	if (!player->exec_code)
		error_msg(MEM_ERROR, NULL);
	read(fd, player->exec_code, size);
	close(fd);
}

void	check_champ(t_player *player, char *file_path)
{
	int magic;

	if (player->file_size < MIN_PROGSIZE)
		error_msg("File %s is too small to be a champion", file_path);
	magic = get_int_number(player->magic);	
	if (magic != COREWAR_EXEC_MAGIC)
		error_msg("File %s has an invalid header", file_path);
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