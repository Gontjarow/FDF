/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:55 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/09 18:30:00 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	draw_line(void *mlx, void *win, t_line line)
{
	t_xy	pixel;
	t_xy	delta;
	int		points;

	pixel = line.pos;
	delta = VEC2(line.end.x - line.pos.x, line.end.y - line.pos.y);
	points = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= points;
	delta.y /= points;
	while (points > 0)
	{
		mlx_pixel_put(mlx, win, pixel.x, pixel.y, line.color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--points;
	}
	return (1);
}
