/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:09:55 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/13 23:34:52 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	fdf_atoi_getcolor(const char *str)
{
	size_t	i;
	int		color;

	i = 0;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		i += 3;
	else
		return (0);
	color = 0;
	while (str[i])
	{
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
//sometimes in the .fdf file, color can be given, this function 
//is used to get the color

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
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
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
	return (nbr * sign);
}

//atoi assez standard
//printf("color = %d\n", (mapctr->map[x][y]).color);