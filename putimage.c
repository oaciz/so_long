/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:17:01 by oaciz             #+#    #+#             */
/*   Updated: 2022/10/27 11:37:35 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	forplayer(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->player, x * 64, y * 64);
	data->playerindex_y = y;
	data->playerindex_x = x;
}

void	putimage(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (data->maps[++y])
	{
		x = -1;
		while (data->maps[y][++x])
		{
			if (data->maps[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->wall, x * 64, y * 64);
			else if (data->maps[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->background, x * 64, y * 64);
			else if (data->maps[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->coin, x * 64, y * 64);
			else if (data->maps[y][x] == 'P')
				forplayer(data, x, y);
			else if (data->maps[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->exit_door, x * 64, y * 64);
		}
	}
}

void	add_image(t_data *data)
{
	int	x;
	int	y;

	data->coin = mlx_xpm_file_to_image(data->mlx,
			"./xpms/collectible.xpm", &x, &y);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./xpms/player.xpm", &x, &y);
	data->exit_door = mlx_xpm_file_to_image(data->mlx,
			"./xpms/exit_door.xpm", &x, &y);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./xpms/wall.xpm", &x, &y);
	data->background = mlx_xpm_file_to_image(data->mlx,
			"./xpms/background.xpm", &x, &y);
	if (data->coin == NULL || data->player == NULL || data->exit_door == NULL \
		|| data->wall == NULL || data->background == NULL)
		ft_exit(data);
}
