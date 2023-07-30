/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_findrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:58:53 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/30 12:58:55 by ageiser          ###   ########.fr       */
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

/*
void	fdf_findrangee(t_mapctr *mapctr)
{
	long	x;
	long	y;
	int		current;
printf("-entering findrangee-\n");//
	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			current = ((mapctr->map)[x][y]).z;
			if (current < mapctr->min)
				mapctr->min = current; //min heigth
			if (current > mapctr->max)
				mapctr->max = current; //max heigth
		}
	}
	*/

//	if (mapctr->min < 0)
//	{
//		if ((-(mapctr->min)) > mapctr->max) 
//inversion pour toujours avec le min plus petit que le max
//			mapctr->max = (-(mapctr->min));
//		else
//			mapctr->min = (-(mapctr->max));
//	}
	//printf("-min and max heigth-\n");//
	//printf("mapctr->max = %ld\n", mapctr->max);//
	//printf("mapctr->min = %ld\n", mapctr->min);//
//	mapctr->range = (long) mapctr->max - (long) mapctr->min;
	//printf("-range = max - min-\n");//
	//printf("mapctr-range = %ld\n", mapctr->range);//
//}

/*
void	fdf_findrange(t_mapctr *mapctr)
{
	printf("-entering findrange-\n");//
	fdf_findrangee(mapctr);
	if (mapctr->range == 0)// a verifier pourquoi
		mapctr->range = 1;
}
*/