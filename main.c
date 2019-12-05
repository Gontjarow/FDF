#include "mlx.h"
#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int			fd;
	t_map		map;
	t_shape		line;

	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > 0)
	{
		parse_map(fd, &map);
		close(fd);

		ft_putnbr(map.size.x); ft_putendl(" - width");
		ft_putnbr(map.size.y); ft_putendl(" - height");

		g_env.mlx = mlx_init();
		g_env.size.x = map.size.x * 50;
		g_env.size.y = map.size.y * 50;
		g_env.win = mlx_new_window(g_env.mlx,
			g_env.size.x, g_env.size.y, "Cinematic 16:9 (tm)");

		line.pos = (t_xy){g_env.size.x / 2, g_env.size.y / 2};
		line.data = (t_xy){line.pos.x + 90, line.pos.y + 90};
		line.color = orange;

		// mlx_loop_hook(g_env.mlx, &draw_map, map.array);
		mlx_key_hook(g_env.win, &keyboard, &map);
		mlx_loop(g_env.mlx);
	}
	else
	{
		ft_putendl("usage:\t./fdf input_file");
	}
}
