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
	printf("mapctr->max = %ld\n", mapctr->max);//
	printf("mapctr->min = %ld\n", mapctr->min);//
	if (mapctr->min < 0)
	{
		if ((-(mapctr->min)) > mapctr->max) //inversioon opur toujours avec le min plus petit que le max
			mapctr->max = (-(mapctr->min));
		else
			mapctr->min = (-(mapctr->max));
	}
	mapctr->range = (long) mapctr->max - (long) mapctr->min;
	printf("mapctr-range = %ld\n", mapctr->range);//
}

void	fdf_findrange(t_mapctr *mapctr)
{
	fdf_findrangee(mapctr);
	if (mapctr->range == 0)
		mapctr->range = 1;
}
