/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcontrols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:43:43 by oaciz             #+#    #+#             */
/*   Updated: 2022/10/27 11:48:52 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wallcontrol3(t_data *data)
{
	int	i;
	int	c;
	int	len;
	int	leny;

	i = 0;
	c = 0;
	leny = data->leny;
	len = ft_strlen(data->maps[leny - 2]);
	leny--;
	while (leny)
	{
		if (data->maps[leny][len - 2] == '1' && data->maps[leny][0] == '1')
			leny--;
		else
		{
			ft_printf("ERROR\n");
			exit(1);
		}
	}
}

void	wallcontrol(t_data *data)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = ft_strlen(*data->maps);
	while (data->maps[i][c] != '\0')
	{
		if (data->maps[i][c] == '1' || data->maps[i][c] == '\n')
			c++;
		else
		{
			ft_printf("ERROR");
			exit(1);
		}
	}
}

void	wallcontrol2(t_data *data)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = ft_strlen(data->maps[data->leny - 1]);
	while (data->maps[data->leny - 1][c] != '\0')
	{
		if (data->maps[data->leny - 1][c] == '1')
			c++;
		else
		{
			ft_printf("ERROR");
			exit(1);
		}
	}
}
