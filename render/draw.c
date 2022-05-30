#include "../Include/cube.h" 
#include <sys/types.h>
#include <unistd.h>



void load_image(t_game *game)
{

	const t_mlx_tex *temp =   mlx_load_png(game->map_data->norh_texture);
	const t_mlx_tex *temp2 = mlx_load_png(game->map_data->south_texture );
	const t_mlx_tex *temp3 =  mlx_load_png(game->map_data->west_texture );;
	const t_mlx_tex *temp4 = mlx_load_png(game->map_data->est_texture );;
	 game->map_data->north_tex = mlx_texture_to_image(game-> mlx ,(t_mlx_tex  *) temp);
	 game->map_data->south_tex =  mlx_texture_to_image(game-> mlx ,(t_mlx_tex  *) temp2);
	 game->map_data->est_tex  =   mlx_texture_to_image(game-> mlx ,(t_mlx_tex  *) temp3);
	 game->map_data->west_tex  =  mlx_texture_to_image(game-> mlx ,(t_mlx_tex  *) temp4);
	mlx_delete_texture((t_mlx_tex * ) temp );
	mlx_delete_texture((t_mlx_tex * ) temp2 );
	mlx_delete_texture((t_mlx_tex * ) temp3 );
	mlx_delete_texture((t_mlx_tex * ) temp4 );

}
uint32_t    pixel_to_color(t_mlx_image *tex,uint32_t  x_pos, uint32_t  y_pos)
{
		unsigned int *pixel;
	pixel = (unsigned int *)(tex->pixels + (x_pos + y_pos  % tex->width * 5) * sizeof(unsigned int));
	return(*pixel); 
}

void	draw_pixel(t_mlx_image *img, uint32_t  x, uint32_t  y, uint32_t  color)
{
	uint32_t 	*pixel;

	if (x >= img->width || y >= img->height)
		return ;
	pixel = (uint32_t  *)&img->pixels[(x + y * img->width) * sizeof(uint32_t)];
	*pixel = color;
}
 

t_mlx_image *textur_to_draw(t_game *game)
{
	if(game->last_ray == 'N')
		return (game->map_data->north_tex);
	if(game->last_ray == 'E')
		return (game->map_data->north_tex);
	if(game->last_ray == 'W')
		return (game->map_data->north_tex);
	if(game->last_ray == 'S')
		return (game->map_data->north_tex);






return NULL;
}
int  wall_color( t_mlx_image *tex, t_game *game, uint32_t  ray_x, uint32_t height)
{
	unsigned int	inc = 0;
	(void)game;
	t_mlx_image *type;
	while(inc < height)
	{
		draw_pixel(game-> image .image,  ray_x, inc, pixel_to_color(tex, ray_x, inc));
		inc++;
	}
	return (0);
}

void draw_texture(t_game *game,uint32_t pos_x, uint32_t pos_y)
{
const t_mlx_image *temp = textur_to_draw(game);
const uint32_t color =  pixel_to_color((t_mlx_image *)temp,pos_x,pos_y);
	draw_pixel(game->image.image,pos_x,pos_y,color);
}


