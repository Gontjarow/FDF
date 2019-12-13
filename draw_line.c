/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:55 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 19:41:20 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	draw_line(t_map *map, t_line *line)
{
	t_xy	pixel;
	t_xy	delta;
	int		points;

	pixel = line->pos;
	delta.x = line->end.x - line->pos.x;
	delta.y = line->end.y - line->pos.y;
	points = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= points;
	delta.y /= points;
	while (points > 0)
	{
		if ((pixel.x > 0 && pixel.x < map->window.size.x)
		|| (pixel.y > 0 && pixel.y < map->window.size.y))
			mlx_pixel_put(map->window.mlx, map->window.win,
				pixel.x, pixel.y, line->color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--points;
	}
	return (1);
}
