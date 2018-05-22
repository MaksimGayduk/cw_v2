int		cursor_on_pc(t_data *data, size_t cursor)
{
	size_t i;

	i = 0;
	while (i < data->curs_qty)
	{
		if (data->cursors[i].pc == cursor)
			return (1);
		i++;
	}
	return (0);
}

/*
**	Prints arena memory in hexdump like style. 
*/

void	print_arena(t_data *data)
{
	size_t	i;

	ft_printf("\n\t\t\t\t\t\t~~~ ARENA DUMP ~~~\n\n");
	i = 0;
	ft_printf("\t");
	while (i < DUMP_SIZE)
		ft_printf("%2i ", i++);
	ft_printf("\n\t-----------------------------------------------");
	ft_printf("------------------------------------------------\n");
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % DUMP_SIZE == 0)
			ft_printf("%i\t", i / DUMP_SIZE);
		if (!data->arena[i] && cursor_on_pc(data, i))
			ft_printf(B_YELLOW BLACK "%02hhx" RESET, data->arena[i]);
		else if (!data->arena[i])
			ft_printf("%02hhx", data->arena[i]);
		else if (cursor_on_pc(data, i))
			ft_printf(B_YELLOW GREEN "%02hhx" RESET, data->arena[i]);
		else
			ft_printf(GREEN "%02hhx" RESET, data->arena[i]);
		i++;
		ft_printf(" ");
		if (i % DUMP_SIZE == 0)
			ft_printf("\n");
	}
}