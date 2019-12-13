/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:08:59 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 18:05:21 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	cleanup(char ***data, size_t words)
{
	char	**array;
	size_t	i;

	array = *data;
	i = 0;
	while (i < words)
	{
		free(array[i]);
	}
	free(*data);
	*data = NULL;
}

static int	word_count(const char *str, char c)
{
	size_t	count;
	int		reading;

	count = 0;
	reading = FALSE;
	while (*str)
	{
		if ((!reading && *str != c) && ++count)
			reading = TRUE;
		else if (reading && *str == c)
			reading = FALSE;
		++str;
	}
	return (count);
}

/*
** Returns TRUE if allocations were successful.
** Otherwise FALSE and cleans up any allocations so far.
*/

static int	split_to_array(char **data, const char *str, char c)
{
	int			reading;
	const char	*end;
	size_t		length;
	size_t		i;

	i = 0;
	reading = FALSE;
	while (*str)
	{
		if (!reading && *str != c)
		{
			reading = TRUE;
			end = ft_strchr(str, c);
			length = (end ? (size_t)(end - str) : ft_strlen(str));
			if ((data[i] = ft_strsub(str, 0, length)) == NULL)
				return (FALSE);
			++i;
		}
		else if (reading && *str == c)
			reading = FALSE;
		++str;
	}
	return (TRUE);
}

char		**ft_strsplit(const char *str, char c)
{
	char		**data;
	size_t		bytes;
	size_t		words;

	data = NULL;
	if (str)
	{
		words = (word_count(str, c) + 1);
		bytes = sizeof(char *) * words;
		if ((data = (char **)malloc(bytes)))
		{
			ft_memset((void *)data, '\0', bytes);
			if (bytes > sizeof(char *) && !split_to_array(data, str, c))
				cleanup(&data, words);
		}
	}
	return (data);
}
