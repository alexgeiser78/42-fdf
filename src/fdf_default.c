#include "../include/fdf.h"

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

int	fdf_default(void *data)
{
	t_mlx	*dt;
	dt = (t_mlx *)data;
	//printf("-entering default function-\n");//
	//fdf_clear_img(dt); necessaire ou pas?
	if (FDF_WIDTH <= FDF_HEIGHT && dt->mapctr.width > dt->mapctr.height)
		{
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.width, \
	dt->mapctr.width);//si la largeur est plus grande que la longueur on stocke dans l'argument scale la valeur de 
		//printf("1 FDF_WIDTH/hyp(dt->mapctr.width, dt->mapctr.width) = %f\n", dt->scale);//
		}
	else if (FDF_WIDTH <= FDF_HEIGHT)
	{
		dt->scale = FDF_WIDTH / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
		//printf("2 FDF_WIDTH/hyp(dt->mapctr.height, dt->mapctr.height) = %f\n", dt->scale);//
	}
	else if (FDF_WIDTH > FDF_HEIGHT && dt->mapctr.width > \
	dt->mapctr.height)
	{
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.width, \
	dt->mapctr.width);
		//printf("3 FDF_HEIGHT/hyp(dt->mapctr.width, dt->mapctr.width) = %f\n", dt->scale);//
	}
	else
	{
		dt->scale = FDF_HEIGHT / hypotf(dt->mapctr.height, \
	dt->mapctr.height);
		//printf("4 FDF_HEIGHT/hyp(dt->mapctr.height, dt->mapctr.height) = %f\n", dt->scale);//
	}
	//printf("-setting default values-\n");//
	dt->deg = 45;
	//printf("dt->deg = %f\n", dt->deg);//
	dt->iy = 80;
	//printf("dt->iy = %f\n", dt->iy);//iy ?
	dt->mapctr.translatex = 0;//decalage en x
	//printf("dt->mapctr.translatex = %ld\n", dt->mapctr.translatex);//
	dt->mapctr.translatey = 0; //decalage en y
	//printf("dt->mapctr.translatey = %ld\n", dt->mapctr.translatey);//
	dt->relief = hypotf(dt->mapctr.width, dt->mapctr.width) / 15; // pas tres clair a quoii sert relief et pourquoi / 15
	//printf("dt->relief hyp(mapctr.width, mapctr.width) / 15 = %f\n", dt->relief);//
	fdf_map_to_screen(dt);
	return (1);
}

//hypotf permet de calculer la racine carre de la somme des carre de x et y

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
}