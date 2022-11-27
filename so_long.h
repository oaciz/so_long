/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:53:44 by oaciz             #+#    #+#             */
/*   Updated: 2022/11/14 19:07:53 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define    SO_LONG_H

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdio.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_data{
	int		playerindex_y;
	int		playerindex_x;
	void	*mlx;
	void	*mlx_win;
	void	*exit_door;
	void	*player;
	void	*coin;
	void	*wall;
	void	*background;
	char	**maps;
	char	**maptmp;
	int		playercount;
	int		collectiblecount;
	int		exitdoorcount;
	int		wallcount;
	int		free_spacecount;
	int		getcollect;
	int		x;
	int		y;
	int		move_count;
	int		leny;
	int		linelen;
	int		temp_y;
	int		temp_x;
	int		tempcollect;
	int		exitt;
}	t_data;

char	*get_next_line(int fd);
void	wallcontrol(t_data *map);
void	wallcontrol2(t_data *map);
void	wallcontrol3(t_data *map);
void	all_map_checking(t_data *map);
void	char_control(t_data *map);
void	rectangle_control(t_data *map);
void	maptemp(t_data *data, int len, char **av);
int		isvalid(t_data *data, int len, char **av);
void	reccontrols(t_data *data);
void	reccontrol1(t_data *data);
void	reccontrol2(t_data *data);
void	reccontrol3(t_data *data);
void	reccontrol4(t_data *data);
void	putimage(t_data *map);
void	add_image(t_data *img);
void	moveup(t_data *img);
int		keysignal(int keycode, t_data *data);
void	happy_end(t_data *data);
void	sub_main(t_data *data, int len, char **av);
void	mapcheck(t_data *data, int len, char **av);
void	ft_map_free(t_data *data);
int		ft_free(t_data *data);
void	ft_freeimg(t_data *data);
void	ft_exit(t_data *data);
int		button(t_data *data);
#endif