#include "../include/fdf.h"

void	fdf_fill_img(t_mlx *data)
{
	int		x;
	int		y;
	t_point	current;

	printf("-entering fill img-\n");//
	y = -1;
	while (++y < data->mapctr.height)
	{
		x = -1;
		while (++x < data->mapctr.width)
		{
			current = data->mapctr.map[x][y];
			if (current.x >= 0 && current.x < FDF_WIDTH \
					&& current.y >= 0 && current.y < FDF_HEIGHT) //si le nombre de collones est plus petit que la taille de l'ecran
			{
				printf("img.str '%p'+ (y '%f' * size_line '%d' ) + (x '%f' * (bpp '%d'/ 8))\n", data->img.str, current.y, data->img.size_line, current.x, data->img.bpp);//
				fdf_put_pixel(data, current.color, data->img.str + \
						((long)(current.y)*(long)data->img.size_line) + \
						((long)(current.x)*(long)(data->img.bpp / 8))); //possible que ca ait un rapport avec les bits vu que / 8
			}
			printf("-entering bresenham-\n");//
			if (x > 0)
				fdf_bresenham(data, data->mapctr.map[x - 1][y], current);
			if (y > 0)
				fdf_bresenham(data, data->mapctr.map[x][y - 1], current);
		}
	}
		
}