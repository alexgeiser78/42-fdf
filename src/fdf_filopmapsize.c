/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_filopmapsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:31:36 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 00:48:28 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	fdf_set_mapsize_width(char *line)
{
	int		line_width;
	int		i;

	line_width = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			line_width++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
			if (line[i] == '0' && line [i + 1] == 'x' && i++)
			{
				while (line[++i])
					if (!((line[i] >= '0' && line[i] <= '9')
							|| (line[i] >= 'a' && line[i] <= 'f')
							|| (line[i] >= 'A' && line[i] <= 'F')))
						break ;
			}
		}
		else
			i++;
	}
	return (line_width);
}

//couting the number of colomns per line
//line 31 used in case of file with color already set

int	fdf_set_mapsize(int fd, t_mapctr *mapctr)
{
	char	*line;
	int		line_width;

	mapctr->width = 0;
	mapctr->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_width = fdf_set_mapsize_width(line);
		if (line_width > mapctr->width)
			mapctr->width = line_width;
		(mapctr->height)++;
		free(line);
	}
	if (mapctr->width <= 0 || mapctr->height <= 0)
		return (0);
	return (1);
}
//gnl to store each line of the file
//line 60 arg mapctr->width set
//line 62 arg mapctr->height set

int	fileoperations2(char *argv, t_mlx *data)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("ERROR FD OPEN");
	fdf_generate_map(fd, &(data->mapctr));
	close(fd);
	if (!data->mapctr.map)
		ft_exit("No MAP");
	return (1);
}

int	fdf_fileoperations(char *argv, t_mlx *data, int fd)
{
	if (fd == -1)
		ft_exit_no_file(argv);
	if (fdf_set_mapsize(fd, &(data->mapctr)) != 1)
		ft_exit("at least 1 size is 0 or less");
	data->img.ptr = mlx_new_image(data->ptr, FDF_WIDTH, FDF_HEIGHT);
	if (!(data->img.ptr))
		ft_exit("mlx_new_image error");
	data->img.str = mlx_get_data_addr(data->img.ptr, \
	&(data->img.bpp), &(data->img.size_line), \
	&(data->img.endian));
	if (!(data->img.str))
		ft_exit("mlx_get_data_addr error");
	return (fileoperations2(argv, data));
}

//mlx_new_image stores the iamge to print it later
//mlx_get_data_addr  
//represents the begining of the memory area where the image
//is stored
//args: img.ptr = specifies the image to use, 
//img.bpp = bits per pixel, 
//img.size_line = size of a line of the image in bytes, 
//img.endian = endian, most significant bit at the smallest address
//line_width = nombre de chiffres sur une ligne
//i nombre de charactere par ligne
//printf(" init mapctr->width= %d\n", mapctr->width);
//printf(" init mapctr->height = %d\n", mapctr->height);
//dans le pointeur line on stocke une ligne gnl
//printf("line = %s", line);
//break si on arrive a la fin du fichier on sort de la boucle
//line_width =//taille de la map en x, 
//compte le nombre de chiffre sur une ligne, que se passe t'il si 
//une ligne est plus grande que les autres?
//printf("line width = %d\n", line_width);//
//on stocke la taille de la map en x dans la structure
//printf("mapctr->width= %d\n", mapctr->width);
//on incremente la taille de la map en y de 1 a chaque saut de ligne
//printf("mapctr->height = %d\n", mapctr->height);//
//si la taille de la meme est inferieur ou egale a 0
//get data adress image manipulation, args: connec id, 
//wid, heigth. sorte de tampon a image
//printf("data->img.ptr = %p\n", data->img.ptr);
//printf("data->img.bpp (mlx val) = %d\n", data->img.bpp);//
//printf("data->img.size_line (mlx val)= %d\n", data->img.size_line);//
//printf("data->img.endian (mlx val)= %d\n", data->img.endian);//
//printf("data->img.str = %p\n", data->img.str);//

//mlx_get_data_addr  //returns information about the created image, 
//allowing a user to modify it later
//args: img.ptr = specifies the image to use, 
//img.bpp = bits per pixel, 
//img.size_line = size of a line of the image in bytes, 
//img.endian = endian, most significant bit at the smallest address
