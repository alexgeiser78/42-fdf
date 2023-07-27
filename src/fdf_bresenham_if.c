/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:25:32 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/27 19:25:34 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	fdf_bresenham_if_while_color(t_point s, t_point e, t_bresenham vr)
{
	if (s.x < e.x)
		vr.current.color = rgb(((vr.scl.r * (1 - (vr.current.x - s.x) / \
	vr.diff)) + (vr.ecl.r * (((vr.current.x - s.x) / vr.diff)))), ((vr.scl.g \
	* (1 - (vr.current.x - s.x) / vr.diff)) + (vr.ecl.g * (((vr.current.x - \
	s.x) / vr.diff)))), ((vr.scl.b * (1 - (vr.current.x - s.x) / vr.diff)) \
	+ (vr.ecl.b * (((vr.current.x - s.x) / vr.diff)))));
	else
		vr.current.color = rgb(((vr.scl.r * ((vr.current.x - e.x) / vr.diff)) \
	+ (vr.ecl.r * (1 - ((vr.current.x - e.x) / vr.diff)))), ((vr.scl.g * \
	((vr.current.x - e.x) / vr.diff)) + (vr.ecl.g * (1 - ((vr.current.x - \
	e.x) / vr.diff)))), ((vr.scl.b * ((vr.current.x - e.x) / vr.diff)) + \
	(vr.ecl.b * (1 - ((vr.current.x - e.x) / vr.diff)))));
	return (vr.current.color);
}

static void	fdf_bresenham_if_while(t_mlx *data, \
		t_point s, t_point e, t_bresenham vr)
{
	while ((int)(vr.current.x + 0.5) != (int)(e.x + 0.5))
	{
		vr.current.color = fdf_bresenham_if_while_color(s, e, vr);
		if (vr.current.x < e.x)
			vr.current.x += 1;
		else
			vr.current.x -= 1;
		if (vr.current.y < e.y)
			vr.current.y = s.y + (vr.ratio * vr.i);
		else
			vr.current.y = s.y - (vr.ratio * vr.i);
		(vr.i)++;
		if (vr.current.x >= 0 && vr.current.x < FDF_WIDTH \
					&& vr.current.y >= 0 && vr.current.y < FDF_HEIGHT)
			fdf_call_put_pixel(data, vr.current);
	}
}

void	fdf_bresenham_if(t_mlx *data, \
		t_point s, t_point e, float ratio)
{
	t_bresenham	vr;

	if ((s.x < 0 || s.x >= FDF_WIDTH || s.y < 0 \
	|| s.y >= FDF_HEIGHT) && (e.x < 0 || e.x >= FDF_WIDTH \
	|| e.y < 0 || e.y >= FDF_HEIGHT))
		return ;
	vr.scl = rrgb(s.color);
	vr.ecl = rrgb(e.color);
	vr.diff = fabs(e.x - s.x);
	vr.current = s;
	vr.ratio = ratio;
	vr.i = 0;
	fdf_bresenham_if_while(data, s, e, vr);
}

//static int	fdf_bresenham_if_while_color
//(t_point s, t_point e, t_bresenham vr)
//{	
	//printf("-bresenham_if_while_color\n");//
//	if (s.x < e.x)
//		vr.current.color = rgb(((vr.scl.r * (1 - (vr.current.x - s.x) / 
//	vr.diff)) + (vr.ecl.r * (((vr.current.x - s.x) / vr.diff)))), ((vr.scl.g 
//	* (1 - (vr.current.x - s.x) / vr.diff)) + (vr.ecl.g * (((vr.current.x - 
//	s.x) / vr.diff)))), ((vr.scl.b * (1 - (vr.current.x - s.x) / vr.diff)) 
//	+ (vr.ecl.b * (((vr.current.x - s.x) / vr.diff))))); //args Red Green Blue
//	*//*else
//		vr.current.color = rgb(((vr.scl.r * ((vr.current.x - e.x) / vr.diff)) 
//	+ (vr.ecl.r * (1 - ((vr.current.x - e.x) / vr.diff)))), ((vr.scl.g * \*/
//	((vr.current.x - e.x) / vr.diff)) + (vr.ecl.g * (1 - ((vr.current.x - 
//	e.x) / vr.diff)))), ((vr.scl.b * ((vr.current.x - e.x) / vr.diff)) + 
//	(vr.ecl.b * (1 - ((vr.current.x - e.x) / vr.diff)))));
//	return (vr.current.color);
//}
//rgb est une fonction qui permet de mettre en bit les 3 x 256
//static void	fdf_bresenham_if_while(t_mlx *data, 
//		t_point s, t_point e, t_bresenham vr)
//{
	//printf("-entering bresen if while-\n");//
//	while ((int)(vr.current.x + 0.5) != (int)(e.x + 0.5)) 
//0.5 = approximation pour savoir si il vaut mieux 
//dessiner un pixel plutot qu'un autre
//	{
//		vr.current.color = fdf_bresenham_if_while_color(s, e, vr);
		//printf("vr.current.color = %d\n", vr.current.color);//s
//		if (vr.current.x < e.x)
//			vr.current.x += 1;
//		else
//			vr.current.x -= 1;
//		if (vr.current.y < e.y)
//			vr.current.y = s.y + (vr.ratio * vr.i);
//		else
//			vr.current.y = s.y - (vr.ratio * vr.i);
//		(vr.i)++;
		//printf("vr.current.x = %f vr.current.y = %f\n", 
		//vr.current.x, vr.current.y);//
//		if (vr.current.x >= 0 && vr.current.x < FDF_WIDTH 
//					&& vr.current.y >= 0 && vr.current.y < FDF_HEIGHT)
//			fdf_call_put_pixel(data, vr.current);
//	}	
//}

/*
void	fdf_bresenham_if(t_mlx *data, \
		t_point s, t_point e, float ratio)
{
	t_bresenham	vr;
	//printf("-bresenham_if\n");//
	if ((s.x < 0 || s.x >= FDF_WIDTH || s.y < 0 \
	|| s.y >= FDF_HEIGHT) && (e.x < 0 || e.x >= FDF_WIDTH \
	|| e.y < 0 || e.y >= FDF_HEIGHT))
		return ;
	vr.scl = rrgb(s.color);
	//printf("vr.scl = %d\n", vr.scl.val);//
	vr.ecl = rrgb(e.color);
	//printf("vr.ecl = %d\n", vr.ecl.val);//
	vr.diff = fabs(e.x - s.x); // relie les point entre eux en valeur absolue
	//printf("vr.diff = %f\n", vr.diff);//
	vr.current = s;
	//printf("vr.current = %d\n", vr.current.color);//
	vr.ratio = ratio;
	//printf("vr.ratio = %f\n", vr.ratio);//
	vr.i = 0;
	//printf("vr.i = %f\n", vr.i);//
	fdf_bresenham_if_while(data, s, e, vr);
}*/