/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:47:27 by oaciz             #+#    #+#             */
/*   Updated: 2022/10/27 10:50:03 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(t_data *data)
{
	ft_freeimg(data);
	ft_map_free(data);
	return (0);
}

void	ft_freeimg(t_data *data)
{
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->exit_door)
		mlx_destroy_image(data->mlx, data->exit_door);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->background)
		mlx_destroy_image(data->mlx, data->background);
}
