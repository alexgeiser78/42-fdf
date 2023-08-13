/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_findrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:58:53 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 00:35:00 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_findrangee(t_mapctr *mapctr)
{
	long	x;
	long	y;
	int		current;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			current = ((mapctr->map)[x][y]).z;
			if (current < mapctr->min)
				mapctr->min = current;
			if (current > mapctr->max)
				mapctr->max = current;
		}
	}
	if (mapctr->min < 0)
	{
		if ((-(mapctr->min)) > mapctr->max)
			mapctr->max = (-(mapctr->min));
		else
			mapctr->min = (-(mapctr->max));
	}
	mapctr->range = (long) mapctr->max - (long) mapctr->min;
}
//range calculating the difference between max and min heigth

void	fdf_findrange(t_mapctr *mapctr)
{
	fdf_findrangee(mapctr);
	if (mapctr->range == 0)
		mapctr->range = 1;
}
//range can't be 0
//inversion pour toujours avec le min plus petit que le max
//printf("mapctr->max = %ld\n", mapctr->max);
//printf("mapctr->min = %ld\n", mapctr->min);
//printf("mapctr-range = %ld\n", mapctr->range);//
