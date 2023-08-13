/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:53:10 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/13 23:49:59 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
//printf("ration = %f == bresenham else\n", ratio);