/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:06:02 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/19 16:06:08 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "../include/fdf.h"

void    fdf_print_me_all(t_mlx *data, t_mapctr *mapctr)
{
   printf("data->gradient = %d\n", data->gradient);//
   printf("mapctr->width = %d\n", mapctr->width); //
   printf("mapctr->height = %d\n", mapctr->height);//
   printf("t_point->z = %f\n", mapctr->map[0][0].z);//derniere coordonees en z
}


void    fdf_init(t_mlx *data)
{
    data->ptr = NULL; // pour connection au serveur
    data->win = NULL; // pour la fenetre
    data->mapctr.map = NULL;// map x y
    data->img.ptr = NULL;// pour l'image
    data->img.str = NULL;//mlx_get_data_addr
    data->colors = NULL;//tableau de couleur
    data->gradient = 1;// pas trouve comment le gradient peut etre superieur a 1
    data->mapctr.min = 2147483647; // mise a zero des valeurs min et max
    data->mapctr.max = -2147483648; // mise a zero des valeurs min et max
}
//n'empeche pas le bon fonctionnement si absent

void    fdf_creator(char *argv, int fd)
{
    t_mlx   data; //nom donne a la structure

    fdf_init(&data); //initialise la structure
    data.ptr = mlx_init(); //initie la connection avec le serveur graphique
    
    if (fdf_fileoperations(argv, &data, fd) == 1)
    {
        data.win = mlx_new_window(data.ptr, FDF_WIDTH, FDF_HEIGHT, argv); //creer et ouvrir une fenetre
        data.colors = fdf_colorgradient(&data); //
        if (!(data.colors))
        {
			fdf_free_all(&data);
            ft_exit("Unattributed Color"); 
        }
        fdf_colormap(&data, data.colors);
        fdf_default(&data);
        fdf_print_me_all(&data, &data.mapctr);//
    }

    mlx_loop(data.ptr); //gere les evenements
}

int main(int argc, char **argv)
{
    int fd;

    fd = 0;
    if (argc != 2)
        ft_exit("choose map");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_exit_no_file(argv[1]);
    fdf_creator (argv[1], fd);
    close(fd);
    return(0);
} 

//argv check
//unused: mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF); //dessine un pixel