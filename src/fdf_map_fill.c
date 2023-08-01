/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:07:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/30 13:07:28 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data)
{
	long	x;
	long	y;
	float	old_x;
	t_point	*cur;

	mapctr->xorigin = (((float)mapctr->width - 1.0) / 2) * data->scale;
	mapctr->yorigin = (((float)mapctr->height - 1.0) / 2) * data->scale;
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			cur = &((mapctr->map)[x][y]);
			cur->x = x * data->scale - mapctr->xorigin;
			cur->y = y * data->scale - mapctr->yorigin;
			old_x = cur->x;
			cur->x = old_x * data->deg_cos + cur->y * (-(data->deg_sin));
			cur->y = old_x * data->deg_sin + cur->y * data->deg_cos;
			cur->y = cur->y * data->iy_sin + cur->y * data->iy_cos + \
					FDF_HEIGHT / 2 + mapctr->translatey;
			cur->x = cur->x * 1.41421356237 + FDF_WIDTH / 2 + \
					mapctr->translatex;
		}
	}
}
//origin = calc of the center of rotation
//copy of the map into *cur  ([x][y]) 
//calc of every point of the map regarding the scale and origin
//calc every point using cos and sin
//calc evry point using iy sin and iy cos
//calc every point using tranlate and FDF Heoght and WIDTH
//1.41421356237 = v2

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
//calculate the y point regarding the inclination, used to calculaate
//the relief of the terrain

void	fdf_map_fill(t_mlx *data)
{
	data->deg_sin = sin(data->deg / RAD);
	data->deg_cos = cos(data->deg / RAD);
	data->iy_sin = sin(data->iy / RAD);
	data->iy_cos = cos(data->iy / RAD);
	fdf_map_rotation(&(data->mapctr), data);
	fdf_map_relief(&(data->mapctr), data);
}
//Radian is the angle made by the size of the radius 
//and the circular length of this size
//the value of RAD is 57.295779513082320876798154814105
//integral math used to calculate the size between two points
//when deg or iy changes, those angles are recalculated

//static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data)
//{
//	long	x;
//	long	y;
//	float	old_x;
//	t_point	*cur;
//
//	mapctr->xorigin = (((float)mapctr->width - 1.0) / 2) * data->scale;
//	printf("mapctr->xorigin'%f' = ((mapctr->width '%d' - 1.0) / 2) * 
//data->scale '%f'\n", mapctr->xorigin, mapctr->width, data->scale);//
//	mapctr->yorigin = (((float)mapctr->height - 1.0) / 2) * data->scale;
//	printf("mapctr->yorigin'%f' = ((mapctr->height '%d' - 1.0) / 2) * 
//data->scale '%f'\n\n", mapctr->xorigin, mapctr->height, data->scale);//
//	y = -1;
//	while (++y < mapctr->height)
//	{
//		x = -1;
//		while (++x < mapctr->width)
//		{
//			cur = &((mapctr->map)[x][y]);
//			cur->x = x * data->scale - mapctr->xorigin;
//			printf("cur->x = x '%ld' * data->scale '%f' - 
//mapctr->xorigin '%f'== %f\n", x, data->scale, mapctr->xorigin, cur->x);//
//			cur->y = y * data->scale - mapctr->yorigin;
//			printf("cur->y = y '%ld' * data->scale '%f' - 
//mapctr->yorigin '%f'== %f\n\n", y, data->scale, mapctr->yorigin, cur->y);//
//			old_x = cur->x;
//			printf("old_x = %f = cur->x\n\n", old_x);//
//			cur->x = old_x * data->deg_cos + cur->y * (-(data->deg_sin));
//			printf("old_x '%f'* data->deg_cos '%f'+ cur->y '%f' * 
//(-(data->deg_sin '%f')) == cur->x =='%f'\n", old_x, data->deg_cos, cur->y, 
//data->deg_sin, cur->x);//
//			cur->y = old_x * data->deg_sin + cur->y * data->deg_cos;
//			printf("old_x '%f'* data->deg_sin '%f'+ cur->y '%f' * 
//(-(data->deg_cos '%f')) == cur->y =='%f'\n\n", old_x, data->deg_sin, cur->y, 
//data->deg_cos, cur->y);//
//			cur->y = cur->y * data->iy_sin + cur->y * data->iy_cos + 
//					FDF_HEIGHT / 2 + mapctr->translatey;
//					printf("cur->y '%f'* data->iy_sin '%f' + cur->y '%f'* 
//data->iy_cos '%f'+ FDF_HEIGHT '%d'/ 2 + mapctr->translatey '%ld' == 
//cur->y '%f'\n", cur->y, data->iy_sin, cur->y, data->iy_cos, FDF_HEIGHT, 
//mapctr->translatey, cur->y);//
//			cur->x = cur->x * 1.41421356237 + FDF_WIDTH / 2 + 
//					mapctr->translatex;
//			printf("cur->x '%f'* 1.41421356237 + FDF_WIDTH '%d' / 2 + 
//mapctr->translatex '%ld' == cur->x '%f'\n\n", cur->x, FDF_WIDTH, 
//mapctr->translatex, cur->x);//
//		}
//	}
//}
//origin = calc of the center of rotation
//copy of the map into *cur  ([x][y]) 
//calc of every point of the map regarding the scale and origin
//calc every point using cos and sin
//calc evry point using iy sin and iy cos
//calc every point using tranlate and FDF Heoght and WIDTH
//1.41421356237 = v2

//static void	fdf_map_relief(t_mapctr *mapctr, t_mlx *data)
//{
//	long	x;
//	long	y;
//	float	in_range;

//	printf("-entering map relief-\n");//
//	if (data->mapctr.range == 0)
//		return ;
//	y = -1;
//	while (++y < mapctr->height)
//	{
//		x = -1;
//		while (++x < mapctr->width)
//		{
//			in_range = ((((float)mapctr->range - 
//				((float)mapctr->max - (float)(mapctr->map[x][y].z))) 
//					/ (float)mapctr->range) * data->relief) * 
//						((hypot(data->scale, data->scale)) / 2);
		//printf("range '%ld'- max '%ld'- (z '%f'  / range '%ld') * 
		//relief '%f' * hyp(scale '%f', scale'%f') ==  in_range = %f\n", 
		//mapctr->range, mapctr->max, mapctr->map[x][y].z, mapctr->range, 
		//data->relief, data->scale, data->scale, in_range);//
//			((mapctr->map)[x][y]).y -= in_range * (-(data->iy_cos)) 
//	+ in_range * (data->iy_sin);
	//printf("in_range '%f' * -data->iy_cos '%f' + in_range '%f' * 
	//data->iy_sin '%f' == mapctr->map)[x][y]).y '%f'\n", in_range, 
	//data->iy_cos, in_range, data->iy_sin, mapctr->map[x][y].y);//
//		}
//	}
//}
//*/

/*
void	fdf_map_fill(t_mlx *data)
{
	printf("-entering map-fill function-\n");//
	data->deg_sin = sin(data->deg / RAD);
	//printf("data->deg_sin = sin(data->deg / RAD) == %f\n", data->deg_sin);//
	data->deg_cos = cos(data->deg / RAD);
	//printf("data->deg_cos = cos(data->deg / RAD) == %f\n", data->deg_cos);//
	data->iy_sin = sin(data->iy / RAD);
	//printf("data->iy_sin = sin(data->iy / RAD) == %f\n", data->iy_sin);//
	data->iy_cos = cos(data->iy / RAD);
	//printf("data->iy_cos = cos(data->iy / RAD) == %f\n", data->iy_cos);//
	fdf_map_rotation(&(data->mapctr), data);
	fdf_map_relief(&(data->mapctr), data);
}
*/
//qu'est-ce que viweent foutre ce putain de RAD?
