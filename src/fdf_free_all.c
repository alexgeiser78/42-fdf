/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:02:28 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 19:13:28 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_free_map(t_point **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

//freeing the map
/*
int	fdf_free_all(t_mlx *data)
{
	if (data->ptr && data->win)
		mlx_destroy_window(data->ptr, data->win);
	data->win = NULL;
	if (data->ptr && data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = NULL;
	if (data->ptr)
	{
		mlx_destroy_window(data->ptr, data->win);
		free(data->ptr);
	}
	data->ptr = NULL;
	if (data->mapctr.map)
		fdf_free_map(data->mapctr.map);
	data->mapctr.map = NULL;
	if (data->colors)
		free(data->colors);
	data->colors = NULL;
	return (0);
}
*/
#ifndef MACOS

int	fdf_free_all(t_mlx *data)
{
	if (data->ptr && data->win)
		mlx_destroy_window(data->ptr, data->win);
	data->win = NULL;
	if (data->ptr && data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = NULL;
	if (data->ptr)
		free(data->ptr);
	data->ptr = NULL;
	if (data->mapctr.map)
		fdf_free_map(data->mapctr.map);
	data->mapctr.map = NULL;
	if (data->colors)
		free(data->colors);
	data->colors = NULL;
	return (0);
}

#endif

#ifdef MACOS

int	fdf_free_all(t_mlx *data)
{
	if (data->ptr && data->win)
		mlx_destroy_window(data->ptr, data->win);
	data->win = NULL;
	if (data->ptr && data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = NULL;
	if (data->ptr)
		free(data->ptr);
	data->ptr = NULL;
	if (data->mapctr.map)
		fdf_free_map(data->mapctr.map);
	data->mapctr.map = NULL;
	if (data->colors)
		free(data->colors);
	data->colors = NULL;
	return (0);
}

#endif