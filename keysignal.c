/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keysignal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:23:33 by oaciz             #+#    #+#             */
/*   Updated: 2022/10/27 10:23:39 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveleft(t_data *data)
{
	if (data->maps[data->playerindex_y][data->playerindex_x - 1] != '1' &&
		(data->maps[data->playerindex_y][data->playerindex_x - 1] != 'E' ||
			data->getcollect == data->collectiblecount))
	{
		if (data->maps[data->playerindex_y][data->playerindex_x - 1] == 'C')
			data->getcollect++;
		data->maps[data->playerindex_y][data->playerindex_x] = '0';
		if (data->maps[data->playerindex_y][data->playerindex_x - 1] == 'E')
			happy_end(data);
		data->maps[data->playerindex_y][data->playerindex_x - 1] = 'P';
		data->move_count++;
		ft_printf("Move Count:%d\n", data->move_count);
	}
}

void	movedown(t_data *data)
{
	if (data->maps[data->playerindex_y + 1][data->playerindex_x] != '1' &&
		(data->maps[data->playerindex_y + 1][data->playerindex_x] != 'E' ||
			data->getcollect == data->collectiblecount))
	{
		if (data->maps[data->playerindex_y + 1][data->playerindex_x] == 'C')
			data->getcollect++;
		data->maps[data->playerindex_y][data->playerindex_x] = '0';
		if (data->maps[data->playerindex_y + 1][data->playerindex_x] == 'E')
			happy_end(data);
		data->maps[data->playerindex_y + 1][data->playerindex_x] = 'P';
		data->move_count++;
		ft_printf("Move Count:%d\n", data->move_count);
	}
}

void	moveup(t_data *data)
{
	if (data->maps[data->playerindex_y - 1][data->playerindex_x] != '1' &&
		(data->maps[data->playerindex_y - 1][data->playerindex_x] != 'E' ||
			data->getcollect == data->collectiblecount))
	{
		if (data->maps[data->playerindex_y - 1][data->playerindex_x] == 'C')
			data->getcollect++;
		data->maps[data->playerindex_y][data->playerindex_x] = '0';
		if (data->maps[data->playerindex_y - 1][data->playerindex_x] == 'E')
			happy_end(data);
		data->maps[data->playerindex_y - 1][data->playerindex_x] = 'P';
		data->move_count++;
		ft_printf("Move Count:%d\n", data->move_count);
	}
}

void	moveright(t_data *data)
{
	if (data->maps[data->playerindex_y][data->playerindex_x + 1] != '1' &&
		(data->maps[data->playerindex_y][data->playerindex_x + 1] != 'E' ||
			data->getcollect == data->collectiblecount))
	{
		if (data->maps[data->playerindex_y][data->playerindex_x + 1] == 'C')
			data->getcollect++;
		data->maps[data->playerindex_y][data->playerindex_x] = '0';
		if (data->maps[data->playerindex_y][data->playerindex_x + 1] == 'E')
			happy_end(data);
		data->maps[data->playerindex_y][data->playerindex_x + 1] = 'P';
		data->move_count++;
		ft_printf("Move Count:%d\n", data->move_count);
	}	
}

int	keysignal(int keycode, t_data *data)
{
	if (keycode == 13)
		moveup(data);
	if (keycode == 1)
		movedown(data);
	if (keycode == 2)
		moveright(data);
	if (keycode == 0)
		moveleft(data);
	if (keycode == 53)
		ft_exit(data);
	mlx_clear_window(data->mlx, data->mlx_win);
	putimage(data);
	return (0);
}
