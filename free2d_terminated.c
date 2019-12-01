/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d_terminated.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:30:43 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 12:36:02 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free2d_terminated(char **strarray)
{
	size_t	i;

	i = 0;
	while (strarray[i])
	{
		free(strarray[i]);
		++i;
	}
	free(strarray);
}
