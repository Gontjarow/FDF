/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:28:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/04 16:52:40 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static size_t	arrlen_terminated(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		++i;
	return (i);
}

// static size_t	arrlen2_terminated(t_xyz **array)
// {
// 	size_t	i;

// 	i = 0;
// 	printf("oh no?\n");
// 	while (array[i])
// 		++i;
// 	return (i);
// }

void			parse_map(int fd, t_map *map)
{
	t_xyz	**final;
	char	*lines[4096];
	char	*line;
	char	**split;
	int		width;
	int		height;
	int		x;
	int		y;
	(void)map;

	height = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		lines[height] = line;
		++height;
	}
	lines[height] = NULL;
	width = 0;
	y = 0;
	while (y < height)
	{
		split = ft_strsplit(lines[y], ' ');
		if (width == 0)
		{
			width = arrlen_terminated(split);
			final = malloc2d_xyz((t_xy){width, height});
		}
		x = 0;
		while (x < width)
		{
			final[y][x].x = x;
			final[y][x].y = y;
			final[y][x].z = ft_atoi(split[x]);
			++x;
		}
		++y;
	}
	map->array = final;
	map->size = (t_xy){width, height};
}
