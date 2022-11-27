/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:28 by oaciz	           #+#    #+#             */
/*   Updated: 2022/11/14 18:14:19 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_read(char **av)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit(NULL);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	if (str)
		free(str);
	close(fd);
	return (i);
}

void	mapcontrol(char *av)
{
	size_t	size;

	size = ft_strlen(av) - 1;
	if (size > 3 && (av[size] == 'r' && av[size -1] == 'e'
			&& av[size -2] == 'b' && av[size - 3] == '.'))
		;
	else
	{
		ft_printf("Error\n MAP Error");
		exit(1);
	}
}

int	mapycount(t_data *data)
{
	int	i;

	i = 0;
	while (data->maps[i])
		i++;
	return (i);
}

int	line_len(t_data *data)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (data->maps[i][c])
	{
		c++;
	}
	c--;
	return (c);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.mlx = mlx_init();
	if (ac == 2)
	{
		mapcontrol(av[1]);
		mapcheck(&data, map_read(av), av);
		data.leny = mapycount(&data);
		data.linelen = line_len(&data);
		sub_main(&data, map_read(av), av);
		data.mlx_win = mlx_new_window(data.mlx, data.linelen * 64,
				data.leny * 64, "so_long");
		add_image(&data);
		putimage(&data);
		mlx_hook(data.mlx_win, 2, 0, keysignal, &data);
		mlx_hook(data.mlx_win, 17, 0, button, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}
