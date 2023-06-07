#include "../include/fdf.h"

void	fdf_clear_img(t_mlx *data)
{
	if (data->img.ptr)
		mlx_destroy_image(data->ptr, data->img.ptr);
	data->img.ptr = mlx_new_image(data->ptr, \
			FDF_WIDTH, FDF_HEIGHT);
	data->img.str = mlx_get_data_addr(data->img.ptr, \
			&(data->img.bpp), &(data->img.size_line), \
			&(data->img.endian));
}