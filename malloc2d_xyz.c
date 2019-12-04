/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2d_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:51:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/04 16:07:28 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xyz	**malloc2d_xyz(t_xy size)
{
	t_xyz	**rows;
	int		x;
	int		y;

	if((rows = (t_xyz **)malloc(size.y * sizeof(t_xyz **))))
	{
		y = 0;
		while (y < size.y)
		{
			x = 0;
			while (x < size.x)
			{
				if (NULL == (rows[x] = (t_xyz *)malloc(size.x * sizeof(t_xyz))))
					die("malloc failed in malloc2dxyz");
				++x;
			}
			++y;
		}
	}
	return (rows);
}
