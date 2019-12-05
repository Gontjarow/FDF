/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:44:22 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/05 14:49:48 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyboard(int keycode, void *map)
{
	static double map_scale;

	if (map_scale == 0)
		map_scale = 1;
	if (keycode == key_ESC)
		exit (0);
	else if (keycode == key_W)
		map_scale += 10;
	else if (keycode == key_S)
		map_scale -= 10;
	draw_map(map, map_scale);
	ft_putstr("pressed "); ft_putnbr(keycode); ft_putendl("");
	return (1);
}
