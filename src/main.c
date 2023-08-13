/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:33:46 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 01:19:21 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	fdf_quit(void *param)
{
	exit(fdf_free_all((t_mlx *)param));
}

void	fdf_init(t_mlx *data)
{
	data->ptr = NULL;
	data->win = NULL;
	data->mapctr.map = NULL;
	data->img.ptr = NULL;
	data->img.str = NULL;
	data->colors = NULL;
	data->gradient = 1;
	data->mapctr.min = 2147483647; 
	data->mapctr.max = -2147483648; 
}
//reset of some data elements
/*
    data->ptr = NULL; // pour connection au serveur
    data->win = NULL; // pour la fenetre
    data->mapctr.map = NULL;// map x y
    data->img.ptr = NULL;// pour l'image
    data->img.str = NULL;//mlx_get_data_addr
    data->colors = NULL;//tableau de couleur
    data->gradient = 1;// pas trouve comment le gradient peut etre superieur a 1
    data->mapctr.min = 2147483647; // mise a zero des valeurs min et max
    data->mapctr.max = -2147483648; // mise a zero des valeurs min et max
*/

void	fdf_creator(char *argv, int fd)
{
	t_mlx	data;

	fdf_init(&data);
	data.ptr = mlx_init();
	if (fdf_fileoperations(argv, &data, fd) == 1)
	{
		data.win = mlx_new_window(data.ptr, FDF_WIDTH, FDF_HEIGHT, argv);
		data.colors = fdf_colorgradient(&data);
		if (!(data.colors))
		{
			fdf_free_all(&data);
			ft_exit("Unattributed Color"); 
		}
		fdf_colormap(&data, data.colors);
		fdf_default(&data);
		mlx_hook(data.win, 02, (1L << 0), fdf_keypressed, &data);
		mlx_hook(data.win, 17, 0, fdf_quit, &data);
		mlx_mouse_hook(data.win, fdf_mouseclick, &data);
	}
	mlx_loop(data.ptr);
}
//data.ptr = mlx_init(); //init the connection between 
//the software and the screen
//mlx_new_window generates the window where the image will be displayed
//mlx_hook(mlx_new_window, keypressed (x11 call), bit mask (bit 0) to 1, 
//"A" key, function to call, data)
//mlx_hook(mlx_new_window, generic (x11 call), no mask,function to call, data)
//mlx_mouse_hook(mlx_new_window, function to call, data)
//mlx_loop(mlx_new_window(server init))

int	main(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
		ft_exit("choose map");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_no_file(argv[1]);
	fdf_creator (argv[1], fd);
	close(fd);
	return (0);
}

//argv check
//open file
//fd check
//fdf_creator

//mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF); //dessine un pixel

/*void    fdf_print_me_all(t_mlx *data, t_mapctr *mapctr)
{
   printf("data->gradient = %d\n", data->gradient);//
   printf("mapctr->width = %d\n", mapctr->width); //
   printf("mapctr->height = %d\n", mapctr->height);//
   printf("t_point->z = %f\n", mapctr->map[0][0].z);//derniere coordonees en z
}
*/
