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
#include "../libft/libft.h"
#include <fcntl.h> //open
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h> //hypotf

#define FDF_WIDTH 1920
#define FDF_HEIGHT 1080

# ifndef RAD
#  define RAD 57.2958 //1 radian = 57.2958 deg
# endif



typedef struct s_point
{
	float	x; //axe x
	float	y; // axe y
	float	z; // axe z, valeur en char
	int		color; //valeur de la couleur en int
}		t_point;

typedef struct s_mapctr
{
	t_point		**map;// tableau 2D axe x et y
	int			width;// nombre de colones
	int			height;// nombre de lignes
	long		min; //nbr min linked to the gradient
	long		max; //nbr max linked to the gradient
	long		range;//  diff between max z and min z linked to gradient and color == max - min
	long		translatex; // decalage de l'image sur l'axe x 
	long		translatey;// decalage de l'image sur l'axe x
	float		xorigin;// centre de rotation probable
	float		yorigin;// centre de rotation probable
}				t_mapctr;

typedef struct s_mlximg
{
	void	*ptr; //mlx_new_image
	char	*str; //mlx_get_data_addr 
	int		bpp; // bit per pixel
	int		size_line; // longuer d'une ligne de fichioer fdf
	int		endian; // most significant byte of the pixel
}			t_mlximg;

typedef struct s_mlx
{
    void *ptr; //mlx_init 
    void *win; //mlx_new_window
    t_mapctr mapctr; //structure mapctr avec argument mapctr 
    t_mlximg img; // structure mlximg avec argument image pour le dessin de l'image
    int *colors; // pointeur sur un tableau de 256 cases de degrade de couleur
    int nbrcolors; // nombre de degrades de couleur
    int gradient; //vecteur indiquant comment une grandeur physique varie dans l'espace, degrade de couleur
    float scale; // valeur de l'hypothenus de height et width
    float relief; // echelle de la hauteur y
    float deg; // orientation de l'image (+45 deg)
    float deg_sin; //sinus (deg / RAD) 
    float deg_cos; // cosinus (deg / RAD)
    float iy; // pivotement sur son axe y
    float iy_sin; // sinus (iy / RAD)
    float iy_cos; // cosinus (iy / RAD)
}               t_mlx;

typedef struct s_color
{
	int				val; //
	unsigned char	r; // rouge 
	unsigned char	g; // vert
	unsigned char	b; // bleu
}					t_color;


typedef struct s_bresenham
{
	float	ratio; // rapport entre x et y
	t_point	current; //
	float	diff; //
	float	i; //
	t_color	scl; // s color
	t_color	ecl; // e color
}			t_bresenham;

void fdf_creator(char *argv, int fd); //
void fdf_init(t_mlx *data); //

void ft_exit(char *str); //
void ft_exit_no_file(char *argv); //

int fdf_fileoperations(char *argv, t_mlx *data, int fd);//
int	fdf_set_mapsize(int fd, t_mapctr *mapctr); //
int	fdf_set_mapsize__width(char *line); //
int	fileoperations2(char *argv, t_mlx *data); //
t_point	**fdf_generate_map(int fd, t_mapctr *mapctr); //
void	fdf_free_map(t_point **map); //
int	fdf_atoi_color(const char *str, t_mapctr *mapctr, int x, int y); //
int	fdf_atoi_getcolor(const char *str); //
void	fdf_findrange(t_mapctr *mapctr); //
void	fdf_findrangee(t_mapctr *mapctr); //
int	*fdf_colorgradient(t_mlx *data); //
int	*fdf_colorgradient_1(t_mlx *data); //
int	*fdf_colorgradient_2(t_mlx *data); //
int	*fdf_colorgradient_3(t_mlx *data); //
int	*fdf_colorgradient_4(t_mlx *data); //
int	fdf_free_all(t_mlx *data); //
void	fdf_colormap(t_mlx *data, int *colors); //
long	fdf_colorgradient_indice(t_mlx *data, int x, int y); //
int	fdf_default(void *param); //
int	fdf_map_to_screen(t_mlx *data); //
void	fdf_map_fill(t_mlx *data); //
//static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data); //
//static void	fdf_map_relief(t_mapctr *mapctr, t_mlx *data); //
void	fdf_fill_img(t_mlx *data); //
int	fdf_put_pixel(t_mlx *data, int color, char *pixel); //
t_color	rrgb(int color); //
void	fdf_bresenham(t_mlx *data, t_point s, t_point e); //
void	fdf_bresenham_if(t_mlx *data, \
t_point s, t_point e, float ratio); //
//static void	fdf_bresenham_if_while(t_mlx *data, t_point s, t_point e, t_bresenham vr); //
//static int	fdf_bresenham_if_while_color(t_point s, t_point e, t_bresenham vr); //
int	rgb(unsigned char red, unsigned char green, unsigned char blue); //
void	fdf_call_put_pixel(t_mlx *data, t_point current); //
void	fdf_bresenham_else(t_mlx *data, t_point s, t_point e, float ratio); //
//static void	fdf_bresenham_else_while(t_mlx *data, t_point s, t_point e, t_bresenham vr); //
//static int	fdf_bresenham_else_while_color(t_point s, t_point e, t_bresenham vr); //
void	fdf_print_me_all(t_mlx *data, t_mapctr *mapctr); // personal checker
///////////////////////////////////////////
//int line_counter(int fd, int height);
//int ft_width(char **character);
//char **str_data(int fd, int height, char *argv);
//void invalid_file_msg(int ft_return, char *argv);
//int ft_wordcount(char *str, char c);

//void	fdf_empty_colormap(t_mlx *data, int *colors);

//int	fdf_parallel(t_mlx *dt);
//int	fdf_flat(t_mlx *dt);

//int	fdf_changecolor(t_mlx *dt);

//void	fdf_clear_img(t_mlx *data);

//static void	fdf_colorset_screen(t_mlx *data);

//unsigned char	red_part(int color);
//unsigned char	green_part(int color);
//unsigned char	blue_part(int color);

#endif