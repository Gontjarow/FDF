/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_nulls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:39:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/04 16:35:44 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is similar to ft_pustrn,
** except each non-printing character (including NULL) is replaced
** by the specified character, preferably one that
** should not be encountered in n bytes.
*/

void	ft_putstrn_nulls(const char *str, const char c, size_t n)
{
	size_t		byte;

	if (str != NULL)
	{
		byte = 0;
		while (byte < n)
		{
			if (!ft_isprint(str[byte]))
				write(1, &c, 1);
			else
				write(1, &str[byte], 1);
			++byte;
		}
	}
}
