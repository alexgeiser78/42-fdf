/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:19:08 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 01:04:00 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	fdf_colorset_screen(t_mlx *data)
{
	int	x;
	int	y;

	if (FDF_WIDTH < 1000 || FDF_HEIGHT < 500)
		return ;
	x = 0;
	while (x < 255)
	{
		y = 0;
		while (y < 25)
		{
			fdf_put_pixel(data, data->colors[x], data->img.str \
	+ ((long)(y + 25)*(long)data->img.size_line) \
	+ ((long)(FDF_WIDTH - 255 + x - 25)*(long)(data->img.bpp / 8)));
			y++;
		}
		x++;
	}
}
//small color table screen
//will be 255 x 25
//25px down and 25px to the left border

int	fdf_map_to_screen(t_mlx *data)
{
	fdf_map_fill(data);
	fdf_fill_img(data);
	fdf_colorset_screen(data);
	mlx_put_image_to_window(data->ptr, \
			data->win, data->img.ptr, 0, 0);
	return (1);
}
//beginning of the modified part when an event is done
//0, 0 = origin  of the draw
