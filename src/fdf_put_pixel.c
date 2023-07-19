#include "../include/fdf.h"

int	fdf_put_pixel(t_mlx *data, int color, char *pixel)
{
	t_color	tcolor;
	printf("-entering put_pixel-\n");//
	printf("data->img.str = %c\n", *data->img.str);//pourquoi n'affiche rien?
	printf("pixel = %c\n", *pixel);//pourquoi n'affiche rien?
	if (pixel < data->img.str || pixel >= (data->img.str + \
			((FDF_HEIGHT - 1) * data->img.size_line) + \
			((FDF_WIDTH - 1) * (data->img.bpp / 8))))
		return (0); //control a comprendre
	tcolor = rrgb(color); //fonction de color.c
	printf("tcolor r = %c g = %c b = %c\n", tcolor.r, tcolor.g, tcolor.b);//pourquoi n'affiche rien?
	if (data->img.endian == 1)// est-ce qu'on est en mode big ou little endian
	{
		*(pixel + 0) = 0;    // ce serait bien dans un tableau mais je comprends pas ce "+"
		*(pixel + 1) = tcolor.r; //?
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