/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc2d_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:51:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 15:01:06 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**malloc2d_int(t_xy dimensions)
{
	int		**rows;
	size_t	count;

	if((rows = (int **)malloc(sizeof(int **) * dimensions.y)))
	{
		count = 0;
		while (count < dimensions.y)
		{
			if (NULL == (rows[count] = (int *)malloc(sizeof(int) * dimensions.x)))
			{
				free2d((void **)rows, sizeof(int), count);
				return (NULL);
			}
			++count;
		}
	}
	return (rows);
}
