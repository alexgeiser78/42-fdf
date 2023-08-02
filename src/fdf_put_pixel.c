/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:28:26 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/30 13:28:29 by ageiser          ###   ########.fr       */
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

/*unsigned char r, g, b, a;

    // Access the color components in the pixel memory location
    b = *(pixel + 0); // Blue component
	g = *(pixel + 1); // Green component
    r = *(pixel + 2); // Red component
    a = *(pixel + 3); // Alpha component
   

    // Print the color component values
    printf("Alpha: %u, Red: %u, Green: %u, Blue: %u\n", a, r, g, b);*/

//int	fdf_put_pixel(t_mlx *data, int color, char *pixel)
//{
//	t_color	tcolor;
	//printf("-entering put_pixel-\n");//
	//printf("data->img.str = %c\n", *data->img.str);//pourquoi n'affiche rien?
	//printf("pixel = %c\n", *pixel);//pourquoi n'affiche rien?
//	if (pixel < data->img.str || pixel >= (data->img.str + 
//			((FDF_HEIGHT - 1) * data->img.size_line) + 
//			((FDF_WIDTH - 1) * (data->img.bpp / 8))))
//		return (0); //control a comprendre
//	tcolor = rrgb(color); //fonction de color.c
	//printf("tcolor r = %c g = %c b = %c\n", tcolor.r, 
	//tcolor.g, tcolor.b);//pourquoi n'affiche rien?
//	if (data->img.endian == 1)// est-ce qu'on est en mode big ou little endian
//	{
//		*(pixel + 0) = 0;    
// ce serait bien dans un tableau mais je comprends pas ce "+"
//		*(pixel + 1) = tcolor.r; //?
//		*(pixel + 2) = tcolor.g;
//		*(pixel + 3) = tcolor.b;
//	}
//	else if (data->img.endian == 0)
//	{
//		*(pixel + 3) = 0;
//		*(pixel + 2) = tcolor.r;
//		*(pixel + 1) = tcolor.g;
//		*(pixel + 0) = tcolor.b;
//	}
//	else
//		return (0);
	//printf("pixel + 0 = %s\n", pixel + 0);//
	//printf("pixel + 1 = %s\n", pixel + 1);//
	//printf("pixel + 2 = %s\n", pixel + 2);//
	//printf("pixel + 3 = %s\n", pixel + 3);//

//	return (1);
//}