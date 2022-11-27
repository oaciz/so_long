/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reccontrols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:22:45 by oaciz             #+#    #+#             */
/*   Updated: 2022/10/27 10:22:49 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reccontrol1(t_data *data)
{
	if (data->maptmp[data->temp_y][data->temp_x + 1] != '.' && \
			data->maptmp[data->temp_y][data->temp_x + 1] != '1')
	{
		data->maptmp[data->temp_y][data->temp_x] = '.';
		data->temp_x++;
		if (data->maptmp[data->temp_y][data->temp_x] == 'C')
			data->tempcollect--;
		if (data->maptmp[data->temp_y][data->temp_x] == 'E')
		{
			if (data->tempcollect != 0)
			{
				data->temp_x--;
				data->exitt--;
				return ;
			}
			data->exitt--;
		}
		reccontrols(data);
		data->temp_x--;
	}
}

void	reccontrol2(t_data *data)
{
	if (data->maptmp[data->temp_y + 1][data->temp_x] != '.' && \
		data->maptmp[data->temp_y + 1][data->temp_x] != '1')
	{
		data->maptmp[data->temp_y][data->temp_x] = '.';
		data->temp_y++;
		if (data->maptmp[data->temp_y][data->temp_x] == 'C')
			data->tempcollect--;
		if (data->maptmp[data->temp_y][data->temp_x] == 'E')
		{
			if (data->tempcollect != 0)
			{
				data->temp_y--;
				data->exitt--;
				return ;
			}
			data->exitt--;
		}
		reccontrols(data);
		data->temp_y--;
	}
}

void	reccontrol3(t_data *data)
{
	if (data->maptmp[data->temp_y][data->temp_x - 1] != '.' && \
		data->maptmp[data->temp_y][data->temp_x - 1] != '1')
	{
		data->maptmp[data->temp_y][data->temp_x] = '.';
		data->temp_x--;
		if (data->maptmp[data->temp_y][data->temp_x] == 'C')
			data->tempcollect--;
		if (data->maptmp[data->temp_y][data->temp_x] == 'E')
		{
			if (data->tempcollect != 0)
			{
				data->temp_x++;
				data->exitt--;
				return ;
			}
			data->exitt--;
		}
		reccontrols(data);
		data->temp_x++;
	}
}

void	reccontrol4(t_data *data)
{
	if (data->maptmp[data->temp_y - 1][data->temp_x] != '.' && \
		data->maptmp[data->temp_y - 1][data->temp_x] != '1')
	{
		data->maptmp[data->temp_y][data->temp_x] = '.';
		data->temp_y--;
		if (data->maptmp[data->temp_y][data->temp_x] == 'C')
			data->tempcollect--;
		if (data->maptmp[data->temp_y][data->temp_x] == 'E')
		{
			if (data->tempcollect != 0)
			{
				data->temp_y++;
				data->exitt--;
				return ;
			}
			data->exitt--;
		}
		reccontrols(data);
		data->temp_y++;
	}
}
