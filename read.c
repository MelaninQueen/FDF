/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:21:53 by nnqisha           #+#    #+#             */
/*   Updated: 2018/08/19 18:10:54 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		ft_strcountlen(const char *str, char c)
{
	int cnt;

	cnt = 0;
	while (str[cnt] && str[cnt] != c)
		cnt++;
	return (cnt);
}

t_map	ft_read(int fd)
{
	t_map	p;

	p.line = NULL;
	p.map = (int **)malloc(256 * sizeof(int));
	p.y = 0;
	while (get_next_line(fd, &p.line) == 1 && p.y <= 255)
	{
		p.s = p.line;
		p.rv = (int *)ft_memalloc((ft_numcount(p.s) * sizeof(int)) + 1);
		p.x = -1;
		while (*p.s)
		{
			if (*p.s == '-' || ft_isdigit(*p.s))
				p.rv[++p.x] = ft_atoi(p.s);
			p.s = ((ft_strcountlen(p.s, ' ')) ? p.s
				+ ft_strcountlen(p.s, ' ') : p.s + 1);
		}
		p.map[p.y] = p.rv;
		free(p.line);
		p.y++;
	}
	return (p);
}
