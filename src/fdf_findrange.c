#include "../include/fdf.h"

void	fdf_findrangee(t_mapctr *mapctr)
{
	long	x;
	long	y;
	int		current;

	y = -1;
	while (++y < mapctr->height)
	{
		x = -1;
		while (++x < mapctr->width)
		{
			current = ((mapctr->map)[x][y]).z;
			if (current < mapctr->min)
				mapctr->min = current;
			if (current > mapctr->max)
				mapctr->max = current;
		}
	}
	if (mapctr->min < 0)
	{
		if ((-(mapctr->min)) > mapctr->max)
			mapctr->max = (-(mapctr->min));
		else
			mapctr->min = (-(mapctr->max));
	}
	mapctr->range = (long) mapctr->max - (long) mapctr->min;
}

void	fdf_findrange(t_mapctr *mapctr)
{
	fdf_findrangee(mapctr);
	if (mapctr->range == 0)
		mapctr->range = 1;
}
