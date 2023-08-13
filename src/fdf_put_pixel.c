/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:28:26 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 01:14:58 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	fdf_put_pixel(t_mlx *data, int color, char *pixel)
{
	t_color	tcolor;

	if (pixel < data->img.str || pixel >= (data->img.str + \
			((FDF_HEIGHT - 1) * data->img.size_line) + \
			((FDF_WIDTH - 1) * (data->img.bpp / 8))))
		return (0);
	tcolor = rrgb(color);
	if (data->img.endian == 1)
	{
		*(pixel + 0) = 0;
		*(pixel + 1) = tcolor.r;
		*(pixel + 2) = tcolor.g;
		*(pixel + 3) = tcolor.b;
	}
	else if (data->img.endian == 0)
	{
		*(pixel + 3) = 0;
		*(pixel + 2) = tcolor.r;
		*(pixel + 1) = tcolor.g;
		*(pixel + 0) = tcolor.b;
	}
	else
		return (0);
	return (1);
}

//*pixel is a pointer to the memory where the pixel color 
//information is stored
//endian 1 for MacOs
//pixel + 0 = alpha 
//4 bits pers pixel
//endian 0 on MACOS

/*unsigned char r, g, b, a;

    // Access the color components in the pixel memory location
    b = *(pixel + 0); // Blue component
	g = *(pixel + 1); // Green component
    r = *(pixel + 2); // Red component
    a = *(pixel + 3); // Alpha component
   

    // Print the color component values
    printf("Alpha: %u, Red: %u, Green: %u, Blue: %u\n", a, r, g, b);*/

//	unsigned char q = *pixel;
//	printf("%u", q);
//printf("tcolor r = %c g = %c b = %c\n", tcolor.r, 
//tcolor.g, tcolor.b);

void	fdf_call_put_pixel(t_mlx *data, t_point current)
{
	fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
}

//callback fuction when an event occurs


