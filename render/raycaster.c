#include "../Include/cube.h"


float distance(ax, ay, bx, by, ang)
{
	return cos(ang)*(bx-ax)-sin(ang)*(by-ay);
}

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
	(void)angle;
	(void)inc;

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
	return (0);
}
/*
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


	float wall_height  = 21000 / ( inc + 0.001);
		printf("%f\n",wall_height);
	draw_line(&image, scree_strip,  (1080 / 2)  - wall_height / 2, scree_strip,wall_height);

	return(0);
}

int ray_fov3d(t_game *state,t_image image ,float angle,int inc)
{
	float	until;
	float	plus;
	int	scree_strip;
	t_ray	ray;
	int step = 0;
		plus = 0;
		until = state->player->direction +  PI / 3;
		while(state->player->direction + plus < until)
	{
			ray.angle = state->player->direction + plus;
					raycaster3d(state, image, ray, step);
					step+= 16;
			plus += PI  / 84;
	}
}
*/
