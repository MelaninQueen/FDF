/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:24:42 by nnqisha           #+#    #+#             */
/*   Updated: 2018/08/19 18:06:35 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		my_key_funct(int keycode)
{
	if (keycode == 53 || keycode == 12 || keycode == 65307)
	{
		exit(0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		if ((map.fd = open(av[1], O_RDONLY)) < 0 || !ft_strstr(av[1], ".fdf"))
			return (0);
		map = ft_read(map.fd);
		map.mlx.mlx_ptr = mlx_init();
		map.mlx.win = mlx_new_window(map.mlx.mlx_ptr, WIN_HEIGHT, WIN_WIDTH,
				"NNQISHA FDF");
		display_image(map);
		mlx_key_hook(map.mlx.win, my_key_funct, 0);
		mlx_loop(map.mlx.mlx_ptr);
	}
	return (0);
}
