#include "../include/fdf.h"

int	rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	color;

	color = 0;
	color += blue;
	color += (green * 256);
	color += (red * 256 * 256);
	return (color);
}

t_color	rrgb(int color)
{
	t_color	elem;

	elem.r = 0;
	elem.g = 0;
	elem.b = 0;
	while (color >= (256 * 256))
	{
		(elem.r)++;
		color -= (256 * 256);
	}
	while (color >= 256)
	{
		(elem.g)++;
		color -= 256;
	}
	elem.b = color;
	return (elem);
}

unsigned char	red_part(int color)
{
	int	red;

	red = 0;
	while (color >= (256 * 256))
	{
		red++;
		color -= (256 * 256);
	}
	return (red);
}

unsigned char	green_part(int color)
{
	int	green;

	while (color >= (256 * 256))
		color -= (256 * 256);
	green = 0;
	while (color >= 256)
	{
		green++;
		color -= 256;
	}
	return (green);
}

unsigned char	blue_part(int color)
{
	int	blue;

	while (color >= (256 * 256))
		color -= (256 * 256);
	while (color >= 256)
		color -= 256;
	blue = color;
	return (blue);
}

//les rgb part servent a filtrer les information pour n'avoir qu'une valeur en tre 0 et 255