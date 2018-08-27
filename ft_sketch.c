/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sketch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:03:11 by nnqisha           #+#    #+#             */
/*   Updated: 2018/08/26 10:52:15 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		ft_abs(float n)
{
	return ((n > 0) ? n : (n * (-1)));
}

int		sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void	calcu_points(t_map map)
{
	float mult;

	mult = 1 / sqrt(6);
	map.top = map.map[map.idx.j][map.idx.i];
	map.z0 = map.map[map.idx.j][map.idx.i];
	map.x0 = (mult * sqrt(3) * map.idx.i) + (mult * 0 * map.idx.j)
		+ (mult * -sqrt(3) * map.top);
	map.y0 = (mult * 1 * map.idx.i) + (mult * 2 * map.idx.j)
		+ (mult * 1 * map.top);
	map.x0 = 10 * map.x0 + 200;
	map.y0 = 10 * map.y0 + 400;
	map.top = map.map[map.idx.j][map.idx.i + 1];
	map.z1 = map.map[map.idx.j][map.idx.i + 1];
	map.x1 = (mult * sqrt(3) * (map.idx.i + 1))
		+ (mult * 0 * map.idx.j) + (mult * -sqrt(3) * map.top);
	map.y1 = (mult * 1 * (map.idx.i + 1)) + (mult * 2 * map.idx.j)
		+ (mult * 1 * map.top);
	map.x1 = 10 * map.x1 + 200;
	map.y1 = 10 * map.y1 + 400;
	map.x2 = map.x1;
	map.y2 = map.y1;
	bres(map.x0, map.y0, map);
}

void	calcu_points2(t_map map)
{
	float mult;

	mult = 1 / sqrt(6);
	map.top = map.map[map.idx.j][map.idx.i];
	map.z0 = map.map[map.idx.j][map.idx.i];
	map.x0 = (mult * sqrt(3) * map.idx.i) + (mult * -sqrt(3) * map.top);
	map.y0 = (mult * 1 * map.idx.i) + (mult * 2 * map.idx.j)
		+ (mult * 1 * map.top);
	map.x0 = 10 * map.x0 + 200;
	map.y0 = 10 * map.y0 + 400;
	map.top = map.map[map.idx.j + 1][map.idx.i];
	map.z1 = map.map[map.idx.j + 1][map.idx.i];
	map.x1 = (mult * sqrt(3) * map.idx.i) + (mult * 0 * (map.idx.j + 1))
		+ (mult * -sqrt(3) * map.top);
	map.y1 = (mult * 1 * map.idx.i) + (mult * 2 * (map.idx.j + 1))
		+ (mult * 1 * map.top);
	map.x1 = 10 * map.x1 + 200;
	map.y1 = 10 * map.y1 + 400;
	map.x2 = map.x1;
	map.y2 = map.y1;
	bres(map.x0, map.y0, map);
}
