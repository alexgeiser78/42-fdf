#include "../include/fdf.h"

static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data)
{
	long	x;
	long	y;
	float	old_x;
	t_point	*cur;

	printf("-entering map rotation-\n");//
	mapctr->xorigin = (((float)mapctr->width - 1.0) / 2) * data->scale; // probablement le centre de rotation 
	printf("mapctr->xorigin = ((mapctr->width '%d' - 1.0) / 2) * data->scale '%f'= %f\n", mapctr->width, data->scale, mapctr->xorigin);//
	mapctr->yorigin = (((float)mapctr->height - 1.0) / 2) * data->scale;
	printf("mapctr->yorigin = ((mapctr->height '%d' - 1.0) / 2) * data->scale '%f'= %f\n", mapctr->height, data->scale, mapctr->yorigin);//
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			cur = &((mapctr->map)[x][y]);
			cur->x = x * data->scale - mapctr->xorigin;
			printf("cur->x = x '%ld' * data->scale '%f' - mapctr->xorigin '%f'== %f\n", x, data->scale, mapctr->xorigin, cur->x);//
			cur->y = y * data->scale - mapctr->yorigin;
			printf("cur->y = y '%ld' * data->scale '%f' - mapctr->yorigin '%f'== %f\n", y, data->scale, mapctr->yorigin, cur->y);//
			old_x = cur->x;
			printf("old_x = %f\n", old_x);//
			cur->x = old_x * data->deg_cos + cur->y * (-(data->deg_sin));
			printf("old_x '%f'* data->deg_cos '%f'+ cur->y '%f' * (-(data->deg_sin '%f')) == cur->x =='%f'\n", old_x, data->deg_cos, cur->y, data->deg_sin, cur->x);//
			cur->y = old_x * data->deg_sin + cur->y * data->deg_cos;
			printf("old_x '%f'* data->deg_sin '%f'+ cur->y '%f' * (-(data->deg_cos '%f')) == cur->y =='%f'\n", old_x, data->deg_sin, cur->y, data->deg_cos, cur->y);//
			cur->y = cur->y * data->iy_sin + cur->y * data->iy_cos + \
					FDF_HEIGHT / 2 + mapctr->translatey;
			cur->x = cur->x * 1.41421356237 + FDF_WIDTH / 2 + \
					mapctr->translatex; //1.41 == racine carree de 2
		}
	}
}

static void	fdf_map_relief(t_mapctr *mapctr, t_mlx *data)
{
	long	x;
	long	y;
	float	in_range;

	if (data->mapctr.range == 0)
		return ;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			in_range = ((((float)mapctr->range - \
				((float)mapctr->max - (float)(mapctr->map[x][y].z))) \
					/ (float)mapctr->range) * data->relief) * \
						((hypot(data->scale, data->scale)) / 2);
			((mapctr->map)[x][y]).y -= in_range * (-(data->iy_cos)) \
	+ in_range * (data->iy_sin);
		}
	}
}

void	fdf_map_fill(t_mlx *data)
{
	printf("-entering map-fill function-\n");//
	data->deg_sin = sin(data->deg / RAD);
	printf("data->deg_sin = sin(data->deg / RAD) == %f\n", data->deg_sin);//
	data->deg_cos = cos(data->deg / RAD);
	printf("data->deg_cos = cos(data->deg / RAD) == %f\n", data->deg_cos);//
	data->iy_sin = sin(data->iy / RAD);
	printf("data->iy_sin = sin(data->iy / RAD) == %f\n", data->iy_sin);//
	data->iy_cos = cos(data->iy / RAD);
	printf("data->iy_cos = cos(data->iy / RAD) == %f\n", data->iy_cos);//
	fdf_map_rotation(&(data->mapctr), data);
	fdf_map_relief(&(data->mapctr), data);
}

//qu'est-ce que viweent foutre ce putain de RAD?