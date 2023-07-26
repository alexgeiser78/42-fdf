#include "../include/fdf.h"

long	fdf_colorgradient_indice(t_mlx *data, int x, int y)
{
	long	range;
	long	max;
	long	heigth;
	long	indice;

	printf("-colorgradient_indice-\n");//
	range = data->mapctr.range;
	max = data->mapctr.max;
	heigth = (data->mapctr.map[x][y].z);
	indice = ((range - (max - heigth)) * data->nbrcolors) / range; //a conprendre aec un printf
	//printf("(range:%ld - (max:%ld - height:%ld) * nbrcolors:%d) / range:%ld == indice = %ld\n", range, max, heigth, data->nbrcolors, range, indice);//
	return (indice);
}

void	fdf_empty_colormap(t_mlx *data, int *colors)
{
	long	x;
	long	y;

	printf("-empty_colormap-\n");//
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

	printf("-colormap-\n");//
	if (!colors)
	{
		ft_exit("Unattributed Color");
	}
	x = 0;
	while (x < data->mapctr.width)
	{
		y = 0;
		while (y < data->mapctr.height)
		{
			if (!(data->mapctr.map[x][y].color)) //verifier pourquoi il n'y aurait pas de color dans color
				data->mapctr.map[x][y].color = \
						colors[fdf_colorgradient_indice(data, x, y)]; //fonction entre crochets donc induque la position dans le tab de couleur
			//printf("data->mapctr.map[%ld][%ld].color = %d\n", x, y, data->mapctr.map[x][y].color);//
			y++;
		}
		x++;
	}
}