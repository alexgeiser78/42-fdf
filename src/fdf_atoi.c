#include "../include/fdf.h"

int	fdf_atoi_getcolor(const char *str)
{
	size_t	i;
	int		color;

	i = 0;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x') // on peu imaginer que les coordonnes soient separees par des virgules
		i += 3;
	else
		return (0);
	color = 0;
	//printf("color =\n");//
	while (str[i])
	{
		//printf("color = %d\n", color);//
		if (str[i] >= '0' && str[i] <= '9')
			color = color * 16 + str[i] - '0'; 
		else if (str[i] >= 'a' && str[i] <= 'f')
			color = color * 16 + str[i] + 10 - 'a';
		else if (str[i] >= 'A' && str[i] <= 'F')
			color = color * 16 + str[i] + 10 - 'A';
		else
			break ;
		i++;
		
	}
	
	return (color);
}

int	fdf_atoi_color(const char *str, t_mapctr *mapctr, int x, int y)
{
	int		nbr;
	int		sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+') // le plus on s'en fout
		i++;
	else if (str[i] == '-') //le moins on le plus
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
		(mapctr->map[x][y]).color = fdf_atoi_getcolor((char *)str + i);
	printf("color = %d\n", (mapctr->map[x][y]).color);// quelque chose ne marche pas a ce niveau val a 0 tout le temps

	return (nbr * sign);
}

//atoi assez standard