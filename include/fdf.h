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

# ifndef mapz
#  define mapz ((mapctr->map)[x][y])
# endif


typedef struct s_point
{
	float	x; //axe x
	float	y; // axe y
	float	z; // axe z, valeur en char
	int		color; //valeur de la couleur en int, mais qui deviendra tripotee par brensenham if
}		t_point;

typedef struct s_mapctr
{
	t_point		**map;// tableau 2D axe x et y
	int			width;// nombre de colones
	int			height;// nombre de lignes
	long		min; //nbr min linked to the gradient
	long		max; //nbr max linked to the gradient
	long		range;//  diff between max z and min z linked to gradient and color == max - min used to calculate the indice
	long		translatex; // decalage de l'image sur l'axe x 
	long		translatey;// decalage de l'image sur l'axe x
	float		xorigin;// centre de rotation probable
	float		yorigin;// centre de rotation probable
}				t_mapctr;

typedef struct s_mlximg
{
	void	*ptr; //mlx_new_image
	char	*str; //mlx_get_data_addr 
	int		bpp; // bit per pixel = 32 parce que 4 x 8 definie par mlx 
	int		size_line; // longuer d'une ligne de fichier fdf = 7680, width * UNIQ_BPP definie par mlx
	int		endian; // little endian for now on mac-intel  val = 0
}			t_mlximg;

typedef struct s_mlx
{
    void *ptr; //mlx_init 
    void *win; //mlx_new_window
    t_mapctr mapctr; //structure mapctr avec argument mapctr 
    t_mlximg img; // structure mlximg avec argument image pour le dessin de l'image
    int *colors; // pointeur sur un tableau de 256 cases de degrade de couleur
    int nbrcolors; // nombre de degrades de couleur
    int gradient; // permet de choisir une gamme de couleur / vecteur indiquant comment une grandeur physique varie dans l'espace, degrade de couleur
    float scale; // valeur de l'hypothenus de height et width
    float relief; // echelle de la hauteur y
    float deg; // orientation de l'image (+45 deg)
    float deg_sin; //sinus (deg / RAD) 
    float deg_cos; // cosinus (deg / RAD)
    float iy; // pivotement sur son axe y (80)
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
	t_point	current; // t_point s
	float	diff; //valeur de e - s 
	float	i; //compteur
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
void	fdf_map_fill_z(t_mapctr *mapctr, int fd);//
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
int	fdf_default(void *data); //
int	fdf_map_to_screen(t_mlx *data); //
void	fdf_map_fill(t_mlx *data); //
//static void	fdf_map_rotation(t_mapctr *mapctr, t_mlx *data); //
//static void	fdf_map_relief(t_mapctr *mapctr, t_mlx *data); //
void	fdf_fill_img(t_mlx *data); //
int	fdf_put_pixel(t_mlx *data, int color, char *pixel); //
t_color	rrgb(int color); //
void	fdf_bresenham(t_mlx *data, t_point s, t_point current); //
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

int			fdf_keypressed(int key, void *param);//
int			fdf_mouseclick(int key, int x, int y, void *param);//
void	fdf_clear_img(t_mlx *data);//
int		fdf_parallel(t_mlx *dt);//
int		fdf_flat(t_mlx *dt);//
int		fdf_changecolor(t_mlx *dt);//
void	fdf_empty_colormap(t_mlx *data, int *colors);

//int	fdf_incline(int key, t_mlx *data);//

///////////////////////////////////////////
//int line_counter(int fd, int height);
//int ft_width(char **character);
//char **str_data(int fd, int height, char *argv);
//void invalid_file_msg(int ft_return, char *argv);
//int ft_wordcount(char *str, char c);






//static void	fdf_colorset_screen(t_mlx *data);

//unsigned char	red_part(int color);
//unsigned char	green_part(int color);
//unsigned char	blue_part(int color);

#endif

#ifndef KEYBOARDVALUES_H
# define KEYBOARDVALUES_H

# define KV_ESCAPE 65307
# define KV_ESCAPE_M 53

# define KV_SPACE 32
# define KV_SPACE_M 49

# define KV_PLUS 61
# define KV_PLUS_M 24
# define KV_MINUS 45
# define KV_MINUS_M 27

# define KV_PLUS2 65451
# define KV_MINUS2 65453

# define KV_R 114
# define KV_R_M 15

# define KV_P 112
# define KV_P_M 35

# define KV_W 119
# define KV_W_M 13
# define KV_A 97
# define KV_A_M 0
# define KV_S 115
# define KV_S_M 1
# define KV_D 100
# define KV_D_M 2

# define KV_C 99
# define KV_C_M 8

# define KV_LEFTARROW 65361
# define KV_LEFTARROW_M 123
# define KV_RIGHTARROW 65363
# define KV_RIGHTARROW_M 124
# define KV_TOPARROW 65362
# define KV_TOPARROW_M  126
# define KV_BOTTOMARROW 65364
# define KV_BOTTOMARROW_M 125

# define KV_LEFTCHEVRON 44
# define KV_LEFTCHEVRON_M 43
# define KV_RIGHTCHEVRON 46
# define KV_RIGHTCHEVRON_M 47

/* Same on linux and macos */
# define KV_SCROLLUP 4
# define KV_SCROLLDOWN 5
# define KV_SCROLLLEFT 7
# define KV_SCROLLRIGHT 6

# define KV_SCROLLBUTTON 2

# define KV_LEFTCLICK 1
# define KV_RIGHTCLICK 3

#endif