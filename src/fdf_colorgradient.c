/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colorgradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:26:18 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 00:04:35 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* White -> Blue */
int	*fdf_colorgradient_1(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0xffffff;
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color -= 0x000100;
		color -= 0x010000;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}
//malloc of 256 cases
//0xffffff = white
//every case contains a different color

/* Yellow -> Red */
int	*fdf_colorgradient_2(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0xffff00;
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color -= 0x000100;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}
//0xffff00 = yellow

/* Blue -> Purple */
int	*fdf_colorgradient_3(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0x00ffff;
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color += 0x010000;
		color -= 0x000100;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}
//0x00ffff = blue

/* Yellow -> Pink */
int	*fdf_colorgradient_4(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0xffff00;
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color -= 0x000100;
		color += 0x000001;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}
//0xffff00 = yellow

int	*fdf_colorgradient(t_mlx *data)
{
	if (data->gradient == 1)
		return (fdf_colorgradient_1(data));
	else if (data->gradient == 2)
		return (fdf_colorgradient_2(data));
	else if (data->gradient == 3)
		return (fdf_colorgradient_3(data));
	else if (data->gradient == 4)
		return (fdf_colorgradient_4(data));
	else
		data->gradient = 1;
	return (fdf_colorgradient_1(data));
}

//gradient predefined to 1, but could be changed with key c
//permet de na pas avoir de gradient superieur a 4
//printf("-entering colorgradient-\ndata->gradient = %d\n", 
//data->gradient);
