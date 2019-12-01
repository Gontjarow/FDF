#include "mlx.h"
#include "fdf.h"



int			main(int argc, char **argv)
{
	int			**map;
	t_xy		scale;
	t_line		line;
	t_rect		rect;

	if (argc == 2 && get_dimensions(argv[1], &scale))
	{
		map = malloc2d_int(scale);
		ft_putnbr(scale.x); ft_putendl(" - width");
		ft_putnbr(scale.y); ft_putendl(" - height");

		g_env.mlx = mlx_init();
		g_env.win = mlx_new_window(g_env.mlx,
			scale.x * 100, scale.y * 100, "Cinematic 16:9 (tm)");

		line = (t_line){{10,10}, {40,40}, white};
		mlx_loop_hook(g_env.mlx, &draw_line, &line);

		rect = (t_rect){{10, 20}, {scale.x, scale.y}, orange};
		draw_rect(g_env.mlx, g_env.win, rect); // won't draw at the same time?

		mlx_key_hook(g_env.win, &keyboard, NULL);
		mlx_loop(g_env.mlx);
	}
	else
	{
		ft_putendl("usage:\t./fdf input_file");
	}
}
