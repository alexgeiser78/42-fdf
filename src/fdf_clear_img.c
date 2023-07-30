/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clear_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:18:53 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/30 12:18:57 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_clear_img(t_mlx *data)
{
	if (data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = mlx_new_image(data->ptr, \
			FDF_WIDTH, FDF_HEIGHT);
	data->img.str = mlx_get_data_addr(data->img.ptr, \
			&(data->img.bpp), &(data->img.size_line), \
			&(data->img.endian));
}

/*
void	fdf_clear_img(t_mlx *data)
{
	printf("-clear_img-\n");//
	if (data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr); //permet d'effacer l'image
	data->img.ptr = mlx_new_image(data->ptr, \
			FDF_WIDTH, FDF_HEIGHT);
	data->img.str = mlx_get_data_addr(data->img.ptr, \
			&(data->img.bpp), &(data->img.size_line), \
			&(data->img.endian));
}
//regeneration de l'image
*/
