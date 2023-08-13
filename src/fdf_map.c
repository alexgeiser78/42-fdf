/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:47:27 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 01:06:11 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_map_fill_z(t_mapctr *mapctr, int fd)
{
	long	x;
	long	y;
	long	i;
	char	*line;

	y = -1;
	while (++y < mapctr->height)
	{
		line = get_next_line(fd);
		i = 0;
		x = 0;
		while (x < mapctr->width)
		{
			if (line[i] != ' ' && line[i] != '\n') 
			{
				((mapctr->map)[x][y]).z = (float)B(line + i, mapctr, x, y);
				x++;
				while (line[i] && line[i] != ' ' && line[i] != '\n')
					i++;
			}
			else
				i++;
		}
		free(line);
	}
}
//storing z axis into z arg using gnl and atoi to pass from char to int

t_point	**fdf_generate_map(int fd, t_mapctr *mapctr)
{
	t_point		**map;
	long		i;

	if (fd == -1 || mapctr->width <= 0 || mapctr->height <= 0)
		return (NULL);
	map = ft_calloc(sizeof(t_point *), mapctr->width + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (i < mapctr->width)
	{
		map[i] = ft_calloc(sizeof(t_point), mapctr->height);
		if (!map[i])
			fdf_free_map(map);
		i++;
	}
	mapctr->map = map;
	fdf_map_fill_z(mapctr, fd);
	fdf_findrange(mapctr);
	return (map);
}
//createur de calloc pour la map, tableau 2D avec axe x et y

// dans la struct, pour z, on lui attribue une valeur 
//en int car dans le fichier fdf il y a que des valeurs en char
//printf("t_point->z = %f\n", mapctr->map[x][y].z);//valeur de z
//	t_point		**map; //pointeur 2D pour stocker les axes x et y
