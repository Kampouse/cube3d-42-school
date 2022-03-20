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
	while(game->map[ (int)(game->player->y_pos + (ray.dy * inc)) / game->player->scale][(int)(game->player->x_pos + (ray.dx * inc))  / game->player->scale] != '1')
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
			raycaster2d(state, image, ray);
		ray.angle = state->player->direction - plus;
			raycaster2d(state, image, ray );
			plus += PI / 84;
	}
}
int raycaster3d(t_game *game, t_image image, t_ray ray,int scree_strip)
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
	while(game->map[ (int)(game->player->y_pos + (ray.dy * inc)) / game->player->scale][(int)(game->player->x_pos + (ray.dx * inc))  / game->player->scale] != '1')
		inc +=1;		

	printf("%d\n",inc);
	square_shape(&image,scree_strip *  inc,0,color_to_rgb(0,0,0,0));
	return(0);
}

int ray_fov3d(t_game *state,t_image image ,float angle,int inc)
{
	float	until;
	float	plus;
	int	scree_strip;
	t_ray	ray;

	plus = 0;
	until = state->player->direction +  PI / 6;
	scree_strip= 0;
		while(state->player->direction + plus < until)
	{

		ray.angle = state->player->direction + plus;
			raycaster3d(state, image, ray,scree_strip);
		scree_strip+=16;
		//ray.angle = state->player->direction - plus;
	//		raycaster3d(state, image, ray,scree_strip);
			plus += PI / 84;
	}
}
