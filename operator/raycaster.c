#include "../cube.h"



int raycaster2d(t_game *game, t_image image, t_ray ray)
{
	int inc;

	inc = 0;
	ray.delta_y = cos(ray.angle) / 1;
	ray.delta_x = sin(ray.angle);
	ray.dx = cos(degToRad(ray.angle)) * ray.delta_x -  sin(degToRad(ray.angle)) * ray.delta_y;
	ray.dy = sin(degToRad(ray.angle)) * ray.delta_x + cos(degToRad(ray.angle)) * ray.delta_y;
	ray.max_value = fmax(fabs(ray.dx), fabs(ray.dy));
	ray.dx/= ray.max_value;
	ray.dy/= ray.max_value;
	while(game->map[ (int)(game->player->y_pos + (ray.dy * inc)) >> 5][(int)(game->player->x_pos + (ray.dx * inc)) >> 5] != '1')
		inc +=1;		
	draw_line(&image, game->player->x_pos, game->player->y_pos, game->player->x_pos + (ray.dx * inc), game->player->y_pos + (ray.dy * inc));
	return(0);
}

int ray_fov(t_game *state,t_image image ,float angle,int inc)
{
	float	until;
	float	plus;
	t_ray	ray;

	plus = 0;
	until = state->player->direction +  PI / 6;
		while(state->player->direction + plus < until)
	{
		ray.angle = state->player->direction + plus;
			raycaster2d(state, image,	 ray);
		ray.angle = state->player->direction - plus;
			raycaster2d(state, image, ray );
			plus += PI / 84;
	}
}
