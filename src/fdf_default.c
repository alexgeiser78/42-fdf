#include "../include/fdf.h"
/*
int	fdf_parallel(t_mlx *dt)
{
	fdf_clear_img(dt);
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (FDF_WIDTH <= FDF_HEIGHT)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 135;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}

int	fdf_flat(t_mlx *dt)
{
	fdf_clear_img(dt);
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, dt->mapctr.width);
	else if (FDF_WIDTH <= FDF_HEIGHT)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, dt->mapctr.height);
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, dt->mapctr.width);
	else
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, dt->mapctr.height);
	dt->deg = 0;
	dt->iy = 45;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}
*/
int	fdf_default(void *param)
{
	t_mlx	*dt;
	dt = (t_mlx *)param;
	//fdf_clear_img(dt); necessaire ou pas?
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, \
	dt->mapctr.width);//si la largeur est plus grande que la longueur on stocke dans l'argument scale la valeur de 
	else if (FDF_WIDTH <= FDF_HEIGHT)
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > \
	dt->mapctr.height)
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, \
	dt->mapctr.width);
	else
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
	dt->deg = 45;
	dt->iy = 80;
	dt->mapctr.translatex = 0;
	dt->mapctr.translatey = 0;
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15;
	fdf_map_to_screen(dt);
	return (1);
}

//hypotf permet de calculer la racine carre de la somme des carre de x et y
/*
int	fdf_changecolor(t_mlx *dt)
{
	if (dt->colors)
		free(dt->colors);
	else
		return (0);
	fdf_clear_img(dt);
	dt->colors = NULL;
	dt->gradient += 1;
	dt->colors = fdf_colorgradient(dt);
	fdf_empty_colormap(dt, dt->colors); //permet de mettre l'arguement color(z) a 0
	fdf_colormap(dt, dt->colors);
	fdf_map_to_screen(dt);
	return (1);
}*/