/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:44:22 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/09 18:55:35 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void pan_map(t_map map, t_xy offset)
{
	int x;
	int y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			map.array[y][x].x += offset.x;
			map.array[y][x].y += offset.y;
			++x;
		}
		++y;
	}
}

int		keyboard(int keycode, void *map)
{
	static double map_scale = 20;

	if (map_scale == 0)
		map_scale = 1;
	if (keycode == key_ESC)
		exit (0);
	else if (keycode == key_W)
		pan_map(*(t_map *)map, (t_xy){0, -5});
	else if (keycode == key_A)
		pan_map(*(t_map *)map, (t_xy){-5, 0});
	else if (keycode == key_S)
		pan_map(*(t_map *)map, (t_xy){0, 5});
	else if (keycode == key_D)
		pan_map(*(t_map *)map, (t_xy){5, 0});
	else if (keycode == key_numPLUS)
		map_scale += 10;
	else if (keycode == key_numMIN)
		map_scale -= 10;
	draw_map(map, map_scale, &project_isometric_point);
	return (1);
}
