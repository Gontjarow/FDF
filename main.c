/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:04:39 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 18:04:40 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > 0)
	{
		if ((map = (t_map*)malloc(sizeof(t_map))))
		{
			parse_map(fd, map);
			close(fd);
			map->window.mlx = mlx_init();
			map->window.size.x = map->size.x * 20;
			map->window.size.y = map->size.y * 20;
			map->window.win = mlx_new_window(map->window.mlx,
				map->window.size.x, map->window.size.y, "Cinematic 16:9 (tm)");
			draw_map_iso(map, 20);
			mlx_key_hook(map->window.win, &keyboard, map);
			mlx_loop(map->window.mlx);
		}
		else
			die("Failed to allocate memory in main.");
	}
	else
	{
		ft_putendl("usage:\t./fdf input_file");
	}
}
