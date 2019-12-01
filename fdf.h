/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:33:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 15:08:24 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

typedef struct	s_xy
{
	size_t	x;
	size_t	y;
}				t_xy;

typedef struct	s_rect
{
	t_xy pos;
	t_xy size;
	int color;
}				t_rect;

typedef enum	e_color
{
	black = 0x0,
	white = 0xFFFFFF,
	red = 0xEF1048,
	green = 0x27E11E,
	blue = 0x007CFF,
	orange = 0xFF8300,
	tangelo = 0xf94d00,
	yellow = 0xFFFF56
}				t_color;

void			free2d_terminated(char **strarray);
void			free2d(void **array, size_t type_size, size_t count);
int				get_dimensions(char *file, t_xy *dimensions);
int				**malloc2d_int(t_xy dimensions);
int				draw_rect(void *mlx_ptr, void *win_ptr, t_rect rect);

#endif