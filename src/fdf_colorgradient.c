#include "../include/fdf.h"

/* White -> Blue */
int	*fdf_colorgradient_1(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0xffffff; //white
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color -= 0x000100;
		color -= 0x010000;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}

/* Yellow -> Red */
int	*fdf_colorgradient_2(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0xffff00; //Yellow
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color -= 0x000100;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}

/* Blue -> Purple */
int	*fdf_colorgradient_3(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0x00ffff; //aqua
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color += 0x010000;
		color -= 0x000100;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}

/* Pink -> Green */
int	*fdf_colorgradient_4(t_mlx *data)
{
	int		*tab;
	int		color;
	size_t	i;

	tab = malloc(sizeof(int) * (255 + 1));
	if (!tab)
		return (NULL);
	color = 0xffff00; //yellow 2?
	i = 0;
	while (1)
	{
		tab[i] = color;
		if (i >= 255)
			break ;
		color -= 0x000100;
		color += 0x000001;
		i++;
	}
	data->nbrcolors = 255;
	return (tab);
}

int	*fdf_colorgradient(t_mlx *data)
{
	if (data->gradient == 1)
		return (fdf_colorgradient_1(data));
	else if (data->gradient == 2)
		return (fdf_colorgradient_2(data));
	else if (data->gradient == 3)
		return (fdf_colorgradient_3(data));
	else if (data->gradient == 4)
		return (fdf_colorgradient_4(data));
	else
		data->gradient = 1;
	return (fdf_colorgradient_1(data));
}