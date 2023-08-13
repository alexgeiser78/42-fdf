/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:25:32 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/13 23:48:28 by mamita           ###   ########.fr       */
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
//rgb est une fonction qui permet de mettre en bit les 3 x 256 
//printf("vr.current.x = %f vr.current.y = %f\n", 
//vr.current.x, vr.current.y);
//printf("vr.scl = %d\n", vr.scl.val);
//printf("vr.ecl = %d\n", vr.ecl.val);
// relie les point entre eux en valeur absolue
//printf("vr.diff = %f\n", vr.diff);
//printf("vr.current = %d\n", vr.current.color);
//printf("vr.ratio = %f\n", vr.ratio);
//printf("vr.i = %f\n", vr.i);