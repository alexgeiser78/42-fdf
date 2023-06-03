#include "../include/fdf.h"

int	fdf_set_mapsize__width(char *line)
{
	int		line_width;
	size_t	i;

	line_width = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			line_width++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
			/*if (line[i] == '0' && line [i + 1] == 'x' && i++)                    // quoi?
			{
				while (line[++i])
					if (!(('0' <= line[i] && line[i] <= '9')
							|| ('a' <= line[i] && line[i] <= 'f')
							|| ('A' <= line[i] && line[i] <= 'F')))
						break ;
			}*/
		}
		else
			i++;
	}
	return (line_width);
}

// line_width = nombre de chiffres sur une ligne
// i nombre de charactere par ligne


int	fdf_set_mapsize(int fd, t_mapctr *mapctr)
{
	char	*line;
	int		line_width;

	mapctr->width = 0; // largeur de la map fdf
	mapctr->height = 0; // hauteur de la map fdf
	while (1)
	{
		line = get_next_line(fd); //dans le pointeur line on stocke une ligne gnl
		if (!line)
			break ; //si on arrive a la fin du fichier on sort de la boucle
		line_width = fdf_set_mapsize__width(line); //taille de la map en x
		if (line_width > mapctr->width)
			mapctr->width = line_width; //on stocke la taille de la map en x dans la structure
		(mapctr->height)++; //on incremente la taille de la map en y de 1 a chaue saut de ligne
		free(line); //liberation de la memoire
	}
	close(fd); // fermeture du fichier
	if (mapctr->width <= 0 || mapctr->height <= 0)
		return (0);
	return (1);
}

int	fileoperations2(char *argv, t_mlx *data)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit("ERRROER");
	fdf_generate_map(fd, &(data->mapctr)); //map.c
	close(fd);
	if (!data->mapctr.map)
		ft_exit("ERRROERsfgasfg");
	return (1);
}

int fdf_fileoperations(char *argv, t_mlx *data)
{
    int fd;
    
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        ft_exit_no_file(argv);
    if (fdf_set_mapsize(fd , &(data->mapctr)) != 1) //taille de la map
        ft_exit("wrong size");
    data->img.ptr = mlx_new_image(data->ptr, FDF_WIDTH, FDF_HEIGHT); //?
    if (!(data->img.ptr))
        ft_exit("mlx_new_image error");
    data->img.str = mlx_get_data_addr(data->img.ptr, \
    &(data->img.bpp), &(data->img.size_line), \
    &(data->img.endian)); //?
    if (!(data->img.str))
        ft_exit("mlx_get_data_addr error");
    return (fileoperations2(argv, data));
}




