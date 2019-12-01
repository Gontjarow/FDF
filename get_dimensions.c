/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:28:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 15:02:33 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static size_t	arrlen_terminated(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		++i;
	}
	return (i);
}

int				get_dimensions(char *file, t_xy *dimensions)
{
	int		fd;
	char	*line;
	char	**split;
	size_t	width;
	size_t	height;

	if ((fd = open(file, O_RDONLY)) > 0)
	{
		height = 0;
		width = 0;
		while (ft_get_next_line(fd, &line) > 0)
		{
			++height;
			if (width == 0)
			{
				width = arrlen_terminated((split = ft_strsplit(line, ' ')));
				free2d_terminated(split);
			}
			free(line);
		}
		dimensions->x = width;
		dimensions->y = height;
		close(fd);
	}
	return (fd > 0);
}