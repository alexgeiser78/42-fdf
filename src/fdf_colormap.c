/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colormap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:31:35 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 00:09:41 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

long	fdf_colorgradient_indice(t_mlx *data, int x, int y)
{
	long	range;
	long	max;
	long	heigth;
	long	indice;

	range = data->mapctr.range;
	max = data->mapctr.max;
	heigth = (data->mapctr.map[x][y].z);
	indice = ((range - (max - heigth)) * data->nbrcolors) / range;
	return (indice);
}
//choosing the color tab to use

void	fdf_empty_colormap(t_mlx *data, int *colors)
{
	long	x;
	long	y;

	if (!colors)
	{
		ft_exit("ERR_ALLOC");
	}
	x = 0;
	while (x < data->mapctr.width)
	{
		y = 0;
		while (y < data->mapctr.height)
		{
			if (data->mapctr.map[x][y].color)
				data->mapctr.map[x][y].color = 0;
			y++;
		}
		x++;
	}
}

//reseting the color tab

void	fdf_colormap(t_mlx *data, int *colors)
{
	long	x;
	long	y;

	if (!colors)
	{
		ft_exit("Unattributed Color");
	}
	x = 0;
	while (x < data->mapctr.width)
	{
		y = 0;
		while (y < data->mapctr.height)
		{
			if (!(data->mapctr.map[x][y].color))
				data->mapctr.map[x][y].color = \
						colors[fdf_colorgradient_indice(data, x, y)];
			y++;
		}
		x++;
	}
}

//setting the colour tab
//printf("(range:%ld - (max:%ld - height:%ld) * nbrcolors:%d) / 
//range:%ld == indice = %ld\n", 
//range, max, heigth, data->nbrcolors, range, indice);
