/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keypressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:04:52 by ageiser           #+#    #+#             */
/*   Updated: 2023/07/30 13:04:54 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	fdf_rotate(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_RIGHTARROW || key == KV_RIGHTARROW_M)
		(data->deg) += 1.5;
	else if (key == KV_LEFTARROW || key == KV_LEFTARROW_M)
		(data->deg) -= 1.5;
	fdf_map_to_screen(data);
	return (1);
}
//always a clear image before every change
//and a map to screen after
//modify deg value to rotate
//values changes always to make it smooth

static int	fdf_translate(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_W || key == KV_W_M)
		(data->mapctr.translatey) -= (data->scale / 5);
	else if (key == KV_S || key == KV_S_M)
		(data->mapctr.translatey) += (data->scale / 5);
	else if (key == KV_A || key == KV_A_M)
		(data->mapctr.translatex) -= (data->scale / 5);
	else if (key == KV_D || key == KV_D_M)
		(data->mapctr.translatex) += (data->scale / 5);
	fdf_map_to_screen(data);
	return (1);
}
//modify the translate value to move the map

static int	fdf_incline(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_TOPARROW || key == KV_TOPARROW_M)
		(data->iy) += 5;
	else if (key == KV_BOTTOMARROW || key == KV_BOTTOMARROW_M)
		(data->iy) -= 5;
	else if (key == KV_P || key == KV_P_M)
		return (fdf_parallel(data));
	fdf_map_to_screen(data);
	return (1);
}
//modify the incline value to change the angle of the map

static int	fdf_relief(int key, t_mlx *data)
{
	fdf_clear_img(data);
	if (key == KV_PLUS || key == KV_PLUS_M || key == KV_PLUS2)
		data->relief += 0.25;
	else if (key == KV_MINUS || key == KV_MINUS_M || key == KV_MINUS2)
		data->relief -= 0.25;
	if (data->relief != 0 && data->relief > -0.13 && data->relief < 0.13)
		data->relief = 0;
	fdf_map_to_screen(data);
	return (1);
}
//modify relief value to change the height of the map

int	fdf_keypressed(int key, void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	if (key == KV_LEFTARROW || key == KV_LEFTARROW_M
		|| key == KV_RIGHTARROW || key == KV_RIGHTARROW_M)
		fdf_rotate(key, data);
	if (key == KV_PLUS || key == KV_PLUS_M || key == KV_MINUS
		|| key == KV_PLUS2 || key == KV_MINUS2 || key == KV_MINUS_M)
		fdf_relief(key, data);
	else if (key == KV_W || key == KV_W_M || key == KV_S || key == KV_S_M
		|| key == KV_A || key == KV_A_M || key == KV_D || key == KV_D_M)
		fdf_translate(key, data);
	else if (key == KV_TOPARROW || key == KV_TOPARROW_M
		|| key == KV_BOTTOMARROW || key == KV_BOTTOMARROW_M
		|| key == KV_P || key == KV_P_M)
		fdf_incline(key, data);
	else if (key == KV_C || key == KV_C_M)
		fdf_changecolor(data); 
	else if (key == KV_R || key == KV_R_M)
		fdf_default(data);
	else if (key == KV_SPACE || key == KV_SPACE_M)
		fdf_flat(data);
	else if (key == KV_ESCAPE || key == KV_ESCAPE_M)
		exit(fdf_free_all(data));
	return (1);
}

//key dispatcher
//fdf_changecolor, fdf_flat in fdf_default.c
//fdf_free_all in fdf_free_all.c 
/*
static int	fdf_rotate(int key, t_mlx *data)
{
	printf("-rotate-\n");//
	fdf_clear_img(data);
	if (key == KV_RIGHTARROW || key == KV_RIGHTARROW_M)
		(data->deg) += 1.5;
	else if (key == KV_LEFTARROW || key == KV_LEFTARROW_M)
		(data->deg) -= 1.5;
	fdf_map_to_screen(data);
	return (1);
}
*/
/*
static int	fdf_translate(int key, t_mlx *data)
{
	printf("-entering translate-\n");//
	fdf_clear_img(data);
	if (key == KV_W || key == KV_W_M)
		(data->mapctr.translatey) -= (data->scale / 5);
	else if (key == KV_S || key == KV_S_M)
		(data->mapctr.translatey) += (data->scale / 5);
	else if (key == KV_A || key == KV_A_M)
		(data->mapctr.translatex) -= (data->scale / 5);
	else if (key == KV_D || key == KV_D_M)
		(data->mapctr.translatex) += (data->scale / 5);
	fdf_map_to_screen(data);
	return (1);
}
*/
/*
static int	fdf_incline(int key, t_mlx *data)
{
	printf("-entering incline-\n");//
	fdf_clear_img(data);
	if (key == KV_TOPARROW || key == KV_TOPARROW_M)
			(data->iy) += 5;
	else if (key == KV_BOTTOMARROW || key == KV_BOTTOMARROW_M)
			(data->iy) -= 5;
	else if (key == KV_P || key == KV_P_M)
		return (fdf_parallel(data));
	fdf_map_to_screen(data);
	return (1);
}
*/
/*
static int	fdf_relief(int key, t_mlx *data)
{
	printf("-entering relief-\n");//
	fdf_clear_img(data);
	if (key == KV_PLUS || key == KV_PLUS_M || key == KV_PLUS2)
		data->relief += 0.25;
	else if (key == KV_MINUS || key == KV_MINUS_M || key == KV_MINUS2)
		data->relief -= 0.25;
	if (data->relief != 0 && data->relief > -0.13 && data->relief < 0.13)
		data->relief = 0;
	fdf_map_to_screen(data);
	return (1);
}
*/
/*
int	fdf_keypressed(int key, void *param)
{
	t_mlx	*data;
	printf("-entering keypressed-\n");//
	data = (t_mlx *)param;
	if (key == KV_LEFTARROW || key == KV_LEFTARROW_M
		|| key == KV_RIGHTARROW || key == KV_RIGHTARROW_M)
		fdf_rotate(key, data);
	if (key == KV_PLUS || key == KV_PLUS_M || key == KV_MINUS
		|| key == KV_PLUS2 || key == KV_MINUS2 || key == KV_MINUS_M)
		fdf_relief(key, data);
	else if (key == KV_W || key == KV_W_M || key == KV_S || key == KV_S_M
		|| key == KV_A || key == KV_A_M || key == KV_D || key == KV_D_M)
		fdf_translate(key, data);
	else if (key == KV_TOPARROW || key == KV_TOPARROW_M
		|| key == KV_BOTTOMARROW || key == KV_BOTTOMARROW_M
		|| key == KV_P || key == KV_P_M)
		fdf_incline(key, data);
	else if (key == KV_C || key == KV_C_M)
		fdf_changecolor(data);
	else if (key == KV_R || key == KV_R_M)
		fdf_default(data);
	else if (key == KV_SPACE || key == KV_SPACE_M)
		fdf_flat(data);
	else if (key == KV_ESCAPE || key == KV_ESCAPE_M)
		exit(fdf_free_all(data));
	return (1);
}
*/