/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptemp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:50:43 by oaciz             #+#    #+#             */
/*   Updated: 2022/10/27 10:55:15 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maptemp(t_data *data, int len, char **av)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	data->maptmp = malloc(sizeof(char *) * (len + 1));
	data->maptmp[len] = NULL;
	fd = open(av[1], O_RDONLY);
	while (len)
	{
		s = get_next_line(fd);
		data->maptmp[i] = s;
		i++;
		len--;
	}
	i = 0;
}
