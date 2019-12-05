/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:33:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/05 15:13:34 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

/*
** double can accurately represent all 32-bit integers.
** The exact precision cutoff is between 52 and 53 bits.
** Sidenote: float can only represent up to 24 bits.
*/

typedef struct	s_xy
{
	double	x;
	double	y;
}				t_xy;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	t_xy	size;
}				t_window;

typedef struct	s_shape
{
	t_xy	pos;
	t_xy	data;
	int		color;
}				t_shape;

typedef struct s_xyz
{
	double	x;
	double	y;
	double	z;
}				t_xyz;

typedef struct s_map
{
	t_xyz	**array;
	t_xy	size;
}				t_map;

enum	e_color
{
	black = 0x0,
	white = 0xFFFFFF,
	red = 0xEF1048,
	green = 0x27E11E,
	blue = 0x007CFF,
	orange = 0xFF8300,
	tangelo = 0xf94d00,
	yellow = 0xFFFF56
};

enum	e_keycode
{
	key_ESC = 53,
	key_W = 13,
	key_A = 0,
	key_S = 1,
	key_D = 2
};

void			die(char *error);
t_xyz			**malloc2d_xyz(t_xy size);
void			free2d(void **array, size_t type_size, size_t count);
void			free2d_terminated(char **strarray);

void			parse_map(int fd, t_map *map);

int				draw_rect(void *mlx_ptr, void *win_ptr, t_shape rect);
int				draw_line(t_shape *line);
int				draw_map(t_map *map, double scale);
int				draw_gradient_line(t_shape *line, int clr_start, int clr_end);

int				keyboard(int keycode, void *param);

// int				gradient(t_xy current, t_xy start, t_xy end, t_xy delta);
// int				gradient(t_xy delta, int start, int end);
int				gradient(t_xyz current, int start, int end, t_xy delta);

t_window		g_env;
#endif