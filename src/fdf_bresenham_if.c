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

static int	fdf_bresenham_if_while_color(t_point base, t_point current, \
t_bresenham vr)
{
	if (base.x < current.x)
		vr.current.color = rgb(((vr.bcol.r * (1 - (vr.current.x - base.x) / \
	vr.diff)) + (vr.ccol.r * (((vr.current.x - base.x) / \
	vr.diff)))), ((vr.bcol.g * (1 - (vr.current.x - base.x) / \
	vr.diff)) + (vr.ccol.g * (((vr.current.x - base.x) / \
	vr.diff)))), ((vr.bcol.b * (1 - (vr.current.x - base.x) / \
	vr.diff)) + (vr.ccol.b * (((vr.current.x - base.x) / vr.diff)))));
	else
		vr.current.color = rgb(((vr.bcol.r * ((vr.current.x - current.x) / \
		vr.diff)) + (vr.ccol.r * (1 - ((vr.current.x - current.x) / \
		vr.diff)))), ((vr.bcol.g * ((vr.current.x - current.x) / \
		vr.diff)) + (vr.ccol.g * (1 - ((vr.current.x - current.x) / \
		vr.diff)))), ((vr.bcol.b * ((vr.current.x - current.x) / \
		vr.diff)) + (vr.ccol.b * (1 - ((vr.current.x - current.x) / \
		vr.diff)))));
	return (vr.current.color);
}

//used to calc the color add r g b values

static void	fdf_bresenham_if_while(t_mlx *data, \
		t_point base, t_point current, t_bresenham vr)
{
	while ((int)(vr.current.x + 0.5) != (int)(current.x + 0.5))
	{
		vr.current.color = fdf_bresenham_if_while_color(base, current, vr);
		if (vr.current.x < current.x)
			vr.current.x += 1;
		else
			vr.current.x -= 1;
		if (vr.current.y < current.y)
			vr.current.y = base.y + (vr.ratio * vr.i);
		else
			vr.current.y = base.y - (vr.ratio * vr.i);
		(vr.i)++;
		if (vr.current.x >= 0 && vr.current.x < FDF_WIDTH \
					&& vr.current.y >= 0 && vr.current.y < FDF_HEIGHT)
			fdf_call_put_pixel(data, vr.current);
	}
}
//algorithme of Bresenham to trace to most precise line using pixels
// the + 0.5 is to discover which pixel is the closest to draw the line

void	fdf_bresenham_if(t_mlx *data, \
		t_point base, t_point current, float ratio)
{
	t_bresenham	vr;

	if ((base.x < 0 || base.x >= FDF_WIDTH || base.y < 0 \
	|| base.y >= FDF_HEIGHT) && (current.x < 0 || current.x >= FDF_WIDTH \
	|| current.y < 0 || current.y >= FDF_HEIGHT))
		return ;
	vr.bcol = rrgb(base.color);
	vr.ccol = rrgb(current.color);
	vr.diff = fabs(current.x - base.x);
	vr.current = base;
	vr.ratio = ratio;
	vr.i = 0;
	fdf_bresenham_if_while(data, base, current, vr);
}
//vr created with t_bresenham struct
//struct init
// fabs = absolute value of a floating point (-4 or +4 = 4)

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