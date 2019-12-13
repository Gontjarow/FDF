/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:28:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 20:46:08 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
** Counts the size of a NULL-terminated array,
** including the NULL address, because it must be feed.
*/

static size_t	arrlen_terminated(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		++i;
	return (i + 1);
}

/*
** Matching function for arrlen_terminated;
** Frees every element and the base address itself.
*/

static size_t	arr_free(char **array, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(array[i++]);
	free(array);
	return (i);
}

static t_xy		process(char *lines[], int filey, t_map *map)
{
	int		filex;
	int		x;
	int		y;
	char	**split;

	y = 0;
	filex = 0;
	while (lines[y])
	{
		split = ft_strsplit(lines[y], ' ');
		if (filex == 0 && (filex = arrlen_terminated(split) - 1))
			map->array = malloc2d_xyz(VEC2(filex, filey));
		x = 0;
		while (x < filex)
		{
			map->array[y][x].x = x;
			map->array[y][x].y = y;
			map->array[y][x].z = ft_atoi(split[x]);
			++x;
		}
		arr_free(split, filex + 1);
		free(lines[y++]);
	}
	return (VEC2(x, y));
}

void			parse_map(int fd, t_map *map)
{
	char	*lines[1024];
	char	*line;
	int		count;

	count = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		lines[count] = line;
		++count;
	}
	lines[count] = NULL;
	map->size = process(lines, count, map);
}
