#include "../include/fdf.h"

static int	fdf_bresenham_else_while_color(t_point s, \
		t_point e, t_bresenham vr)
{
	if (s.y < e.y)
		vr.current.color = rgb(((vr.scl.r * (1 - (vr.current.y - s.y) / \
	vr.diff)) + (vr.ecl.r * (((vr.current.y - s.y) / vr.diff)))), ((vr.scl.g \
	* (1 - (vr.current.y - s.y) / vr.diff)) + (vr.ecl.g * (((vr.current.y - \
	s.y) / vr.diff)))), ((vr.scl.b * (1 - (vr.current.y - s.y) / vr.diff)) + \
	(vr.ecl.b * (((vr.current.y - s.y) / vr.diff)))));
	else
		vr.current.color = rgb(((vr.scl.r * ((vr.current.y - e.y) / \
	vr.diff)) + (vr.ecl.r * (1 - ((vr.current.y - e.y) / vr.diff)))), \
	((vr.scl.g * ((vr.current.y - e.y) / vr.diff)) + (vr.ecl.g * (1 - \
	((vr.current.y - e.y) / vr.diff)))), ((vr.scl.b * ((vr.current.y - e.y) \
	/ vr.diff)) + (vr.ecl.b * (1 - ((vr.current.y - e.y) / vr.diff)))));
	return (vr.current.color);
}

static void	fdf_bresenham_else_while(t_mlx *data, \
		t_point s, t_point e, t_bresenham vr)
{
	while ((int)(vr.current.y + 0.5) != (int)(e.y + 0.5))
	{
		vr.current.color = fdf_bresenham_else_while_color(s, e, vr);
		if (vr.current.y < e.y)
			vr.current.y += 1;
		else
			vr.current.y -= 1;
		if (vr.current.x < e.x)
			vr.current.x = s.x + (vr.ratio * vr.i);
		else
			vr.current.x = s.x - (vr.ratio * vr.i);
		(vr.i)++;
		if (vr.current.x >= 0 && vr.current.x < FDF_WIDTH \
					&& vr.current.y >= 0 && vr.current.y < FDF_HEIGHT)
			fdf_call_put_pixel(data, vr.current);
	}
}

void	fdf_bresenham_else(t_mlx *data, \
		t_point s, t_point e, float ratio)
{
	t_bresenham	vr;

	if ((s.x < 0 || s.x >= FDF_WIDTH || s.y < 0 \
	|| s.y >= FDF_HEIGHT) && (e.x < 0 || e.x >= FDF_WIDTH \
	|| e.y < 0 || e.y >= FDF_HEIGHT))
		return ;
	vr.scl = rrgb(s.color);
	vr.ecl = rrgb(e.color);
	vr.diff = fabs(s.y - e.y);
	vr.current = s;
	vr.ratio = ratio;
	vr.i = 0;
	fdf_bresenham_else_while(data, s, e, vr);
}