/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:57:15 by oaciz             #+#    #+#             */
/*   Updated: 2022/11/10 21:58:37 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_moveline(char *string);
char	*ft_save(char *string);
char	*ft_read_and_save(int fd, char *string);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str);
size_t	ftt_strlen(const char *str);
#endif
