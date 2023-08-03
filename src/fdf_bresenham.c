/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:53:10 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/27 19:53:13 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_call_put_pixel(t_mlx *data, t_point current)
{
	fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
}

void	fdf_bresenham(t_mlx *data, t_point base, t_point current)
{
	float	xrange;
	float	yrange;
	float	ratio;

	xrange = current.x - base.x;
	if (xrange < 0)
		xrange = xrange * -1;
	yrange = current.y - base.y;
	if (yrange < 0)
		yrange = yrange * -1;
	if (xrange > yrange)
	{
		ratio = yrange / xrange;
		fdf_bresenham_if(data, base, current, ratio);
	}
	else
	{
		ratio = xrange / yrange;
		fdf_bresenham_else(data, base, current, ratio);
	}
}
//calc the ratio between current and base to dispatch to
//if or else

//void	fdf_call_put_pixel(t_mlx *data, t_point current)
//{
	//printf("-entering call put pix-\n");//
//	fdf_put_pixel(data, current.color, data->img.str + 
//				((long)(current.y)*(long)data->img.size_line) + 
//				((long)(current.x)*(long)(data->img.bpp / 8)));
//}
//void	fdf_bresenham(t_mlx *data, t_point s, t_point current) //s?
//{
//	float	xrange;
//	float	yrange;
//	float	ratio;
	//printf("-bresenham\n");//
//	xrange = current.x - s.x; //calcul d'une moyenne sur l'axe x
	//printf("xrange '%f' = current.x '%f'- s.x '%f'\n", 
	//xrange, current.x, s.x);// ne se passe rien
//	if (xrange < 0) //si resultat negatif
//		xrange = xrange * -1; //on le converti en positif
//	yrange = current.y - s.y;
	//printf("yrange '%f' = current.y '%f'- s.y '%f'\n", 
	//yrange, current.y, s.y);//ne se passe rien
//	if (yrange < 0)
//		yrange = yrange * -1;
		//printf("xrange = %f yrange = %f\n", xrange, yrange);//
//	if (xrange > yrange) //si x est plus grand que y
//	{
//		ratio = yrange / xrange;
		//printf("ration = %f == bresenham if\n", ratio);//
//		fdf_bresenham_if(data, s, current, ratio);
//	}
//	else
//	{
//		ratio = xrange / yrange;
		//printf("ration = %f == bresenham else\n", ratio);//
//		fdf_bresenham_else(data, s, current, ratio);
//	}
//}
