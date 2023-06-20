#include "../include/fdf.h"

void	fdf_call_put_pixel(t_mlx *data, t_point current)
{
	fdf_put_pixel(data, current.color, data->img.str + \
				((long)(current.y)*(long)data->img.size_line) + \
				((long)(current.x)*(long)(data->img.bpp / 8)));
}

void	fdf_bresenham(t_mlx *data, t_point s, t_point e)
{
	float	xrange;
	float	yrange;
	float	ratio;

	xrange = e.x - s.x; //calcul d'une moyenne sur l'axe x
	if (xrange < 0) //si resultat negatif
		xrange = xrange * -1; //on le converti en positif
	yrange = e.y - s.y;
	if (yrange < 0)
		yrange = yrange * -1;
	if (xrange > yrange) //si x est plus grand que y
	{
		ratio = yrange / xrange;
		fdf_bresenham_if(data, s, e, ratio);
	}
	else
	{
		ratio = xrange / yrange;
		fdf_bresenham_else(data, s, e, ratio);
	}
}