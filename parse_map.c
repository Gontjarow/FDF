/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:28:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/09 21:54:11 by ngontjar         ###   ########.fr       */
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

void			parse_map(int fd, t_map *map)
{
	static char	*lines[1024];
	char	*line;
	char	**split;
	t_xy	size;
	t_xy	in;

	ft_memset((void*)lines, 0, 1024 * sizeof(char*));
	size.y = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		lines[(int)size.y] = line;
		++size.y;
	}
	lines[(int)size.y] = NULL;
	size.x = 0;
	in.y = 0;
	while (in.y < size.y)
	{
		printf("lines[in.y] %s\n", lines[(int)in.y]);
		// And printf in ft_strsplit
		split = ft_strsplit(lines[(int)in.y], ' ');
		if (size.x == 0)
		{
			size.x = arrlen_terminated(split);
			map->array = malloc2d_xyz((t_xy){size.x, size.y});
		}
		in.x = 0;
		while (in.x < size.x)
		{
			map->array[(int)in.y][(int)in.x].x = in.x;
			map->array[(int)in.y][(int)in.x].y = in.y;
			map->array[(int)in.y][(int)in.x].z = ft_atoi(split[(int)in.x]);
			++in.x;
		}
		++in.y;
	}
	map->size = (t_xy){size.x, size.y};
}
