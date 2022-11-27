/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:14:18 by oaciz             #+#    #+#             */
/*   Updated: 2022/11/10 22:15:28 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reccontrols(t_data *data)
{
	reccontrol1(data);
	reccontrol2(data);
	reccontrol3(data);
	reccontrol4(data);
}

int	isvalid(t_data *data, int len, char **av)
{
	data->exitdoorcount = data->exitt;
	maptemp(data, len, av);
	reccontrols(data);
	if (data->tempcollect <= 0 && data->exitt <= 0)
		return (1);
	else
	{
		ft_printf("İs Valid Path Error");
		exit(1);
	}
	return (0);
}
