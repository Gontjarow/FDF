/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:04:42 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/29 20:41:08 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*pointer;
	size_t	length;
	size_t	i;

	pointer = NULL;
	if (str != NULL)
	{
		length = ft_strlen(str) + 1;
		i = 0;
		c = (char)c;
		while (i < length)
		{
			if (str[i] == c)
			{
				pointer = (char *)&str[i];
				break ;
			}
			++i;
		}
	}
	return (pointer);
}
