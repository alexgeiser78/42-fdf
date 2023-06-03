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
				((m->map)[x][y]).z = (float)fdf_atoi_color(line + i, m, x, y);
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

//createur de malloc pour la map