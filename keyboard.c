/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:44:22 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 18:45:09 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyboard(int keycode, void *param)
{
	(void)param;
	if (keycode == key_ESC)
		exit (0);
	;
	ft_putstr("pressed "); ft_putnbr(keycode); ft_putendl("");
	return (1);
}
