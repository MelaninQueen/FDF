/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:58:55 by nnqisha           #+#    #+#             */
/*   Updated: 2018/08/26 10:52:38 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_draw	draw_line(t_draw draw)
{
	if (draw.dy > draw.dx)
	{
		draw.temp = draw.dx;
		draw.dx = draw.dy;
		draw.dy = draw.temp;
		draw.swap = 1;
	}
	return (draw);
}

t_draw	next_step(t_draw draw)
{
	while (draw.p >= 0)
	{
		draw.p = draw.p - 2 * draw.dx;
		if (draw.swap)
			draw.x += draw.s1;
		else
			draw.y += draw.s2;
	}
	draw.p = draw.p + 2 * draw.dy;
	if (draw.swap)
		draw.y += draw.s2;
	else
		draw.x += draw.s1;
	return (draw);
}

int		colour(float z0, float z1)
{
	if (z0 >= 10 || z1 >= 10)
		return (YELLOW);
	else if (z0 <= 9 || z1 <= 9)
		return (PINK);
	else
		return (BLUE);
}

void	bres(float x1, float y1, t_map pg)
{
	t_draw draw;

	draw.x = x1;
	draw.y = y1;
	draw.dx = ft_abs(pg.x2 - x1);
	draw.dy = ft_abs(pg.y2 - y1);
	draw.s1 = sign(pg.x2 - x1);
	draw.s2 = sign(pg.y2 - y1);
	draw.swap = 0;
	mlx_pixel_put(pg.mlx.mlx_ptr, pg.mlx.win, y1, x1,
			colour(pg.z0, pg.z1));
	draw = draw_line(draw);
	draw.p = 2 * (draw.dy - draw.dx);
	draw.i = 0;
	while (draw.i < draw.dx)
	{
		mlx_pixel_put(pg.mlx.mlx_ptr, pg.mlx.win,
				draw.y, draw.x, colour(pg.z0, pg.z1));
		draw = next_step(draw);
		draw.i++;
	}
	mlx_pixel_put(pg.mlx.mlx_ptr, pg.mlx.win, pg.y2,
			pg.x2, colour(pg.z0, pg.z1));
}

int		display_image(t_map map)
{
	map.idx.j = 0;
	mlx_clear_window(map.mlx.mlx_ptr, map.mlx.win);
	while (map.idx.j < map.y)
	{
		map.idx.i = 0;
		while (map.idx.i < map.x)
		{
			calcu_points(map);
			map.idx.i++;
		}
		map.idx.j++;
	}
	map.idx.i = 0;
	while (map.idx.i < map.x)
	{
		map.idx.j = 0;
		while (map.idx.j < map.y - 1)
		{
			calcu_points2(map);
			map.idx.j++;
		}
		map.idx.i++;
	}
	return (0);
}
