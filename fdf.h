/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:33:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/09 21:56:34 by ngontjar         ###   ########.fr       */
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

# define VEC2(a,b) (t_xy){a,b}
typedef struct	s_xy
{
	double	x;
	double	y;
}				t_xy;


# define VEC3(a,b,c) (t_xy){a,b,c}
typedef struct s_xyz
{
	double	x;
	double	y;
	double	z;
}				t_xyz;

# define LINE(aX,aY,bX,bY,color) (t_line){{aX,aY},{bX,bY},color}
typedef struct	s_line
{
	t_xy	pos;
	t_xy	end;
	int		color;
}				t_line;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	t_xy	size;
}				t_window;

typedef struct s_map
{
	t_xyz		**array;
	t_xy		size;
	t_window	window;
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
	key_D = 2,
	key_numPLUS = 69,
	key_numMIN = 78

};

# define SQRT2 (1.4142135623730950488016887242096980785696)
# define SQRT6 (2.4494897427831780981972840747058913919659)

void			die(char *error);
t_xyz			**malloc2d_xyz(t_xy size);

void			parse_map(int fd, t_map *map);

int				draw_line(void *mlx, void *win, t_line line);
int				draw_map(t_map *map, double scale, t_xy (*perspective)(t_xyz));

int				keyboard(int keycode, void *param);

t_xy			project_isometric_point(t_xyz p);

#endif
