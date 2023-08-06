/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:19:08 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/30 13:19:11 by ageiser          ###   ########.fr       */
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

//static void	fdf_colorset_screen(t_mlx *data)
//{
//	int	x;
//	int	y;

//	printf("-entering colorset screen-");//
//	if (FDF_WIDTH < 1000 || FDF_HEIGHT < 500)
//		return ;
//	x = 0;
//	while (x < 255)
//	{
//		y = 0;
//		while (y < 25) //25?
//		{
//			fdf_put_pixel(data, data->colors[x], data->img.str 
//	+ ((long)(y + 25)*(long)data->img.size_line) 
//	+ ((long)(FDF_WIDTH - 255 + x - 35)*(long)(data->img.bpp / 8)));
//			y++; //255 + x - 35 mais biensur
//		}
//		x++;
//	}
//}
//	fdf_colorset_screen(data);
	//mlx_clear_window(data->ptr, data->win); 
	//put the window in black maybe unnecessary
//	printf("-entering put image to window-");//
//	mlx_put_image_to_window(data->ptr, 
//			data->win, data->img.ptr, 0, 0); //dessine enfin l'image a l'ecran
	//printf("image painted");
//	return (1);
//}