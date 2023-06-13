#include "../include/fdf.h"

int	fdf_atoi_getcolor(const char *str)
{
	size_t	i;
	int		color;

	i = 0;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x') // ,? 
		i += 3;
	else
		return (0);
	color = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9') //hein?
			color = color * 16 + str[i] - '0'; 
		else if ('a' <= str[i] && str[i] <= 'f')
			color = color * 16 + str[i] + 10 - 'a';
		else if ('A' <= str[i] && str[i] <= 'F')
			color = color * 16 + str[i] + 10 - 'A';
		else
			break ;
		i++;
		
	}
	printf("color = %d\n", color);//
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
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r')) // hein?
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9') //explication du hein
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	printf("cucu"); //
		(mapctr->map[x][y]).color = fdf_atoi_getcolor((char *)str + i);
	return (nbr * sign);
}

//atoi assez standard