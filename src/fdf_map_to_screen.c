#include "../include/fdf.h"

static void	fdf_colorset_screen(t_mlx *data)
{
	int	x;
	int	y;

	if (FDF_WIDTH < 1000 || FDF_HEIGHT < 500)
		return ;
	x = 0;
	while (x < 255)
	{
		y = 0;
		while (y < 25) //25?
		{
			fdf_put_pixel(data, data->colors[x], data->img.str \
	+ ((long)(y + 25)*(long)data->img.size_line) \
	+ ((long)(FDF_WIDTH - 255 + x - 35)*(long)(data->img.bpp / 8)));
			y++; //255 + x - 35 mais biensur
		}
		x++;
	}
}

int	fdf_map_to_screen(t_mlx *data)
{
	fdf_map_fill(data);
	fdf_fill_img(data);
	fdf_colorset_screen(data);
	//mlx_clear_window(data->ptr, data->win); //put the window in black maybe unnecessary
	mlx_put_image_to_window(data->ptr, \
			data->win, data->img.ptr, 0, 0); //dessine enfin l'image a l'ecran
	return (1);
}