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
				mapctr->min = current; //min heigth
			if (current > mapctr->max)
				mapctr->max = current; //max heigth
		}
	}
	
	if (mapctr->min < 0)
	{
		if ((-(mapctr->min)) > mapctr->max) //inversion pour toujours avec le min plus petit que le max
			mapctr->max = (-(mapctr->min));
		else
			mapctr->min = (-(mapctr->max));
	}
	printf("-min and max heigth-\n");//
	printf("mapctr->max = %ld\n", mapctr->max);//
	printf("mapctr->min = %ld\n", mapctr->min);//
	mapctr->range = (long) mapctr->max - (long) mapctr->min;
	printf("-range = max - min-\n");//
	printf("mapctr-range = %ld\n", mapctr->range);//
}

void	fdf_findrange(t_mapctr *mapctr)
{
	printf("-entering findrange-\n");//
	fdf_findrangee(mapctr);
	if (mapctr->range == 0)// a verifier pourquoi
		mapctr->range = 1;
}
