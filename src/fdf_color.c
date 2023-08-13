/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:20:28 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 00:00:10 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	int	color;

	color = 0;
	color += blue;
	color += (green * 256);
	color += (red * 256 * 256);
	return (color);
}
//int adding all rgb values to get a color value

t_color	rrgb(int color)
{
	t_color	elem;

	elem.r = 0;
	elem.g = 0;
	elem.b = 0;
	while (color >= (256 * 256))
	{
		(elem.r)++;
		color -= (256 * 256); 
	}
	while (color >= 256)
	{
		(elem.g)++;
		color -= 256;
	}
	elem.b = color;
	return (elem);
}
//reverse rgb invert the process of rgb
//to get 3 x 256
//printf("elem.r = %c elem.g = %c elem.b = %c\n", elem.r, elem.g, elem.b); 
