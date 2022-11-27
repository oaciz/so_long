/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 07:41:19 by oaciz             #+#    #+#             */
/*   Updated: 2022/02/17 14:27:17 by oaciz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < ft_strlen(s))
	{
		f(i, s + i);
		i++;
	}
}
/*
void	f(unsigned int i, char *dizi)
{
	*dizi -= 32;
}
#include <stdio.h>

int	main()
{
	char	dizi[] = "omer";
	ft_striteri(dizi, &f);
	printf("%s", dizi);
}
*/
