/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:09:10 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 17:47:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xy	to_isometric(t_xyz p)
{
	return ((t_xy){
		(p.x - p.z) / SQRT2,
		(p.x + (p.y * 2) + p.z) / SQRT6
	});
}
