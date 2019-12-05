/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:39:46 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/05 15:23:57 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		draw_map(t_map *map, double scale)
{
	t_xy	point;
	t_shape	left;
	t_shape	down;

	point = (t_xy){0, 0};
	left = (t_shape){{0,0}, {0,0}, orange};
	down = (t_shape){{0,0}, {0,0}, red};
	mlx_clear_window(g_env.mlx, g_env.win);
	while (point.y < map->size.y)
	{
		point.x = 0;
		while (point.x < map->size.x)
		{
			// double height = map->array[(int)point.y][(int)point.x].z;
			// left.color = gradient();
			if (point.x + 1 < map->size.x)
			{
				left.pos = (t_xy){point.x * scale, point.y * scale};
				left.data = (t_xy){left.pos.x + scale, left.pos.y};
				// draw_gradient_line(&left, orange, red);
				draw_line(&left);
				printf("draw left from x%1.0f->%1.0f y%1.0f->%1.0f\n",
					point.x, point.x * scale, point.y, point.y * scale);
			}
			if (point.y + 1 < map->size.y)
			{
				down.pos = (t_xy){point.x * scale, point.y * scale};
				down.data = (t_xy){down.pos.x, down.pos.y + scale};
				// draw_gradient_line(&down, orange, red);
				draw_line(&down);
				printf("draw down from x%1.0f->%1.0f y%1.0f->%1.0f\n",
					point.x, point.x * scale, point.y, point.y * scale);
			}
			++point.x;
		}
		++point.y;
	}
	return (1);
}
