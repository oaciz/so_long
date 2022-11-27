/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:51:20 by oaciz             #+#    #+#             */
/*   Updated: 2022/11/10 21:43:15 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangle_control(t_data *data)
{
	int	len;
	int	len_cont;
	int	leny;

	leny = data->leny;
	len = ft_strlen(data->maps[--leny]) + 1;
	while (--leny >= 0)
	{
		len_cont = ft_strlen(data->maps[leny]);
		if (len != len_cont)
		{
			ft_printf("Error\n");
			exit (1);
		}
	}
}

void	ft_map_free(t_data *data)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (data->maps[i])
	{
		free(data->maps[i]);
		i++;
	}
	free(data->maps);
}

int	button(t_data *data)
{
	ft_exit(data);
	return (0);
}
