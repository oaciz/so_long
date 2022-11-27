/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:13:07 by oaciz             #+#    #+#             */
/*   Updated: 2022/11/17 19:29:06 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	happy_end(t_data *data)
{
	ft_printf("Game Finish Your Move Count -> %d <-", ++data->move_count);
	ft_exit(data);
}

void	ft_exit(t_data *data)
{
	if (data)
		ft_free(data);
	exit(1);
}
