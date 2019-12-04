#include "fdf.h"
#include "mlx.h"

int		draw_rect(void *mlx_ptr, void *win_ptr, t_shape rect)
{
	int		w;
	int		h;

	h = 0;
	while (h < rect.data.y)
	{
		w = 0;
		while (w < rect.data.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr,
				rect.pos.x + w, rect.pos.y + h, rect.color);
			++w;
		}
		++h;
	}
	return (1);
}
