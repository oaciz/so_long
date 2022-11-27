/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_map_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:32:38 by oaciz             #+#    #+#             */
/*   Updated: 2022/11/11 12:51:40 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapcheck(t_data *data, int len, char **av)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	data->maps = malloc(sizeof(char *) * (len + 1));
	data->maps[len] = NULL;
	fd = open(av[1], O_RDONLY);
	while (len)
	{
		s = get_next_line(fd);
		data->maps[i] = s;
		i++;
		len--;
	}
}

void	sub_main(t_data *data, int len, char **av)
{
	wallcontrol(data);
	wallcontrol2(data);
	wallcontrol3(data);
	all_map_checking(data);
	char_control(data);
	rectangle_control(data);
	isvalid(data, len, av);
	if (data->collectiblecount <= 0 || data->exitdoorcount <= 0)
	{
		ft_printf("ERROR\n");
		ft_exit(data);
	}
}

void	val_check(t_data *data, int i, int j)
{
	if (data->maps[i][j] == '1' || data->maps[i][j] == '0')
		;
	else if (data->maps[i][j] == 'P')
	{
		data->temp_y = i;
		data->temp_x = j;
		data->playercount++;
	}
	else if (data->maps[i][j] == 'E')
	{
		data->exitt++;
	}
	else if (data->maps[i][j] == 'C')
	{	
		data->collectiblecount++;
		data->tempcollect++;
	}
	else if (data->maps[i][j] == '\n')
		;
	else
	{
		ft_printf("ERROR\n");
		ft_map_free(data);
		exit(1);
	}
}

void	all_map_checking(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->maps[i])
	{
		while (data->maps[i][j])
		{
			val_check(data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	if (data->playercount != 1)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}

void	char_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->maps[i])
	{
		while (data->maps[i][j])
		{
			if (data->maps[i][j] != '1' && data->maps[i][j] != '0' && \
				data->maps[i][j] != 'E' && data->maps[i][j] != 'C' && \
					data->maps[i][j] != 'P' && data->maps[i][j] != '\n')
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
