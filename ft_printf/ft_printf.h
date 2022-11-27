/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 05:10:18 by oaciz             #+#    #+#             */
/*   Updated: 2022/02/28 18:06:18 by oaciz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H	
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	control(char type, va_list list);
int	ft_printf(const char *str, ...);
int	fputchar(char c);
int	fputstr(char *str);
int	fputnbr(long nb);
int	fhexa(unsigned long int nb, char flag);
#endif
