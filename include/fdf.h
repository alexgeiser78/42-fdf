/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:09:48 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/19 16:09:51 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

#include "../minilibx/mlx.h"
// #include "../src/get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h> //open
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //hypotf

#define FDF_WIDTH 1920
#define FDF_HEIGHT 1080

# ifndef RAD
#  define RAD 57.2958
# endif



typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}		t_point;

typedef struct s_mapctr
{
	t_point		**map;//
	int			width;//
	int			height;//
	long		min;
	long		max;
	long		range;//
	long		translatex; //
	long		translatey;//
	float		xorigin;//
	float		yorigin;//
}				t_mapctr;

typedef struct s_mlximg
{
	void	*ptr;
	char	*str;
	int		bpp; //
	int		size_line; //
	int		endian; //
}			t_mlximg;

typedef struct s_mlx
{
    void *ptr; 
    void *win; 
    t_mapctr mapctr;
    t_mlximg img;
    int *colors;
    int nbrcolors; //
    int gradient;
    float scale; //
    float relief; //
    float deg; //
    float deg_sin; //
    float deg_cos; //
    float iy; //
    float iy_sin; //
    float iy_cos; //
}               t_mlx;

typedef struct s_color
{
	int				val;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;


typedef struct s_bresenham
{
	float	ratio;
	t_point	current;
	float	diff;
	float	i;
	t_color	scl;
	t_color	ecl;
}			t_bresenham;

void fdf_creator(char *argv);
void fdf_init(t_mlx *data);

void ft_exit(char *str);
//size_t ft_putstr( char *s);
void ft_exit_no_file(char *argv);

int line_counter(int fd, int height);
int ft_width(char **character);
char **str_data(int fd, int height, char *argv);
void invalid_file_msg(int ft_return, char *argv);
int ft_wordcount(char *str, char c);
int fdf_fileoperations(char *argv, t_mlx *data);
int	fileoperations2(char *argv, t_mlx *data);
int	fdf_set_mapsize(int fd, t_mapctr *mapctr);
int	fdf_set_mapsize__width(char *line);
t_point	**fdf_generate_map(int fd, t_mapctr *mapctr);
int	fdf_atoi_getcolor(const char *str);
int	fdf_atoi_color(const char *str, t_mapctr *mapctr, int x, int y);
int	fdf_free_all(t_mlx *data);
void	fdf_free_map(t_point **map);
void	fdf_findrangee(t_mapctr *mapctr);
void	fdf_findrange(t_mapctr *mapctr);
int	*fdf_colorgradient_1(t_mlx *data);
int	*fdf_colorgradient_2(t_mlx *data);
int	*fdf_colorgradient_3(t_mlx *data);
int	*fdf_colorgradient_4(t_mlx *data);
int	*fdf_colorgradient(t_mlx *data);
void	fdf_empty_colormap(t_mlx *data, int *colors);
void	fdf_colormap(t_mlx *data, int *colors);
long	fdf_colorgradient_indice(t_mlx *data, int x, int y);

int	fdf_parallel(t_mlx *dt);
int	fdf_flat(t_mlx *dt);
int	fdf_default(void *param);
int	fdf_changecolor(t_mlx *dt);

void	fdf_clear_img(t_mlx *data);

//static void	fdf_colorset_screen(t_mlx *data);
int	fdf_map_to_screen(t_mlx *data);

//static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data);
//static void	fdf_map_relief(t_mapctr *mapctr, t_mlx *data);

void	fdf_map_fill(t_mlx *data);

void	fdf_fill_img(t_mlx *data);

int	fdf_put_pixel(t_mlx *data, int color, char *pixel);

void	fdf_call_put_pixel(t_mlx *data, t_point current);
void	fdf_bresenham(t_mlx *data, t_point s, t_point e);

int	rgb(unsigned char red, unsigned char green, unsigned char blue);

t_color	rrgb(int color);
unsigned char	red_part(int color);
unsigned char	green_part(int color);
unsigned char	blue_part(int color);

//static int	fdf_bresenham_else_while_color(t_point s, t_point e, t_bresenham vr);

		//static void	fdf_bresenham_else_while(t_mlx *data, t_point s, t_point e, t_bresenham vr);
		void	fdf_bresenham_else(t_mlx *data, t_point s, t_point e, float ratio);

		//static int	fdf_bresenham_if_while_color(t_point s, t_point e, t_bresenham vr);
		//static void	fdf_bresenham_if_while(t_mlx *data, t_point s, t_point e, t_bresenham vr);
		void	fdf_bresenham_if(t_mlx *data, \
		t_point s, t_point e, float ratio);








#endif