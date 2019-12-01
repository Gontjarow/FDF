/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:32:18 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 13:54:45 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free2d(void **array, size_t type_size, size_t count)
{
	size_t	i;
	char	**ptr;

	ptr = (char **)array;
	i = 0;
	while (i < count)
	{
		free(ptr[i * type_size]);
		++i;
	}
	free(array);
}
