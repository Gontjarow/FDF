/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_para.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:39:46 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 19:39:45 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw(t_map *map, t_xyz point, t_xyz next, double scale)
{
	t_line	direction;

	direction = (t_line){
		{point.x * scale, point.y * scale},
		{next.x * scale, next.y * scale},
		orange
	};
	draw_line(map, &direction);
}

int			draw_map_para(t_map *map, double scale)
{
	t_xyz	point;
	int		x;
	int		y;

	mlx_clear_window((*map).window.mlx, (*map).window.win);
	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			point = map->array[y][x];
			if (x + 1 < map->size.x)
			{
				draw(map, point, map->array[y][x + 1], scale);
			}
			if (y + 1 < map->size.y)
			{
				draw(map, point, map->array[y + 1][x], scale);
			}
			++x;
		}
		++y;
	}
	return (1);
}
