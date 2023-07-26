#include "../include/fdf.h"

int	rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	color;
	//printf("-rgb-\n");//
	color = 0;
	color += blue;
	color += (green * 256);
	color += (red * 256 * 256);
	//printf("color = %d\n", color);//
	return (color);
}

t_color	rrgb(int color)
{
	t_color	elem;
	//printf("-rrgb-\n");//
	//printf("color = %d\n", color);//
	elem.r = 0;
	elem.g = 0;
	elem.b = 0;
	while (color >= (256 * 256)) //connaitre la valeur de color
	{
		(elem.r)++;
		color -= (256 * 256); 
	}
	while (color >= 256)
	{
		(elem.g)++;
		color -= 256;
	}
	elem.b = color; // on veut une couleur en moins de 256 ce qui est assez logique
	//printf("elem.r = %c elem.g = %c elem.b = %c\n", elem.r, elem.g, elem.b);// a faire fonctionner
	return (elem);
}

unsigned char	red_part(int color)
{
	int	red;
	printf("-red_part-\n");//
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
	printf("-green_part-\n");//
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

	printf("-blue_part-\n");//
	while (color >= (256 * 256))
		color -= (256 * 256);
	while (color >= 256)
		color -= 256;
	blue = color;
	return (blue);
}

//les rgb part servent a filtrer les information pour n'avoir qu'une valeur entre 0 et 255