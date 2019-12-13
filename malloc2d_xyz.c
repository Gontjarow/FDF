/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2d_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:51:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 20:45:35 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xyz	**malloc2d_xyz(t_xy size)
{
	t_xyz	**rows;
	int		y;

	if ((rows = (t_xyz **)malloc(size.y * sizeof(t_xyz **))))
	{
		y = 0;
		while (y < size.y)
		{
			rows[y] = (t_xyz *)malloc(size.x * sizeof(t_xyz));
			if (rows[y] == NULL)
				die("malloc failed in malloc2dxyz");
			++y;
		}
	}
	return (rows);
}
