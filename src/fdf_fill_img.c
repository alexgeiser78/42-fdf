#include "../include/fdf.h"

void	fdf_fill_img(t_mlx *data)
{
	int		x;
	int		y;
	t_point	current;

	y = -1;
	while (++y < data->mapctr.height)
	{
		x = -1;
		while (++x < data->mapctr.width)
		{
			current = data->mapctr.map[x][y];
			if (current.x >= 0 && current.x < FDF_WIDTH \
					&& current.y >= 0 && current.y < FDF_HEIGHT)
			{
				fdf_put_pixel(data, current.color, data->img.str + \
						((long)(current.y)*(long)data->img.size_line) + \
						((long)(current.x)*(long)(data->img.bpp / 8)));
			}
			if (x > 0)
				fdf_bresenham(data, data->mapctr.map[x - 1][y], current);
			if (y > 0)
				fdf_bresenham(data, data->mapctr.map[x][y - 1], current);
		}
	}
}