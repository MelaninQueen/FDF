/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:02:11 by nnqisha           #+#    #+#             */
/*   Updated: 2018/08/22 16:36:12 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define OFFSET_X 100
# define OFFSET_Y 100

# define BLUE 0x0099FF
# define YELLOW 0xF3F315
# define PINK 0xFF0099

# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# define WIN_HEIGHT 1500
# define WIN_WIDTH 1250

typedef struct	s_index
{
	int i;
	int j;
}				t_index;

typedef struct	s_draw
{
	float x;
	float y;
	float dx;
	float dy;
	float swap;
	float temp;
	float s1;
	float s2;
	float p;
	float i;
}				t_draw;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_map
{
	float	x2;
	float	y2;
	int		**map;
	char	*s;
	int		*rv;
	char	*line;
	float	y0;
	float	y1;
	float	x0;
	float	x1;
	float	z0;
	float	z1;
	int		fd;
	char	*file;
	int		top;
	int		x;
	int		y;
	t_mlx	mlx;
	t_index idx;
}				t_map;

int				ft_abs(float n);
int				display_image(t_map map);
t_map			ft_read(int fd);
int				sign(int x);
void			calcu_points(t_map map);
void			calcu_points2(t_map map);
void			bres(float x1, float y1, t_map pg);

#endif
