/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:37:07 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/30 12:37:10 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	fdf_parallel(t_mlx *dt)
{
	fdf_clear_img(dt);
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (FDF_WIDTH <= FDF_HEIGHT)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 135;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}

int	fdf_flat(t_mlx *dt)
{
	fdf_clear_img(dt);
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (FDF_WIDTH <= FDF_HEIGHT)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 45;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}

int	fdf_init2(t_mlx *dt)
{
	dt->deg = deg_init;
	dt->iy = incl_y;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}
// relief = echelle de la hauteur z par rapport a width

int	fdf_default(void *data)
{
	t_mlx	*dt;

	dt = (t_mlx *)data;
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
	{
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, \
	dt->mapctr.width);
	}
	else if (FDF_WIDTH <= FDF_HEIGHT)
	{
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
	}
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > \
	dt->mapctr.height)
	{
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, \
	dt->mapctr.width);
	}
	else
	{
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
	}
	return (fdf_init2(dt));
}

//scale calculating, using FDF_WIDTH ot FDF_HEIGHT / hyp(width or heigth) 
//(default zoom)
//hyp = v(x^2 + y^2)
//hypotf = h permet de calculer la racine carre de la somme des carre de x et y
//sachant que height = nbr de lignes et width = nbr de colonnes
//si on divise la hauteur ou largeur de la window par cette valeur 
//on obtient l'echelle
//exemple case 3 with 42.fdf, FDF_WIDTH > FDF_HEIGHT && 
//dt->mapctr.width > dt->mapctr.height
//1080 / v(19^2 + 19^2) = 1080 / 26.87 = 40.19 

int	fdf_changecolor(t_mlx *dt)
{
	if (dt->colors)
		free(dt->colors);
	else
		return (0);
	fdf_clear_img(dt);
	dt->colors = NULL;
	dt->gradient += 1;
	dt->colors = fdf_colorgradient(dt);
	fdf_empty_colormap(dt, dt->colors);
	fdf_colormap(dt, dt->colors);
	fdf_map_to_screen(dt);
	return (1);
}
/*
int	fdf_parallel(t_mlx *dt)
{
	printf("-parallel-\n");//
	fdf_clear_img(dt);
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (FDF_WIDTH <= FDF_HEIGHT)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 135;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}
*/
/*
int	fdf_flat(t_mlx *dt)
{
	printf("-flat-\n");//
	fdf_clear_img(dt);
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (FDF_WIDTH <= FDF_HEIGHT)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 45;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}
*/

//int	fdf_default(void *data)
//{
//	t_mlx	*dt;
//	dt = (t_mlx *)data;
//	printf("-entering default function-\n");//
//	//fdf_clear_img(dt); necessaire ou pas?
//	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
//		{
//		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, 
//	dt->mapctr.width); //si la largeur est plus grande que la longueur 
//on stocke dans l'argument scale la valeur de 
//		printf("1 FDF_WIDTH'%d'/hyp(.width'%d', .width'%d') = %f\n",FDF_WIDTH, 
//dt->mapctr.width, dt->mapctr.width, dt->scale);
//		}
//	else if (FDF_WIDTH <= FDF_HEIGHT)
//	{
//		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, 
//	dt->mapctr.height);
//		printf("2 FDF_WIDTH'%d'/hyp(.height'%d', .height'%d') = %f\n",
//FDF_WIDTH, dt->mapctr.height, dt->mapctr.height, dt->scale);
//	}
//	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > 
//	dt->mapctr.height)
//	{
//		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, 
//	dt->mapctr.width);
//		printf("3 FDF_HEIGHT'%d'/hyp(.width'%d', .width'%d') = %f\n",FDF_HEIGHT, 
//dt->mapctr.width, dt->mapctr.width, dt->scale);//
//	}
//	else
//	{
//		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, 
//	dt->mapctr.height);
//		printf("4 FDF_HEIGHT'%d'/hyp(.height'%d', .height'%d') = %f\n",
//FDF_HEIGHT,dt->mapctr.height, dt->mapctr.height, dt->scale);//
//	}
//	printf("-setting default values-\n");//
//	dt->deg = 45;
//	printf("dt->deg = %f\n", dt->deg);//
//	dt->iy = 80;
//	printf("dt->iy = %f\n", dt->iy);//iy ?
//	dt->mapctr.translatex = 0;//decalage en x
//	printf("dt->mapctr.translatex = %ld\n", dt->mapctr.translatex);//
//	dt->mapctr.translatey = 0; //decalage en y
//	printf("dt->mapctr.translatey = %ld\n", dt->mapctr.translatey);//
//	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15; 
// pas tres clair a quoii sert relief et pourquoi / 15
//	printf("dt->relief hyp(mapctr.width '%d', mapctr.width'%d') / 15 
//= %f\n", dt->mapctr.width, dt->mapctr.width, dt->relief);////
//	fdf_map_to_screen(dt);
//return (1);
//}

//hypotf = h permet de calculer la racine carre de la somme des carre de x et y
//sachant que height = nbr de lignes et width = nbr de colonnes
//si on divise la hauteur ou largeur de la window par cette valeur 
//on obtient l'echelle
//exemple case 3 with 42.fdf, FDF_WIDTH > FDF_HEIGHT && 
//dt->mapctr.width > dt->mapctr.height
//1080 / v(19^2 + 19^2) = 1080 / 26.87 = 40.19 
/*
int	fdf_changecolor(t_mlx *dt)
{
	printf("-changecolor-\n");//
	if (dt->colors)
		free(dt->colors);
	else
		return (0);
	fdf_clear_img(dt);
	dt->colors = NULL;
	dt->gradient += 1;
	dt->colors = fdf_colorgradient(dt);
	fdf_empty_colormap(dt, dt->colors); //permet de mettre l'arguement color(z) a 0
	fdf_colormap(dt, dt->colors);
	fdf_map_to_screen(dt);
	return (1);
}
*/