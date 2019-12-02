/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:55 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/02 19:02:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>
#include <time.h>

int	draw_line(t_shape *line)
{
	mlx_clear_window(g_env.mlx, g_env.win);
	t_xy	pixel;
	t_xy	delta;
	int		points;

	// struct timespec tp;
	// clock_gettime(CLOCK_REALTIME, &tp);
	// line->data.x = line->pos.x + 300 * cos(tp.tv_nsec);
	// line->data.y = line->pos.y + 300 * sin(tp.tv_nsec);

	pixel = line->pos;
	delta = (t_xy){line->data.x - line->pos.x, line->data.y - line->pos.y};
	points = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= points;
	delta.y /= points;
	while (points > 0)
	{
		mlx_pixel_put(g_env.mlx, g_env.win, pixel.x, pixel.y, line->color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--points;
	}
	return (1);
}
