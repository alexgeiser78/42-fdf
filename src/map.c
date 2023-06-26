#include "../include/fdf.h"

void	fdf_map_fill_z(t_mapctr *m, int fd)
{
	long	x;
	long	y;
	long	i;
	char	*line;

	y = -1;
	while (++y < m->height)
	{
		line = get_next_line(fd);
		i = 0;
		x = 0;
		while (x < m->width)
		{
			if (line[i] != ' ' && line[i] != '\n') 
			{
				((m->map)[x][y]).z = (float)fdf_atoi_color(line + i, m, x, y); // dans la struct, pour z, on lui attribue une valeur en int car dans le fichier fdf il y a que des valeurs en char
				//printf("t_point->z = %f\n", m->map[x][y].z);//valeur de z
				x++;
				while (line[i] && line[i] != ' ' && line[i] != '\n')
					i++;
			}
			else
				i++;
		}
		//printf("m->height = %d\n", m->height);//
		//printf("m->width = %d\n", m->width);//
		//printf("i = %ld\n", i); //
		free(line);
	}
}

//*m est un renvoi vers la structure mapctr

t_point	**fdf_generate_map(int fd, t_mapctr *mapctr)
{
	t_point		**map; //pointeur 2D pour stocker les axes x et y
	long		i;

	if (fd == -1 || mapctr->width <= 0 || mapctr->height <= 0)
		return (NULL);
	map = ft_calloc(sizeof(t_point *), mapctr->width + 1); //calloc de l'axe x
	if (!map)
		return (NULL);
	i = 0;
	while (i < mapctr->width)
	{
		map[i] = ft_calloc(sizeof(t_point), mapctr->height); //calloc de l'axe
		if (!map[i])
			fdf_free_map(map);
		i++;
	}
	mapctr->map = map; // map 2D
	fdf_map_fill_z(mapctr, fd); //axe z
	fdf_findrange(mapctr); //?
	return (map);
}

//createur de malloc pour la map, tableau 2D avec axe x et y