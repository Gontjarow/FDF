/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:03:39 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/29 16:48:44 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Shortness challenge.
*/

int		ft_atoi(const char *str)
{
	unsigned int	number;
	int				sign;
	size_t			digit;

	if ((digit = (str == NULL)))
		return (0);
	while (ft_isspace(str[digit]))
		++digit;
	sign = ((str[digit] == '-') ? -1 : 1);
	digit += (str[digit] == '-' || str[digit] == '+');
	number = 0;
	while (ft_isdigit(str[digit++]))
		number = (number * 10) + (str[digit - 1] - '0');
	return (sign * number);
}
