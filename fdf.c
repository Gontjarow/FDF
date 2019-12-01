#include "mlx.h"
#include "libft/libft.h"

int		key_press(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putchar('x');
	return (0);
}

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hello world");

	mlx_key_hook(win_ptr, &key_press, NULL);
	mlx_loop(mlx_ptr);
}
