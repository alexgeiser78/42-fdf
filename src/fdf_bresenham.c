#include "../include/fdf.h"

void	fdf_call_put_pixel(t_mlx *data, t_point current)
{
	printf("-entering call put pix-\n");//
	fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
}

void	fdf_bresenham(t_mlx *data, t_point s, t_point current) //s? e?
{
	float	xrange;
	float	yrange;
	float	ratio;
		
	xrange = current.x - s.x; //calcul d'une moyenne sur l'axe x
	printf("xrange '%f' = current.x '%f'- s.x '%f'\n", xrange, current.x, s.x);// ne se passe rien
	if (xrange < 0) //si resultat negatif
		xrange = xrange * -1; //on le converti en positif
	yrange = current.y - s.y;
	printf("yrange '%f' = current.y '%f'- s.y '%f'\n", yrange, current.y, s.y);//ne se passe rien
	if (yrange < 0)
		yrange = yrange * -1;
		printf("xrange = %f yrange = %f\n", xrange, yrange);//
	if (xrange > yrange) //si x est plus grand que y
	{
		ratio = yrange / xrange;
		printf("ration = %f == bresenham if\n", ratio);//
		fdf_bresenham_if(data, s, current, ratio);
	}
	else
	{
		ratio = xrange / yrange;
		printf("ration = %f == bresenham else\n", ratio);//
		fdf_bresenham_else(data, s, current, ratio);
	}
}