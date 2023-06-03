#include "../include/fdf.h"

long	fdf_colorgradient_indice(t_mlx *data, int x, int y)
{
	long	range;
	long	max;
	long	point;
	long	indice;

	range = data->mapctr.range;
	max = data->mapctr.max;
	point = (data->mapctr.map[x][y].z);
	indice = ((range - (max - point)) * data->nbrcolors) / range;
	return (indice);
}

void	fdf_empty_colormap(t_mlx *data, int *colors)
{
	long	x;
	long	y;

	if (!colors)
	{
		ft_exit("ERR_ALLOC");
	}
	x = 0;
	while (x < data->mapctr.width)
	{
		y = 0;
		while (y < data->mapctr.height)
		{
			if (data->mapctr.map[x][y].color)
				data->mapctr.map[x][y].color = 0;
			y++;
		}
		x++;
	}
}

void	fdf_colormap(t_mlx *data, int *colors)
{
	long	x;
	long	y;

	if (!colors)
	{
		ft_exit("ERR_ALLOC");
	}
	x = 0;
	while (x < data->mapctr.width)
	{
		y = 0;
		while (y < data->mapctr.height)
		{
			if (!(data->mapctr.map[x][y].color))
				data->mapctr.map[x][y].color = \
						colors[fdf_colorgradient_indice(data, x, y)];
			y++;
		}
		x++;
	}
}