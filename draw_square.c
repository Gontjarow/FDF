#include "fdf.h"
#include "mlx.h"

int		draw_rect(void *mlx_ptr, void *win_ptr, t_rect rect)
{
	size_t	w;
	size_t	h;

	h = 0;
	while (h < rect.size.y)
	{
		w = 0;
		while (w < rect.size.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr,
				rect.pos.x + w, rect.pos.y + h, rect.color);
			++w;
		}
		++h;
	}
	return (1);
}
