#include "mlx.h"
#include "fdf.h"

static int	key_press(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit (0);
	;
	ft_putnbr(key);
	ft_putendl("");
	return (0);
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_xy	dimensions;
	int		**map;

	if (argc == 2)
	{
		get_dimensions(argv[1], &dimensions);
		map = malloc2d_int(dimensions);
		ft_putnbr(dimensions.x); ft_putendl("");
		ft_putnbr(dimensions.y); ft_putendl("");
		ft_putendl(ft_itoa(map[3][3]));

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 800, 450, "Cinematic 16:9 (tm)");
		mlx_key_hook(win_ptr, &key_press, NULL);
		t_xy cell_size = { 800/19, 450/11 };
		draw_rect(mlx_ptr, win_ptr, (t_rect){{0, 0}, cell_size, orange});
		ft_putendl("I AM HERE!");

		mlx_loop(mlx_ptr);
	}
	else
	{
		ft_putendl("usage:\t./fdf input_file");
	}
}
