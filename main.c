#include "mlx.h"
#include "fdf.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > 0)
	{
		// map = (t_map){NULL, {0,0}, {NULL, NULL, {0,0}}};
		parse_map(fd, &map);
		close(fd);
		map.window.mlx = mlx_init(); // BAD_ACCESS ?
		map.window.size.x = map.size.x * 20;
		map.window.size.y = map.size.y * 20;
		map.window.win = mlx_new_window(map.window.mlx,
			map.window.size.x, map.window.size.y, "Cinematic 16:9 (tm)");
		draw_map(&map, 20, &project_isometric_point);
		mlx_key_hook(map.window.win, &keyboard, &map);
		mlx_loop(map.window.mlx);
	}
	else
	{
		ft_putendl("usage:\t./fdf input_file");
	}
}
