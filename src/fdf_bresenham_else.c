/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_else.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:18:52 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/13 23:41:45 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	fdf_bresenham_else_while_color(t_point base, \
		t_point current, t_bresenham vr)
{
	if (base.y < current.y)
		vr.current.color = rgb(((vr.bcol.r * (1 - (vr.current.y - base.y) / \
	vr.diff)) + (vr.ccol.r * (((vr.current.y - base.y) / \
	vr.diff)))), ((vr.bcol.g * (1 - (vr.current.y - base.y) / \
	vr.diff)) + (vr.ccol.g * (((vr.current.y - base.y) / \
	vr.diff)))), ((vr.bcol.b * (1 - (vr.current.y - base.y) / vr.diff)) + \
	(vr.ccol.b * (((vr.current.y - base.y) / vr.diff)))));
	else
		vr.current.color = rgb(((vr.bcol.r * ((vr.current.y - current.y) / \
	vr.diff)) + (vr.ccol.r * (1 - ((vr.current.y - current.y) / vr.diff)))), \
	((vr.bcol.g * ((vr.current.y - current.y) / vr.diff)) + (vr.ccol.g * (1 - \
	((vr.current.y - current.y) / vr.diff)))), ((vr.bcol.b * ((vr.current.y - \
	current.y) / vr.diff)) + (vr.ccol.b * (1 - ((vr.current.y - \
	current.y) / vr.diff)))));
	return (vr.current.color);
}

static void	fdf_bresenham_else_while(t_mlx *data, \
		t_point base, t_point current, t_bresenham vr)
{
	while ((int)(vr.current.y + 0.5) != (int)(current.y + 0.5))
	{
		vr.current.color = fdf_bresenham_else_while_color(base, current, vr);
		if (vr.current.y < current.y)
			vr.current.y += 1;
		else
			vr.current.y -= 1;
		if (vr.current.x < current.x)
			vr.current.x = base.x + (vr.ratio * vr.i);
		else
			vr.current.x = base.x - (vr.ratio * vr.i);
		(vr.i)++;
		if (vr.current.x >= 0 && vr.current.x < FDF_WIDTH \
					&& vr.current.y >= 0 && vr.current.y < FDF_HEIGHT)
			fdf_call_put_pixel(data, vr.current);
	}
}

void	fdf_bresenham_else(t_mlx *data, \
		t_point base, t_point current, float ratio)
{
	t_bresenham	vr;

	if ((base.x < 0 || base.x >= FDF_WIDTH || base.y < 0 \
	|| base.y >= FDF_HEIGHT) && (current.x < 0 || current.x >= FDF_WIDTH \
	|| current.y < 0 || current.y >= FDF_HEIGHT))
		return ;
	vr.bcol = rrgb(base.color);
	vr.ccol = rrgb(current.color);
	vr.diff = fabs(base.y - current.y);
	vr.current = base;
	vr.ratio = ratio;
	vr.i = 0;
	fdf_bresenham_else_while(data, base, current, vr);
}
