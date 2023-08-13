/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:08:28 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/14 00:21:48 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_exit_dir(char *argv)
{
	ft_putstr("error: ");
	perror(argv); 
	exit(EXIT_FAILURE);
}

// perror(argv); produce a message on standard error describing 
//the last error encountered during a call to a system or library function

void	ft_exit_no_file(char *argv)
{
	ft_putstr(argv);
	ft_putstr(" No file loaded");
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

//perror(argv); // produce a message on standard error describing 
//the last error encountered during a call to a system or library function
