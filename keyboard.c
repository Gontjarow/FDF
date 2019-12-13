/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:44:22 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 18:02:46 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		pan_map(t_map *map, double movex, double movey)
{
	int x;
	int y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			map->array[y][x].x += movex;
			map->array[y][x].y += movey;
			++x;
		}
		++y;
	}
}

static void		rot_map(t_map *map, t_matrix mat)
{
	int x;
	int y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			map->array[y][x] = vec3_mulmat(map->array[y][x], mat);
			++x;
		}
		++y;
	}
}

static void		check_wasd(int keycode, t_map *map)
{
	if (keycode == key_W)
		pan_map((t_map *)map, 0, -5);
	else if (keycode == key_A)
		pan_map((t_map *)map, -5, 0);
	else if (keycode == key_S)
		pan_map((t_map *)map, 0, 5);
	else if (keycode == key_D)
		pan_map((t_map *)map, 5, 0);
}

static void		check_8456(int keycode, t_map *map)
{
	if (keycode == key_num8)
		rot_map(map, mat_new_rotx(10 * DEG_TO_RAD));
	else if (keycode == key_num4)
		rot_map(map, mat_new_roty(10 * DEG_TO_RAD));
	else if (keycode == key_num5)
		rot_map(map, mat_new_rotx(-10 * DEG_TO_RAD));
	else if (keycode == key_num6)
		rot_map(map, mat_new_roty(-10 * DEG_TO_RAD));
}

int				keyboard(int keycode, void *map)
{
	static double	map_scale = 20;
	static int		proj_type = 1;

	if (map_scale == 0)
		map_scale = 1;
	if (keycode == key_ESC)
		exit(0);
	check_wasd(keycode, map);
	check_8456(keycode, map);
	if (keycode == key_numPLUS)
		map_scale += 10;
	else if (keycode == key_numMIN)
		map_scale -= 10;
	else if (keycode == key_P)
		proj_type = !proj_type;
	if (proj_type)
		draw_map_iso(map, map_scale);
	else
		draw_map_para(map, map_scale);
	return (1);
}
