/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2d_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:51:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/02 19:55:36 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xyz	**malloc2d_xyz(t_xy size)
{
	t_xyz	**rows;
	size_t	i;

	if((rows = (t_xyz **)malloc(sizeof(t_xyz **) * size.y)))
	{
		i = 0;
		while (i < size.y)
		{
			if (NULL == (rows[i] = (t_xyz *)malloc(sizeof(t_xyz) * size.x)))
			{
				free2d((void **)rows, sizeof(t_xyz), i);
				return (NULL);
			}
			++i;
		}
	}
	return (rows);
}
