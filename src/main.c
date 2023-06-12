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

void    fdf_init(t_mlx *data)
{
    data->ptr = NULL;
    data->win = NULL;
    data->mapctr.map = NULL;//
    data->img.ptr = NULL;//
    data->img.str = NULL;//
    data->colors = NULL;//
    data->gradient = 1;//
    data->mapctr.min = 2147483647; //
    data->mapctr.max = -2147483648; //
}

void    fdf_creator(char *argv, int fd)
{
    t_mlx   data;

    fdf_init(&data); //initialise la structure
    data.ptr = mlx_init(); //initie la connection avec le serveur graphique
    
    if (fdf_fileoperations(argv, &data, fd) == 1)
    {
        data.win = mlx_new_window(data.ptr, FDF_WIDTH, FDF_HEIGHT, argv); //creer et ouvrir une fenetre
        data.colors = fdf_colorgradient(&data);
        if (!(data.colors))
        {
			fdf_free_all(&data); //printf
            ft_exit("ERR_ALLOC"); 
        }
        fdf_colormap(&data, data.colors);
        fdf_default(&data);

    }

    mlx_loop(data.ptr); //gere les evenements
}

int main(int argc, char **argv)
{
    int fd;

    fd = 0;
    if (argc != 2)
        ft_exit("map missing");
    
fd = open(argv[1], O_RDONLY);
if (fd == -1)
    ft_exit_no_file(argv[1]);

//    mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF); //dessine un pixel

    fdf_creator (argv[1], fd);
    close(fd);
    return(0);
} 

//argv check