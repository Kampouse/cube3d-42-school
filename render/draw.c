#include "../Include/cube.h" 
#include <_types/_uint32_t.h>
#include <unistd.h>



void load_image(t_map *map_data)
{
	 map_data->north_tex = mlx_load_png(map_data->norh_texture);
	 map_data->south_tex = mlx_load_png(map_data->south_texture );
	 map_data->west_tex	 = mlx_load_png(map_data->west_texture );
	 map_data->est_tex 	 = mlx_load_png(map_data->west_texture );
}

int   pixel_to_color(t_mlx_tex *tex,uint32_t  x_pos, uint32_t  y_pos)
{
 int color;
	if(  x_pos < 0 ||  x_pos  >= tex->width ||  y_pos < 0 ||  y_pos >= tex->height)


		return(0x0); 
color = tex->pixels[(y_pos * tex->width + x_pos) * 4];
return (color);
}

