/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:20:12 by oaciz             #+#    #+#             */
/*   Updated: 2022/02/16 06:22:08 by oaciz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char) c != *s)
		s++;
	if ((char) c == *s)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	const char	dizi[] = "ömeraciz";
	char	*res;
	res = ft_strchr(dizi, 'r');
	printf("%s", res);
}
*/
/*stringin belirtilen karakterden sonrasını ekrana bastrırır.*/
