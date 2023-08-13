/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamita <mamita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:09:48 by ageiser           #+#    #+#             */
/*   Updated: 2023/08/13 23:57:49 by mamita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h> //open
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h> //hypotf

# define FDF_WIDTH 400
# define FDF_HEIGHT 300

# ifndef RAD
#  define RAD 57.2958 //1 radian = 57.2958 deg
# endif

# ifndef B
#  define B fdf_atoi_color
# endif

# ifndef DEG_INIT
#  define DEG_INIT 45
# endif

# ifndef INCL_Y
#  define INCL_Y 80
# endif

# ifndef KEYBOARDVALUES_H
#  define KEYBOARDVALUES_H

#  define KV_ESCAPE 65307
#  define KV_ESCAPE_M 53

#  define KV_SPACE 32
#  define KV_SPACE_M 49

#  define KV_PLUS 61
#  define KV_PLUS_M 24
#  define KV_MINUS 45
#  define KV_MINUS_M 27

#  define KV_PLUS2 65451
#  define KV_MINUS2 65453

#  define KV_R 114
#  define KV_R_M 15

#  define KV_P 112
#  define KV_P_M 35

#  define KV_W 119
#  define KV_W_M 13
#  define KV_A 97
#  define KV_A_M 0
#  define KV_S 115
#  define KV_S_M 1
#  define KV_D 100
#  define KV_D_M 2

#  define KV_C 99
#  define KV_C_M 8

#  define KV_LEFTARROW 65361
#  define KV_LEFTARROW_M 123
#  define KV_RIGHTARROW 65363
#  define KV_RIGHTARROW_M 124
#  define KV_TOPARROW 65362
#  define KV_TOPARROW_M  126
#  define KV_BOTTOMARROW 65364
#  define KV_BOTTOMARROW_M 125

/* Same on linux and macos */
#  define KV_SCROLLUP 4
#  define KV_SCROLLDOWN 5
#  define KV_SCROLLLEFT 7
#  define KV_SCROLLRIGHT 6

#  define KV_SCROLLBUTTON 2

#  define KV_LEFTCLICK 1
#  define KV_RIGHTCLICK 3

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
	t_point		**map;
	int			width;
	int			height;
	long		min;
	long		max;
	long		range;
	long		translatex;
	long		translatey;
	float		xorigin;
	float		yorigin;
}				t_mapctr;
//**map = tableau 2D axe x et y
//width = nombre de colones
//height = nombre de lignes
//min = min z value
//range = diff between max z and min z
//translatex = decalage de l'image sur l'axe x
//xorigin = centre de la map

typedef struct s_mlximg
{
	void	*ptr;
	char	*str;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlximg;
//*ptr = mlx_new_image
//*str = mlx_get_data_addr
//bpp = bit per pixel = 32 parce que 4 x 8 defini par mlx
//size_line = longuer d'une ligne de fichier fdf = 
//7680, width * UNIQ_BPP defini par mlx
//endian = little endian for now on mac-intel  val = 0

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	t_mapctr	mapctr;
	t_mlximg	img;
	int			*colors;
	int			nbrcolors;
	int			gradient;
	float		scale;
	float		relief;
	float		deg;
	float		deg_sin;
	float		deg_cos;
	float		iy;
	float		iy_sin;
	float		iy_cos;
}				t_mlx;
//*ptr = mlx_init
//*win = mlx_new_window
//mapctr = structure mapctr avec argument mapctr
//img = structure mlximg avec argument image pour le dessin de l'image
//*colors = pointeur sur un tableau de 256 cases de degrade de couleur
//nbrcolors = nombre de degrades de couleur
//gradient = permet de choisir une gamme de couleur / vecteur indiquant 
//comment une grandeur physique varie dans l'espace, degrade de couleur
//scale = valeur de l'hypothenus de height et width
//relief = echelle de la hauteur y
//deg = orientation de l'image (+45 deg)
//deg_sin = sinus (deg / RAD)
//deg_cos = cosinus (deg / RAD)
//iy = pivotement sur son axe y (80)
//iy_sin = sinus (iy / RAD)
//iy_cos = cosinus (iy / RAD)

typedef struct s_color
{
	int				val;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;
//val = int value of color

typedef struct s_bresenham
{
	float	ratio;
	t_point	current;
	float	diff;
	float	i;
	t_color	bcol;
	t_color	ccol;
}			t_bresenham;

//ratio = rapport entre x et y
//current = t_point s
//diff = valeur de current - base
//i = compteur
//bcol = base color
//ccol = current color

void	fdf_creator(char *argv, int fd);
void	fdf_init(t_mlx *data);
void	ft_exit(char *str);
void	ft_exit_no_file(char *argv);
int		fdf_fileoperations(char *argv, t_mlx *data, int fd);
int		fdf_set_mapsize(int fd, t_mapctr *mapctr);
int		fdf_set_mapsize__width(char *line); 
int		fileoperations2(char *argv, t_mlx *data);
t_point	**fdf_generate_map(int fd, t_mapctr *mapctr);
void	fdf_map_fill_z(t_mapctr *mapctr, int fd);
void	fdf_free_map(t_point **map);
int		fdf_atoi_color(const char *str, t_mapctr *mapctr, int x, int y);
int		fdf_atoi_getcolor(const char *str);
void	fdf_findrange(t_mapctr *mapctr);
void	fdf_findrangee(t_mapctr *mapctr);
int		*fdf_colorgradient(t_mlx *data);
int		*fdf_colorgradient_1(t_mlx *data);
int		*fdf_colorgradient_2(t_mlx *data);
int		*fdf_colorgradient_3(t_mlx *data);
int		*fdf_colorgradient_4(t_mlx *data);
int		fdf_free_all(t_mlx *data);
void	fdf_colormap(t_mlx *data, int *colors);
long	fdf_colorgradient_indice(t_mlx *data, int x, int y);
int		fdf_default(void *data);
int		fdf_map_to_screen(t_mlx *data);
void	fdf_map_fill(t_mlx *data);
//static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data);
//static void	fdf_map_relief(t_mapctr *mapctr, t_mlx *data);
void	fdf_fill_img(t_mlx *data);
int		fdf_put_pixel(t_mlx *data, int color, char *pixel);
t_color	rrgb(int color);
void	fdf_bresenham(t_mlx *data, t_point base, t_point current);
void	fdf_bresenham_if(t_mlx *data, \
t_point base, t_point current, float ratio);
//static void	fdf_bresenham_if_while(t_mlx *data, t_point base, 
//t_point current, t_bresenham vr);
//static int	fdf_bresenham_if_while_color(t_point base, 
//t_point current, t_bresenham vr);
int		rgb(unsigned char red, unsigned char green, unsigned char blue);
void	fdf_call_put_pixel(t_mlx *data, t_point current);
void	fdf_bresenham_else(t_mlx *data, t_point s, t_point e, float ratio);
//static void	fdf_bresenham_else_while(t_mlx *data, t_point s, 
//t_point e, t_bresenham vr);
//static int	fdf_bresenham_else_while_color(t_point s, 
//t_point e, t_bresenham vr);
//void	fdf_print_me_all(t_mlx *data, t_mapctr *mapctr);
int		fdf_keypressed(int key, void *param);
int		fdf_mouseclick(int key, int x, int y, void *param);
void	fdf_clear_img(t_mlx *data);//
int		fdf_parallel(t_mlx *dt);//
int		fdf_flat(t_mlx *dt);//
int		fdf_changecolor(t_mlx *dt);//
void	fdf_empty_colormap(t_mlx *data, int *colors);
//int	fdf_incline(int key, t_mlx *data);//
//static void	fdf_colorset_screen(t_mlx *data);

#endif
