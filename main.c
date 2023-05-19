/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:06:02 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/19 16:06:08 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "fdf.h"

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init(); //initie la connection avec le serveur graphique
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "mlx 42"); //creer et ouvrir une fenetre
    mlx_loop(mlx_ptr); //gere les evenements
} 