/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:39:46 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/09 18:25:46 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

int		draw_map(t_map *map, double scale, t_xy (*perspective)(t_xyz))
{
	t_line	left;
	t_line	down;
	t_xy	next;
	int x;
	int y;

	mlx_clear_window((*map).window.mlx, (*map).window.win);

	left.color = orange;
	down.color = red;
	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			t_xy iso = perspective(map->array[y][x]);

			if (x + 1 < map->size.x)
			{
				next = perspective(map->array[y][x + 1]);
				left.pos = VEC2(iso.x * scale, iso.y * scale);
				left.end = VEC2(next.x * scale, next.y * scale);
				draw_line((*map).window.mlx, (*map).window.win, left);
			}
			if (y + 1 < map->size.y)
			{
				next = perspective(map->array[y + 1][x]);
				down.pos = VEC2(iso.x * scale, iso.y * scale);
				down.end = VEC2(next.x * scale, next.y * scale);
				draw_line((*map).window.mlx, (*map).window.win, down);
			}
			++x;
		}
		++y;
	}
	return (1);
}
