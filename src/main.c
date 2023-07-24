#include "../include/fdf.h"

void    fdf_print_me_all(t_mlx *data, t_mapctr *mapctr)
{
   printf("data->gradient = %d\n", data->gradient);//
   printf("mapctr->width = %d\n", mapctr->width); //
   printf("mapctr->height = %d\n", mapctr->height);//
   printf("t_point->z = %f\n", mapctr->map[0][0].z);//derniere coordonees en z
}

static int	fdf_quit(void *param)
{
	exit(fdf_free_all((t_mlx *)param));
}

void fdf_print_data_init(t_mlx *data)
{
    printf("-data elements reset-\n");//
    printf("data->ptr = %p\n", data->ptr);//
    printf("data->win = %p\n", data->win);//
    printf("data->mapctr.map = %p\n", data->mapctr.map);//
    printf("data->img.ptr = %p\n", data->img.ptr);//
    printf("data->img.str = %p\n", data->img.str);//
    printf("data->colors = %p\n", data->colors);// 
    printf("data->gradient = %d\n", data->gradient);//
    printf("data->mapctr.min = %ld\n", data->mapctr.min);//
    printf("data->mapctr.max = %ld\n", data->mapctr.max);//
    /*printf("data->scale = %f\n", data->scale);//
    printf("data->relief = %f\n", data->relief);//
    printf("data->deg = %f\n", data->deg);//
    printf("data->deg_sin = %f\n", data->deg_sin);//
    printf("data->deg_cos = %f\n", data->deg_cos);//
    printf("data->iy = %f\n", data->iy);//
    printf("data->iy_sin = %f\n", data->iy_sin);//
    printf("data->iy_cos = %f\n", data->iy_cos);//*/
    //printf("data->nbrcolors = %d\n", data->nbrcolors);//
}
void    fdf_init(t_mlx *data)
{
    printf("-fdf_init-\n");//
    data->ptr = NULL; // pour connection au serveur
    data->win = NULL; // pour la fenetre
    data->mapctr.map = NULL;// map x y
    data->img.ptr = NULL;// pour l'image
    data->img.str = NULL;//mlx_get_data_addr
    data->colors = NULL;//tableau de couleur
    data->gradient = 1;// pas trouve comment le gradient peut etre superieur a 1
    data->mapctr.min = 2147483647; // mise a zero des valeurs min et max
    data->mapctr.max = -2147483648; // mise a zero des valeurs min et max
    //fdf_print_data_init(data);//
    //printf("-data elements reseted-\n");//
}
//n'empeche pas le bon fonctionnement si absent

void    fdf_creator(char *argv, int fd)
{
    //printf("-entering creator-\n"); //
    t_mlx   data; //nom donne a la structure
    //printf("-variable 'data' created with t_mlx structure-\n");//
    fdf_init(&data); //initialise la structure
    data.ptr = mlx_init(); //initie la connection avec le serveur graphique
    //printf("server connected = data->ptr = %p\n", data.ptr);//
    //printf("-entering filoperation and mapsize-\n");//
    if (fdf_fileoperations(argv, &data, fd) == 1)
    {
        data.win = mlx_new_window(data.ptr, FDF_WIDTH, FDF_HEIGHT, argv); //creer et ouvrir une fenetre
        //printf("-window created-\ndata->win = %p\n", data.win);//
        data.colors = fdf_colorgradient(&data); //
        if (!(data.colors))
        {
			fdf_free_all(&data); //if no colors we free
            ft_exit("Unattributed Color"); 
        }
        //printf("data->colors = %p\n", data.colors);//afficher le tableau de couleur
        //printf("data->nbrcolors = %d\n", data.nbrcolors);//
        fdf_colormap(&data, data.colors);
        fdf_default(&data);
        mlx_hook(data.win, 02, (1L << 0), fdf_keypressed, &data);
		mlx_hook(data.win, 17, 0, fdf_quit, &data);
		mlx_mouse_hook(data.win, fdf_mouseclick, &data);
        //fdf_print_me_all(&data, &data.mapctr);//
    }

    mlx_loop(data.ptr); //gere les evenements
}

int main(int argc, char **argv)
{
    int fd;

    fd = 0;
    if (argc != 2)
        ft_exit("choose map");
    printf("-argc check passed-\n");//
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_exit_no_file(argv[1]);
    printf("-open done-\n");//
    fdf_creator (argv[1], fd);
    close(fd);
    return(0);
} 

//argv check
//unused: mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF); //dessine un pixel