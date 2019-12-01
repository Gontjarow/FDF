/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:47:55 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 18:49:27 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	draw_line(t_line *line)
{
	mlx_clear_window(g_env.mlx, g_env.win);
	static double shiftx = 4;
	static double shifty = 2;
	double	dx = ((line->end.x + (shiftx += 4)) - line->start.x);
	double	dy = ((line->end.y + (shifty += 2)) - line->start.y);
	size_t	step = (ABS(dx) >= ABS(dy) ? ABS(dx) : ABS(dy));
	dx /= step;
	dy /= step;

	size_t	i = 1;
	double	x = line->start.x;
	double	y = line->start.y;
	while (i <= step)
	{
		mlx_pixel_put(g_env.mlx, g_env.win, x, y, line->color);
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
	return (1);
}
